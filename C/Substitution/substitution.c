#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

void substitution(char *text, string key);

int main(int argc, string argv[])
{
    // Check whether the program was initialized with the correct number of arguments
    if (argc != 2)
    {
        printf("./substitution key\n");
        return 1;
    }

    // Verify that the key is the correct size
    int n = strlen(argv[1]);
    if (n < 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Scroll through the digits of the key, checking that they are all letters
    for (int i = 0; i < n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must contain only alphabetic chacacters.\n");
            return 1;
        }

        for (int j = i + 1; j < n; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Key must not cotain repeated characters.\n");
                return 1;
            }
        }
    }

    string key = argv[1];

    // Ask the user the text to be encrypted
    string text = get_string("plaintext: ");

    substitution(text, key);

    printf("ciphertext: %s\n", text);
}

// Replace the letters of the entered phrase with the encryption code
void substitution(char *text, string key)
{
    for (int i = 0, j = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            j = text[i] - 'A';
            text[i] = toupper(key[j]);
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            j = text[i] - 'a';
            text[i] = tolower(key[j]);
        }
    }
}