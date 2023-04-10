#define _GNU_SOURCE
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sio.h>
enum EE_SIO_START_RETCODES
{
    EESIO_SUCESS = 0,          /** everything is OK! */
    EESIO_COOKIE_OPEN_IS_NULL, /** fopencookie() failed to hook the custom stream */
    EESIO_BUFFER_ALLOC_IS_NULL /** the allocation of memfile_cookie.buf failed */
};
// GLOBAL
FILE *EE_SIO;
cookie_io_functions_t COOKIE_FNCTS;

ssize_t cookie_sio_write(void *c, const char *buf, size_t size);
ssize_t cookie_sio_read(void *c, char *buf, size_t size);
// int cookie_sio_seek(void *c, _off64_t *offset, int whence);
// int cookie_sio_close(void *c);

int ee_sio_start(u32 baudrate, u8 lcr_ueps, u8 lcr_upen, u8 lcr_usbl, u8 lcr_umode, int hook_stdout)
{
    sio_init(baudrate, lcr_ueps, lcr_upen, lcr_usbl, lcr_umode);

    COOKIE_FNCTS.read = cookie_sio_read;
    COOKIE_FNCTS.close = NULL;
    COOKIE_FNCTS.seek = NULL;
    COOKIE_FNCTS.write = cookie_sio_write;
    EE_SIO = fopencookie(NULL, "w", COOKIE_FNCTS);
    if (hook_stdout)
    {
        sio_putsn("hooking std streams...\n");
        sio_putsn("\tstdout...\n");
        stdout = fopencookie(NULL, "w", COOKIE_FNCTS);
        setvbuf(stdout, NULL, _IONBF, 0); // no buffering
        sio_putsn("\treplacing stderr with stdout...\n");
        stderr = stdout;
        sio_putsn("\treplacing EE_SIO with stdout...\n");
        EE_SIO = stdout;
    } else {
        setvbuf(EE_SIO, NULL, _IONBF, 0); // no buffering for this bad boy
    }
    if (EE_SIO == NULL) {
        printf("EE_SIO stream is NULL\n");
        return EESIO_COOKIE_OPEN_IS_NULL;
    }
    fprintf(EE_SIO, "%s: successfully started with:\n\t"
    "baudrate=%d\n\t"
    "lcr_ueps=%d\n\t"
    "lcr_upen=%d\n\t"
    "lcr_usbl=%d\n\t"
    "lcr_umode=%d\n"
    , __func__, baudrate, lcr_ueps, lcr_upen, lcr_usbl, lcr_umode);
    return EESIO_SUCESS;
}


ssize_t cookie_sio_write(void *c, const char *buf, size_t size)
{
    return sio_putsn(buf);
}

ssize_t cookie_sio_read(void *c, char *buf, size_t size)
{
    return sio_read(buf, size);
}
/*
int cookie_sio_seek(void *c, _off64_t *offset, int whence)
{
    DPRINTF("%s: start", __func__);
    return 0;
}

int cookie_sio_close(void *c)
{
    DPRINTF("%s: start", __func__);
    return 0;
} */
