/*
Author: Thomas Hazekamp
Date: 08/11/2021
Description: Prints the longest strings from command line
*/
/* Relevant libraries  & description */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Function prototypes */
/* This function returns either a 0 or the largest number to signify it has/has not found a correct number (being atleast twice the size of another number)
So we will need the following functions:
*/

/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    int length = argc - 1; // length of numbers to add to a new list
    char *pStrings = NULL;
    //int *pResult = NULL;
    int j = 0;

    pStrings = (char*)malloc(length*(sizeof(char)));
    if(!pStrings)
    {
        // Code to deal with memory allocation failure
        printf("Failed to allocate memory!");
        return 0;
    }

    // Adding relevant argument line numbers to a list
    for(int i = 1; i < argc; i++)
    {
        //*(pStrings + j) = argv[i];
        if(strlen(argv[i]) == 6)
        {
            printf("%s\n", argv[i]);
        }
        j++;
    }

    //pResult = (int*)malloc(1*(sizeof(int))); // Allocating the size of memory
    //*pResult = largest_twice(pNumbers, length);

    printf("%c\n", *pStrings);

    // Free the memory
    //free(pResult);
    free(pStrings);

    return 0;
}

/* actual implementation of the functions */