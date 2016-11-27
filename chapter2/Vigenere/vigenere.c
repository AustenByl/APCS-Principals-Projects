/**
 * vigenere.c
 *
 * Austen van der Byl
 * austen.vanderbyl@aupschool.org
 *
 * Encrypts a string with a user entered cipher
 */
 
 
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    // Forces argv[1] into a string for checking that everything is a letter
    string cipherKey = argv[1];
    if (argc != 2)
    {
        printf("Usage: ./vigenere <keyword>\n");
        return 1;
    }
    else
    {
        // Checks is argv[1] is only letters before resuming
        for(int i = 0; i < strlen(cipherKey); i++)
        {
            if (!isalpha(cipherKey[i]))
            {
                printf("Usage: ./vigenere <keyword>\n");
                return 1;
            }
        }
        char *text = GetString();
        int cipherLength = strlen(argv[1]);
        // Accounts for number of things that aren't letters
        int notLetter = 0;
        for(int i = 0; i < strlen(text); i++)
        {
            // Varibles to be updated during loop
            int key;
            char letter;
            // If ith letter in the key isupper, convert to key
            if (isupper(argv[1][i % cipherLength]))
            {
                key = (argv[1][(i - notLetter) % cipherLength] - 65) % 26;
                // printf("%i", key);
            }
            // If ith letter in the key islower, convert to key
            else if(islower(argv[1][i % cipherLength]))
            {
                key = (argv[1][(i - notLetter) % cipherLength] - 97) % 26;
                // printf("%i", key);
            }
            
            // If ith letter in user text isupper, apply key
            if (isupper(text[i]))
            {
                letter = (text[i] - 65 + key) % 26 + 65;
                printf("%c", letter);
            }
            // If ith letter in user text islower, apply key
            else if(islower(text[i]))
            {
                letter = (text[i] - 97 + key) % 26 + 97;
                printf("%c", letter);
            }
            // Prints everything that is not a letter and adds i to notLetter
            // in order to apply the cipher correctly to the next letter
            // (Doesn't work though)
            else if(isalpha(text[i]) == false)
            {
                printf("%c", text[i]);
                notLetter++;
            }
        }
        printf("\n");
    }
}