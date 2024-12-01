#include <cs50.h>
#include <stdio.h>

long get_card_number();
void validation_check(long number);

int main(void)
{
    // Receives the card number from the user
    long number = get_card_number();
    // Function that checks whether the card is valid
    validation_check(number);
}

// Function that receives a positive integer of type 'long' from the user
long get_card_number()
{
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number <= 0);
    return number;
}

// Function that checks whether the card is valid
void validation_check(long number)
{
    // calculates the size of the card number for validation
    int size = 0;
    long n0 = number;
    while (n0 != 0)
    {
        n0 /= 10;
        size++;
    }

    long n1 = number;
    long n2 = number;
    int remainder = 0;
    int sum = 0;
    int mult = 0;
    int rem_mult = 0;

    // Verifies and validates the card number
    if (size == 13 || size == 15 || size == 16)
    {
        /* First mathematical validation process based on the addition and multiplication of the
        numbers on the card */
        while (n1 > 0)
        {
            n1 /= 10;
            remainder = n1 % 10;
            mult = remainder * 2;
            if (mult > 9)
            {
                rem_mult = mult % 10;
                sum += rem_mult;
                rem_mult = mult / 10;
                sum += rem_mult;
                n1 /= 10;
            }
            else
            {
                sum += mult;
                n1 /= 10;
            }
        }

        /* Second mathematical validation process based on the sum of the remaining numbers on the
        card */
        while (n2 > 0)
        {
            remainder = n2 % 10;
            sum += remainder;
            n2 /= 100;
        }

        /* Third and final card validation process and verification of its type: 'AMEX - MASTERCARD
        - VISA' */
        if (sum % 10 == 0)
        {
            if (size == 15 &&
                (number / 10000000000000 == 34 ||
                 number / 10000000000000 == 37)) // Validate if it is the American Express card
            {
                printf("AMEX\n");
            }
            else if (size == 16 &&
                     (number / 100000000000000 == 51 || number / 100000000000000 == 52 ||
                      number / 100000000000000 == 53 || number / 100000000000000 == 54 ||
                      number / 100000000000000 == 55)) // Validate if it is the MasterCard card
            {
                printf("MASTERCARD\n");
            }
            else if (((size == 13 && number / 1000000000000 == 4) ||
                      (size == 16 &&
                       number / 1000000000000000 == 4))) // Validate if it is the VISA card
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
