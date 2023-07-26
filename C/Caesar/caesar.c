#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void encrypt(char *text, int key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("./caesar key\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);

    string text = get_string("plaintext: ");

    encrypt(text, key);

    printf("ciphertext: %s\n", text);
}

void encrypt(char *text, int key)
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = ((text[i] - 'A') + key) % 26 + 'A';
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = ((text[i] - 'a') + key) % 26 + 'a';
        }
    }
}