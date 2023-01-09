#include <kernel.h>
#define _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sio.h>


int printf(const char *format, ...);
ssize_t cookie_sio_write(void *c, const char *buf, size_t size)
{
    //printf("%s recieved this [%s]", __func__, buf);
    //return sio_write(buf, size);
    return sio_putsn(buf);
    //sio_flush();
}


ssize_t cookie_sio_read(void *c, char *buf, size_t size)
{
    //printf("%s recieved this [%s]", __func__, buf);
    return 0;
}


int cookie_sio_seek(void *c, _off64_t *offset, int whence)
{
    //printf("%s\n", __func__);
    return 0;
}

int cookie_sio_close(void *c)
{
    printf("%s\n", __func__);
    return 0;
}

cookie_io_functions_t COOKIE_FNCTS;

struct memfile_cookie  {
    char   *buf;        /* Dynamically sized buffer for data */
    size_t  allocated;  /* Size of buf */
    size_t  endpos;     /* Number of characters in buf */
    off_t   offset;     /* Current file offset in buf */
};

int main()
{
    int x = 0;
    printf("main start\n");
	sio_init(38400, 0, 0, 0, 0);
    struct memfile_cookie EE_SIO_COOKIE;
    EE_SIO_COOKIE.buf = NULL;
    EE_SIO_COOKIE.allocated = 0;
    EE_SIO_COOKIE.offset = 0;
    EE_SIO_COOKIE.endpos = 0;
    
    FILE *EE_SIO;
    COOKIE_FNCTS.read = cookie_sio_read;
    COOKIE_FNCTS.close = cookie_sio_close;
    COOKIE_FNCTS.seek = cookie_sio_seek;
    COOKIE_FNCTS.write = cookie_sio_write;
    EE_SIO = fopencookie(&EE_SIO_COOKIE, "w+", COOKIE_FNCTS);
    if (EE_SIO == NULL) {
        printf("EE_SIO stream is NULL\n");
    }
    setvbuf(EE_SIO, EE_SIO_COOKIE.buf, _IONBF, EE_SIO_COOKIE.allocated); // no buffering for this bad boy
    while (1) {
        fprintf(EE_SIO, "EE SIO fprintf with fopencookie!\n");
        //fputs("EE_SIO fputs()\n", EE_SIO);
        printf("..\n");
        sleep(1);
    }

    return 0;
}

#if defined(DUMMY_TIMEZONE)
void _libcglue_timezone_update()
{
}
#endif

#if defined(DUMMY_LIBC_INIT)
void _libcglue_init()
{
}
void _libcglue_deinit() {}
void _libcglue_args_parse() {}
#endif

#if defined(KERNEL_NOPATCH)
DISABLE_PATCHED_FUNCTIONS();
#endif
