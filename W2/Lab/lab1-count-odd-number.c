/* Include standard input and output */
#include <stdio.h>
#include <stdlib.h> // Used for atoi function
/*
Function: Main
Parameters: int argc (argument count), char * argv[] an array of command-line arguments
returns: int
description: Prints out the number of odd numbers in the command line argument
*/
int main(int argc, char*argv[])
{ /* Begin Function */

    // Initialise variable
    int count = 0;
    int number = 0;

    for(int i = 1; i < argc; ++i) // This for loop is used to go through all numbers in the argv list
    {
        number = atoi(argv[i]); // This is taking a single number turned into an integer for i times(for the length of the array)

        if((number % 2) != 0){ // Using the modulus it calculates if it is even or odd(in this case odd)
            count += 1;
        }
    }
    printf("%d\n", count); /* Actual print statement */
    return (0); // exit function correctly
    } /* End function and program*/