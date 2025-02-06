#include <cs50.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // Iterar sobre todos os candidatos
    for (int i = 0; i < candidate_count; i++)
    {
        // Verificar se o nome do candidato corresponde ao nome fornecido
        if (strcmp(candidates[i].name, name) == 0)
        {
            // Se sim, registrar a preferência do eleitor
            preferences[voter][rank] = i;
            return true;
        }
    }
    // Se o nome do candidato não for encontrado, retornar false
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // Iterar sobre cada eleitor
    for (int i = 0; i < voter_count; i++)
    {
        // Iterar sobre cada preferência do eleitor
        for (int j = 0; j < candidate_count; j++)
        {
            int index = preferences[i][j];
            // Verificar se o candidato não foi eliminado
            if (!candidates[index].eliminated)
            {
                // Incrementar o contador de votos do candidato
                candidates[index].votes++;
                break; // Sair do loop
            }
        }
    }
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int total_votes = 0;

    // Calcular o Total de Votos
    for (int i = 0; i < candidate_count; i++)
    {
        total_votes += candidates[i].votes;
    }

    // Verificar se algum candidato tem mais da metade dos votos
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > total_votes / 2)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }

    // Se nenhum candidato tiver mais da metade dos votos
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min_votes = INT_MAX;

    // Iterar sobre todos os candidatos
    for (int i = 0; i < candidate_count; i++)
    {
        // Verificar se o candidato não foi eliminado
        if (!candidates[i].eliminated)
        {
            // Atualizar min_votes se o candidato tiver menos votos
            if (candidates[i].votes < min_votes)
            {
                min_votes = candidates[i].votes;
            }
        }
    }

    // Retornar min_votes
    return min_votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // Iterar sobre todos os candidatos
    for (int i = 0; i < candidate_count; i++)
    {
        // Verificar se o candidato não foi eliminado
        if (!candidates[i].eliminated)
        {
            // Verificar se os votos do candidato são diferentes de min
            if (candidates[i].votes != min)
            {
                return false;
            }
        }
    }

    // Se todos os candidatos restantes têm o mesmo número de votos
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // Iterar sobre todos os candidatos
    for (int i = 0; i < candidate_count; i++)
    {
        // Verificar se o candidato não foi eliminado
        if (!candidates[i].eliminated)
        {
            // Verificar se os votos do candidato são diferentes de min
            if (candidates[i].votes == min)
            {
                candidates[i].eliminated = true;
            }
        }
    }
}
