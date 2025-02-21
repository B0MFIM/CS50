#include <stdio.h>
#include <cs50.h>
#include <string.h>

/* Esse código foi um exemplo de manipulação de arquivos em C. Ele mostra
   como podemos abrir um arquivo, escrever nele e fechá-lo. */

int main(void)
{
    // Abrir o arquivo 'phonebook.csv' para escrita
    FILE *file = fopen("phonebook.csv", "a");
    // Verificar se o arquivo foi aberto corretamente
    if (file == NULL)
    {
        return 1;
    }

    // Pedir ao usuário para digitar um nome e um número de telefone
    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    // Escrever o nome e o número de telefone no arquivo 'phonebook.csv'
    fprintf(file, "%s,%s\n", name, number);

    // Fechar o arquivo
    fclose(file);
    
    return 0;
}