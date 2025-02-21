#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    // Pedir ao usuário para digitar uma string
    char *a = get_string("a: ");

    // Alocar memória para a string 'b', baseada no tamanho da string 'a', mais 1 para o caractere nulo
    char *b = malloc(strlen(a) + 1);

    // Verificar se a alocação de memória foi bem sucedida
    if (b == NULL)
    {
        return 1;
    }

    // Copiar a string 'a' para a string 'b'
    strcpy(b, a);

    // Modificar a string 'b' para que a primeira letra seja maiúscula
    if (strlen(b) > 0)
    {
        b[0] = toupper(b[0]);
    }

    // Exibir as strings 'a' e 'b'
    printf("a: %s\n", a);
    printf("b: %s\n", b);

    // Liberar a memória alocada para a string 'b'
    free(b);

    return 0;
}