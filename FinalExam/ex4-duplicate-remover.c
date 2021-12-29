/*
Author: Thomas Hazekamp
Date: 10/12/2021
Description: This program removes duplicate items from the array, including the value itself. Finally it prints the remaining values in the list.
*/
/* Relevant libraries  & description */
#include <stdio.h>
#include <stdlib.h> // Used for atoi function

/* Function prototypes */
/* 
-> printNoDuplicates function is used to remove duplicates (including the value itself), then prints remaining values as output
So we will need the following functions:
*/
void printNoDuplicates(int * array, int size);

/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    int lst[argc - 1], j = 0;
    int size = argc - 1;

    // Adding values from command line to an array
    for(int i = 1; i < argc; i++)
    {
        lst[j] = atoi(argv[i]);
        j++;
    }

    printNoDuplicates(lst, size); // Removes duplicates and prints remaining values

    return 0; // Exiting the function correctly
}

/* actual implementation of the functions */
// This function removes duplicates from the array (including the value itself), then prints remainig values as output
void printNoDuplicates(int * array, int size)
{
    //statements
    int count; // Used to signify if a duplicate has been found

    // Looping through each item in the list
    for (int i = 0; i < size; i++)
    {
        count = 0; // Setting count to 0 (used to signify a duplicate)
        // A nested too used for comparison
        for (int j = i + 1; j < size; j++)
        {
            // If we have found a duplicate
            if (array[i] == array[j])
            {
                count = 1; // This count will be used to signify that the current i element need to be removed too
                // Shifting consequent items up one position
                for (int k = j; k < size - 1; k++)
                {
                    array[k] = array[k + 1]; // Setting current item to the next item
                }
                size--; // Since one item has been removed, we reduce the size
                j--; // Needs to go back one, so it doesnt miss a possible duplicate value
            }
        }
        // Need to remove the duplicate value itself
        if (count == 1)
        {
            // Shifting consequent items up one position
            for (int k = i; k < size - 1; k++)
            {
                array[k] = array[k + 1]; // Setting current item to the next item
            }
            size--; // Reducing size by one since we are "removing" the current item
            i--; // i needs to be rechecked since it has changed value
        }
    }

    // A loop to print the remaining array (non duplicates)
    for(int i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }
}