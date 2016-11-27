/**
 * ceaser.c
 *
 * Austen van der Byl
 * austen.vanderbyl@aupschool.org
 *
 * Applies the Caesar cipher to a string gotten from the user with the
 * key gotten from the user
 */
 
#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Stores the numerical on an individual letter at a later point
    int letter;
    // Validates the correct number of inputs
    if (argc != 2)
    {
        printf("Usage: ./ceaser <key>");
        return 1;
    }
    // Code to apply the ceaser cipher
    else
    {
        // Converts the key the user inputted from a string to an int
        int key = atoi(argv[1]);
        // Gets a string from the user to apply the ciper to
        string text = GetString();
        
        // Loop that itterates over each charecter individually in a way to
        // Preserve the case
        for (int i = 0, n = strlen(text); i < n; i++)
        {
            // If for if the charecter is uppercase
            if (isupper(text[i]) && isalpha(text[i]))
            {
                // Math to add the key, convert it to an alphabet scale
                // from 1-26 and adds a value to get an ascii value in uppercase
                letter = (text[i] - 65 + key) % 26 + 65;
                // Prints the letter after converting an int to letter (char)
                char letter1 = letter;
                printf("%c", letter1);
            }
            // Else for if the letter is lowercase
            else if(isalpha(text[i]) && islower(text[i]))
            {
                // Math to add the key, convert it to an alphabet scale
                // from 1-26 and adds a value to get an ascii value in lowercase
                letter = (text[i] - 97 + key) % 26 + 97;
                // Prints the letter after converting an int to letter (char)
                char letter1 = letter;
                printf("%c", letter1);
            }
            // Else for if the letter is not a letter and instead prints
            // whatever the original char was (e.g: a space, comma, period ect.)
            else
            {
                // Converts an int to ascii charecter and prints it
                char letter1 = text[i];
                printf("%c", letter1);
            }
        }
        // Prints a new line to look nice in the terminal
        printf("\n");
        return 0;
    }
}