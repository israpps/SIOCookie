#ifndef SIO_COOKIE_H
#define SIO_COOKIE_H

#define _GNU_SOURCE
#include <stdio.h>

enum  {EESIO_SUCESS = 0, COOKIE_OPEN_IS_NULL, BUFFER_ALLOC_IS_NULL}EE_SIO_START_RETVAL;
extern FILE *EE_SIO;
#endif