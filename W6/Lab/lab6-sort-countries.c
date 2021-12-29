/*
Author: Thomas Hazekamp
Date: 29/10/21
Description: Reading data of a list of countries from command line argument and printing all
*/
/* Relevant libraries  & description */
#include <stdio.h> // for input and output
#include <stdlib.h> // for atof and atoi functions

/* Function prototypes */
/* ... description
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
void bub_sort(Location list[50], int size);

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

    bub_sort(location, lcount); // calling bubble sort to sort the countries by highest population first (Descending order)

    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n"); // printing top of the table

    // looping to print each country individually
    int count = 0;
    for(int i = 0; i < lcount; i++)
    {
        location_print(location[count].country, location[count].capital, location[count].population, location[count].size); // calling function to print each country
        count++;
    }

    return 0; // exiting the main function correctly
}

/* prints the country one at a time*/
void location_print(char *country, char *cap, float pop, int s)
{
    // the country print
    printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", country, cap, s, pop);
}

// This function sorts by using bubble sort
void bub_sort(Location location[50], int size)
{
    int i = 0;
    int j = 0;
    //int a = 1;
    Location temp;

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < (size - 1); j++)
        {
            if(location[j].population < location[j + 1].population)
            {
                temp = location[j];
                location[j] = location[j + 1];
                location[j + 1] = temp;
            }
            //a++;
        }
    }

}