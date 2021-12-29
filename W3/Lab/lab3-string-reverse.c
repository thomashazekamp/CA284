/*
Author: Thomas Hazekamp
Date: 07/10/21
Description: Reversing a string
*/
/* Relevant libraries  & description */
#include <stdio.h>
#include <string.h>

void reverse_string(char *string);

/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    char string[50];

    strcpy(string, argv[1]);

    reverse_string(string);

    printf("%s\n", string);

    return 0; // exit main function correctly
}

void reverse_string(char *string)
{
    int i, temp, length;
    length = strlen(string);

    for(i = 0; i < length/2; i++)
    {
        temp = string[i]; // making i letter a temp
        string[i] = string[length - i - 1]; // following is the swapping of letters
        string[length - i - 1] = temp;
    }
}