/* Include standard input and output */
#include <stdio.h>
#include <stdlib.h>
/*
Function: Main
Parameters: two measurements in cm
returns: float
description: Prints out the conversion of cm to inches
*/
int main(int argc, char*argv[])
{ /* Begin Function */

    float measurement_given;

    measurement_given = atof(argv[1]); /* atof is used to convert to float instead of using atoi for int */
    float conversion = measurement_given / 2.54;
    
    printf("The Ammount in Inches is: %.2f\n", conversion); /* Actual print statement */
    
    return (0);
    } /* End function and program*/