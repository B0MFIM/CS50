#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function that will validate a key
bool check_key(string key);

int main(int argc, string argv[])
{
    int length;
    string plaintext;

    // Checks if command line arguments are greater than or less than 2
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Check if the key is correct
    if (!check_key(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Receive a message from the user
    plaintext = get_string("plaintext:  ");
    // Message size
    length = strlen(plaintext);
    // Key to the ciphers
    string key = argv[1];
    // Where the encrypted message will be stored
    char ciphertext[length + 1];

    // Encrypts a message
    for (int i = 0; i < length; i++)
    {
        // Cifra o caractere e o converte para minusculo
        if (islower(plaintext[i]))
        {
            ciphertext[i] = key[plaintext[i] - 97];
            ciphertext[i] = tolower(ciphertext[i]);
        }
        // Cifra o caracte e o converte para maiusculo
        else if (isupper(plaintext[i]))
        {
            ciphertext[i] = key[plaintext[i] - 65];
            ciphertext[i] = toupper(ciphertext[i]);
        }
        // If it is not an alphabetic character, it just stores
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    // Specifies to the compiler that the string has reached the end
    ciphertext[length] = '\0';
    // Displays the encrypted message to the user
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

// Function that validates a key and returns a false or true value
bool check_key(string key)
{
    // Checks if the key is less than or greater than 26 characters
    if (strlen(key) < 26 || strlen(key) > 26)
    {
        return false;
    }

    // Check the characters of the key
    for (int i = 0; i < strlen(key); i++)
    {
        // Checks if the key contains only alphabetic characters
        if (!isalpha(key[i]))
        {
            return false;
        }

        // Checks if the key has no duplicate characters
        for (int j = i + 1; j < strlen(key); j++)
        {
            if (key[i] == key[j])
            {
                return false;
            }
        }
    }

    return true;
}
