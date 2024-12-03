#include <cs50.h>
#include <stdio.h>

// Variável Constante
#define SIDES 3

// Declaração de Função
bool valid_triangle(float a, float b, float c);

int main(void)
{
    // Recebe do usuário 3 valores positivos acima de zero dentro de uma matriz 'triangle'
    float triangle[SIDES];
    for (int i = 0; i < SIDES; i++)
    {
        triangle[i] = get_float("Size %i: ", i + 1);
    }

    // Chamada da função 'valid_triangle' que recebe 3 parâmetros
    bool valid = valid_triangle(triangle[0], triangle[1], triangle[2]);

    // Imprime na tela se o triangulo é verdadeiro ou falso
    if (valid == true)
    {
        printf("True Triangle\n");
    }
    else
    {
        printf("False Triangle\n");
    }
}

// Definição de Função que valida um triangulo hipotético, retornando 'true' ou 'false'
bool valid_triangle(float a, float b, float c)
{
    if ((a + b <= c) || (a + c <= b) || (b + c <= a))
    {
        return false;
    }
    else
    {
        return true;
    }
}