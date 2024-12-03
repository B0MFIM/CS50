#include <cs50.h>
#include <stdio.h>

#define SIDES 3

bool valid_triangle(float a, float b, float c);

int main(void)
{
    float triangle[SIDES];
    for (int i = 0; i < SIDES; i++)
    {
        triangle[i] = get_float("Size %i: ", i + 1);
    }

    bool valid = valid_triangle(triangle[0], triangle[1], triangle[2]);

    if (valid == true)
    {
        printf("True Triangle\n");
    }
    else
    {
        printf("False Triangle\n");
    }
}

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