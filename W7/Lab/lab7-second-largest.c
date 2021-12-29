/*
Author: Thomas Hazekamp
Date: 08/11/2021
Description: This program prints the second largest float number given in the command line
*/
/* Relevant libraries  & description */
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
/* The second_largest function will return the second largest float from the argument line
So we will need the following functions:
*/
float second_largest(float *pNumbers, int length);

/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    int length = argc - 1; // length of numbers to add to a new list
    float *pNumbers = NULL;
    float *pResult = NULL;
    int j = 0;

    pNumbers = (float*)malloc(length*(sizeof(float)));
    if(!pNumbers)
    {
        // Code to deal with memory allocation failure
        printf("Failed to allocate memory!");
        return 0;
    }

    // Adding relevant argument line numbers to a list
    for(int i = 1; i < argc; i++)
    {
        *(pNumbers + j) = atof(argv[i]);
        j++;
    }

    pResult = (float*)malloc(1*(sizeof(float))); // Allocating the size of memory
    *pResult = second_largest(pNumbers, length);

    printf("%.1f\n", *pResult);

    // Free the memory
    free(pResult);
    free(pNumbers);

    return 0;
}

/* actual implementation of the functions */
float second_largest(float *pNumbers, int length)
{
    //statements
    float result = 0;
    float largest;
    float second_l;
    int i = 1;
    
    // Setting initial values for largest and second largest
    if(*(pNumbers) > *(pNumbers + 1))
    {
        largest = *(pNumbers);
        second_l = *(pNumbers + 1);
    }
    else if(*(pNumbers) < *(pNumbers + 1)) // If the second element in the array is larger than first
    {
        largest = *(pNumbers + 1);
        second_l = *(pNumbers);
    }
    else // This loop is to make sure that the base case for the second largest is not equal to the largest number
    {
        largest = *(pNumbers);

        while(*(pNumbers) == *(pNumbers + i)) // Loops until it finds a non equal number to the first
        {
            i++;
        }
        second_l = *(pNumbers + i); // setting the second highest number to the new number (which is different than the previous)
    }

    // This loop goes through the whole list again to possibly change the largest and smallest values
    for(int i = 0; i < length; i++)
    {
        if(*(pNumbers + i) > largest)
        {
            second_l = largest;
            largest = *(pNumbers + i);
        }
        else if(*(pNumbers + i) > second_l && (*(pNumbers + i) != largest)) // Making sure that repeated large numbers will not become the second largest nums
        {
            second_l = *(pNumbers + i);
        }
    }

    return second_l;
}