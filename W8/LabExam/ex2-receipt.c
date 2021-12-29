/*
Author: Thomas Hazekamp
Date: 12/11/2021
Description: This program returns the total price of the shopping cart taken from command line,
this includes the total of all on sale and not on sale items added together.
The sale items have a 3 for 2 deal
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
-> print_items_tot_price will add the total price of each item and its amount together including the items on sale
-> sale_items_price will do the calculations of the total price of the items which are on sale
So we will need the following functions:
*/
void items_list(Item item[], int num_items, char * argv[]);
void print_items_tot_price(Item item[], int num_items);
float sale_items_price(int amount, float price);

/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    Item item[50]; // Max items is 50
    int num_items = (argc - 1) / 4; // Since each item from command line has 4 attributes

    // Calling the functions
    items_list(item, num_items, argv);
    print_items_tot_price(item, num_items);

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
// Will add the total price of each item and its amount together including the items on sale
void print_items_tot_price(Item item[], int num_items)
{
    // Statements
    float value_cart = 0; // Starting value will always be 0
    float *pValueCart = &value_cart; // Using pointers (pointing to address)

    // This loop goes through each item and will add the price of the items to the total price of the cart
    for(int i = 0; i < num_items; i++)
    {
        if(item[i].promotion == 0) // Checking which promotion the item is on
        {
            *pValueCart += item[i].amount * item[i].price; // Normal calculation for a number of items and the price of each
        }
        else
        {
            *pValueCart += sale_items_price(item[i].amount, item[i].price); // Calling the sale_items_price function to get the price after the sale has been applied
        }
    }
    printf("%.2f\n", *pValueCart);
}
// Will do the calculations of the total price of the items which are on sale
float sale_items_price(int amount, float price)
{
    // Statements
    float final_total = 0; // This is the total price of the specific item and its amount
    float *pFinalTotal = &final_total; // Using pointers (pointing to address)

    // Going through each item and adding the corresponding price of each
    // Every third item we skip (since its a 3 for 2 sale)
    for(int i = 1; i <= amount; i++)
    {
        if((i % 3) != 0) // If the item is not third, then add to total price
        {
            *pFinalTotal += price;
        }
    }

    return *pFinalTotal; // Returning the final value of the item and its amount
}