#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct // Definindo uma estrutura de dados
{
    string name;    // definindo um dos tipos de dados da estrutura
    string number;
}
person; // Definindo o nome da estrutura de dados

int main(void)
{
    person people[3]; // Definindo um array do tipo de dado 'person' (da estrutura que criamos) de 3 posições

    people[0].name = "Eve";                     // Definindo dado name da posição 0
    people[0].number = "+55 00 00000-0000";     // Definindo dado number da posição 0

    people[1].name = "Alexandre";               // Definindo dado name da posição 1
    people[1].number = "+55 11 11111-1111";     // Definindo dado number da posição 1

    people[2].name = "José";                    // Definindo dado name da posição 2
    people[2].number = "+55 22 22222-2222";     // Definindo dado number da posição 2

    string name = get_string("Name: ");         // Recebe um nome do usuário

    for (int i = 0; i < 3; i++)
    {
        if (strcmp(people[i].name, name) == 0)  // Comparando dados name da estrutura person com a variável name
        {
            printf("Found %s\n", people[i].number); // Exibe o número caso encontre o nome dentro da estrutura
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}