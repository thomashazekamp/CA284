/*
Author: Thomas Hazekamp
Date:
Description:
*/
/* Relevant libraries  & description */
#include <stdio.h>
#include <string.h>

typedef struct Student Student;

struct Student{
    char name[50];
    char college[50];
    int age;
    float grade;
}; Student s2;

/* Function prototypes */
/* ... description
So we will need the following functions:
*/
// etc...

/* main function */
int main(int argc, char * argv[])
{
    /* statments */
    FILE *pfile = NULL;
    char *filename = "studentBinary.bin";

    pfiel = fopen(filename, "rb");
    if(!pfile)
    {
        printf("Failed to open %s.\n", filename);
    }

    Student s2;

    int rcount_name_len = fread()
    int rcount1 = fread(s2.name, sizeof(char), 1, pfile);
    int rcount2 = fread(s2.college, sizeof(char), 1, pfile);
    int rcount3 = fread(s2.age, sizeof(int), 1, pfile);
    int rcount4 = fread(s2.grade, sizeof(float), 1, pfile);

    

    return 0;
}