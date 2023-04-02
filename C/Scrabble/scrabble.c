#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1:");
    string word2 = get_string("Player 2:");

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Check who won the game and show the result
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Calculate the word score
int compute_score(string word)
{
    int sum = 0;
    int n = strlen(word);

    for (int i = 0; i < n; i++)
    {
        if (!isalpha(word[i]))
        {
            sum += 0;
        }
        else
        {
            sum += POINTS[tolower(word[i]) - 'a'];
        }
    }

    return sum;
}