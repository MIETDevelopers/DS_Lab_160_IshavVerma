//A C program demonstrating use of malloc() to store and print integers.                      © Ishav Verma 09/June/2021
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, *ptr, sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    ptr = (int*) malloc(n * sizeof(int));

    printf("Enter elements: ");

    for(i = 0; i < n; ++i)
    {
        scanf("%d", ptr + i);
    }
    
    for(i = 0; i < n; ++i)
    {
        printf(" %d \n", *(ptr + i));
    }

    return 0;
}