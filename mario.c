#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while ((n > 8) || (n < 1 ));

    // For each row
    for (int i = 0; i < n; i++)
    {
        // spaces before pyramid/
        for (int k = n - i - 1; k > 0; k--)
        {
            printf(" ");
        }

        // For each column
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        //2 spaces
        printf("  ");

        // second part of pyramid
        for (int l = 0; l < i + 1; l++)
        {
            printf("#");
        }
        // Next row
        printf("\n");
    }

}
