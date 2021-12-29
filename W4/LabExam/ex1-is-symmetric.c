/*
Author: Thomas Hazekamp
Date: 15/10/21
Description: The output gives "yes" or "no" depending on whether the string is symmetric or not
*/
/* Relevant libraries  & description */
#include <stdio.h>
#include <string.h>

// this reverse_string function reverses the string which will then be used to compare with original
void reverse_string(char *string);

/* main function */
int main(int argc, char * argv[])
{
    /* initialising variables */
    char string[50];
    char original_string[50];

    strcpy(string, argv[1]); // making string == the argument line string

    strcpy(original_string, argv[1]); // making a copy of the argument line string

    reverse_string(string); // reversing the string

    // comparing if the reversed string is the same as the original string
    if(strcmp(string, original_string) == 0)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }

    return 0; // exit main function correctly
}
// function used to reverse a string
void reverse_string(char *string)
{
    // initialising the variables
    int i, temp, length;
    length = strlen(string); // getting length of string

    // this loop is used to replace individually each letter and reverse the string
    for(i = 0; i < length/2; i++)
    {
        temp = string[i]; // making i letter a temp
        string[i] = string[length - i - 1]; // following is the swapping of letters
        string[length - i - 1] = temp;
    }
}