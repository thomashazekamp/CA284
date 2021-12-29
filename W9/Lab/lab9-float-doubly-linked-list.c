/*
Author: Thomas Hazekamp
Date: 19/11/2021
Description: Forming a doubly linked list from command line arguments and printing the contents reversed
*/
/* Relevant libraries  & description */
#include <stdio.h>
#include <stdlib.h>


typedef struct LinkedList LinkedList; // The doubly linked list struct

struct LinkedList {
    float value;
    LinkedList *next;
    LinkedList *prev;
};


/* Function prototypes */
/* get_values creates the structs for the items
printLinkedListReversed starts from end of the linked list and prints the float values
So we will need the following functions:
*/
LinkedList* get_values(float *array, int length);
void printLinkedListReversed(LinkedList *last);
// etc...
/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    LinkedList *start = NULL;
    int num = atoi(argv[1]); // First number in arg line

    float arg_array[argc - 1]; // The size of the array which will hold all the command line arguments
    int length = argc - 1; // Length of the wanted command line integers
    int j = 0;

    // This for loop is making the command line arguments integers and adding them to an array
    for(int i = 2; i < argc; i++)
    {
        *(arg_array + j) = atof(argv[i]);
        j++;
    }

    start = get_values(arg_array, length); // Calls the function
    printLinkedListReversed(start); // Calls the printing function

    return 0; // Exits the function correctly
}

/* actual implementation of the functions */
LinkedList* get_values(float *array, int length)
{
    //statements
    LinkedList *current, *first, *prev; // Initializing the structs

    first = (LinkedList*)calloc(1, sizeof(LinkedList)); // This is mem allocation for the first item
    current = first;

    current->value = array[0]; // Setting the value

    current->prev = NULL; // Setting prev to NULL

    // Using this for loop to add all other values to the stuct
    for(int i = 1; i < length - 1; i++)
    {
        current->next = (LinkedList*)calloc(1, sizeof(LinkedList));

        prev = current;

        current = current->next;

        current->value = array[i];

        current->prev = prev;
    }
    current->next = NULL; // Setting last value to NULL, signifying end of the linked list
    return current; // Returning the last node of the doubly linked list
}

void printLinkedListReversed(LinkedList *last)
{
    LinkedList* p = NULL;
    for(p = last; p != NULL; p = p->prev)
    {
        printf("%.2f\n", p->value); // Printing each value with a newline
    }
}