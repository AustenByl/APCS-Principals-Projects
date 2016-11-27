/**
 * greedy.c
 *
 * Austen van der Byl
 * austen.vanderbyl@aupschool.org
 * 
 * Verifys an ISBN number
 */
 
#include <cs50.h>
#include <stdio.h>

 
int main(void)
{
    // Gets an ISBN number from the user to check
    printf("Please enter the ISBN-10 digits: ");
    long long isbnNumber = GetLongLong();
    // Holds a number the current isbnNumber has to be multiplied with
    int multiplicand = 10;
    // Stores the sum of all the numbers being multiplied together
    int total = 0;
    // Stores the number currently being multiplied by multiplicand
    int checkInt;
    
    // Loop for adding together all the isbnNumbers being multiplied together
    // by the multiplicand so that it can be verified
    for (int i = 1; i <= 10; i++)
    {
        checkInt = isbnNumber % 10;
        total += checkInt * multiplicand;
        isbnNumber = isbnNumber / 10;
        multiplicand--;
    }
    // Verifies if the isbnNumber is valid or not
    if (total % 11 == 0)
    {
        printf("YES\n");
    }
    else 
    {
        printf("NO\n");
 
    }
    }