#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string phrase = get_string("Phrase: ");
    int length = strlen(phrase);
    for (int i = 0; i < length - 1; i++)
    {
        // Check if character are NOT in alphabetical order
        if (phrase[i] > phrase[i + 1])
        {
            printf("Not in alphabetical order!\n");
            return 1;
        }
    }
    printf("Alphabetical order.\n");
    return 0;
}
