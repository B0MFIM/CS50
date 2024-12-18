#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");
    draw(height);
}

void draw(int n)
{
    // Se não há mais nada para exibir, encerre.
    if (n <= 0)
    {
        return;
    }

    // Exibe uma pirâmide de tamanho n - 1.
    draw(n - 1);

    // Exibe mais uma linha.
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
