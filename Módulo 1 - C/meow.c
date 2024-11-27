#include <stdio.h>
#include <cs50.h>

void meow(int n); /* Informa ao compilador que a função existe */

int main(void)
{
    /*

    int i = 1;
    while (i <= 3)  -> um loop while com uma expressão booleana (traduzindo: Enquanto i for menor ou igual a 3, continue)
    {
        printf("meow\n");
        i++;        -> incrementa +1 ao valor de i
    }
    
    for (int i = 0; i < 3; i++) -> o primeiro argumento inicia uma variável, a segundo é um valor booleano e o terceiro é o update da variável
    {
            printf("meow\n");
    }

    */

    meow(5);  /* aqui nos chamamos a função criada e adicionamos o seu valor de argumento do tipo inteiro */

}

void meow(int n) /* criamos uma função chamada meow, com um argumento "n" do tipo int, para receber um valor quando chamada */
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n"); /* dentro da função se localiza a sua funcionalidade, o que ela faz */
    }
}