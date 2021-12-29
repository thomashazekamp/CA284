/* Include standard input and output */
#include <stdio.h>
#include <stdlib.h>

/*
Function: Main
Parameters: int argc (argument count), char * argv[] an array of command-line arguments
returns: char, day of the week
description: Prints out the corresponding day of the week
*/
int main(int argc, char * argv[])
{ /* Begin Function */

    // Initialise variable
    int number = 0;

    // Makes command line number an integer
    number = atoi(argv[1]);

    // For Sunday
    if(number == 1)
    {
        printf("Sunday\n");
    }
    // For Monday
    if(number == 2)
    {
        printf("Monday\n");
    }
    // For Tuesday
    if(number == 3)
    {
        printf("Tuesday\n");
    }
    // For Wednesday
    if(number == 4)
    {
        printf("Wednesday\n");
    }
    // For Thursday
    if(number == 5)
    {
        printf("Thursday\n");
    }
    // for Friday
    if(number == 6)
    {
        printf("Friday\n");
    }
    // For Saturday
    if(number == 7)
    {
        printf("Saturday\n");
    }
    
    return (0); // Exit correctly
    } /* End function and program*/