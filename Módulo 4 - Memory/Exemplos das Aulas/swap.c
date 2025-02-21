#include <stdio.h>

/* Esse código foi um exemplo de como podemos trocar os valores de duas variáveis
   usando ponteiros. Utilizando um conceito chamado de "passing by reference", 
   podemos passar o endereço de memória de uma variável para uma função, e então
   modificar o valor da variável através do ponteiro. */

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    // Exibir os valores de 'x' e 'y antes da troca
    printf("x is %i, y is %i\n", x, y);
    // Chamar a função swap e passar os endereços de memória de 'x' e 'y' e trocar os valores
    swap(&x, &y);
    // Exibir os valores de 'x' e 'y depois da troca
    printf("x is %i, y is %i\n", x, y);
}

// Função que troca os valores de duas variáveis usando ponteiros para as variáveis originais da função main
void swap(int *a, int *b)
{
    // Salvar o valor de 'a' em uma variável temporária
    int tmp = *a;
    // Atribuir o valor de 'b' para 'a'
    *a = *b;
    // Atribuir o valor de 'a' (salvo na variável temporária) para 'b'
    *b = tmp;
}