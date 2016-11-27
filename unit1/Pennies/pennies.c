/**
 * pennies.c
 *
 * Austen van der Byl
 * austen.vanderbyl@aupschool.org
 * 
 * Asks user for days and coins the multiplies the amount of coins
 * by two for the number of days the user entered, prints total coins in dollars
 */
 
#include <cs50.h>
#include <stdio.h>

int main(void)
{
     // Varible for the days in the month the user inputs
    int dayInMonth;
    long long startCents = 0;
    long long totalCents = 0;
    // Loop to ensure the amount of days the user enters is between 28 and 31
    do
    {
        printf("Please enter the amount of days in this month: \n");
        dayInMonth = GetInt();
    }
    while (dayInMonth < 28 || dayInMonth > 31);
    
    // Loop prompting user for coins on day one. Ensures there's avalid input
    do
    {
        printf("Enter the number of cents you will recieve on day one: \n"); 
        startCents = GetInt();
    }
    while (startCents <= 0);
    // Loop multiplying the originalnumber of pennies 
    // by two for each day the user entered
    for (int i = 1; i <= dayInMonth; i++)
    {
        totalCents += startCents;
        startCents *= 2;
    }
    // Converts the number of cents to dollars 
    // and prints the total amount of pennies
    double endAmount = ((double) totalCents) / 100;
    printf("$%.2f\n", endAmount);
}