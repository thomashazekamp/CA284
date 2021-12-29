/*
Author: Thomas Hazekamp
Date: 24/10/21
Description: Get a result to multiple operations
*/
/* Relevant libraries  & description */
#include <stdio.h> // for input and output
#include <stdlib.h> // for atoi function
#include <math.h> // for pow function

/* Function prototypes */
/* each of the following functions are used for the different operations
So we will need the following functions:
*/
float sum(int, int);
float product(int, int);
float difference(int, int);
float division(int, int);
float power(int, int);
float logarithmic(int, int);
float call_function(float(*pOper)(int, int), int x, int y);

/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    int first = atoi(argv[1]); // converting both given numbers into ints
    int second = atoi(argv[2]);
    float result = 0;
    float (*pOper)(int, int) = NULL;

    // passing a pointer to a sum function
    pOper = sum;
    result = call_function(pOper, first, second);
    printf("%.2f\n", result);

        // passing a pointer to a difference function
    pOper = difference;
    result = call_function(pOper, first, second);
    printf("%.2f\n", result);

        // passing a pointer to a product function
    pOper = product;
    result = call_function(pOper, first, second);
    printf("%.2f\n", result);

    // passing a pointer to a product division function
    pOper = division;
    result = call_function(pOper, first, second);
    printf("%.2f\n", result);

    // passing a pointer to a product power function
    pOper = power;
    result = call_function(pOper, first, second);
    printf("%.2f\n", result);

    // passing a pointer to a product logarithmicfunction
    pOper = logarithmic;
    result = call_function(pOper, first, second);
    printf("%.2f\n", result);

    //printf("%d, %d\n", first, second);

    return 0;
}

/* actual implementation of the functions */
float call_function(float(*pOper)(int, int), int x, int y)
{
    //statements
    return pOper(x, y);
}

// definition of the function sum
float sum(int x, int y)
{
    return x + y;
}
// Definition of the function product
float product(int x, int y)
{
    return x * y;
}
// Definition of the function difference
float difference(int x, int y)
{
    return x - y;
}
// Definition of the function division
float division(int x, int y)
{
    return x / y;
}
// Definition of the function power
float power(int x, int y)
{
    return pow(x, y);
}
// Definition of the function logarithmic
float logarithmic(int x, int y)
{
    return log(x) + log(y);
}