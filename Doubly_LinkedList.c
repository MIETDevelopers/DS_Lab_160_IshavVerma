#include<stdio.h>
#include<stdlib.h>

void insert();
void delete();
void display();

int count=0, i=2;

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
    int pos;
    node *ptr, *temp;
    ptr=(node*) malloc(sizeof(node));
    if (ptr==NULL)
    {
        printf("Oops! can't enter element.....Memory not available\n");
    }
    printf("Enter the element\n");
    scanf("%d",&ptr->data);
    ptr->prev=NULL;
    ptr->next=NULL;
    printf("Enter the position\n");
    scanf("%d",&pos);

    if (head==NULL)
    {
        if (pos==1)
        {
            head=ptr;
            last=ptr;
            count++;
            printf("Node inserted\n");
        }
        else
        {
            printf("Invalid position\n");
        }
    }
    else if (pos==1)
    {
        ptr->next=head;
        head->prev=ptr;
        head=ptr;
        count++;
        printf("Node inserted\n");
    }
    else if (pos==count+1)
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        ptr->prev=temp;
        temp->next=ptr;
        last=ptr;
        count++;
        printf("Node inserted\n");
    }
    else
    {
        temp=head;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        temp->next->prev=ptr;
        ptr->next=temp->next;
        temp->next=ptr;
        ptr->prev=temp;
        count++;
        printf("Node Inserted\n");

    }
    printf("Total elements=%d\n",count);
}

void delete()
{
    int num, choice, pos, x=1;
    node *ptr, *temp;
    if (head==NULL)
    {
        printf("Oops! List is empty\n");
        return;
    }

    printf("Enter the position of node: ");
    scanf("%d",&pos);

    if (head==NULL)
        {
            printf("\nList is empty! :/");
        }
    else 
        if (head->next==NULL)
            {
                printf("\n Node deleted!");
                head=NULL;
                last=NULL;
                    free(head);
                count--;
            }
        else 
            if (pos>count)
                {
                    printf("\nInvalid Position! :/");
                }
            else
                if (pos==1)
                {
                    temp=head;
                    printf("\n Node deleted!");
                    head=head->next;
                    free(temp);
                    count--;
                }
                else
                {
                    temp=head;
                    while(x<pos)
                    {
                        ptr=temp;
                        temp=temp->next;
                        x++;
                    }
                    ptr->next=temp->next;
                    printf("\n Node deleted!");
                    free(temp);
                    count--;
                }
    printf("\nTotal elements in list are: %d",count);
}

void display()
{
    int choice;
    node *temp;
    if (head==NULL)
    {
            printf("\nNo node elements to display! :/");
    }
    else
    {
    temp=head;
    printf("Elements in list are: ");
        while(temp!=NULL)
            {   
                printf("%d ",temp->data);
                temp=temp->next;
            }
        printf("\nTotal elements in list are: %d",count);
    }       
}