#include <cs50.h>
#include <stdio.h>

void buildPyramid(int height);

int main(void)
{
    int height;

    // Ask the user for the height of the pyramid
    do
    {
        height = get_int("Digite a altura da pirâmide: ");
    }
    while ((height < 1) || (height > 8));

    buildPyramid(height);
}

// Create the pyramid according to the height passed
void buildPyramid(int height)
{
    int j = 0;
    int m;

    for (int i = 0; i < height; i++)
    {
        for (int k = height - 1; k > j; k--)
        {
            printf(" ");
        }
        j++;

        for (m = 0; m < j; m++)
        {
            printf("#");
        }
        printf("  ");

        for (m = 0; m < j; m++)
        {
            printf("#");
        }
        printf("\n");
    }
}
