/*
Author: Thomas Hazekamp
Date: 09/12/2021
Description: This program stores information about items in a cart. The status is initially set to 0,
the status is set to 1 if the sales of the item is more or equal to the average sales of all items in the cart.
The program finally prints the status and the country name of each item in the cart.
*/
/* Relevant libraries  & description */
#include <stdio.h> // For output & input
#include <stdlib.h> // Used for atoi function
#include <string.h> // Used for strcpy(), strcmp() and strncpy() functions

// The Item information structure, incorporating a linked list
typedef struct Item Item;

struct Item {
    char item_code[20];
    float price;
    int sold_items;
    int status;
    Item *next;
    Item *prev;
};
/* Function prototypes */
/* 
-> add_items is used to initially add all the items information from command line arguments
-> modify_items is used to get the average sales for all items and changes the status for each item if their sales are higher or equal to the average sales.
-> print_items prints as an output the status & country name (taken from country code) line by line.
So we will need the following functions:
*/
Item* add_items(int length, char * argv[]);
Item* modify_items(Item *first);
void print_items(Item *first);

/* main function */
int main(int argc, char * argv[])
{
    /* statments & initialisation */
    Item* first = NULL;
    int number_of_items = (argc - 1);

    first = add_items(number_of_items, argv); // Adding items to linked list from command line
    first = modify_items(first); // Changing status of each item if necessary
    print_items(first); // Printing the updated items, line by line (status and country name)

    return 0; // Exiting the function correctly
}

/* actual implementation of the functions */
Item* add_items(int length, char * argv[])
{
    //statements & initialisation
    Item *current, *first, *prev;

    first = (Item*)calloc(1, sizeof(Item)); // This is memory allocation for the first item in command line
    current = first;

    // Creating the first node in the linked list as the item
    strcpy(current->item_code, argv[1]);
    current->price = atof(argv[2]);
    current->sold_items = atoi(argv[3]);
    current->status = 0; // Setting status to 0 initially
    current->prev = NULL;

    // Starting after the first item has been stored, this loop adds all remaining items to the linked list
    for(int i = 4; i < length; i+= 3)
    {
        current->next = (Item*)calloc(1, sizeof(Item)); // Memory allocation for each item in the linked list

        prev = current;

        current = current->next;

        strcpy(current->item_code, argv[i]);
        current->price = atof(argv[i + 1]);
        current->sold_items = atoi(argv[i + 2]);
        current->status = 0;
        
        current->prev = prev;
    }
    current->next = NULL; // Making sure after the last item in the linked list points to NULL
    return first; // Returning the start of the linked list (first item)
}

Item* modify_items(Item *first)
{
    // Statements & initialising
    Item *p = NULL;
    int tot_sales = 0;
    int counter = 0; // Used to keep track of how many items there are
    int average_sales = 0;

    // Using for loop to get total sales of all items combined
    for(p = first; p != NULL; p = p ->next)
    {
        tot_sales += (p->price * p->sold_items);
        counter++;
    }

    average_sales = tot_sales / counter;
    
    // Using for loop to change status if the sales per item is greater or equal to average sales of all items
    for(p = first; p != NULL; p = p->next)
    {
        if((p->price * p->sold_items) >= average_sales)
        {
            p->status = 1; // Changing status to 1 (Higher/equal than average)
        }
    }

    return first; // Returning the start of the linked list (first item)
}

void print_items(Item *first)
{
    // Statements & initialisation
    Item *p = NULL;
    char country[3]; // Will be used for country code comparison

    // Going through the linked list and printing all relevant item information   
    for (p = first; p != NULL; p = p->next)
    {
        strncpy(country, &p->item_code[0], 2); // Retrieving country code from the item_code
        country[2] = '\0';

        if (strcmp(country, "IE") == 0)
        {
            printf("%d\n", p->status);
            printf("Ireland\n");
        }
        else if (strcmp(country, "FR") == 0)
        {
            printf("%d\n", p->status);
            printf("France\n");
        }
        else if (strcmp(country, "SP") == 0)
        {
            printf("%d\n", p->status);
            printf("Spain\n");
        }
        else if (strcmp(country, "US") == 0)
        {
            printf("%d\n", p->status);
            printf("USA\n");
        }
        else if (strcmp(country, "RU") == 0)
        {
            printf("%d\n", p->status);
            printf("Russia\n");
        }
        else
        {
            printf("The code is undefined!\n");
        }
    }

}