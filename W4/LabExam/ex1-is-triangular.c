/*
Author: Thomas Hazekamp
Date: 15/10/2021
Description: This program tests whether or not the number in command line is a triangular number
*/
/* Relevant libraries  & description */
#include <stdio.h>
#include <stdlib.h> // for atoi function

/* Function prototypes */
/* is_tirangular will either give the triangular number (for passed test) or a -1 (for failed test)
So we will need the following functions:
*/
int is_triangular(int number);

/* main function */
int main(int argc, char * argv[])
{
    /* initialising variables */
    int i, number, result;

    number = atoi(argv[1]); // converts the first command line number to an integer

    result = is_triangular(number); // returns either the triangular num or -1 (signifing that it is not triangular)

    if(result != -1) // if not -1, this means the number is a triangular number
    {
        printf("%d is a triangular number\n", number);
    }
    else
    {
        printf("%d is not a triangular number\n", number);
    }

    return 0; // exiting the function correctly
}

/* actual implementation of the functions */
int is_triangular(int number)
{
    //statements
    int i;
    int tot_sum = 0;

    // this for loop goes through all positive integers before the number and adds then,
    // if the addition is equal to the number then it is a triangular number, else it return -1
    for(i = 0; i < number; i++)
    {
        tot_sum += i;

        if(tot_sum == number)
        {
            return number;
        }
    }

    return -1; // base case since -1 cannot be a triangular number
}