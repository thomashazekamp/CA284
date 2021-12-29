/*
Author: Thomas Hazekamp
Date: 15/10/21
Description: Outputting the sequence from 1 to n (positive integer given)
*/
/* Relevant libraries  & description */
#include <stdio.h> // for input and output
#include <stdlib.h> // for atoi funciton

/* Function prototypes */
/* Will print the full hailstone sequence including the starting number in front
So we will need the following functions:
*/
int hailstone_sequence(int number);
// etc...

/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    int number;

    number = atoi(argv[1]); // converts number from command line to an integer

    hailstone_sequence(number); // calls the function and prints the sequence on one line ending with /n (newline)

    return 0; // exits the main function correctly
}

/* actual implementation of the functions */
int hailstone_sequence(int number)
{
    //no need of initialisation

    printf("%d ", number); // printing the original number
    
    while (1) // infinite loop, breaks when number becomes 1
    {
        if(number != 1) // if the sequence hasnt ended then continue
        {    
            if(number % 2 == 0) // even number formula
            {
                number = number / 2;
                if(number != 1)
                {
                    printf("%d ", number);
                }
            }
            else // odd number formula
            {
                number = (number * 3) + 1;
                if(number != 1)
                {
                    printf("%d ", number);
                }
            }
        }
        else // this will be the last sequence therefore number = 1
        {
            printf("%d\n", number);
            break;
        }
    }

    return 0; // exiting the function correctly
}