//A C program demonstrating queue operations using array.                      © Ishav Verma 27/May/2021
#include<stdio.h>
#include<stdlib.h> 
#define MAX 100
 
void EnQueue();
void DeQueue();
void Peek();
int queue_array[MAX];
int rear = - 1, front = - 1;
int main()
{
    printf("");
    int choice;
    do
    {
        printf("1.EnQueue element to queue \n2.DeQueue element from queue \n3.Peek all elements of queue \n4.Quit \n ----- \nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                EnQueue();
                break;
            case 2:
                DeQueue();
                break;
            case 3:
                Peek();
                break;
            case 4:
                printf("Exitting!");
                exit(0);
                break;
            default:
            printf("Wrong choice \n");
        }
    }
    while(choice!=4); 
    return 0;
}
 
void EnQueue()
{
    int add_item;
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        /*If queue is initially empty */
        front = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
}
 
void DeQueue()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Element DeQueued from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
} /* End of DeQueue() */
 
void Peek()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
}