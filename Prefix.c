//A C Program to evaluate Prefix Expressions.                © Ishav Verma 04/July/2021
#include<stdio.h>  
#include<conio.h>  
#include<string.h>   
	
int QUEUE[20], top=-1,A,B,i;
void push(int value)  
{
	top=top+1;
	QUEUE[top]=value;
}
	
int pop()
{
	return(QUEUE[top--]);
}
	
int operator(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/')
	return 1;
		
	else
	return 0;
}
	
int main()
{
	int exp1;
	int exp2;
	int res;
	char prefix[10];
	
	printf("Enter the Expression: ");
	scanf("%s",prefix);
	
	A=strlen(prefix);
	for(i=A-1;i>=0;i--)
	{
	switch(operator(prefix[i]))
		{
		case 0:
			B=prefix[i];
			push(B);
			break;
	
		case 1: 	
			exp1=pop();
			exp2=pop();
			switch(prefix[i])
				{
				case '+': 
					res=exp1+ exp2;
					break;
	
				case '-': 
					res=exp1- exp2;
					break;
	
				case '*': 
					res=exp1* exp2;
					break;
	
				case '/': 
				res=exp1/ exp2;
				break;
				}
		push(res);
	
		}
	
	}
	printf("\nResult is: %d",QUEUE[top]);
	
return 0;		
}