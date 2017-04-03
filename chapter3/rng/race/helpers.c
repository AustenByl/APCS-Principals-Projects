/**
 * helpers.c
 *
 * CS50 AP
 * Sort Race
 * 
 * Name: Austen van der Byl
 *
 * Helper functions for the sort race
 */

#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if str is a valid flag (-a, -b, -r, or -s), false otherwise
 */
 
bool check_flag(char* str)
{
    // Checks if -a, -b, -r, or -s is in argv[1], if so it returns true
    if (((str = "-a") || (str = "-b")) || ((str = "-r") || (str = "-a")))
    {
        return true;
    }
    return false;
}

/**
 * Sorts array of n values using bubble sort.
 */
 // Initialize earlier
void bubble(int values[], int n)
{
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

/**
 * Sorts array of n values using selection sort.
 */
void selection(int values[], int n)
{
    // Goes over array n - 1 times
    for(int i = 0; i < n - 1; i++)
    {
        // Stores value for if and swap
        int min = i;
        // Works to get current min in correct position
        for(int x = i + 1; x < n; x++)
        {
            // Checks if current value is min or not
            if (values[x] < values[min])
            {
                min = x;
            }
        }
        // Swiches if the value of min has changed 
        // to be in a different spot then switches
        if (min != i)
        {
            int tempInt = values[i];
            values[i] = values[min];
            values[min] = tempInt;
        }
    }
    return;
}

/**
 * Sorts array of n values using insertion sort.
 */
void insertion(int values[], int n)
{ 
    // Loop to move each item
    for(int i = 1; i <= n - 1; i++)
    {
        // Stores for swap
        int element = values[i];
        // Used for comparasin in while loop and for swap
        int x = i;
        // Puts item in correct place
        while(0 < x && element < values[x - 1])
        {
            // Swaps
            values[x] = values[x - i];
            x--;
            values[x] = element;
        }
    }
    return;
}