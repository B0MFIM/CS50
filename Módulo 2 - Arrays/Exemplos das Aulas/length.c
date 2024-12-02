#include <cs50.h>
#include <stdio.h>
#include <string.h> // Biblioteca C que trabalha com strings

int main(void)
{
    string name = get_string("Name: ");
    int length = strlen(name); // Função da biblioteca string.h que calcula o tamanho de uma string
    printf("%i\n", length);
}