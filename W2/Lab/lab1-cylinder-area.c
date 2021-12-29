/* Include standard input and output */
#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415 // Defining pi as a constant

/*
Function: Main
Parameters: int argc (argument count), char * argv[] an array of command-line arguments
returns: float (area of cylider)
description: Given the radius and height, it prints the area
*/
int main(int argc, char * argv[])
{ /* Begin Function */
    // Variable initialisation
    int radius = 0;
    int height = 0;
    float area = 0;

    if (argc == 1){ // If the measurements aren't given it will print the following and exit the program
        printf("No input given!\n");
        return(0);
    }

    if (argc == 2) { // If only one of the two measurements are given it will print the following and exit program
        printf("Two arguments needed!\n");
        return(0);
    }

    // Turning the command line inputs to integers
    radius = atoi(argv[1]);
    height = atoi(argv[2]);

    if (radius < 0 || height < 0){ // If one or the other arguments is negative it will print the following and exit the program
        printf("The radious or height cannot be negative!\n");
        return(0);
    }

    int radius_squared = radius*radius; // radius squared variable

    area = (2*PI*radius*height) + (2*PI*radius_squared); // Cylinder formula for finding area

    printf("%.2f\n", area); /* Actual print statement */
    return (0); // exit correctly
    } /* End function and program*/