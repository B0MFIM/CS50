#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
     string s = get_string("Input:  ");
     printf("Output: ");
     for (int i = 0, n = strlen(s); i < n; i++) // podemos chamar mais de uma variável alem de 'i' no loop for.
     {
        printf("%c", s[i]);
     }
     printf("\n");
}