/*
Author: Thomas Hazekamp
Date: 24/10/21
Description: Retriving numbers to be put in a matrix and getting the sum of the diagonal
*/
/* Relevant libraries  & description */
#include <stdio.h> // for input and output
#include <stdlib.h> // for atoi function

/* Function prototypes */
/* Calling this function will print the sum of the diagonal
So we will need the following functions:
*/
int diag_sum(int matrix[], int len, int s);

/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    int length = argc - 2;
    int size = atoi(argv[1]);
    int matrix[argc - 1]; // size of matrix

    int j = 0, result;

    // converting all elements (except the first) of the argv array to a new array and making them integers 
    for(int i = 2; i < argc; i++)
    {
        matrix[j] = atoi(argv[i]);
        j++;
    }

    diag_sum(matrix, length, size); // calling the sum of diagonal

    return 0;
}

/* actual implementation of the functions */
int diag_sum(int matrix[], int len, int s)
{
    //statements
    int sum = 0, i = 0, j = 0;

    while(j < s) // while it has gone through the whole diagonal line
    {
        sum += *(matrix + i); // adding the number to the sum using pointers
        i += (s + 1);
        j++;
    }
    printf("%d\n", sum); // printing the sum of the diagonal array
    return 0;
}