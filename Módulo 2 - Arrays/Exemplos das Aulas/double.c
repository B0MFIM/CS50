#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // variável constante
    const int L = 6;

    // array 'sequence' com 'L' posições
    int sequence[L];

    // atribuindo valor para a posição 0 do array
    sequence[0] = 1;
    // exibir o valor da posição 0 do array
    printf("%i\n", sequence[0]);

    // loop para acessar as outras 4 posições do array
    for (int i = 1; i < L; i++)
    {
        // atribuindo um valor na posição 'i' do array
        sequence[i] = sequence[i - 1] * 2; // o valor atribuido é o valor da posição anterior multiplicado por 2
        // exibir o valor da posição 'i'
        printf("%i\n", sequence[i]);
    }
}