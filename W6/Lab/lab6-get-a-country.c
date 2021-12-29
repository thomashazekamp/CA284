/*
Author: Thomas Hazekamp
Date: 28/10/2021
Description: Reading data from command line, using struct prints out the country details
*/
/* Relevant libraries  & description */
#include <stdio.h>
#include <stdlib.h> // for atoi and atof functions

/* Function prototypes */
/* Defining type
So we will need the following functions:
*/
typedef struct Location Location;

struct Location // Structure type definition
{
    char *country;
    char *capital;
    float population;
    int size;
};

/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    Location location1;

    location1.country = argv[1];
    location1.capital = argv[2];
    location1.population = atof(argv[3]);
    location1.size = atoi(argv[4]);

    //printf("%s", first);
    printf("%s\n%s\n%.2f million people\n%d km2\n", location1.country, location1.capital, location1.population, location1.size);


    return 0;
}