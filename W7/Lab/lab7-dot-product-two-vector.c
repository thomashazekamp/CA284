/*
Author: Thomas Hazekamp
Date: 08/11/2021
Description: Prints to screen the dot product of the two vectors
*/
/* Relevant libraries  & description */
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
/* The dot_product_vec is calculating the dot product of the vectors
So we will need the following functions:
*/
int dot_product_vec(int *pNumbers, int vec_size);

/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    int length = argc - 2; // length of numbers to add to a new list
    int *pNumbers = NULL;
    int *pResult = NULL;
    int vec_size = 0;
    int j = 0;

    vec_size = atoi(argv[1]); // this is the vector sizes

    pNumbers = (int*)malloc(length*(sizeof(int)));
    if(!pNumbers)
    {
        // Code to deal with memory allocation failure
        printf("Failed to allocate memory!");
        return 0;
    }

    // Adding relevant argument line numbers to a list
    for(int i = 2; i < argc; i++)
    {
        *(pNumbers + j) = atoi(argv[i]);
        j++;
    }

    pResult = (int*)malloc(1*(sizeof(int))); // Allocating the size of memory
    *pResult = dot_product_vec(pNumbers, vec_size);

    printf("%d\n", *pResult);

    // Free the memory
    free(pResult);
    free(pNumbers);

    return 0;
}

/* actual implementation of the functions */
int dot_product_vec(int *pNumbers, int vec_size)
{
    //statements
    int product = 0;

    // Getting the total of the dot product for the two vectors
    for(int i = 0; i < vec_size; i++)
    {
        product += *(pNumbers + i) * *(pNumbers + (i + vec_size));
    }
    return product;
}