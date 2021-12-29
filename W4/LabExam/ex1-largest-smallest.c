/*
Author: Thomas Hazekamp
Date: 15/10/21
Description: Finding the largest or smallest number from command line
*/
/* Relevant libraries  & description */
#include <stdio.h> // for input & output
#include <stdlib.h> // for atoi function
#include <string.h> // to use strcmp

/* Function prototypes */
/* find_largest will return the largest float number in the commanc line array
find_smallest will return the smallest float number in the command line array
So we will need the following functions:
*/
float find_largest(float nums[], int length);
float find_smallest(float nums[], int length);
// etc...

/* main function */
int main(int argc, char * argv[])
{
    /* intialiasised variables */
    int i;
    float result;
    float nums[argc - 1]; // the new array to store command line numbers
    int length = argc - 2; // this is the length of the array with only float numbers
    int j = 0;

    // converting all elements of the argv array to a new array and making them integers 
    for(i=2; i<argc; i++)
    {
        nums[j] = atof(argv[i]);
        j++;
    }

    // checking which function to use if the argument word is largest or smallest
    if(strcmp(argv[1], "largest") == 0)
    {
        result = find_largest(nums, length);
        printf("%.2f\n", result);
    }
    else
    {
        result = find_smallest(nums, length);
        printf("%.2f\n", result);
    }

    return 0; // exiting the program correctly
}

/* actual implementation of the functions */
float find_largest(float nums[], int length)
{
    //initialising variables
    int i;
    float largest_num;

    // this for loop loops around the nums array to find the largest float number
    for(i = 0; i < length; i++)
    {
        if(nums[i] > largest_num)
        {
            largest_num = nums[i];
        }

    }

    return largest_num; // returning the largest float number
}

float find_smallest(float nums[], int length)
{
    //initialising variables
    int i;
    float smallest_num = nums[0]; // setting the smallest number to the first number in array

    // this for loop loops around the array to find the smallest number 
    for(i = 0; i < length; i++)
    {
        if(nums[i] < smallest_num)
        {
            smallest_num = nums[i];
        }
    }
    return smallest_num; // returns the smallest float number found
}