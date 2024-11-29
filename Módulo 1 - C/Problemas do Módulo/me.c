#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // The variable 'name' receives a value of type 'string' from the user
    string name = get_string("What's your name? ");
    // Prints a message to the terminal, with the value of the 'name'
    printf("Hello, %s\n", name);
}