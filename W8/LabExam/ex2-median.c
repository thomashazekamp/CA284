/*
Author: Thomas Hazekamp
Date: 11/11/2021
Description: This program prints out the center numbers of a given list in the command line by sorting it and outputting the center integers.
*/
/* Relevant libraries  & description */
#include <stdio.h> // For input and output
#include <stdlib.h> // For atoi function

/* Function prototypes */
/* 
-> bubble_sort will be used to sort the array of integers
-> swap_pass_by_reference will be used to swap values using pass by reference mechanism
-> center_number will be used to find and print out the middle value(s)
So we will need the following functions:
*/
int bubble_sort(int *array, int length);
void swap_pass_by_reference(int *a, int *b);
void center_numbers(int *array, int length);

/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    int arg_array[argc - 1]; // The size of the array which will hold all the command line arguments
    int length = argc - 1; // Length of the wanted command line integers
    int j = 0;

    // This for loop is making the command line arguments integers and adding them to an array
    for(int i = 1; i < argc; i++)
    {
        *(arg_array + j) = atoi(argv[i]);
        j++;
    }

    bubble_sort(arg_array, length); // Sorting the command line array

    center_numbers(arg_array, length); // This will find the center numbers and print them out line by line

    return 0; // Exiting the main function correctly
}

/* This function bubble_sort is using the popular bubble sorting algorithm to sort a given array*/
int bubble_sort(int *array, int length)
{
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < (length - 1); j++)
        {
            if(*(array + j) > *(array + j + 1))
            {
                swap_pass_by_reference(&*(array + j), &*(array + j + 1)); // Calling this function will swap the addresses
            }
        }
    }

    return 0;
}

// Swaping the address of a and b
void swap_pass_by_reference(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Printing out the middle integers
void center_numbers(int *array, int length)
{
    int first_middle, second_middle;
    int middle_index = length / 2; // This is the middle of the array (index)

    first_middle = *(array + middle_index - 1); // The first middle integer
    second_middle = *(array + middle_index); // The second middle integer

    printf("%d\n%d\n", first_middle, second_middle); // Printing line by line the two middle integers
}