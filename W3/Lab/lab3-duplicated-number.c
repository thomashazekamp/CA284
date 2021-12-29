/*
Author: Thomas Hazekamp
Date: 10/10/21
Description: finds the first duplicate number in the array
*/
/* Relevant libraries  & description */
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
/* ... description
So we will need the following functions:
*/
int duplicated_number(int nums[], int len);
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

    length = argc - 1; // length of the nums array

    result = duplicated_number(nums, length);

    // If there is no duplicate number in the array the result will be -1
    if(result != -1)
    {
        printf("%d\n", result);
    }
    else
    {
        printf("no duplicated number\n");
    }

    return 0;
}

/* actual implementation of the functions */
int duplicated_number(int nums[], int len)
{
    //statements
    int i, j, dup_num;

    dup_num = -1; // this means no duplicate number has yet been found

    // First for loop to go through all items in array
    for(i = 0; i < len; i++)
    {
        // Second for loop to find if a duplicate of nums[i] exits, if reached end of array, the prev loop with move up one
        for(j = i + 1; j < len; j++)
        {
            if(nums[j] == nums[i]) // test for duplicate
            {
                dup_num = nums[i];
                return dup_num; // exiting the function and returning the duplicate number
            }
        }
    }
    return dup_num; // exiting the function and returning either a duplicate number or -1 (meaning no duplicate was found)
}
