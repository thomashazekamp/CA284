/*
Author: Thomas Hazekamp
Date: 10/10/21
Description: First number in the array is the number to find in remaining array
*/
/* Relevant libraries  & description */
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
/* ... description
So we will need the following functions:
*/
int search_number(int *p,  int first_num, int length);
// etc...

/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    int i, length, result, first_num, nums[argc];
    int j = 0;

    first_num = atoi(argv[1]);
    // converting all elements of the argv array to a new array and making them integers 
    for(i=1; i<argc; i++)
    {
        nums[j] = atoi(argv[i]);
        j++;
    }

    result = search_number(nums, first_num, argc);

    // If the index position changes from -1 to a possible index pos then print the following
    if(result != -1)
    {
        printf("Found %d at %d\n", first_num, result);
    }
    else
    {
        printf("%d not found\n", first_num);
    }

    return 0;
}

/* actual implementation of the functions */
int search_number(int *p, int first_num, int length)
{
    //statements
    int i, pos;

    pos = -1; // this will signify that there is no reoccurence of the number we are searching

    p++; // Since the first number in array is the number that needs to be found we move one item up

    // This for loop gives the position of the first occurence of the number we need to find
    for(i = 0; i < (length - 2); i++)
    {
        if(*p == first_num)
        {
            pos = i; // store the position to be able to return it
            return pos;
        }
        p++; // gets the next elements in nums[] array
    }

    return pos; // returning the -1 position since the for loop has not found a reoccurence of the first number
}