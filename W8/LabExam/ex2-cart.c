/*
Author: Thomas Hazekamp
Date: 12/11/2021
Description: This program takes arguments for command line and inserts them into a struct,
it prints them and states whether the item is on sale or not
*/
/* Relevant libraries  & description */
#include <stdio.h> // For input and output
#include <stdlib.h> // For atoi and atof functions
#include <string.h> // For strcpy function

// Defining a new type
typedef struct Item Item;

// Defining a new struct
struct Item
{
    char name[20];
    unsigned int amount;
    float price;
    int promotion;
};

/* Function prototypes */
/*
-> items_list will add all argument line items to the Items struct
-> print_items_list will print each item's information line by line and replacing the 1 or 0 stating whether the item is on sale or not
So we will need the following functions:
*/
void items_list(Item item[], int num_items, char * argv[]);
void print_items_list(Item item[], int num_items);

/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    Item item[50]; // Max items is 50
    int num_items = (argc - 1) / 4; // Since each item from command line has 4 attributes

    // Calling the functions
    items_list(item, num_items, argv);
    print_items_list(item, num_items);

    return 0; // Exiting the main function correctly
}

/* actual implementation of the functions */
// Will add all argument line items to the Items struct
void items_list(Item item[], int num_items, char * argv[])
{
    //statements
    int i, j = 1; // j is used to keep the index of each individual item in the command line

    // This loop gives each item the propper attributes
    for(i = 0; i < num_items; i++)
    {
        strcpy(item[i].name, argv[j]);
        item[i].amount = atoi(argv[j + 1]);
        item[i].price = atof(argv[j + 2]);
        item[i].promotion = atoi(argv[j + 3]);
        j+=4;
    }
}
// Will print each item's information line by line and replacing the 1 or 0 stating whether the item is on sale or not
void print_items_list(Item item[], int num_items)
{
    // This loop goes through each item and prints the items info and whether it is an "On sale" or "No Sale" item
    for(int i = 0; i < num_items; i++)
    {
        if(item[i].promotion == 0) // Checking which promotion the item is on
        {
            printf("%s,%d,%.2f,No Sale\n", item[i].name, item[i].amount, item[i].price);
        }
        else
        {
            printf("%s,%d,%.2f,On Sale\n", item[i].name, item[i].amount, item[i].price);
        }
    }
}