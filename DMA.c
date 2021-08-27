//A C program demonstrating use of malloc(), calloc() & free() to store and print integers.                      © Ishav Verma 13/June/2021
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *ptr, *ptr1;
	int n, i;

    printf("Enter number of elements to be stored by each (malloc & calloc): ");
    scanf("%d", &n);

	ptr = (int*)malloc(n * sizeof(int));

	ptr1 = (int*)calloc(n, sizeof(int));

	if (ptr == NULL || ptr1 == NULL) {
		printf("Memory not allocated.\n");
		exit(0);
	}
	else {
		//For malloc.
		printf("Memory successfully allocated using malloc.\n");
		printf("Let's try to read and print %d elements using malloc.\n", n);
		printf("Enter %d values: ", n);
    		for(i = 0; i < n; ++i)
    		{
        		scanf("%d", ptr + i);
   			}
		printf("Enter %d values are as follows: \n", n);    
    		for(i = 0; i < n; ++i)
    		{
        		printf(" %d \n", *(ptr + i));
    		}
		free(ptr);
		printf("Malloc Memory successfully freed.\n");

		// For calloc
		printf("\nMemory successfully allocated using calloc.\n");
		printf("Let's try to read and print %d elements using calloc.\n", n);
 		printf("Enter %d values: ", n);
    		for(i = 0; i < n; ++i)
    		{
        		scanf("%d", ptr1 + i);
   			}
		printf("Enter %d values are as follows: \n", n);
    		for(i = 0; i < n; ++i)
    		{
        		printf(" %d \n", *(ptr1 + i));
    		}
		free(ptr1);
		printf("Calloc Memory successfully freed.\n");
	}

	return 0;
}