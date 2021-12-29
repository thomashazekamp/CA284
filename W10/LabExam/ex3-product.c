/*
Author: Thomas Hazekamp
Date: 25/11/2021
Description: This program gets information of a product from the command line, it uses a linked list to store the info,
after all command line information is stored in the linked list, products price having the origin from Ireland receive a
20% increase, the prices are then modified to the new price.
*/
/* Relevant libraries  & description */
#include <stdio.h> // For output & input
#include <stdlib.h> // Used for atoi function
#include <string.h> // Used for strcpy() and strcmp() functions

// The Product information structure, incorporating a linked list
typedef struct Product Product;

struct Product {
    char code[10];
    char name[60];
    int price;
    Product *next;
    Product *prev;
};
/* Function prototypes */
/* 
-> add_products is used to initially add all the product information from command line arguments
-> modify_products is used to change the price of the products which have their origin in Ireland
-> print_products prints as an output the produtct code, name and new price, line by line
So we will need the following functions:
*/
Product* add_products(int length, char * argv[]);
Product* modify_products(Product *first);
void print_products(Product *first);

/* main function */
int main(int argc, char * argv[])
{
    /* statments & initialisation */
    Product* first = NULL;
    int number_of_products = (argc - 1);

    first = add_products(number_of_products, argv); // Adding products to linked list from command line
    first = modify_products(first); // Changing the price of the products from Ireland
    print_products(first); // Printing the updated products, line by line

    return 0; // Exiting the function correctly
}

/* actual implementation of the functions */
Product* add_products(int length, char * argv[])
{
    //statements & initialisation
    Product *current, *first, *prev;

    first = (Product*)calloc(1, sizeof(Product)); // This is memory allocation for the first product in command line
    current = first;

    // Creating the first node in the linked list as the product
    strcpy(current->code, argv[1]);
    strcpy(current->name, argv[2]);
    current->price = atoi(argv[3]);
    current->prev = NULL;

    // Starting after the first product has been stored, this loop adds all remaining products to the linked list
    for(int i = 4; i < length; i+= 3)
    {
        current->next = (Product*)calloc(1, sizeof(Product)); // Memory allocation for each product in the linked list

        prev = current;

        current = current->next;

        strcpy(current->code, argv[i]);
        strcpy(current->name, argv[i + 1]);
        current->price = atoi(argv[i + 2]);
        
        current->prev = prev;
    }
    current->next = NULL; // Making sure after the last product in the linked list points to NULL
    return first; // Returning the start of the linked list (first product)
}

Product* modify_products(Product *first)
{
    // Statements & initialising
    Product *p = NULL;

    // Going through linked list to modify the prices of the products with origins Ireland
    for(p = first; p != NULL; p = p->next)
    {
        if(!strcmp(p->name, "Ireland"))
        {
            p->price = p->price * 1.2; // 20% increase in the price
        }
    }
    return first; // Returning the start of the linked list (first product)
}

void print_products(Product *first)
{
    // Statements & initialisation
    Product *p = NULL;

    // Going through the linked list and printing all product information   
    for (p = first; p != NULL; p = p->next)
    {
        printf("%s\n", p->code);
        printf("%s\n", p->name);
        printf("%d\n", p->price);
    }
}