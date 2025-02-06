#include <cs50.h>
#include <stdio.h>

// Número máximo de candidatos
#define MAX 9

// preferências[i][j] é o número de eleitores que preferem i em vez de j
int preferences[MAX][MAX];

// bloqueado[i][j] significa que i está bloqueado em j
bool locked[MAX][MAX];

// Cada par tem um vencedor e um perdedor
typedef struct
{
    int winner;
    int loser;
} pair;

// Matriz de Candidatos
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Protótipos de Funções
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Verifique se há uso inválido
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Preencher matriz de candidatos
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Gráfico claro de pares bloqueados
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Consulta de votos
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] é a preferência i do eleitor
        int ranks[candidate_count];

        // Consulta para cada classificação
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Atualizar classificações com nova votação
bool vote(int rank, string name, int ranks[])
{
    // TODO
    return false;
}

// Atualizar preferências de acordo com a classificação de um eleitor
void record_preferences(int ranks[])
{
    // TODO
    return;
}

// Registre pares de candidatos onde um é preferido ao outro
void add_pairs(void)
{
    // TODO
    return;
}

// Classifique os pares em ordem decrescente pela força da vitória
void sort_pairs(void)
{
    // TODO
    return;
}

// Bloqueie os pares no gráfico candidato em ordem, sem criar ciclos
void lock_pairs(void)
{
    // TODO
    return;
}

// Imprima o vencedor da eleição
void print_winner(void)
{
    // TODO
    return;
}
