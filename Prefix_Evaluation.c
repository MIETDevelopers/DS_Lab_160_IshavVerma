#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

#define STACK_MAX 500
#define OPERAND 10
#define OPERATOR 20

/* stack structure */
typedef struct prexp
{
  int top;
  int stack[STACK_MAX];
}stck;

// Init the stack
void init(stck *st )
{
  st->top=-1;
  //memset(st->stack, 0, STACK_MAX);
}

void push(stck *st,int num)
{
	if(st->top == STACK_MAX)
	{
		printf("Stack Overflow \n");
		exit(-1);
	}
    st->top++;
    st->stack[st->top]=num;
}

int pop(stck *st)
{
    int num;
    if(st->top < 0 )
    {
    	printf("Stack Underflow \n");
    	exit(-1);
    }
    num=st->stack[st->top];
    st->top--;
    return num;
}

int top(stck *st)
{
	return st->stack[0];
}
// evaluate an expression
void eval(stck *st,char op,int num1,int num2)
{
	int res;
	switch(op)
	{
		case '+': res=num1+num2;
		break;
		case '-': res=num1-num2;
		break;
		case '*': res=num1*num2;
		break;
		case '/': res=num1/num2;
		break;
		case '%': res=num1%num2;
		break;
		case '$': res=pow(num1,num2);
		break;
	}
	push(st,res);
}

int gettype(char c)
{
      switch(c)
      {
         case '+':
         case '-':
         case '*':
         case '/':
         case '$':
         case '%': return OPERATOR;
         default : return OPERAND;
        }
}


int main(int argc, char *argv[])
{

	if ( argc != 2 ) /* argc should be 2 for correct execution */
	{
		/* argv[0] is the program name */
		/* argc is the count of the number of strings in argv */
		/* In this case argc=2 as argv[0] contains the filename
				argv[1] is prefix expression respectively */
		printf( "Invalid Syntax :: Format - prefix.exe expr \n");
		return -1;
	}
	else
	{

		char * pre;
		int num1,num2,item,l,i;
		stck stk;

		init(&stk);
		pre = argv[1];
		l=strlen(pre);

		for(i=l-1;i>=0;i--)
		{
			if(pre[i]==' ' || pre[i]=='\0') //just in case!
				continue;
			switch(gettype(pre[i])) // process type
			{
				case OPERAND :
					item=pre[i]-'0'; // string to int conversion
					push(&stk,item);
				break;

				case OPERATOR :
					num1=pop(&stk);
					num2=pop(&stk);
					eval(&stk,pre[i],num1,num2);
				break;
			}
		}

		if(stk.top != 0 )
		{
			printf("Invalid Expression! \n");
			return -1;
		}

		printf("Result = %d \n",top(&stk)); // print result
		return 0 ;
	}
}