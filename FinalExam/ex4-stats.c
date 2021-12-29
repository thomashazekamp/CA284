/*
Author: Thomas Hazekamp
Date: 09/12/2021
Description: This program will output a certain integer or calculation depending on the last integer given in the command line.
The output can be: the largest number, the mode or the standard deviation of the array.
*/
/* Relevant libraries  & description */
#include <stdio.h> // For input and output
#include <stdlib.h> // For atoi function
#include <math.h> // used for pow and sqrt functions

/* Function prototypes */
/* 
-> get_max function prints the largest value of the array
-> get_mode function prints the most occuring value in the array
-> get_sd function prints the standard deviation of the array
So we will need the following functions:
*/
void get_max(int * num_array, int size);
void get_mode(int * num_array, int size);
void get_sd(int * num_array, int size);

/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    int num_array[argc - 2];
    int size = argc - 2;
    int j = 0;
    int stat_indicator = atoi(argv[argc - 1]);
    // Using pointer functions, pointing to the address of functions
    void (*pget_max)(int *, int) = &get_max;
    void (*pget_mode)(int *, int) = &get_mode;
    void (*pget_sd)(int *, int) = &get_sd;

    // Storing command line values into an array
    for(int i = 1; i < argc - 1; i++)
    {
        num_array[j] = atoi(argv[i]);
        j++;
    }

    // Using a switch statement
    switch(stat_indicator)
    {
        case 1: // If last element in command line is 1
            // Get max value
            (*pget_max)(num_array, size); // Calling a pointer function
            break;
        case 2: // If last element in command line is 2
            // Get mode (most frequent value)
            (*pget_mode)(num_array, size); // Calling a pointer function
            break;
        case 3: // If last element in command line is 3
            // Get standard deviation
            (*pget_sd)(num_array, size); // Calling a pointer function
            break;
        default: // If last element in command line is anything other than the above digits
            // Get max value
            (*pget_max)(num_array, size); // Calling a pointer function
            break;
    }
    return 0; // Exiting the function correctly
}

/* actual implementation of the functions */
// Prints the largest number in the array
void get_max(int * num_array, int size)
{
    //statements
    int max_num = num_array[0];

    // Using a for loop to copare and find the largest value
    for (int i = 1; i < size; i++)
    {
        if (num_array[i] > max_num)
        {
            max_num = num_array[i];
        }
    }
    printf("%d\n", max_num); // Printing the largest value
}

// Prints the most occuring value in the array
void get_mode(int * num_array, int size)
{
    //statements
    int most_common_num = -1;
    int freq = 0;
    int count;

    // Using a douple loop to find most common integer
    for(int i = 0; i < size; i++)
    {
        count = 1;
        for(int j = 0; j < size; j++)
        {
            if(num_array[i] == num_array[j]) // Checking to increase the count, if numbers are same
            {
                count++;
            }
        }
        if(count > freq) // Setting the highest count number and changing the varable if passed
        {
            freq = count;
            most_common_num = num_array[i];
        }
    }
    printf("%d\n", most_common_num); // Printing the mode as the output
}

// Printing the standard deviation of the array
void get_sd(int * num_array, int size)
{
    //statements
    float mean;
    float sd = 0.0;
    float sum_nums = 0.0;

    // For loop used to get sum of all elements in the array
    for (int i = 0; i < size; i++)
    {
        sum_nums += num_array[i];
    }

    // Mean of the array (average value)
    mean = sum_nums / size;

    // Calculating the standard deviation of the array
    for (int i = 0; i < size; i++)
    {
        sd += pow(num_array[i] - mean, 2); // pow() is used for "the power of" 2 in this case
    }
    printf("%.2f\n", sqrt(sd / size)); // Printing the standard deviation as output
}