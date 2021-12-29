/*
Author: Thomas Hazekamp
Date: 07/10/21
Description: Dividing or multiplying two float numbers
*/
/* Relevant libraries  & description */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function prototypes */
/* Functions to multiply and divide
So we will need the following functions:
*/
float multiply_calc(float first, float second);
float divide_calc(float first, float second);
// etc...

/* main function */
int main(int argc, char *argv[])
{
    /* Initilise variables */
    char calculation[] = "not done";
    float first_number = 0.0;
    float second_number = 0.0;

    float result = 0;

    char multi_str[] = "multiply";
    char div_str[] = "divide";

    strcpy(calculation, argv[1]);
    first_number = atof(argv[2]);
    second_number = atof(argv[3]);

    if(strcmp(calculation, multi_str) == 0)
    {
        result = multiply_calc(first_number, second_number);
    }

    if(strcmp(calculation, div_str) == 0)
    {
        result = divide_calc(first_number, second_number);
    }

    printf("%f\n", result);
    return 0;
}

/* actual implementation of the functions */
float multiply_calc(float first, float second)
{
    // Initialise variable
    float result = 0.0;

    result = first * second;
    return result;
}

float divide_calc(float first, float second)
{
    // Initialise variable
    float result = 0.0;

    if(second == 0.0)
    {
        printf("invalid\n");
        exit(0);
    }
    else
    {
        result = first / second;
    }

    return result;
}
