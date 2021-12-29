/*
Author: Thomas Hazekamp
Date: 25/11/2021
Description: Takes items from command line and adds them to a doubly linked list, 
then it removes the even numbers from linked list, 
then gets the sum of remaining numbers and add to the linked list
*/
/* Relevant libraries  & description */
#include <stdio.h> // For input and output
#include <stdlib.h> // For the atoi() function

// The linked list structure
typedef struct LinkedList LinkedList;

struct LinkedList {
    int value;
    LinkedList *next;
    LinkedList *prev;
};

/* Function prototypes */
/* 
-> getList creates the linked list
-> print_resulting_list prints the end result with the remaining list components and the total sum
-> remove_even removes even numbers from the linked list
-> add_total get the total of all the numbers remaining and adds the sum to the linked list
So we will need the following functions:
*/
LinkedList* getList(int length, char * argv[]);
void print_resulting_list(LinkedList *first);
LinkedList* remove_even(LinkedList *first);
LinkedList* add_total(LinkedList *first);

/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    int length = argc - 1;
    LinkedList* first = NULL;

    first = getList(length, argv); // Creates the linked list using command line
    first = remove_even(first); // Removes all the even numbers
    first = add_total(first); // Adds the total sum of numbers remaining to the linked list
    print_resulting_list(first); // Prints each elements of linked list

    return 0; // Exiting the function correctly
}

/* actual implementation of the functions */
LinkedList* getList(int length, char * argv[])
{
    //statements
    LinkedList *current, *first, *prev; // Initializing the structs

    first = (LinkedList*)calloc(1, sizeof(LinkedList)); // This is mem allocation for the first item
    current = first;

    current->value = atoi(argv[1]); // Setting the value

    current->prev = NULL;

    // Using this for loop to add all other values to the stuct
    for(int i = 2; i < length + 1; i++)
    {
        if(atoi(argv[i]) % 2 == 0 && i == length) // If last element is an even integer, ignore it
        {
            current->next = NULL;
            return first; // This means we are at the end of the linked list and we want to return the first item
        }

        // Getting memory and setting appropriate values
        current->next = (LinkedList*)calloc(1, sizeof(LinkedList));

        prev = current;

        current = current->next;

        current->value = atoi(argv[i]); // Using atoi to convert string into integer

        current->prev = prev;
    }
    current->next = NULL; // Setting last value to NULL, signifying end of the linked list
    return first; // Returning the head of the linked list
}
// Removes all even integers from linked list
LinkedList* remove_even(LinkedList *first)
{
    // Statements & initialisation
    LinkedList *p = first;
    LinkedList *temp = NULL;

    // Removing even integers if they are first in the linked list
    while (first->value % 2 == 0)
    {
        temp = first->next;
        free(first); // Freeing memory
        first = temp;
    }

    // Removing even values from the linked list
    for (p = first; p != NULL; p = p->next)
    {
        if(p->value % 2 == 0) // If the value is even we remove from linked list by freeing memory and changing pointers
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            temp = p->prev;
            free(p); // Freeing memory
            p = temp;
            
        }
    }
    return first; // Returning the first item in linked list
}
// Adding total to the linked list
LinkedList* add_total(LinkedList *first)
{
    // Initialise variables
    LinkedList* p = NULL;
    LinkedList* temp = NULL;
    int total = 0;

    // Getting the total sum of odd integers
    for(p = first; p != NULL; p = p->next)
    {
        total += p->value; // Adding each item from linked list to the total
        // Checking if p is the last pointer, so we can add the total sum at end of linked list
        if(p->next == NULL)
        {
            p->next = (LinkedList*)calloc(1, sizeof(LinkedList)); // Allocating memory for the sum integer

            // The following is setting the variables for the sum item
            temp = p->prev;
            p = p->next;
            p->value = total;
            p->next = NULL;
            p->prev = temp;
            break;
        }
    }
    return first; // Returning the first item in the linked list
}

// Printing the linked list, line by line
void print_resulting_list(LinkedList *first)
{
    // Statements & initialisation
    LinkedList* p = NULL;

    // Printing each item in the linked list
    for (p = first; p != NULL; p = p->next)
    {
        printf("%d\n", p->value);
    }
}