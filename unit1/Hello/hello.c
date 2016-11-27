/**
 * hello.c
 *
 * Austen van der Byl
 * austen.vanderbyl@aupschool.org
 *
 * Promts user for name and greets them
 */
 
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Enter your  name: ");
    string name = GetString();
    printf("hello, %s\n", name);
}
