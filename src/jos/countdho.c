#define IS_RP6502
// #define IS_DOSWIN

#include "kc-functions.c"
#include <stdio.h>

int main()
{
    int x;

    printf(" Dec\t Hex\t Oct\n");
    printf(" ===\t ===\t ===\n");

    for (x = 0; x < 25; x++)
    {
        printf("%4.3d\t", x);
        printf("%4.3x\t", x);
        printf("%4.3o\n", x);
    }

    return (0);
}