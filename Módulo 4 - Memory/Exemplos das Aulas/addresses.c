#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("\n");
    printf("POINTERS\n");
    printf("====================\n");
    int n = 50;
    int *p = &n;
    printf("%p\n", p);
    printf("%p\n", &n);
    printf("%p\n", &p);
    printf("%i\n", n);

    printf("\n");
    printf("STRINGS\n");
    printf("====================\n");
    string s = "HI!";
    printf("%p\n", s);
    printf("%p\n", &s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
    printf("%s\n", s);

    printf("\n");
    printf("CHAR\n");
    printf("====================\n");
    char *c = "HI!";
    printf("%p\n", c);
    printf("%p\n", &c);
    printf("%c\n", *c);
    printf("%c\n", c[1]);
    printf("%c\n", c[2]);
    printf("%s\n", c);

    printf("\n");
    printf("POINTER ARITHMETIC\n");
    printf("====================\n");
    printf("%c\n", *c);
    printf("%c\n", *(c + 1));
    printf("%c\n", *(c + 2));
    printf("%s\n", c + 1);
}