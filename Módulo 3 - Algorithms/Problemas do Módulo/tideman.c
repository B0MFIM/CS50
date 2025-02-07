#include <cs50.h>
#include <stdio.h>
#include <string.h>

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

// Definição de uma constante MAX, que será o número máximo de candidatos
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
    A matriz de Locked é uma matriz bidimensional, booleana. Se locked[i][j] for true, isso significa
    que bloqueamos a aresta ou a seta apontando do candidato i para o candidato j. A princípio, todos
    os valores de locked serão falsos, porque ainda não bloqueamos nenhuma aresta, não temos setas 
    apontando para nenhum lugar no início do nosso código. Toda vez que se quiser adcionar uma seta ou
    uma aresta apontando de um candidato para outro, se deve alterar o valor de locked[i][j] para true. */
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

// Variáveis Globais, que armazenam o número de pares e o número de candidatos
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
    // Verifique se há argumentos de linha de comando, se não houver, imprima a mensagem de uso.
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Preencher a matriz de candidatos com os nomes dos candidatos, que são argumentos de linha de comando.
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

    // Gráfico de preferências e bloqueio de pares, inicialmente, todos os valores de locked serão falsos.
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    // Inicializa o número de pares como zero.
    pair_count = 0;

    // Número de eleitores, de acordo com a entrada do usuário.
    int voter_count = get_int("Number of voters: ");

    // Consulta de votos para cada eleitor
    for (int i = 0; i < voter_count; i++)
    {
        /* ranks[i] é a classificação do eleitor i, onde ranks[i][0] é a primeira preferência, 
           ranks[i][1] é a segunda preferência, e assim por diante. */
        int ranks[candidate_count];

        // Consulta para cada classificação do eleitor, onde o eleitor classifica cada candidato.
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Verifique se o nome é válido, se não for, imprima a mensagem de erro.
            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        // Registre as preferências do eleitor, com base na classificação do eleitor.
        record_preferences(ranks);

        printf("\n");
    }

    // Adicione pares de candidatos onde um é preferido ao outro.
    add_pairs();
    // Classifique os pares em ordem decrescente pela força da vitória.
    sort_pairs();
    // Bloqueie os pares no gráfico candidato em ordem, sem criar ciclos.
    lock_pairs();
    // Imprima o vencedor da eleição.
    print_winner();
    return 0;
}

/* Vote Function:
    Verifique se o nome é válido, se for, atualize a classificação do eleitor.
    A função será chamada toda vez um eleitor indicar sua preferência. Vote recebe três argumentos: rank, name e ranks. 
    Rank é a classificação do eleitor, Name é o nome do candidato que o eleitor classificou e Ranks é a matriz de classificação
    do eleitor. A função retorna true se o nome for válido e false se o nome for inválido. */
bool vote(int rank, string name, int ranks[])
{
    /* O que se vai fazer nessa função é procurar o nome do candidato na matriz de candidatos, se o nome for encontrado,
       atualize a matriz ranks e retorne true. Se o nome não for encontrado, retorne false. */

    // Loop que percorre a matriz de candidatos, verificando se o nome do candidato é válido.
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }

    return false;
}

/* Record Preferences Function:
    Atualize a matriz de preferências com base na classificação do eleitor.
    A função será chamada toda vez que um eleitor indicar suas preferências. Record_preferences recebe um argumento: ranks.
    Ranks é a matriz de classificação do eleitor. */
void record_preferences(int ranks[])
{
    /* 
    O que se vai fazer nessa função é atualizar a matriz de preferências com base na classificação do eleitor. 
    Se o eleitor classificar o candidato x em primeiro lugar e o candidato y em segundo lugar, isso significa que
    o eleitor prefere x em vez de y.

    Vamos dar olhada de um eleitor em particula como exemplo: ranks[0] = 3, ranks[1] = 0, ranks[2] = 4, ranks[3] = 1, ranks[4] = 2.
    Isso significa que o eleitor prefere o candidato 3 em vez do candidato 0, o candidato 0 em vez do candidato 4, o candidato 4 em 
    vez do candidato 1 e o candidato 1 em vez do candidato 2.

    Então, para essa matriz de classificação específica, conseguimos determinar quais candidatos são preferidos em relação a outros.
    Logo, vamos atualizar a matriz de preferências com base nessa matriz de classificação, que é ranks.
    */


}

/* Add Pairs Function:
    Adicione pares de candidatos, onde um é preferido ao outro, no array pairs. E atualiza a variável pair_count, para o número
    total de pares. A função será chamada após registrar todas as preferências dos eleitores. Add_pairs não recebe argumentos. */
void add_pairs(void)
{
    // O que se vai fazer nessa função é adicionar pares de candidatos, onde um é preferido ao outro, no array pairs.
}

/* Sort Pairs Function:
    Classifique os pares em ordem decrescente pela força da vitória. A função será chamada após todos os pares serem adicionados 
    ao array pairs. Sort_pairs não recebe argumentos. */
void sort_pairs(void)
{
    // O que se vai fazer nessa função é classificar os pares em ordem decrescente pela força da vitória.
}

/* Lock Pairs Function:
    Bloqueie os pares no gráfico de candidatos em ordem, sem criar ciclos. A função será chamada após os pares serem classificados. 
    Lock_pairs não recebe argumentos. */
void lock_pairs(void)
{
    // O que se vai fazer nessa função é bloquear os pares no gráfico de candidatos em ordem, sem criar ciclos.
}

/* Print Winner Function:
    Imprima o vencedor da eleição. A função será chamada após todos os pares serem bloqueados. Print_winner não recebe argumentos. */
void print_winner(void)
{
    // O que se vai fazer nessa função é imprimir o vencedor da eleição. Com base no gráfico resultante, quem é a 'fonte do gráfico'.
}
