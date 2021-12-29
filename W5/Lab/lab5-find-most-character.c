/*
Author: Thomas Hazekamp
Date: 24/10/21
Description: Finding the most common occuring character in a string
*/
/* Relevant libraries  & description */
#include <stdio.h> // for input and output
#include <string.h> // for strlen funciton
#include <ctype.h> // for isalpha function

/* Function prototypes */
/* max_occuring finds the most occuring char in the stirng
So we will need the following functions:
*/
char max_occuring(char *string);

/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    char *string = argv[1];
    char result;

    result = max_occuring(string);
    printf("%c\n", result);

    return 0;
}

/* actual implementation of the functions */
char max_occuring(char *string)
{
    //statements
    int len, i;
    int max_n = -1;
    char final;
    
    int amount_table[256] = {0}; // max amount of different chars which could be inputted
    len = strlen(string);

    // adding each char to the amout_table and setting the initail frequency to 1
    for(i = 0; i < len; i++)
    {
        if(isalpha(string[i])) // check if the char is lower or upper case
        {
            amount_table[string[i]]++; // increment the frequency by 1
        }
    }

    i = 0;
    while(i < len) // going through the string
    {
        if(isalpha(string[i])) // checking that the char is a lower or uppercase letter, i.e do not want " " (spaces)
        {
            if(max_n < amount_table[string[i]])
            {
            max_n = amount_table[string[i]];
            final = string[i];
            }
        }
        i++;
    }
    return final;
}