/*
Author: Thomas Hazekamp
Date: 08/11/2021
Description: Prints to screen the largest number if it is atleast twice the size of any number in the list
*/
/* Relevant libraries  & description */
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
/* This function returns either a 0 or the largest number to signify it has/has not found a correct number (being atleast twice the size of another number)
So we will need the following functions:
*/
int largest_twice(int *pNumbers, int length);

/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    int length = argc - 1; // length of numbers to add to a new list
    int *pNumbers = NULL;
    int *pResult = NULL;
    int j = 0;

    pNumbers = (int*)malloc(length*(sizeof(int)));
    if(!pNumbers)
    {
        // Code to deal with memory allocation failure
        printf("Failed to allocate memory!");
        return 0;
    }

    // Adding relevant argument line numbers to a list
    for(int i = 1; i < argc; i++)
    {
        *(pNumbers + j) = atoi(argv[i]);
        j++;
    }

    pResult = (int*)malloc(1*(sizeof(int))); // Allocating the size of memory
    *pResult = largest_twice(pNumbers, length);

    printf("%d\n", *pResult);

    // Free the memory
    free(pResult);
    free(pNumbers);

    return 0;
}

/* actual implementation of the functions */
int largest_twice(int *pNumbers, int length)
{
    //statements
    int largest = *(pNumbers); // Setting base case to be the first number
    int count = 0; // This shows that there are/are not numbers half the size of the largest

    // Initially finding the largest number from array
    for(int i = 1; i < length; i++)
    {
        if(*(pNumbers + i) > largest)
        {
            largest = *(pNumbers + i);
        }
    }

    // This loop goes through the list again and adds a 1 to the count when it finds a number which multiplied together gives atleast the largest
    for(int i = 0; i < length; i++)
    {
        if((*(pNumbers + i) * 2) <= largest && (*(pNumbers + i) != largest))
        {
            count++;
        }
    }

    // If the count is not 0, then the array has atleast one number which multiplied times 2 is equal or greater than the largest number
    if(count != 0)
    {
        return largest;
    }
    else
    {
        return 0;
    }

}