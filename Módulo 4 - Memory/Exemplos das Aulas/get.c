#include <stdio.h>

/* Esse código foi um exemplo de como podemos usar a função scanf para
   obter entradas do usuário. O scanf é uma função da biblioteca padrão
   de C que lê entradas do usuário e as armazena em variáveis. Além disso,
   ele pode ser usado para ler strings, mas é importante ter cuidado ao 
   usá-lo para evitar buffer overflows. */

int main(void)
{
    int n;
    printf("n: ");
    scanf("%i", &n);
    printf("n: %i\n", n);

    char s[4];
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);
}