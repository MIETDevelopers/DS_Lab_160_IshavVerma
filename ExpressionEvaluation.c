//A C program to Evaluate a Pre-Defined Expression!         © Ishav Verma 22/June/2021
#include<stdio.h>
#include<stdlib.h>
int a,b,c,d,e,f,result;
int main()
{
    printf("Enter values for variables for solving expression: a+((b*c)-((d/e)*f))");
    printf("\nValue of a: ");
    scanf("%d", &a);
    printf("\nValue of b: ");
    scanf("%d", &b);
    printf("\nValue of c: ");
    scanf("%d", &c);
    printf("\nValue of d: ");
    scanf("%d", &d);
    printf("\nValue of e: ");
    scanf("%d", &e);
    printf("\nValue of f: ");
    scanf("%d", &f);

    result=a+((b*c)-((d/e)*f));
    printf("\nResult after evaluating: %d", result);
    return 0;
}