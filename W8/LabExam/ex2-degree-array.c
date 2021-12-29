/*
Author: Thomas Hazekamp
Date: 11/11/2021
Description: This program will print out the degree of a given number of integers in the command line argument (the number of times a single digit is repeated)
*/
/* Relevant libraries  & description */
#include <stdio.h> // For Input and Output
#include <stdlib.h> // For atoi function

/* Function prototypes */
/*
-> finding_degree will be used to attain the final degree of the given array
So we will need the following functions:
*/
int finding_degree(int *array, int length);

/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    int arg_array[argc - 1]; // The size of the array which will hold all the command line arguments
    int length = argc - 1; // Length of the wanted command line integers
    int j = 0;
    int result; // Value to store the final result as an integer

    // This for loop is making the command line arguments integers and adding them to an array
    for(int i = 1; i < argc; i++)
    {
        *(arg_array + j) = atoi(argv[i]);
        j++;
    }

    result = finding_degree(arg_array, length); // Storing integer value (degree of array)

    printf("%d\n", result); // Printing the degree with new line

    return 0; // Exiting main function correctly
}

/* This finding_degree function will return an iteger corresponding to the degree of the array */
int finding_degree(int *array, int length)
{
    //statements
    int i, j;
    int count = 0; // This will be used for each iteration
    int degree = 0; // This will be used to keep track of the highest degree of the array so far

    // This loop will compare each integer and add to count if it is equal
    for(i = 0; i < length; i++)
    {
        count = 0; // Reset count to 0 after each iteration
        for(j = 0; j < length; j++)
        {
            if(*(array + i) == *(array + j)) // If the integer is the same then add 1 to count
            {
                count++;
            }
        }
        if(count > degree) // If the count for a particular number is greater then previous, set degree to count
        {
            degree = count;
        }
    }
    
    return degree; // Returning the degree of the array
}