#include <stdio.h>

/* Esse código foi um exemplo de garbage values. Ele mostra que, quando
   declaramos um array de inteiros, os valores dos elementos do array
   não são inicializados. E como não inicializamos os valores dos elementos
   do array, eles contêm valores aleatórios que estavam na memória antes
   de o array ser alocado. */

int main(void)
{
    // Declara um array de 1024 inteiros
    int scores[1024];

    // Exibe os valores dos elementos do array, que são valores aleatórios
    for (int i = 0; i < 1024; i++)
    {
        printf("%i\n", scores[i]);
    }
}