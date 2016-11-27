/**
 * pennies.c
 *
 * Austen van der Byl
 * austen.vanderbyl@aupschool.org
 * 
 * Same as original pennies where it take the day and number of pennies
 * and figures out how many pennies you will have with your parameters
 * that were entered at the command line
 */
 
#include <cs50.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("Usage: ./pennies <daysInMonth> <numberOfStartPennies>\n");
        return 1;
    }
    else
    {
        if((atoi(argv[1]) >= 28 && atoi(argv[1]) <= 31) && atoi(argv[2]) >= 0)
        {
            // Varible for the days in the month the user inputs and pennies
            int dayInMonth = atoi(argv[1]);
            long long startCents = atoi(argv[2]);
            long long totalCents = 0;
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
        else
        {
            printf("Usage1: ./pennies <daysInMonth> <numberOfStartPennies>\n");
            return 1;
        }
    }
}