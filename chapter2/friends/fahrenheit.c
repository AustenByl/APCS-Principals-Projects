/**
 * fahrenheit.c
 *
 * Austen van der Byl
 * austen.vanderbyl@aupschool.org
 *
 * Convets <value> to fahrenheit
 */
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./fahrenheit <value>");
        return 1;
    }
    else
    {
        // get celsius from user
        float celsius = atof(argv[1]);
    
        // convert to fahrenheit; no float errors b/c celsius is a float
        float fahrenheit = (celsius * 9) / 5 + 32;
        printf("F: %.1f\n", fahrenheit);
    }
}