#include<stdio.h>
#include<string.h>

void pushopr(char);
char popopr();
char peepopr();
void displayopr(); 
void pushout(char);
void displayout();
int getpriority(char);
char opr[20]={'\0'};
char out[20]={'\0'};
int topopr=-1;
int topout=-1;
char ch;
void main()
{
	char infix[20],ele,people;
	int i;
	printf("Enter infix Expression:-");
	scanf("%s",infix);
	printf("\n infx expression is = %s",infix);
	i=strlen(infix)-1;
	while(i>=0)
	{
		ele=infix[i];
		if(ele==')')
		{
			pushopr(ele);
		}
		else if(ele=='(')
		{ 
			while(peepopr()!= ')')
			{
			people=popopr();
			pushout(people);
		}
		popopr();
	}
	else if(ele=='^' || ele== '*' || ele=='/' || ele== '+' || ele=='-')
	{
		if(topopr>=0)
		{
			while(getpriority(poopopr())>=getpriority(ele) && topopr!=-1)
			{
				people=popopr();
				pushout(people);
			}
		}
		pushopr(ele);
	}
	else
	{
		pushout(ele);
	}
	i--;
}
if(topopr!=-1)
{
	while(topopr!=-1)
	{
		people=popopr();
		pushout(people);
	}
}
printf("\n Prefix expression  == %s ",strrev(out));
}
