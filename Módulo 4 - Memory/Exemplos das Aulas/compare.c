#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Pedir ao usuário para digitar duas strings
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    // Verificar se as strings são nulas
    if (s == NULL || t == NULL)
    {
        return 1;
    }

    // Exibir os endereços de memória das duas strings
    printf("%p\n", s);
    printf("%p\n", t);

    // Comparar as duas strings e exibir se são iguais ou diferentes
    if (strcmp(s, t) == 0)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }

    return 0;
}