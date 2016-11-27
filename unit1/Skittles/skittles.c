/**
 * skittles.c
 *
 * Austen van der Byl
 * austen.vanderbyl@aupschool.org
 *
 * Makes a user guess a random number of Skittles between
 * the numbers of 0 and 1024
 */
  
  // (REMEMBER TO MAKE IN TERMINAL)

#include <cs50.h>  
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    // Explanes the ruls of the game and gives appropiate response
    printf("Let's play a little game... \n I have chosen a random number of S"
    "kittles between the numbers 0 and 1024.\n How many skittles are there?\n");
    // Seeds the pseudorandom number using the number of current seconds
    srand(time(NULL));
    
    // Decides the pseudorandom number based upon seed between [0, 1023]
    int skittles = rand() % 1024;
    int user_guess = GetInt();
    
    while (user_guess != skittles) 
    {
        if (user_guess > 1024 || user_guess < 0) 
            printf("That's not even an option!\nTry again\n");
        else
            printf("Incorrect... I expected better from you.\n"
            "Try again\n");
        user_guess = GetInt();
    }
    
    printf("Congratulations! You win this time...\n");
}