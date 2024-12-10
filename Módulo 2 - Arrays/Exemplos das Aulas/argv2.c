#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./argv2 number\n");
        return 1;
    }

    // Transforma uma string em um inteiro
    int number = atoi(argv[1]);
    printf ("The number is: %i\n", number);
    return 0;
}