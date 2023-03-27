#include <stdio.h>
#include <cs50.h>

void verifyCard(long card_number);

int main(void)
{
    // Ask the user for the card number
    long card_number = 0;

    do
    {
        card_number = get_long("Digite o número do cartão: ");
    }
    while (card_number <= 0);

    verifyCard(card_number);
}

// Check card number
void verifyCard(long card_number)
{
    int digit = 0;
    int digits_counter = 0;
    int sum_digits = 0;
    long card_number_aux = 0;

    card_number_aux = card_number;

    while (card_number != 0)
    {
        digit = card_number % 10;

        card_number /= 10;

        digits_counter++;

        // Check that the counter number is even, so you can get all the alternating digits, starting with the second-to-last one
        if (digits_counter % 2 == 0)
        {
            digit = digit * 2;

            while (digit != 0)
            {
                sum_digits += digit % 10;
                digit /= 10;
            }
        }

        // Check that the counter number is odd, so you can get all the other digits that have not been multiplied by 2
        if (digits_counter % 2 != 0)
        {
            sum_digits += digit;
        }
    }

    // Check if the last digit of the sum is '0'. If the result is true, the card is legitimate
    if (sum_digits % 10 == 0)
    {
        long first_digit = card_number_aux;
        while (first_digit >= 10)
        {
            first_digit /= 10;
        }

        long first_two_digits = card_number_aux;
        while (first_two_digits >= 100)
        {
            first_two_digits /= 10;
        }

        // Verify the card's flag
        if ((digits_counter == 15) && ((first_two_digits == 34) || (first_two_digits == 37)))
        {
            printf("AMEX\n");
        }
        else if ((digits_counter == 16) && ((first_two_digits == 51) || (first_two_digits == 52) || (first_two_digits == 53) || (first_two_digits == 54) || (first_two_digits == 55)))
        {
            printf("MASTERCARD\n");
        }
        else if (((digits_counter == 13) || (digits_counter == 16)) && (first_digit == 4))
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