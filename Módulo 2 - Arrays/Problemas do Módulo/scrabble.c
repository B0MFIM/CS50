#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

void player_word(string words[]);
int compute_score(string word);

int main(void)
{
    // An array for 2 strings
    string players_words[2];
    // A function that takes two words from the user
    player_word(players_words);

    // Compute score
    int score1 = compute_score(players_words[0]);
    int score2 = compute_score(players_words[1]);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// A function that takes two words from the user and stores them in a 2-position array
void player_word(string words[])
{
    words[0] = get_string("Player 1: ");
    words[1] = get_string("Player 2: ");
}

// A function that calculates points from a string
int compute_score(string word)
{
    // Keep track of score
    int score = 0;

    // Compute and return score for word
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }

    return score;
}
