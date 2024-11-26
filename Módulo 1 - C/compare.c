#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("What's x? "); /* recebe um valor inteiro e aloca na variável x */
    int y = get_int("What's y? "); /* recebe um valor inteiro e aloca na variável y */

    if (x < y)          /* expressão booleana que verifica se x é menor que y */
    {
        printf("x is less than y\n"); 
    }
    else if (x > y)     /* expressão booleana que verifica se x é maior que y */
    {
        printf("x is greater than y\n");
    }
    else                /* ultimo caminho de código, para caso as duas acimas sejam expressões falsas */
    {
        printf("x is equal to y\n");
    }
}