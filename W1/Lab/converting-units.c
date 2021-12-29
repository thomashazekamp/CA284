#include <stdio.h>
#include <stdlib.h>

int main(char argc, char *argv[])
{
    float cent;
    printf("Enter an Amount in Centimetres: ");
    scanf("%f", &cent);
    float conv = cent / 2.54;
    printf("The Amount in Inches is: %.2f\n", conv);
    return 0;
}