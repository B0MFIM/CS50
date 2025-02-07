#include <cs50.h>
#include <stdio.h>

/* TIDEMAN VOTE

    Tally (Contagem):
        Os eleitores indicam suas preferências, analiseremos cada par de candidatos
        e determinaremos quem seria o vencedor da eleição para aquele par específico.

    Sort (Classificação):
        Vamos classificar os pares dos candidatos em ordem decrescente de força de vitória,
        onde a margem de vitoria mais forte ou mais ampla vem primeiro. E chegamos a menor
        margem de vitória ao final.

    Locked (Bloqueio):
        O próximo passo é bloquear esses pares um de cada vez, começando com o par mais forte,
        vamos bloquear esse par, ou seja, adicione uma aresta a esse gráfico, desde que essa
        aresta não crie um ciclo, se isso criaria um ciclo, nós pularíamos essa aresta e
        passariamos para o próximo par.

    Winner (Vencedor):
        Depois de termos o gráfico resultante, podemos determinar o vencedor da eleição
        apenas verificando quem é a 'fonte do gráfico', em outras palavras, quem não tem setas
        apontando para si. 
*/

// Número máximo de candidatos, numa variável constante chamada 'MAX'.
#define MAX 9

/* Array Preferences:
    A matriz de preferências é uma matriz bidimensional, de inteiros, interpretados da seguinte forma: 
    Preferências[i][j] é o número de eleitores que preferem i em vez de j. */
int preferences[MAX][MAX];
/*  Exemplo Gráfico:
                        Alice   Bob   Charlie
            Alice   -     0      3       3
            Bob     -     1      0       1
            Charlie -     1      3       0
*/

/* Array Locked:
    A matriz de Locked é uma matriz bidimensional, booleana, onde locked[i][j] é verdadeiro se i está bloqueado
    em j, ou seja, se i é preferido em relação a j. */
bool locked[MAX][MAX];

/* Struct Pair: 
    Esse Struct tem dois campos - vencedor e perdedor - cada um dos quais é um inteiro que representa
    o índice do candidato na matriz desse candidato, quem é o vencedor ou o perdedor, para esse par
    específico, respectivamente. Esses pares serão adicionados para a matriz pairs. */
typedef struct
{
    int winner;
    int loser;
} pair;

// Um Array Candidates do tipo string, que armazena todos os nomes dos candidatos
string candidates[MAX];

/* Array Pairs:
    É uma matriz de pares de candidatos, do tipo pair (struct), onde será um array de todos os pares em que um 
    candidado é prefirido em relação ao outro. Se houver um parde candidatos empatados, não vamos nos preocupar 
    em adicionar esse par para a matriz pairs */
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
