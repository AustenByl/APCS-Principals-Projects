/**
 * initials.c
 *
 * Austen van der Byl
 * austen.vanderbyl@aupschool.org
 *
 * Takes the input of any given name and converts it to initials
 */
 
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
 
int main(void)
{
 // varible for the users input
    string name = GetString();
    // Prints the first letter of the name that was inputted
    printf("%c", toupper(name[0]));
   
   // Loop itterates over entire name and prints the first letter after a space
    for(int i = 0; i < strlen(name); i++)
    {
        if (isspace(name[i]))
        {
            printf("%c", toupper(name[i + 1]));
        }
   }
   // Prints a new line in order to optimize readibility
    printf("\n");
 }