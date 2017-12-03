#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t  BYTE;
#define BLOCK 512;

typedef struct
{
    BYTE first = 0xff;
    BYTE second = 0xd8;
    BYTE third = 0xff;
} JPEGHEADER;