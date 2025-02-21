#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    char *a = get_string("a: ");

    char *b = malloc(strlen(a) + 1);
    if (b == NULL)
    {
        return 1;
    }

    strcpy(b, a);

    if (strlen(b) > 0)
    {
        b[0] = toupper(b[0]);
    }

    printf("a: %s\n", a);
    printf("b: %s\n", b);

    free(b);
    return 0;
}