#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char c = get_char("Do you agree? "); // Recebe um unico caractere e aloca na variável c

    if (c == 'y' || c == 'Y') // "||"" significa "ou", assim como "&&"" significa "e"
    {
        printf("Agreed.\n");
    }
    else if (c == 'n' || c == 'N')
    {
        printf("Not agreed.\n");
    }
}