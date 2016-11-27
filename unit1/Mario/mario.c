/**
 * mario.c
 *
 * Austen van der Byl
 * austen.vanderbyl@aupschool.org
 * 
 * Creates a Mario pyramid
 */
 
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Variables for the empty space, bricks of the pyramid and height
    int height;
    string brick = "#";
    string space = " ";
    // Verifies that the user input is valid
    do 
    {
        printf("Please enter an mount of steps less than or equal to 23: ");
        height = GetInt();
    }
    while (height >= 24 || height < 0);
    // Additional variable for the for loop to ensure the correct 
    // amount of iterations
    int height2 = height;
    // Loop to build the pyramid
    for(int i = 0; i < height; i++)
    {
        // Adds the spaces before the pyramid bricks
        for (int e = height2 - 2; e >= 0; e--)
        {
            printf("%s", space);
        }
        // Adds the bricks of the pyramid
        for (int x = 0; x <= i; x++)
        {
            printf("%s", brick);
        }
        // Prints the extra brick, space and updates height2 variable
        printf("%s", brick);
        printf("\n");
        height2--;
    }
}