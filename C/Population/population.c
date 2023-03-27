#include <stdio.h>
#include <cs50.h>

void calculateYears(int initial_population, int final_population);

int main(void)
{
    int initial_population = 0;
    int final_population = 0;

    // Ask the user the value of the initial population
    do
    {
        initial_population = get_int("Digite o valor inicial da população: ");
    }
    while (initial_population < 9);

    // Ask the user the value of the final population
    do
    {
        final_population = get_int("Digite o valor final da população: ");
    }
    while (final_population < initial_population);

    calculateYears(initial_population, final_population);
}

// Calculate the number of years to reach the final population size
void calculateYears(int initial_population, int final_population)
{
    int current_population = initial_population;
    int years_number = 0;

    while (current_population < final_population)
    {
        current_population = current_population + ((current_population / 3) - (current_population / 4));
        years_number++;
    }

    printf("\n");
    printf("Levará %d anos(s) para a população ir de %d para %d\n", years_number, initial_population, final_population);
}