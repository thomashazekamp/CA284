/*
Author: Thomas Hazekamp
Date: 23/10/21
Description: Given a character and a string, it will count the number of times the given char is in the string
*/
/* Relevant libraries  & description */
#include <stdio.h> // for input and output
#include <string.h> // used for strchr() function

/* Function prototypes */
/* The function will be used to get the certain number of counts of the char
So we will need the following functions:
*/
int count_return(char *letter, char *line);

/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    char *letter = argv[1];
    char *line = argv[2];
    int result;

    // printf("%s, %s\n", letter, line);
    result = count_return(letter, line);
    printf("%d\n", result);

    return 0;
}

/* actual implementation of the functions */
int count_return(char *letter, char *line)
{
    //statements
    char *pCount_char = line;
    int count = 0;

    while((pCount_char = strchr(pCount_char, *letter))) // this is a loop which will go until it becomes NULL
    {
        ++count;
        ++pCount_char;
    }

    return count; // returning the count
}