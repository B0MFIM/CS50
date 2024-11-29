#include <cs50.h>
#include <stdio.h>

// Defining constant variables
#define QUARTERS 25
#define DIMES 10
#define NICKELS 5
#define PENNIES 1

// Defining function
void calculate_coins(int cents);

int main(void)
{
    // Prompt the user for change owed, in cents
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 1);

    // Calculate how many coins you should give customer
    calculate_coins(cents);
}

// Function that calculates how many coins you should give to the customer
void calculate_coins(int cents)
{
    int coins = 0;
    while (true)
    {
        if (cents >= QUARTERS)
        {
            cents -= QUARTERS; // Subtract the value of those quarters from cents
            coins++;
        }
        else if (cents >= DIMES)
        {
            cents -= DIMES; // Subtract the value of those dimes from cents
            coins++;
        }
        else if (cents >= NICKELS)
        {
            cents -= NICKELS; // Subtract the value of those nickels from cents
            coins++;
        }
        else if (cents >= PENNIES)
        {
            cents -= PENNIES; // Subtract the value of those pennies from cents
            coins++;
        }
        else
        {
            if (cents > 0)
            {
                continue; // Continue the loop if there are still cents
            }
            else
            {
                break; // Stops the loop if there are no more cents
            }
        }
    }

    // Prints the number of coins returned to the customer for the user
    printf("%i\n", coins);
}
