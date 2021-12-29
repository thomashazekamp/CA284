/*
Author: Thomas Hazekamp
Date: 11/11/2021
Description: This program will output 1 or 0 signifying a status for attendance or absence respectively 
*/
/* Relevant libraries  & description */
#include <stdio.h> // Used for input and output
#include <string.h> // Used for strlen function

/* Function prototypes */
/*
-> attendance_check will count the number of A's in the record, then will call the count_result function
-> count_result uses pointers to add the correct status to a status array
-> status_attendance_print prints line by line the status for each students record
So we will need the following functions:
*/
void attendance_check(char *string, int *status_array, int j);
void count_result(int final_count, int *status_array, int j);
void status_attendance_print(int *status_array, int size);

/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    int status_array[argc - 1];
    int j = 0;
    int size = argc - 1;

    // Looping through the argument line and calling attendance_check to find the count of A's
    for(int i = 1; i < argc; i++)
    {
        attendance_check(argv[i], status_array, j);
        j++; // j is used to keep track of which index the attendance status should be put in the status_array
    }

    status_attendance_print(status_array, size); // This will finally print all of the students status line by line

    return 0; // Exiting the main function correctly
}

/* actual implementation of the functions */
// Will count the number of A's in the record, then will call the count_result function
void attendance_check(char *string, int *status_array, int j)
{
    //statements
    int count = 0;
    char *a = "A";

    // Checks each character in the string if it is an A and uses ASCII & pointers to determine if the char is equal to A
    for(int i = 0; i < strlen(string); i++)
    {
        char look_char = string[i];
        if(*a == look_char)
        {
            count++; // count increments by 1 if "A" has been found
        }
    }
    count_result(count, status_array, j); // Calling this function will send the final count of the students attendance record
}
// Uses pointers to add the correct status to a status array
void count_result(int final_count, int *status_array, int j)
{
    // If there were more than 2 A's then this means the attendance status for this student is 0 else the status is 1
    // Using pointers it modifies the resulting index to 1 or 0 (status)
    if(final_count > 2)
    {
        *(status_array + j) = 0;
    }
    else
    {
        *(status_array + j) = 1;
    }
}
// Prints line by line the status for each students record
void status_attendance_print(int *status_array, int size)
{
    // Going through each value line by line and using pointers to print the students status
    for(int i = 0; i < size; i++)
    {
        printf("%d\n", *(status_array + i));
    }
}