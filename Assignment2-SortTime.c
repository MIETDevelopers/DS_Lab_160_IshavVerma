//A C program to compare the running times (in milliseconds) of Bubble Sort and Merge Sort.                 © Ishav Verma 11/Sep/2021
#include<stdio.h>
#include<stdlib.h>
#include<time.h>//Use for clock functions.
#include<unistd.h>//Use for sleep function.

int max = 10;//Specifing the maximum size.
int Array0[10] = {1,3,42,2,41,66,66,33,98,0};//Pre-defined array to be sorted.
clock_t t; //Clocks per second.

//Declaring functions.
void printArray();
void BubbleSort();
void MergeSort();
void merge();

//Start of main function.
int main()
{
    int choice;
    do{
        printf("\nArray to be sorted: {1,3,42,2,41,66,66,33,98,0}");
        printf("\n---\n1.Bubble Sort.\n2.Merge Sort.\n3.Exit.\n Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                t = clock();
                BubbleSort(Array0,max);
                printf("\nThe sorted array is:");
                printArray(Array0, max);
                sleep(1);
                t = clock() - t;
                double BubbleSortTime = ((double)t)/CLOCKS_PER_SEC; // in seconds
                printf("Time taken by Bubble sort: %f ms\n", BubbleSortTime*1000);
                fflush(stdin);
                break;
            case 2:
                t = clock();
                MergeSort(Array0, 0, ( max- 1));
                printf("The sorted array is\n");
                printArray(Array0 , max);
                sleep(1);
                t = clock() - t;
                double MergeSortTime = ((double)t) / CLOCKS_PER_SEC;
                printf("Time taken by Merge sort: %f ms\n", MergeSortTime*1000);
                fflush(stdin);
                break;
            case 3:
                exit(0);
                break;
        }
    }while(choice!=3);
    return 0;
}

void BubbleSort(int a[], int size)
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - (i + 1); j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void merge(int a[], int left, int m, int right)
{
    int i, j, k;
    int n1 = m - left + 1;
    int n2 = right - m;

    int L[n1], R[n2];//Create temporary arrays.

    //Copying data to temp arrays L[] and R[].
    for (i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    //Merge the temp arrays back into a[left..right].
    i = 0;    // Initial index of first subarray.
    j = 0;    // Initial index of second subarray.
    k = left; // Initial index of merged subarray.
    
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            {
                a[k] = L[i];
                i++;
            }
        else
            {
                a[k] = R[j];
                j++;
            }
        k++;
    }

    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
        //Copy the remaining elements of L[], if there are any.
    }

    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
        //Copy the remaining elements of R[], if thereare any.
    }
}

void MergeSort(int a[], int left, int right)
{
    //Left is for left index and right is right index of the sub-array of a to be sorted.
    if (left < right)
    {
        int m = left + (right - left) / 2;
        //Same as (left+right)/2, but avoids overflow for large left and halves.

        MergeSort(a, left, m);
        MergeSort(a, m + 1, right);
        merge(a, left, m, right);
        //Sort first and second halves
    }
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        //This loop will iterate through the whole array and will print each element.
        printf(" %d,", arr[i]);
    }
    printf("\n");
}
