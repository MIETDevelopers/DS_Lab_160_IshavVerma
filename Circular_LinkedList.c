#include<stdio.h>
#include<stdlib.h>

void insert();
void delete();
void display();
int count=0;

typedef struct linkedlist 
{
	int data;
	struct linkedlist *prev;
	struct linkedlist *next;
}node;

node *head=NULL, *last=NULL;
int main()
{
	int choice;
    do{
       printf("\n~Doubly Linked List Operation~");
        printf("\n 1. Insert a node.");
        printf("\n 2. Delete a node.");
        printf("\n 3. Display all nodes.");
        printf("\n 4. Exit the proggram.");
        printf("\n Enter your choice: ");
        scanf("%d",&choice);
                switch(choice)
                {
                    case 1:
                            printf("\n~Implementing insert function!~\n");
                            insert();
                            break;
                    case 2:
                            printf("\n~Implementing delete function!~\n");
                            delete();                   
                            break;
                    case 3:
                            printf("\n~Implementing display function!~\n");
                            display();
                            break;    
                    case 4:
                            printf("Exiting the program!");
                            exit(0);
                            break;
                    default:
                            printf("\nWrong Choice! :/");
                            break;  
        }
    }while(choice!=4);
return 0;
}

void insert()
{
	int pos, i=2;
	node *ptr, *temp=head;
	ptr=(node*) malloc(sizeof(node));

	if (ptr==NULL)
	{
		printf("\n Out of memory! :/");
	}
	printf("\nEnter the value of element: ");
	scanf("%d",&ptr->data);
	ptr->next=NULL;
	ptr->prev=NULL;
	printf("\nEnter the index where you want to insert: ");
	scanf("%d",&pos);

	if (head==NULL)
	{
		if (pos==0)
		{
			head=ptr;
			last=ptr;
			head->next=last;
			head->prev=last;
			printf("\nNode inserted!");
			count++;
		}
		else
		{
			printf("\nInvalid position! :/");
			return;
		}
	}
	else
		if (pos==count+1)
		{
			while(temp->next!=head)
				{
					temp=temp->next;
				}
					temp->next=ptr;
					ptr->prev=temp;
					ptr->next=head;
					last=ptr;
					head->prev=last;
					
					printf("Node Inserted! :/");
	count++;
		}
		else
			if (pos==1)
			{
				head=ptr;
				ptr->next=temp;
				temp->prev=ptr;
				head->prev=last;
				last->next=head;
		
				printf("\nNode inserted! :/");
				count++;
			}
			else
			{
				while(i<pos)
				{
					temp=temp->next;
					i++;
				}
					temp->next->prev=ptr;
					ptr->next=temp->next;
					temp->next=ptr;
					ptr->prev=temp;
					printf("\nNode inserted!");
					count++;
			}
			
	printf("\n Total node elements in list: %d",count);
}

void delete()
{
	int pos, i=1;
	node *temp=head, *ptr;

	if (head==NULL)
	{
		printf("List is empty\n");
	}
	printf("Enter the position\n");
	scanf("%d",&pos);

	if (pos==1)
	{
		head=head->next;
		head->prev=last;
		last->next=head;
		printf("%d is deleted\n",temp->data);
		free(temp);
		count--;
	}
	else if (pos==count)
	{
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		last=last->prev;
		last->next=head;
		head->prev=last;
		printf("%d is deleted\n",temp->data);
		free(temp);
		count--;
	}
	else if (pos>count)
	{
		printf("Invalid position\n");
	}
	else
	{
		while(i<pos)
		{
			ptr=temp;
			temp=temp->next;
			i++;
		}
		ptr->next=temp->next;
		temp->next->prev=ptr;
		printf("%d is deleted\n",temp->data);
		free(temp);
		count--;
	}
	printf("\n Total node elements in list are: ",count);
}


void display()
{
	node *temp=head;
	if (head==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		printf("\nNode elements in list are: ");
		do
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}while(temp!=last->next);
		printf("\n Total node elements in list are: ",count);
	}
}