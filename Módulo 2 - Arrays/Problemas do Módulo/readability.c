#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Prompt the user for some text
    string txt = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int len = strlen(txt);
    int letters = 0;
    int words = 0;
    int sentences = 0;
    for (int i = 0; i < len; i++)
    {
        // Counting letters
        char c = txt[i];
        if (isalpha(c) != 0)
        {
            letters++;
        }

        // Counting words
        if (c == ' ')
        {
            words++;
        }

        // Counting Sentences
        if (c == '.' || c == '!' || c == '?')
        {
            sentences++;
        }
    }

    // To account for last word
    words = words + 1;

    // Compute the Coleman-Liau index
    float L = ((float) letters / (float) words) * 100;
    float S = ((float) sentences / (float) words) * 100;
    float subindex = 0.0588 * L - 0.296 * S - 15.8;
    int index = round(subindex);

    // Print the grade level
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
