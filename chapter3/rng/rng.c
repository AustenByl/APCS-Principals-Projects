/**
 * rng.c
 *
 * Austen van der Byl
 * austen.vanderbyl@aupschool.org
 *
 * Generates a pseudorandom number
 */
 
 #define _XOPEN_SOURCE
 #define LIMIT 65536
 #include <stdlib.h>
 #include <cs50.h>
 #include <ctype.h>
 #include <stdio.h>
 #include <time.h>
 
int main(int argc, char *argv[])
{
    // Checks the number of inputs and that the max does not exceed the limit
    if((argc < 3 || argc > 4) || atoi(argv[2]) > 65536)
    {
        // Indicates correct usage
        printf("Usage: ./rng <number of numbers> <maximum value less than 65536>"
        " <seed(optional>\n");
        return 1;
    }
    // Runs the rest of the code
    else
    {
        int max = atoi(argv[2]);
        if(argc == 4)
        {
             srand48((long int) atoi(argv[3]));
        }
        // Else has a seed based on time
        else
        {
            srand48((long int) time(NULL));
        }
        // Prints several randomnumbers depending on how many the user specifed
        for (int i = 0; i < atoi(argv[1]); i++)
        {
            // Prints the random number multiplied by the max to ensure it doesn't exceed it
            printf("%i\n", (int) (drand48() * max));
        }
        return 0;
    }
}