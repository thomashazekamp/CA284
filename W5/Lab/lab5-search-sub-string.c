/*
Author: Thomas Hazekamp
Date: 26/10/21
Description: Outputs the positions of the first and last letter of the founc word
*/
/* Relevant libraries  & description */
#include <stdio.h> // for input and output
#include <string.h> // for strstr() function & strlen() function

/* Function prototypes */
/* If there is a substring the function will print out the position of the first and last character
So we will need the following functions:
*/
int find_pos(char *fir, char *sec);

/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    char *first = argv[1]; // getting the two strings
    char *second = argv[2];
    
    find_pos(first, second); // calling the function


    return 0;
}

/* actual implementation of the functions */
int find_pos(char *fir, char *sec)
{
    //statements
    char *pFound = NULL;
    int pos, final_pos;

    if(strstr(fir, sec)) // checking if the second string is a substring of the first
    {
        char *pFound = strstr(fir, sec); // pFound becomes the address of the first letter of the substring
        int pos = pFound - fir; // subtracting the address of first char in substring (will be larger) from the address of the first letter in the string we are looking at
        int final_pos = (pos + strlen(sec)) - 1; // this final position is attained by having the index of first char in substring plus the rest of number of chars in the substring
        printf("%d %d\n", pos, final_pos); // printing result
    }
    return 0; // exiting the function correctly
}