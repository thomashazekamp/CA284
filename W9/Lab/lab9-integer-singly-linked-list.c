/*
Author: Thomas Hazekamp
Date: 19/11/2021
Description: Forming a singly linked list from command line arguments
*/
/* Relevant libraries  & description */
#include <stdio.h>
#include <stdlib.h>


typedef struct LinkedList LinkedList;

struct LinkedList {
    int value;
    LinkedList *next;
};


/* Function prototypes */
/* ... description
So we will need the following functions:
*/
LinkedList* get_values(int *array, int length);
void printLinkedList(LinkedList *start);
// etc...
/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    LinkedList *start = NULL;
    int num = atoi(argv[1]);

    int arg_array[argc - 1]; // The size of the array which will hold all the command line arguments
    int length = argc - 1; // Length of the wanted command line integers
    int j = 0;

    // This for loop is making the command line arguments integers and adding them to an array
    for(int i = 2; i < argc; i++)
    {
        *(arg_array + j) = atoi(argv[i]);
        j++;
    }

    start = get_values(arg_array, length); // Calls the function
    printLinkedList(start); // Calls the printing function

    return 0;
}

/* actual implementation of the functions */
LinkedList* get_values(int *array, int length)
{
    //statements
    LinkedList *current, *first; // Initializing the structs

    first = (LinkedList*)calloc(1, sizeof(LinkedList)); // This is mem allocation for the first item
    current = first;

    current->value = array[0]; // Setting the value

    // Using this for loop to add all other values to the stuct
    for(int i = 1; i < length - 1; i++)
    {
        current->next = (LinkedList*)calloc(1, sizeof(LinkedList));
        current = current->next;

        current->value = array[i];
    }
    current->next = NULL; // Setting last value to NULL, signifying end of the linked list
    return first; // Returning the head of the linked list
}

void printLinkedList(LinkedList *start)
{
    LinkedList* p = NULL;
    for(p = start; p != NULL; p = p->next)
    {
        printf("%d\n", p->value); // Printing each value with a newline
    }
}