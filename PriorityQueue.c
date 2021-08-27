//A C program demonstrating priority queue operations using array.                      © Ishav Verma 07/July/2021
#include <stdio.h>
#include<stdlib.h>
#define MAX 100
 
void insert();
void delete();
void display();
int Queue1[MAX];
int rear = - 1;
int front = - 1;
int main()
{
    int ch;
    while(1)
    {    
        printf("~Choose your operation~ \n ----- \n");
        printf("1.Insert element to queue. \n");
        printf("2.Delete element from queue. \n");
        printf("3.Display all elements of queue. \n");
        printf("4.Quit. \n");
        printf(" ----- \n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            default:
            printf("Wrong choice \n");
        }
    }
return 0;
}
 
void insert()
{
    int InputVal1;
    if (rear == MAX - 1)
    printf("Queue is Overflowing! \n");
    else
    {
        if (front == - 1)
        front = 0;
        printf("\nEnter value to insert in queue: ");
        scanf("%d", &InputVal1);
        rear = rear + 1;
        Queue1[rear] = InputVal1;
    }
}

void delete()
{
    int InputVal2, i, position, found;
    printf("\nEnter value of element to be deleted: ");
    scanf("%d", &InputVal2);

    for(i = front; i <= rear; i++)
    {
        if(Queue1[i] == InputVal2)
        {
            found = 1;
            position = i;
            break;
        }
    }

    if (found == 1)
    {
        for (i = position; i < rear; i++)
        Queue1[i] = Queue1[i+1];
        rear--;
    }
}
 
/*void delete()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue is underflowing! \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", Queue1[front]);
        front = front + 1;
    }
}*/
 
void display()
{
    int i, j, n, temp;
    if (front == - 1)
        printf("Queue is empty! \n");
    else
    {
        printf("Elements in queue are: ");

    for (i = front ; i <= rear; i++) //Using for loop.
        {
            j = i;
                while ( j > 0 && Queue1[j-1] > Queue1[j])
                {
                //Swap function will help for the purpose.       
                    temp     = Queue1[j];
                  Queue1[j]   = Queue1[j-1];
                    Queue1[j-1] = temp;
                    j--;
                }
        }

        for (i = 0; i <= rear; i++)
        {
            printf("%d ", Queue1[i]);
        }
    }
}