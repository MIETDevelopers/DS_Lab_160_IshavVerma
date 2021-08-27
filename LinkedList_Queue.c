#include<stdio.h>
#include<stdlib.h>

void enqueue();
void dequeue();
void display();
int count=0;

struct node   
{  
    int data;   
    struct node *next;  
};  
struct node *front;  
struct node *rear;

int main()
{
	int choice;
	while(1){
				printf("\n~Queue operations using Linked List~\n");
				printf("\n 1. Enqueue a Node.");
				printf("\n 2. Dequeue a Node.");
				printf("\n 3. Display all nodes available in Queue.");
				printf("\n 4. Exit");

				printf("\nEnter your choice: ");
				scanf("%d", &choice);

				switch(choice)
				{
					case 1:
							printf("\n~Implementing Enqueue function~\n");
							printf("\n Number of nodes available: %d\n", count);
							enqueue();
							break;

					case 2:
							printf("\n~Implementing Dequeue function~\n");
							printf("\n Number of nodes available: %d\n", count);
							dequeue();
							break;
					case 3:
							printf("\n~Implementing Display function~\n");
							printf("\n Number of nodes available: %d\n", count);
							display();
							break;
                    case 4:
                            printf("\nExiting the program!");
                            exit(0);
                            break;
                    default:
                            printf("\nWrong Choice! :/");
                            break;
				}
			}
return 0;
}

void enqueue()  
{  
    struct node *ptr;  
    int item;   
      
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOut of Memory Space! :/ ");  
        return;  
    }  
    else  
    {   
        printf("\nEnter the value of the node: ");  
        scanf("%d",&item);  
        ptr -> data = item;  
        if(front == NULL)  
        {  
            front = ptr;  
            rear = ptr;   
            front->next = NULL;  
            rear->next = NULL;  
        }  
        else   
        {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        }
    count++;  
    }  
}

void dequeue()  
{  
    struct node *ptr;  
    if(front == NULL)  
    {  
        printf("\nThe List is Empty! :/");  
        return;  
    }  
    else   
    {  
        ptr = front;  
        front = front -> next;  
        free(ptr);
        count--; 
    }  
}

void display()  
{  
    struct node *ptr;  
    ptr = front;      
    if(front == NULL)  
    {  
        printf("\nThe List is Empty! :/");  
    }  
    else  
    {   
    	printf("\nThe nodes in the list are:");  
        while(ptr != NULL)   
        {  
            printf(" %d,",ptr -> data);  
            ptr = ptr -> next;  
        }  
    }  
}