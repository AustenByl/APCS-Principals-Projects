/**
 * file.c
 *
 * Austen van der Byl
 * austen.vanderbyl@aupschool.org
 *
 * increases x from 1 to 51 one int at a time and prints everytime this occurs
 */
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = 1;
    while(x <= 50)
    {
        x++;
        printf("%i\n", x);
    }
}