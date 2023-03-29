#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void checkTextLevel(string text);

int main(void)
{
    // Ask the user for the text
    string text = get_string("Digite um texto para a análise do graau de legibilidade: \n");

    checkTextLevel(text);
}

// Checking the readability level from the number of letters, words and phrases of the text
void checkTextLevel(string text)
{
    int number_letters = 0;
    int numbers_words = 0;
    int numbers_phrases = 0;

    int index = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // The function 'isalpha()' returns true if the character is a letter
        if (isalpha(text[i]))
        {
            number_letters++;
        }
        else
        {
            // Check words and phrases from punctuation/spacing marks. This is done using 33 for '!', 46 for '.', 63 for '?' and 32 for spacing
            if (text[i] == 32)
            {
                numbers_words++;
            }
            else if ((text[i] == 33) || (text[i] == 46) || (text[i] == 63))
            {
                numbers_phrases++;
            }
        }
    }

    numbers_words += 1;

    // Checking the readability level using the Coleman-Liau index
    float l = ((float) number_letters / numbers_words) * 100;
    float s = ((float) numbers_phrases / numbers_words) * 100;

    index = round(0.0588 * l - 0.296 * s - 15.8);

    if ((index >= 1) && (index <= 16))
    {
        printf("Categoria %i\n", index);
    }
    else if (index < 1)
    {
        printf("Categoria menor que 1\n");
    }
    else
    {
        printf("Categoria 16+\n");
    }
}