#include <cs50.h>
#include <stdio.h>

int add(int a, int b);

int main(void)  
{
    int x = get_int("x: ");
    int y = get_int("y: ");
    /* int z = add(x, y); /* a função recebe dois valores e retorna a soma dele para a variável z */

    printf("%i\n", add(x, y)); /* podemos simplificar apenas transportando a função add() para dentro do printf() */
}

int add(int a, int b) /* a função agora é do tipo inteiro e possui dois argumentos do tipo inteiro */
{
    return a + b; /* a função retorna a soma dessas duas variáveis */
}