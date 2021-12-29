/* Include standard input and output */
#include <stdio.h>
#include <stdlib.h>

/*
Function: Main
Parameters: int argc (argument count), char * argv[] an array of command-line arguments
returns: string of "*"
description: Prints out strings of a specified number of "*" to form an empty square
*/
int main(int argc, char*argv[])
{ /* Begin Function */

    // Initialise variable
    int number = 0;

    number = atoi(argv[1]); // Retreving number from command line list and making it an integer

    for(int j = 0; j < number; ++j)
    { // Prints first line of "*"
        printf("*");
    } 
    printf("\n");

    // This fist line ingnores the first and last line of the square
    for(int i = 0; i < (number - 2); ++i) // Prints the " " and "*" at the middle and end of each line
    {
        for(int j = 0; j < number; ++j) // Goes through each position of each line
        {
            if((j == 0) || (j == number - 1)) // first and last positions to print the "*" else print " "
                printf("*");
            else
                printf(" ");            
        }
        printf("\n"); // At end of each line add a new line character
    }

    for(int j = 0; j < number; ++j)
    { // prints last line of "*"
        printf("*");
    }
    printf("\n");

    return (0); // exit program correctly
    } /* End function and program*/