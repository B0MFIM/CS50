#include <stdio.h>

int factorial(int n);

int main() {

    // get user's input
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    // call the factorial function
    printf("Factorial of %d is %d\n", number, factorial(number));
    return 0;
}

int factorial(int n) {
    if (n == 0) {   // base case
        return 1;
    } else {        // recursive case
        return n * factorial(n - 1);
    }
}