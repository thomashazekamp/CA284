/* 
circle-area.c
author: Thomas Hazekamp
*/

/* includes */
#include <stdio.h>
#include <stdlib.h> // contains functions we may need 

#define PI 3.1415 // defining PI as a constant

/*
Function: Main
Parameters: int argc (argument count), char * argv[] an array of command-line arguments
returns: float (area of circle)
description: Takes a single argument and computes area of circle
*/

int main(int argc, char * argv[])
{ /* Begin Function */
// variable initialisation 
    int radius = 0;
    float area = 0.0;
// all command-line arguments come in as character strings, so atoi turns them into ints
    radius = atoi(argv[1]);

    /*if (radius < 0){ // fixing the data inputted to a positive number
        radius = abs(radius);
    }*/
    
    /* if (radius < 0){ // this if statement prints a string warning user of incompatibility and exits the program
        printf("You have typed an incompatible number\n");
        exit(0);
    } */

    radius = radius*radius; // radius squared
    
    area = radius*PI; // calculates area of circle

    // print to two decimal places
    printf("%.2f\n", area); // we only want to show two values to the right of the decimal point

    /* printf("%9.2f\n", area); */ // we want to set the width of the shown number = 9. If the total number of digits < 9, spaces will be shown before the number

    return (0); // exit correctly
    } /* End function and program*/