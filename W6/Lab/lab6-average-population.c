/*
Author: Thomas Hazekamp
Date: 29/10/21
Description: Printing all countries and the average population
*/
/* Relevant libraries  & description */
#include <stdio.h> // for input and output
#include <stdlib.h> // for atof and atoi functions

/* Function prototypes */
/* To be able to acquire and print the needed results
So we will need the following functions:
*/
typedef struct Location Location;

struct Location
{
    char *country;
    char *capital;
    float population;
    int size;
};
// This function will print out each Country specified
void location_print(char *country, char *cap, float pop, int s);

void avg_pop_print(float sum, int c_count);

/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    Location location[50];
    int lcount = 0;

    for(int i = 1; i < argc; i += 4)
    {
        location[lcount].country = argv[i];
        location[lcount].capital = argv[i + 1];
        location[lcount].population = atof(argv[i + 2]);
        location[lcount].size = atoi(argv[i + 3]);

        lcount++;
    }

    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n"); // printing top of the table

    // looping to print each country individually
    int count = 0;
    float pop_sum = 0.0;
    for(int i = 0; i < lcount; i++)
    {
        location_print(location[count].country, location[count].capital, location[count].population, location[count].size); // calling function to print each country
        pop_sum += location[count].population;
        count++;
    }
    avg_pop_print(pop_sum, lcount);

    return 0;
}

/* This function prints each Countries Information*/
void location_print(char *country, char *cap, float pop, int s)
{
    // the country print
    printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", country, cap, s, pop);
}

// This function prints the final average population
void avg_pop_print(float sum, int c_count)
{
    float average_sum;

    average_sum = sum / c_count;
    
    printf("Population average: %.2f\n", average_sum);
}