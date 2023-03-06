#include <stdio.h>
#include <cs50.h>
#include <math.h>

void quantityCoins(float cash);

int main(void)
{
    float cash;

    // Receive from the user the amount of change (positive real number)
    do
    {
        cash = get_float("Digite o valor do troco a ser recebido (somente números): ");
    }
    while (cash <= 0);

    quantityCoins(cash);
}

// Calculate and display the quantity of coins to be delivered
void quantityCoins(float cash)
{
    int cents = round(cash * 100);
    int coins = 0;

    while (cents >= 25)
    {
        cents -= 25;
        coins++;
    }

    while (cents >= 10)
    {
        cents -= 10;
        coins++;
    }

    while (cents >= 5)
    {
        cents -= 5;
        coins++;
    }

    while (cents >= 1)
    {
        cents -= 1;
        coins++;
    }

    printf("\nDeve ser entregue %i moedas!\n", coins);
}