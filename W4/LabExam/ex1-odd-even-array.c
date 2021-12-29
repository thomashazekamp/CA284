/*
Author: Thomas Hazekamp
Date: 14/10/21
Description: Getting a summary of odd and even numbers (odd - adding then together, even - subtracting them all starting from the first even number)
*/
/* Relevant libraries  & description */
#include <stdio.h>
#include <stdlib.h>


/* Function prototypes */
/* Calling the function numbers_summary will do all summary calculations and print the appropriate values
So we will need the following functions:
*/
int numbers_summary(int lst[], int length);

/* main function */
int main(int argc, char * argv[])
{
    /* initialise all variable names */
    int nums[50], i; // i is used to go through all index in the command line
    int j = 0;

    // read all numbers from command line as input and store them in a list (array)
    for(i = 1; i < argc; i++)
    {
        nums[j] = atoi(argv[i]);
        j++;
    }

    // calling numbers_summary to print the summary of odd and even numbers
    numbers_summary(nums, argc - 1);
    
    return 0; // quitting and exiting the main function correctly
}

/* actual implementation of the functions */
int numbers_summary(int lst[], int length)
{
    // initialised all variable names
    int i, prev_odd, prev_even;
    int sum_odds = 0;
    int sum_evens = 0;
    int c = 0;

    // this for loop is going through the array lst
    for(i = 0; i < length; i++)
    {
        // to check for the first even number
        if(lst[i] % 2 == 0 && c == 0)
        {
            sum_evens = lst[i];
            c = 1;
        }
        // subtracting rest of even numbers from the total
        else if(lst[i] % 2 == 0 && c == 1)
        {
            sum_evens -= lst[i];
        }
        
        // adding odd numbers to get a summary
        if(lst[i] % 2 != 0)
        {
            sum_odds += lst[i];
        }
    }

    // printing each result on a new line
    printf("%d\n%d\n", sum_odds, sum_evens);

    return 0; // exiting the numbers_summary function correctly
}