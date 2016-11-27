/**
 * farenheit.c

 *
 * Austen van der Byl
 * austen.vanderbyl@aupschool.org
 
*
 * Prompts user for input then converts celcius to farenheit 
 
* through a set of two varibles
 
*/
  
  

// (REMEMBER TO MAKE IN TERMINAL)


#include <cs50.h>

#include <stdio.h>



int main(void)
{

    printf("Enter the number of degrees celcius: ");

    float celcius = GetFloat();

    float equation = celcius * 9 / 5 + 32;

    printf("%f Degrees Celcius =\n%.1f Degrees Fahrenheit\n",celcius, equation);

}