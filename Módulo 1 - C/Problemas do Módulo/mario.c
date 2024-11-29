#include <cs50.h>
#include <stdio.h>

void print_row(int spaces, int left_bricks, int right_bricks);

int main(void)
{
    // Prompt for the user to enter the size of the pyramid
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Print a pyramid of that height
    for (int i = 0; i < height; i++)
    {
        // Print row of bricks
        print_row(i + 1, height, i + 1);
    }
}

// Print rows of spaces and bricks
void print_row(int spaces, int left_bricks, int right_bricks)
{
    // First half of the row
    for (int i = 0; i < left_bricks; i++)
    {
        if (spaces < left_bricks) // Print spaces
        {
            printf(" ");
        }
        else // Print bricks
        {
            printf("#");
        }
        spaces++;
    }

    printf("  "); // Separates the two halves

    // Second half of the row
    for (int i = 0; i < right_bricks; i++)
    {
        printf("#"); // print bricks
    }

    printf("\n"); // Change to next row
}
