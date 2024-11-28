#include <stdio.h>
#include <cs50.h> // Biblioteca da CS50

int main(void)
{
    string answer = get_string("What's your name? "); // "get_string("");" recebe uma string (texto) | "answer" é uma variável do tipo "string" | "string" é um tipo de dado
    printf("Hello, %s\n", answer); // %s recebe e adiciona uma string, do segundo parâmetro "answer", ao seu texto
}