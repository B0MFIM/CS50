#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do // isso é um "do while" loop, o que significa: quero repetir o que esta dentro do "do" se a expressão no "while" for verdadeira
    {
        n = get_int("Size: ");
    }
    while (n < 1);

    for (int i = 0; i < n; i++) // este loop é para as Linhas
    {
        for (int j = 0; j < n; j++) // este loop é para as Colunas
        {
            printf("#");
        }
        printf("\n");
    }
}