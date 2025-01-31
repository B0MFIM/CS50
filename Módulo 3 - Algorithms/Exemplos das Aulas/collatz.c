#include <stdio.h>

int collatz(int n);

int main(void) {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    
    int steps = collatz(number);
    printf("Number of steps: %d\n", steps);
    
    return 0;
}

int collatz(int n) {
    if (n == 1) {
        return 0;
    } else if (n % 2 == 0) {
        return 1 + collatz(n / 2);
    } else {
        return 1 + collatz(3 * n + 1);
    }
}