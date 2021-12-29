/*
Author: Thomas Hazekamp
Date: 11/11/2021
Description: This program will output the sum of the anti diagonal values in a 2D matrix
*/
/* Relevant libraries  & description */
#include <stdio.h> // Used for input and output
#include <stdlib.h> // Used for atoi function

/* Function prototypes */
/*
-> sum_anti_diag is a function used to find the final sum of the anti diagonal of the 2D matrix, it returns an integer
So we will need the following functions:
*/
int sum_anti_diag(int (*pMatrixArray)[100], int size);

/* main function */
int main(int argc, char* argv[]) 
{
    /* statments */
	int matrix_array[100][100]; // Setting max size of the 2D matrix
	int (*pMatrixArray)[100] = matrix_array; // Using pointers for the matrix array
    int size;
    
    size = atoi(argv[1]); // This will be the size of the matrix (size x size)

    // This loop is creating the 2D matrix
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			*(*(pMatrixArray + i) + j) = atoi(argv[(i * size) + j + 2]); // atoi converts command line value to an integer


	printf("%d\n", sum_anti_diag(pMatrixArray, size)); // Calling the function to get the final sum value and print

	return 0; // Exiting the function correctly
}

/* actual implementation of the functions */
// Function used to find the final sum of the anti diagonal of the 2D matrix, it returns an integer
int sum_anti_diag(int (*pMatrixArray)[100], int size)
{
    // Statements
	int final_sum = 0;
	int *pSumFinal = &final_sum; // This pointer points to the address of final_sum
    int j = 0; // Used to move through each row of the matrix

    // This loop is starting from the end of the column, j is incremented by 1 to move through each row
	for (int i = (size - 1); i >= 0; i--)
    {
		*pSumFinal += *(*(pMatrixArray + j) + i); // Using pointers only, this gets the actual value of the each antidiagonal number
        j++;
    }
	return *pSumFinal; // Returning the pointer of pSumFinal which is pointing to the address of sum, in the end this will return the final vaule of the sum
}