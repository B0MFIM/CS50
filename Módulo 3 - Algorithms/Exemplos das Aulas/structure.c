#include <stdio.h>
#include <cs50.h>

// Define um struct "candidate"
typedef struct
{
    string name;
    int votes;
} candidate;

int main(void)
{
    // Define um número de candidatos
    const int num = 3;
    candidate candidates[num];

    // encher o array com inputs do usuário
    for (int i = 0; i < num; i++)
    {
        candidates[i].name = get_string("Name: ");
        candidates[i].votes = get_int("Votes: ");
    }

    int highest_vote = 0;
    for (int i = 0; i < num; i++)
    {
        if (candidates[i].votes > highest_vote)
        {
            highest_vote = candidates[i].votes;
        }
    }

    for (int i = 0; i < num; i++)
    {
        if (candidates[i].votes == highest_vote)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
