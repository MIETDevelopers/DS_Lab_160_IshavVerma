//A C Program to perform singly linked list operations.                © Ishav Verma 31/July/2021
#include<stdlib.h>
#include<stdio.h>

void insert();
void delete();
void insertMultiple();
void deleteMultiple();
void generateRandom();
void checkRandom();
void display();
int count=0, num1, x;

struct node
{
    int info;
    struct node *next;
};
struct node *start=NULL;
int main()     
{
    int choice, choice2, time, i;
    while(1){
                printf("\n~Singly Linked List Operation~");
                printf("\n 1. Insert node.");
                printf("\n 2. Delete node.");
                printf("\n 3. Display all nodes.");
                printf("\n 4. Exit the proggram.");
                printf("\n Enter your choice: ");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1:
                            printf("\n~Implementing insert function!~\n");
                            printf("\nNumber of nodes available: %d", count);
                            printf("\n~Available options: \n 1.Insert a single node.\n 2.Insert multiple nodes.");
                            printf("\n Choose preffered insert operation: ");
                            scanf("%d", &choice2);
                            switch(choice2)
                            {
                                case 1: //This will redirect to single node insertion function. 
                                    insert();
                                    count++;
                                    break;

                                case 2: //This will redirect to multiple node insertion function.
                                    printf("\nEnter the number of elements you want to insert to the List: ");
                                    scanf("%d", &time);
                                    for(i=0; i<=time-1; i++){ generateRandom(); count++; }
                                    break;

                                default:
                                    printf("\n Wrong choice!");
                                    break;
                            }
                            
                            break;
                    case 2:
                            printf("\n~Implementing delete function!~\n");
                            printf("\nNumber of nodes available: %d", count);
                            printf("\n~Available options: \n 1.Delete a single node.\n 2.Delete multiple nodes.");
                            printf("\n Choose preffered delelte operation: ");
                            scanf("%d", &choice2);
                            switch(choice2)
                            {
                                case 1: //This will redirect to single node deletion function.
                                    delete();
                                    break;

                                case 2: //This will redirect to multiple node deletion function.
                                    printf("\nEnter the number of elements you want to delete from the List: ");
                                    scanf("%d", &time);
                                    for(i=0; i<=time-1; i++){ deleteMultiple(); }
                                    break;

                                default:
                                    printf("\n Wrong choice!");
                                    break;
                            }

                            break;
                    case 3:
                            printf("\n~Implementing display function!~\n");
                            printf("\nNumber of nodes available: %d", count);
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
        }
        return 0;
}

void insert()
{
    struct node *ptr,*temp;
    int i,pos;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\nOut of Memory Space! :/ ");
        return;
    }
    printf("\nEnter the index value for the new node to be inserted: ");
    scanf("%d",&pos);
    printf("\nEnter the value of the node: ");
    scanf("%d",&temp->info) ;
  
    temp->next=NULL;
        if(pos==0)
        {
            temp->next=start;
            start=temp;
        }
        else
        {
            for(i=0,ptr=start;i<pos-1;i++) 
                { 
                    ptr=ptr->next;
                        if(ptr==NULL)
                        {
                            printf("\nIndex not found! :/");
                            return;
                        }
                }

                temp->next =ptr->next ;
                ptr->next=temp;
        }
}

void delete()
{
    int i,pos;
    struct node *temp,*ptr;
    if(start==NULL)
    {
        printf("\nThe List is Empty! :/");
        return;
    }
    else
    {
        printf("\nEnter the index value of the node to be deleted: ");
        scanf("%d",&pos);
            if(pos==0)
            {
                ptr=start;
                start=start->next ;
            
                printf("\nThe deleted node is: %d",ptr->info );
                count--;
                    free(ptr);
            }
            else
            {
                ptr=start;
                for(i=0;i<pos;i++) 
                { 
                    temp=ptr; 
                    ptr=ptr->next;
                    if(ptr==NULL)
                    {
                        printf("\nNode not found :/");
                        return;
                    }
                }
                temp->next =ptr->next ;
                printf("\nThe deleted node is: %d",ptr->info);
                count--;
            free(ptr);
            }
    }
}

void insertMultiple()
{
    struct node *ptr,*temp;
    int i,pos;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\nOut of Memory Space! :/ ");
        return;
    }

    pos=count;

    temp->info=x; //Here the value of randomly generated integer carried by x is assigned to node.
  
    temp->next=NULL;
        if(pos==0)
        {
            temp->next=start;
            start=temp;
        }
        else
        {
            for(i=0,ptr=start;i<pos-1;i++) 
                { 
                    ptr=ptr->next;
                        if(ptr==NULL)
                        {
                            printf("\nIndex not found! :/");
                            return;
                        }
                }

                temp->next =ptr->next ;
                ptr->next=temp;
        }
}

void deleteMultiple() //This function is whole same as convetional delete function but with less printf statements.
{
    int i,pos;
    struct node *temp,*ptr;
    if(start==NULL)
    {
        printf("\nThe List is Empty! :/");
        return;
    }
    else
    {
        pos=count-1;
            if(pos==0)
            {
                ptr=start;
                start=start->next ;
            
                printf("\nThe deleted node is: %d",ptr->info );
                count--;
                    free(ptr);
            }
            else
            {
                ptr=start;
                for(i=0;i<pos;i++) 
                { 
                    temp=ptr; 
                    ptr=ptr->next;
                    if(ptr==NULL)
                    {
                        printf("\nNode not found :/");
                        return;
                    }
                }
                temp->next =ptr->next ;
                printf("\nThe deleted node is: %d",ptr->info);
                count--;
            free(ptr);
            }
    }
}

void display()
{
    struct node *ptr;
    if(start==NULL)
    {
        printf("\nList is empty! :/");
        return;
    }
    else
    {
        ptr=start;
        printf("\nThe nodes in the list are: ");
        while(ptr!=NULL)
        {
            printf(" %d,",ptr->info );
            ptr=ptr->next ;
        }
    }
}

void generateRandom()
{
        x=rand(); //This will create some random integer value and assign it to variable x.
        checkRandom(x); //This will carry forward the assigned value of x to checkRandom function.
}
void checkRandom()
{
        if (x>99 && x<999)
        {
        insertMultiple(x); //If the mentioned condition is staisfied by variable then it will carry forward to insertMultiple function.
        return;
        }
        else
        {
            generateRandom(); //But if it doesn't staisfies the condition it will redirect to generateRandom function.
        }
}