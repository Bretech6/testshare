#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    //checks if the user provides exactly one command-line argument
    if (argc != 2)
    {
        printf("Usage: %s key\n", *argv);
        return 1;
    }

    for (int i = 0; argv[1][i]; i++)
    {
        // check each char of argv[1] for non digit.

        if (!isdigit((unsigned char) argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // convert key to int
    int cipher_key = atoi(argv[1]);

    // Prompt user for plaintext
    string ptext = get_string("Plaintext:  ");
    printf("ciphertext: ");

    // For each character in the plaintext:
    for (int i = 0, length = strlen(ptext); i < length; i++)
    {
        // check for lower case + move cipher
        if (ptext[i] >= 'a' && ptext[i] <= 'z')
        {
            printf("%c", (((ptext[i] - 'a') + cipher_key) % 26) + 'a');
        }
        // check for upper case + move cipher
        else if (ptext[i] >= 'A' && ptext[i] <= 'Z')
        {
            printf("%c", (((ptext[i] - 'A') + cipher_key) % 26) + 'A');
        }
        //print non alpha
        else
        {
            printf("%c", ptext[i]);
        }
    }
    printf("\n");
    return 0;
}