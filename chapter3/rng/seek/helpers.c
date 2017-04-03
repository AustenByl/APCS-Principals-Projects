/**
 * helpers.c
 *
 * CS50 AP
 * Seek
 *
 * Helper functions.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // Stores the current middle value
    int start=0;
    int end = n - 1;
    while(start <= end)
    {
        int middle = (end + start) / 2;
        if (values[middle] == value)
        {
            return true;
        }
        // Goes on to refine search on left side
        else if (value < values[middle])
        {
            end = middle - 1;
        }
        // Goes on to refine search on right side
        else if (value > values[middle])
        {
            start = middle + 1;
        }
    }
    return false;
    
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // Bubble sort algorithm
    for(int i = 0; i < n - 1; i++)
    {
        for(int x = 0; x < n - i - 1; x++)
        {
            // Checks if a switch needs to be preformed
            if (values[x] > values[x + 1])
            {
                // Preformes switch and increases n to continue down the list
                int tempValue = values[x];
                values[x] = values[x + 1];
                values[x + 1] = tempValue;
            }
        }
    }
    return;
}
