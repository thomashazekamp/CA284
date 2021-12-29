#include <stdio.h>
#include <stdlib.h>

#define MAX_LIMIT 20

int main(char argc, char *argv[])
{
    char a_name[MAX_LIMIT];
    printf("Enter your name: ");
    scanf("%s", a_name);
    printf("Hello %s\n", a_name);
    return 0;
}
