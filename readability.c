#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//define functions
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //get user input
    string user_text = get_string("Text: ");
    printf("%s\n", user_text);

    //call functions
    int letters = count_letters(user_text);
    float words = count_words(user_text);
    int sentences = count_sentences(user_text);

    //convert letters to avg / 100w
    float L = 100 * (letters / words);
    float S = 100 * (sentences / words);

    //caclulate coleman-liau
    int colemanliau = round(0.0588 * L - 0.296 * S - 15.8);

    //print grades
    if (colemanliau < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (colemanliau > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", colemanliau);
    }

}
// function to count letters
int count_letters(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return (count);
}
// function to count words
int count_words(string text)
{
    int count = 1;
    for (int k = 0; k < strlen(text); k++)
    {
        if (isspace(text[k]))
        {
            count++;
        }
    }
    return (count);
}
// function to count sentences
int count_sentences(string text)
{
    int count = 0;
    for (int j = 0; j < strlen(text); j++)
    {
        if ((text[j]) == 46 || (text[j]) == 33 || (text[j]) == 63)
        {
            count++;
        }
    }
    return (count);
}