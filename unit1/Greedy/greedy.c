/**
 * greedy.c
 *
 * Austen van der Byl
 * austen.vanderbyl@aupschool.org
 * Calculates the amount of change to return the least possible
 * number of coins
 */
 
#include <cs50.h>  
#include <stdio.h>
#include <math.h>


int main(void)
{
    // Varibles for total number of coins returned and amount the user enters
    int total_coins = 0;
    float amount_change = 0;
    float amountChange;
    
    // Gets a valid input from the user
    do 
    {
        printf("Enter amount of change: ");
        amountChange = GetFloat();
    }
    while (amountChange < 0);
    
    // Converts from cents to dollars and rounds the value if needed
    amount_change = amountChange * 100.0;
    int intAmount = round(amount_change);
    
    // Calculates the least possible number of coins to return
    while (intAmount >= 25)     
    {
        total_coins++;
        intAmount -= 25;
    }
    while (intAmount >= 10)
    {
        total_coins++;
        intAmount -= 10;
    }
    while (intAmount >= 5)
    {
        total_coins++;
        intAmount -= 5;
    }
    while (intAmount >= 1)
    {
        total_coins++;
        intAmount -= 1;
    }
    printf("%i\n", total_coins);
} 