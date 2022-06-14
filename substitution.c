#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    int count_repeat = 0;
    int count_key = 0;
    //checks if the user provides exactly one command-line argument
    if (argc != 2)
    {
        printf("Usage: %s key\n", *argv);
        return 1;
    }
    //check that argv = 26 (alphabet)
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // check key for all 26 letters
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        // check each letter of argv[1] for alpha.
        if (isalpha(argv[1][i]))
        {
            count_key++;
        }
        else if (count_key != strlen(argv[1]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }
    //check for repeat characters
    for (int j = 0, n = strlen(argv[1]); j < n; j++)
    {
        for (int k = j + 1; k < n; k++)
        {
            if (tolower(argv[1][j]) == tolower(argv[1][k]))
            {
                count_repeat++;
            }
        }
        if (count_repeat != 0)
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
    }
    // Prompt user for plaintext
    string ptext = get_string("Plaintext:  ");
    printf("ciphertext: ");

    // For each character in the plaintext:
    for (int k = 0, length = strlen(ptext); k < length; k++)
    {
        //check for upper case and pass through with cipher
        if (isalpha(ptext[k]) && isupper(ptext[k]))
        {
            int upper = (ptext[k] - 65);
            printf("%c", toupper(argv[1][upper]));
        }
        //check for lower case and pass through with cipher
        else if (isalpha(ptext[k]) && islower(ptext[k]))
        {
            int lower = (ptext[k] - 97);
            printf("%c", tolower(argv[1][lower]));
        }
        //print non alpha
        else
        {
            printf("%c", ptext[k]);
        }
    }
    printf("\n");
    return 0;
}