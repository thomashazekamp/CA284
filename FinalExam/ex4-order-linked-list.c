/*
Author: Thomas Hazekamp
Date: 10/12/2021
Description: This program adds floats to a doubly linked list, then prints 1 or 0 as the output. Prints 1 if the list is in desceding order, 0 if not. 
*/
/* Relevant libraries  & description */
#include <stdio.h> // For input and output
#include <stdlib.h> // For the atof() function

// The linked list structure
typedef struct LinkedList LinkedList;

struct LinkedList {
    float value;
    LinkedList *next;
    LinkedList *prev;
};

/* Function prototypes */
/* 
-> getList creates the linked list with values from command line
-> printResult moves through the linked list and checks if the previous value is greater than the next, prints 0 if the linked list is not in descending order. Prints 1 if it is.
So we will need the following functions:
*/
LinkedList* getList(int length, char * argv[]);
void printResult(LinkedList *first);

/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    int length = argc - 1;
    LinkedList* first = NULL;

    first = getList(length, argv); // Creates the linked list using command line
    printResult(first); // Prints each elements of linked list

    return 0; // Exiting the function correctly
}

/* actual implementation of the functions */
LinkedList* getList(int length, char * argv[])
{
    //statements
    LinkedList *current, *first, *prev; // Initializing the structs

    first = (LinkedList*)calloc(1, sizeof(LinkedList)); // This is mem allocation for the first item
    current = first;

    current->value = atof(argv[1]); // Setting the value

    current->prev = NULL;

    // Using this for loop to add all other values to the stuct
    for(int i = 2; i < length + 1; i++)
    {
        // Getting memory and setting appropriate values
        current->next = (LinkedList*)calloc(1, sizeof(LinkedList));

        prev = current;

        current = current->next;

        current->value = atof(argv[i]); // Using atof to convert string into integer

        current->prev = prev;
    }

    current->next = NULL; // Setting last value to NULL, signifying end of the linked list
    
    return first; // Returning the head of the linked list
}
// Printing the result of the linked list (1 if its descending, 0 if not)
void printResult(LinkedList *first)
{
    // Statements & initialisation
    LinkedList* p = first;

    // Moving through each item in the linked list to check
    for (p = p->next; p != NULL; p = p->next)
    {
        if(p->prev->value < p->value) // If the previous item is smaller than the current, then it is not in descending order
        {
            printf("0\n");
            exit(0); // Exit function succesfully
        }
    }
    printf("1\n"); // Printing 1 if the comparison of each element was in order
}