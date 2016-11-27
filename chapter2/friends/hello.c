/**
 * hello.c
 *
 * Austen van der Byl
 * austen.vanderbyl@aupschool.org
 *
 * prints hello, <name>
 */
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // collect a string from the user, then print their name
    if(argc != 2)
    {
        printf("Input : ./hello <name>\n");
        return 1;
    }
    else
    printf("hello, %s\n", argv[1]);
}