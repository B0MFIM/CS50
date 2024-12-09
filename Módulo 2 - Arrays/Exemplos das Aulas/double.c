#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // variável constante
    const int L = 6;

    // array 'sequence' com 'L' posições
    int sequence[L];

    // loop para acessar as outras posições do array
    for (int i = 0; i < L; i++)
    {
        if (i == 0)
        {
            // atribuindo valor para a posição 0 do array
            sequence[i] = 1;
        }
        else
        {
            // atribuindo um valor na posição 'i' do array
            // o valor atribuido é o valor da posição anterior multiplicado por 2
            sequence[i] = sequence[i - 1] * 2;
        }
        // exibir o valor da posição 'i'
        printf("%i\n", sequence[i]);
    }
}
