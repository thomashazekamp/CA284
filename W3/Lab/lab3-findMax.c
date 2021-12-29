/*
Author: Thomas Hazekamp
Date: 08/10/21
Description: Program to find largest number for the command line
*/
/* Relevant libraries  & description */
#include <stdio.h>
#include <stdlib.h> // used for atoi

/* Function prototypes */
/* Finding the largest number from command line
So we will need the following functions:
*/
int finding_max(int *p, int length);
// etc...

/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    int i, length, result, nums[argc];
    int j = 0;

    // converting all elements of the argv array to a new array and making them integers 
    for(i=1; i<argc; i++)
    {
        nums[j] = atoi(argv[i]);
        j++;
    }
    

    result = finding_max(nums, argc);

    printf("%d\n", result);

    return 0; // exiting the function correctly
}

/* actual implementation of the functions */

int finding_max(int *p, int length) // *p is a pointer which starts at nums[0], each time p++ it goes to the next nums[] element in the array
{
    //statements
    int i, max_value;

    max_value = 0; // having a base case

    for(i = 1; i < length; i++)
    {
        if(*p > max_value)
        {
            max_value = *p;
        }
        p++; // gets the next elements in nums[] array
    }
    return max_value;
}