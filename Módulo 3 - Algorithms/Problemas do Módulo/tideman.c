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

// Variável Global, que armazena o valor 9, que é o número máximo de candidatos.
#define MAX 9

/* Array Preferences:
   A matriz de preferências é uma matriz bidimensional, de inteiros, interpretados da seguinte forma: 
   Preferências[i][j] é o número de eleitores que preferem i em vez de j. 
   'i' e 'j' representam os índices dos candidatos da matriz de candidatos. */
int preferences[MAX][MAX];

/* Array Locked:
   A matriz de Locked é uma matriz bidimensional, booleana. Se locked[i][j] for true, isso significa
   que bloqueamos a aresta ou a seta apontando do candidato i para o candidato j. A princípio, todos
   os valores de locked serão falsos, porque ainda não bloqueamos nenhuma aresta, não temos setas 
   apontando para nenhum lugar no início do nosso código. Toda vez que se quiser adcionar uma seta ou
   uma aresta apontando de um candidato para outro, se deve alterar o valor de locked[i][j] para true. */
bool locked[MAX][MAX];

/* Struct Pair: 
   Esse Struct tem dois campos - vencedor e perdedor - cada um dos quais é um inteiro que representa o índice do
   candidato na matriz de candidatos. O campo winner é o índice do candidato que venceu e o campo loser é o índice do
   candidato que perdeu no par específico. Se um par de candidatos estiver empatado, não vamos nos preocupar em adicionar
   esse par para a matriz pairs. Se um par de candidatos não estiver empatado, vamos adicionar esse par para a matriz pairs. */
typedef struct
{
    int winner;
    int loser;
} pair;

// Um Array Candidates do tipo string, que armazena todos os nomes dos candidatos.
string candidates[MAX];

/* Array Pairs:
   É uma matriz de pares de candidatos, do tipo pair (struct), onde será um array de todos os pares em que um 
   candidado é prefirido em relação ao outro. Se houver um par de candidatos empatados, não vamos nos preocupar 
   em adicionar esse par para a matriz pairs */
pair pairs[MAX * (MAX - 1) / 2];

// Variáveis Globais, que armazenam o número de pares e o número de candidatos.
int pair_count;
int candidate_count;

// Protótipos de Funções.
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Verifica se há mais de 2 argumentos de linha de comando.
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Preenche a variável com a quantidade de candidatos inseridos na linha de comando.
    candidate_count = argc - 1;

    // Verifica se o número de candidatos não excede o máximo.
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    // Preenche a matriz de candidatos com os nomes dos candidatos da linha de comando.
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
        // O array ranks representa a classificação do eleitor. 
        // Onde seus indices representam o rank e o valor representa o candidato.
        int ranks[candidate_count];

        // Consulta para cada classificação (rank) do eleitor, onde o eleitor classifica certo candidato.
        for (int j = 0; j < candidate_count; j++)
        {
            // Pede ao usuário para inserir o nome do candidato no rank atual.
            string name = get_string("Rank %i: ", j + 1);

            // Verifique se o nome é válido, se não for, imprima a mensagem de erro.
            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        // Registra as preferências do eleitor, com base em sua classificação.
        record_preferences(ranks);

        printf("\n");
    }

    // Adicione pares de candidatos onde um é preferido ao outro.
    add_pairs();
    // Classifique os pares em ordem decrescente pela força da vitória.
    sort_pairs();
    // Bloqueie os pares no gráfico candidato em ordem, sem criar ciclos.
    lock_pairs();
    // Imprime o vencedor da eleição.
    print_winner();
    return 0;
}

/* Vote Function:
   Verifica se o nome é válido, se for, atualize a classificação do eleitor.
   A função é chamada toda vez que um eleitor indicar sua preferência.
   Vote recebe três argumentos: rank, name e ranks.
   Rank é a classificação atual.
   Name é o nome do candidato.
   Ranks é a matriz de classificação do eleitor.
   A função retorna true se o nome for válido e false se o nome forinválido. */
bool vote(int rank, string name, int ranks[])
{
    // Loop que iterará sobre todos os candidatos
    for (int i = 0; i < candidate_count; i++)
    {
        // Verifique se o nome do candidato corresponde ao nome fornecido
        if (strcmp(name, candidates[i]) == 0)
        {
            // Se sim, registre a preferência do eleitor e retorna true
            ranks[rank] = i;
            return true;
        }
    }

    // Se o nome do candidato não for encontrado, retorne false
    return false;
}

/* Record Preferences Function:
   Atualiza a matriz de preferências com base em toda a classificação do eleitor.
   A função é chamada toda vez que o eleitor terminar suas classificações.
   Record_preferences recebe um argumento: ranks.
   Ranks é a matriz de classificação do eleitor. */
void record_preferences(int ranks[])
{
    // Loop que iterará sobre todos os candidatos
    for (int i = 0; i < candidate_count; i++)
    {
        // Loop que iterará sobre todos os candidatos restantes
        for (int j = i + 1; j < candidate_count; j++)
        {
            // Atualize a matriz de preferências com base na classificação do eleitor.
            preferences[ranks[i]][ranks[j]]++;
        }
    }
}

/* Add Pairs Function:
   A função adiciona pares de candidatos onde um é preferido ao outro, no array pairs. 
   E atualiza a variável pair_count, para o número total de pares atual.
   A função será chamada após registrar todas as preferências dos eleitores. */
void add_pairs(void)
{
    // Variável que armazena a força da vitória.
    int strength;

    // Loop que iterará sobre todos os candidatos.
    for (int i = 0; i < candidate_count; i++)
    {
        // Loop que iterará sobre todos os candidatos restantes.
        for (int j = i + 1; j < candidate_count; j++)
        {
            // Calcule a força da vitória entre os candidatos i e j.
            strength = preferences[i][j] - preferences[j][i];

            // Se o candidato i for preferido ao candidato j, adicione o par ao array pairs.
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            // Se o candidato j for preferido ao candidato i, adicione o par ao array pairs.
            else if (preferences[j][i] > preferences[i][j])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
}

/* Sort Pairs Function:
   Classifique os pares em ordem decrescente pela força da vitória. 
   A função será chamada após todos os pares serem adicionados ao array pairs. */
void sort_pairs(void)
{
    // Loop que iterará sobre todos os pares.
    for (int i = 0; i < pair_count; i++)
    {
        // Loop que iterará sobre todos os pares restantes.
        for (int j = i + 1; j < pair_count; j++)
        {
            // Calcule a diferença de força de vitória entre os pares i e j.
            int margem_i = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
            int margem_j = preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner];

            // Se a força de vitória do par j for maior que a força de vitória do par i, troque os pares.
            if (margem_j > margem_i)
            {
                // Variavel temporária para armazenar o par.
                pair temp = pairs[i];

                // Troca os pares.
                pairs[i] = pairs[j];
                pairs[j] = temp;
            }
        }
    }
}

/* Lock Pairs Function:
   Bloqueie os pares no gráfico de candidatos em ordem, sem criar ciclos.
   A função será chamada após os pares serem classificados na ordem decrescente. */
void lock_pairs(void)
{
    // Loop que iterará sobre todos os pares.
    for (int i = 0; i < pair_count; i++)
    {
        // Bloqueie o par.
        locked[pairs[i].winner][pairs[i].loser] = true;
    }
}

/* Print Winner Function:
   Imprima o vencedor da eleição. 
   A função será chamada após todos os pares serem bloqueados. */
void print_winner(void)
{
    // Loop que iterará sobre todos os candidatos.
    for (int i = 0; i < candidate_count; i++)
    {
        // Variável que armazena a quantidade de setas que apontam para o candidato.
        int count = 0;

        // Loop que iterará sobre todos os candidatos.
        for (int j = 0; j < candidate_count; j++)
        {
            // Se o candidato j tiver uma seta apontando para o candidato i, incremente a contagem.
            if (locked[j][i])
            {
                count++;
            }
        }

        // Se o candidato i não tiver nenhuma seta apontando para ele, imprima o nome do candidato.
        if (count == 0)
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }
}
