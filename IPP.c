#include<stdio.h>
#include<stdlib.h>  
#include<conio.h>  
#include<string.h>
#include<ctype.h>

int stack[20], top=-1, i, n1, n2, n3, num, A, B;
//Start of Infix
void pushINF(int x)
{
    stack[++top] = x;
}

int popINF()
{
    return stack[top--];
}

int InfixMain()
{
    char exp[20];
    char *e;
    printf("Enter the expression: ");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0')
    {
        if(isdigit(*e))
        {
            num = *e - 48;
            pushINF(num);
        }
        else
        {
            n1 = popINF();
            n2 = popINF();
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
            pushINF(n3);
        }
        e++;
    }

    printf("\nThe result of expression %s  =  %d\n\n",exp,popINF());
return 0;
}
//End of Infix.

//Start of Prefix.
void pushPRE(int value)  
{
	top=top+1;
	stack[top]=value;
}
	
int popPRE()
{
	return(stack[top--]);
}
	
int operatorPRE(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/')
	return 1;
		
	else
	return 0;
}
	
int PrefixMain()
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
	switch(operatorPRE(prefix[i]))
		{
		case 0:
			B=prefix[i];
			pushPRE(B);
			break;
	
		case 1: 	
			exp1=popPRE();
			exp2=popPRE();
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
		pushPRE(res);
	
		}
	
	}
	printf("\nResult is: %d",stack[top]);
	
return 0;		
} 
//End of Prefix.

//Start of Postfix.
void pushPOS(int x)
{
    top=top+1;
    stack[top]=x;
}
	
int popPOS()
{
   return stack[top--]; 
}

	int PostfixMain()
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
	            pushPOS(num);
	        }
	        else
	        {
	            n1 = popPOS();
	            n2 = popPOS();
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
	            pushPOS(n3);
	        }
	        e++;
	    }
	    printf("\nResult is: %d",popPOS());
return 0;	
}
//End of Postfix.

//Start of Main Function.

int main()
{
	int inpChoice;
	do{
	printf("~Choose your mode of Operation~\n ----- \n 1.Infix Evaluation. \n 2.Prefix Evaluation. \n 3.Postfix Evaluation. \n 4.Exit\n -----\n Choose an Option: ");
	scanf("%d", &inpChoice);
	switch(inpChoice)
		{
			case 1:
				InfixMain();
				break;
			case 2:
				PrefixMain();
				break;
			case 3:
				PostfixMain();
				break;
			case 4:
				exit(0);
				break;

			default:
				printf("\nInvalid option! Please select a valid operation.");
		}
	}while(inpChoice != 4);
}
//End of main Function.