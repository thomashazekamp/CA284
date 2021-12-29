/*
Author: Thomas Hazekamp
Date: 08/11/2021
Description: Prints out students who have CSCE as a programme and then the average grade of all students
*/
/* Relevant libraries  & description */
#include <stdio.h> // For input and output
#include <stdlib.h> // For atof()
#include <string.h> // For strcmp()

// This function will print if the student has a grade higher than average and is in the CSCE programme
void csce_print(char *name, char *programme, float grade, float tot_average);

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

    // Adding all students to the struct
    int count = 0;
    float tot_average = 0;
    for(int i = 1; i < argc - 1; i+=3)
    {
        *pStudent[count].name = argv[i];
        *pStudent[count].programme = argv[i + 1];
        pStudent[count].grade = atof(argv[i + 2]);

        tot_average += pStudent[count].grade; // All marks combined to get the average grade later on

        count++;
    }
    tot_average = tot_average / count; // Final average grade for all students

    // Looping through all students and printing only if their programme and grade is as expected
    for(int i = 0; i < final_capacity; i++)
    {
        csce_print(*pStudent[i].name, *pStudent[i].programme, pStudent[i].grade, tot_average);
    }

    printf("Average grade: %.2f\n", tot_average); // Printing final average grade of all students

    free(pStudent); // Free memory

    return 0; // Exiting the function correctly
}

// This function only prints if the student has achieved greater than the average grade and is in the CSCE programme
void csce_print(char *name, char *programme, float grade, float tot_average)
{
    if(!strcmp(programme, "CSCE") && grade > tot_average)
    {
        printf("%s, %.2f\n", name, grade);
    }
}