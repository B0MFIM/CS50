#include <stdio.h>
#include <stdlib.h>

/* Esse código foi um exemplo de como Valgrind pode ser utilizado para
   verificar se um programa tem vazamento de memória. */

int main(void)
{
    int *x = malloc(3 * sizeof(int));
    x[0] = 72; // x[1] = 72;
    x[1] = 23; // x[2] = 23;
    x[2] = 33; // x[3] = 33;
    free(x);
}