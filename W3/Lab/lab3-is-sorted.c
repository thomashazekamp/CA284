/*
Author: Thomas Hazekamp
Date: 10/10/21
Description: Sorting a list in ascending order using bubble sort
*/
/* Relevant libraries  & description */
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
/* ... description
So we will need the following functions:
*/
int sort_array(int nums_list[], int len);
// etc...

/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    int i, length, sorted_list, nums[argc];
    int j = 0;

    // converting all elements of the argv array to a new array and making them integers 
    for(i=1; i<argc; i++)
    {
        nums[j] = atoi(argv[i]);
        j++;
    }

    length = argc - 1; // length of the nums array

    sort_array(nums, length); // calling the function

    return 0; // exiting the main function correctly
}

/* actual implementation of the functions */
int sort_array(int nums_list[], int len)
{
    //statements
    int i, temp, sorted;

    // using bubble sort to sort the list in ascending order, while(1) means loop will go on forever since 1 means true in this case. It will stop once there a break
    while(1)
    {
        sorted = 0;

        for(i = 0; i < (len - 1); i++)
        {
            if(nums_list[i] > nums_list[i + 1])
            {
                temp = nums_list[i];
                nums_list[i] = nums_list[i + 1];
                nums_list[i + 1] = temp;
                sorted = 1;
            }
        }

        // if the array is finished sorting the while loop will stop
        if(sorted == 0)
        {
            break;
        }
    }

    // printing each sorted value line by line
    for(i = 0; i < len; i++)
    {
        printf("%d\n", nums_list[i]);
    }
    return 0; // exiting the sort_array function correctly
}