/*
Author: Thomas Hazekamp
Date: 25/11/2021
Description: This program takes values from the command line and prints the values which occur more than 3
times, it will print the values in ascending order.

NOTE: This program gives 2, 2, 2, 2 on personal laptop but not for the first test is einstein. But is wrong for following tests.

*/
/* Relevant libraries  & description */
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
/*
-> print_freq_array will print the items which occur more than 3 times
So we will need the following functions:
*/
void print_freq_array(int *pNumber_list, int length);
void bubble_sort(int *pFreq_list, int length);

/* main function */
int main(int argc, char * argv[])
{
    /* statments  and initialising the variables*/
    int *pNumber_list = NULL;
    int length = argc - 1;
    int initial_size = 5;

    pNumber_list = (int*)calloc(initial_size, sizeof(int)); // allocating memory for 5 integers
    if(!pNumber_list) // Catch for an error with memory
    {
        // This deals with memory allocation failure
        printf("Failed to allocate memory!\n");
        return 0;
    }

    // Setting up list and adding memory once its needed
    for (int i = 0; i < length; ++i)
    {
        // If we are still looking at integers within the first 5
        if (i < (initial_size))
        {
            *(pNumber_list + i) = atoi(argv[i + 1]); // Using pointers to assign the number
        }
        else // If we are over the 5 size limit we need to add more by using realloc function
        {
            int *pTemp = NULL;
            initial_size += 1; // Increasing size by 1

            pTemp = (int*)realloc(pNumber_list, initial_size * sizeof(int)); // Memory allocation for the temp vairable
            if(!pTemp) // Dealing with memory allocation failure
            {
                printf("Memory allocation failed for temporary value\n");
                free(pNumber_list);
                pNumber_list = NULL;
                return 0; // Exiting the function if given the error
            }

            pNumber_list = pTemp;
            *(pNumber_list + i) = atoi(argv[i + 1]);
        }
    }
    
    print_freq_array(pNumber_list, length); // Calling variable to print the relevant items from the list

    return 0; // Exiting the main function correctly
}

/* actual implementation of the functions */
void print_freq_array(int *pNumber_list, int length)
{
    //statements & initialisation
    int count, final_count;
    int *pFreq_list = NULL;
    int size = 1; // initial size of list

    pFreq_list = (int*)calloc(size, sizeof(int));
    if(!pFreq_list)
    {
        // This deals with memory allocation failure
        printf("Failed to allocate memory!\n");
        exit(0);
    }

    // Using a double for loop to check the count of each integer
    for (int i = 0; i < length; i++)
    {
        count = 1;
        for (int j = 1; j < length - i; j++)
        {
            if (*(pNumber_list + i) == *(pNumber_list + j))
            {
                count++;
            }
        }

        // If the integer occurs more than 3 times we add the amount to the new list
        if (count >= 4)
        {
            int *pTemp_freq = NULL;
            size += count; // Setting size
            pTemp_freq = (int*)realloc(pFreq_list, size * sizeof(int)); // Allocating more memory
            if(!pTemp_freq) // Testing for memory allocation failure
            {
                printf("There was an error allocating memory\n");
                free(pFreq_list);
                pFreq_list = NULL;
                exit(0);
            }

            pFreq_list = pTemp_freq; // Setting temp list to the new list
            // Adding correct amount of same new itegers to the list
            for (int v = 0; v < count; v++)
            {
                *(pFreq_list + v) = *(pNumber_list + i);
            }

            // Final count is the total size of this new list
            final_count += count;
        }
    }
    // bubble_sort(pFreq_list, final_count); // Calling bubble sort algo
    
    // Printing the frequency list one by one
    for(int i = 0; i < final_count - 1; ++i)
    {
        printf("%d\n", *(pFreq_list + i));
    }
    // NOTE: This program gives 2, 2, 2, 2 for the first test is einstein. But is wrong for following tests
}

void bubble_sort(int *pFreq_list, int length)
{
    // Statements & initialisation
    int temp;

    // Going through each iteger and check if the original is larger than the other, this sorts in ascending order
    for(int i = 0; i < length; i++)
    {
        for(int j = 1; i < length - i; j++)
        {
            if(*(pFreq_list + i) > *(pFreq_list + j))
            {
                temp = *(pFreq_list + i);
                *(pFreq_list + i) = *(pFreq_list + j);
                *(pFreq_list + j) = temp;
            }
        }
    }
}