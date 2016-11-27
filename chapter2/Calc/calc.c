/**
 * calc.c
 *
 * Austen van der Byl
 * austen.vanderbyl@aupschool.org
 *
 * Preformes a calculation with one the the following opperators: +, -, x, /, %
 */
#include <cs50.h>
#include <stdio.h>
#include <string.h>
 
int main(int argc, char *argv[])
{
    // Checks for correct usage
    if (argc != 4)
    {
        printf("Usage: ./calc <number> <operater> <number>\n");
        return 1;
    }
    // Proceed
    else
    {
        // Vars for numbers the user inputted
        float num1 = atof(argv[1]);
        float num2 = atof(argv[3]);
         
        char symbol = *argv[2];
        // If statment for addition
        if (symbol == "+"[0])
        {
            float addition = num1 + num2;
            printf("%f\n", addition);
            return 0;
        }
        // Else if statment for subtraction
        else if(symbol == "-"[0])
        {
            float subtraction = num1 - num2;
            printf("%f\n", subtraction);
            return 0;
        }
        // Else if statment for multiplication
        else if(symbol == "x"[0])
        {
            float multiplication = num1 * num2;
            printf("%f\n", multiplication);
            return 0;
        }
        // Else if statment for division
        else if(symbol == "/"[0])
        {
            float division = num1 / num2;
            printf("%f\n", division);
            return 0;
         }
        // Else if statment for modulo
        else if(symbol == "%"[0])
        {
            int initialDivision = (num1 / num2);
            float modulo = num1 - (num2 * initialDivision);
            printf("%f\n", modulo);
            return 0;
         }
        // Runs only of the operator the user inputted is invalid
        else
        {
            printf("Invalid operator, please rerun the program");
            return 1;
        }
    }
 }