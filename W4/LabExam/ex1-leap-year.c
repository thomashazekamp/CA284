/*
Author: Thomas Hazekamp
Date: 15/10/21
Description: Prints the leap years between the two given in argument line (inclusive)
*/
/* Relevant libraries  & description */
#include <stdio.h> // for input & output
#include <stdlib.h> // for atoi function

/* Function prototypes */
/* leap_calc will require the starting year and finishing year,
    it will then go through a certain ammount of steps to conclude if the year is a leap year,
    this function will only print the years which are leap years
So we will need the following functions:
*/
int leap_calc(int first, int second);

/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    int first_year = atoi(argv[1]); // converting the first number in command line to an integer
    int second_year = atoi(argv[2]); // converting the second number in command line to an integer

    leap_calc(first_year, second_year); // calling the leap calculator function to print all leap years

    return 0; // exiting the main function correctly
}

/* actual implementation of the functions */
int leap_calc(int first, int second)
{
    // renaming the arguments given for easier understanding
    int year = first;
    int last = second;

    // using a while loop to go through all the years between and including the given years
    while(year <= last)
    {
        if(year % 4 == 0) // if evenly divisible by 4
        {
            if(year % 100 == 0) // if evenly divisible by 100
            {
                if(year % 400 == 0) // if evenly divisible by 400
                {
                    printf("%d\n", year); // print the year
                    year++; // increment the year by one (following year)
                }
                else // if year is evenly not divisible by 400, move onto next year
                {
                    year++; // increment the year by one (following year)
                }
            }
            else // if year is not evenly divisible by 100, its a leap year
            {
                printf("%d\n", year); // print leap year
                year++; // increment the year by one (following year)
            }
        }
        else // if year is not evenly divisible by 4, then its automatically not a yeap year
        {
            year++; // increment the year by one (following year)
        }
    }
    
    return 0; // exit leap_calc function correctly
}