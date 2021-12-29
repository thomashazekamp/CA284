/*
Author: Thomas Hazekamp
Date: 08/11/2021
Description: Prints out all students from the command line
*/
/* Relevant libraries  & description */
#include <stdio.h>
#include <stdlib.h>

// The Student struct is used to keep all data on the students

typedef struct Student Student;

struct Student
{
    char *name[20];
    char *programme[20];
    float grade;
};

/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    Student *pStudent;
    int capacity = 2;
    int final_capacity = argc / 3;

    // Allocating enough memory for 2 students
    pStudent = (Student*)calloc(capacity, sizeof(Student));
    if(!pStudent)
    {
        printf("Not enough memory. Exiting...\n");
        free(pStudent);
        pStudent = NULL;
        exit(0);
    }

    // If there are more than 2 students then it will reallocate more memory
    if(final_capacity > capacity)
    {
        Student *pTemp;
        pTemp = (Student*)realloc(pStudent, final_capacity*sizeof(Student));
        if(!pTemp)
        {
            printf("Not enough memory. Exiting...\n");
            free(pStudent);
            pStudent = NULL;
            exit(0);
        }
        pStudent = pTemp;
    }

    // Adding each student to the Student struct from command line
    int count = 0;
    for(int i = 1; i < argc - 1; i+=3)
    {
        *pStudent[count].name = argv[i];
        *pStudent[count].programme = argv[i + 1];
        pStudent[count].grade = atof(argv[i + 2]);
        count++;
    }

    // Printing each student line by line
    for(int i = 0; i < final_capacity; i++)
    {
        printf("%s, %s, %.2f\n", *(pStudent + i)->name, *(pStudent + i)->programme, (pStudent + i)->grade);
        
    }

    free(pStudent); // Free memory


    return 0;
}