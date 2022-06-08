#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // take input
    long card_number = get_long("Number :");

    // count length of input
    int i = 0;
    long card_length = card_number;
    while (card_length > 0)
    {
        card_length = card_length / 10;
        i++;
    }

    // check if number length is valid
    if (i != 13 && i != 15 && i != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // variables for checksum
    int sum1 = 0;
    int sum2 = 0;
    long x = card_number;
    int total = 0;
    int mod1;
    int mod2;
    int div1;
    int div2;

    do
    {
        // take off last digit and add to sum1
        mod1 = x % 10;
        x = x / 10;
        sum1 = sum1 + mod1;

        // take off 2nd last digit
        mod2 = x % 10;
        x = x / 10;

        // double and add digits to sum2
        mod2 = mod2 * 2;
        div1 = mod2 % 10;
        div2 = mod2 / 10;
        sum2 = sum2 + div1 + div2;
    }
    while (x > 0);

    total = sum1 +sum2;

    // check luhn algo
    if (total % 10 != 0)
    {
        printf("INVALID\n");
    }

    // find first 2 digits
    long first_digits = card_number;
    do
    {
        first_digits = first_digits / 10;
    }
    while (first_digits > 100);

    // card type
    if (first_digits == 34 || first_digits == 37)
    {
        printf("AMEX\n");
    }
    else if (first_digits >= 40 && first_digits <= 49)
    {
        printf("VISA\n");
    }
    else if (first_digits > 50 && first_digits < 56)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
