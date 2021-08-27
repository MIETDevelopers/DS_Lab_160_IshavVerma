//A C Program to evaluate Postfix Expressions.                © Ishav Verma 04/July/2021
#include<stdio.h> 
#include<ctype.h>	
int stack[20];  
int top = -1;  
int n1,n2,n3,num;

void push(int x)
{
    top=top+1;
    stack[top]=x;
}
	
int pop()
{
   return stack[top--]; 
}

	int main()
	{
	    char exp[20];
	    char *e;	;
	    printf("Enter the expression: ");
	    scanf("%s",exp);
	    e = exp;
	    while(*e)             
	    {
	        if(isdigit(*e))
	        {
	            num = *e -'0'; 
	            push(num);
	        }
	        else
	        {
	            n1 = pop();
	            n2 = pop();
	            switch(*e)
	            {
	            case '+':
	            {
	                n3 = n1 + n2;
	                break;
	            }
	            case '-':
	            {
	                n3 = n2 - n1;
	                break;
	            }
	            case '*':
	            {
	                n3 = n1 * n2;
	                break;
	            }
	            case '/':
	            {
	                n3 = n2 / n1;
	                break;
	            }
	            }
	            push(n3);
	        }
	        e++;
	    }
	    printf("\nResult is: %d",pop());
return 0;	
}