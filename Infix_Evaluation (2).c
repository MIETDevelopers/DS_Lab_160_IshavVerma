#include<stdio.h>
#include<stdlib.h>
int first_ap,last_alph,result,a,b,c,d,e,f,g,h,i,j;
char user_exp;
int main()
{
    printf("Enter the logical expression: ");
    scanf("%s", &user_exp);

    printf("Enter last variable used: ");
    scanf("%c", &last_alph);
    
    for(first_ap=a; first_ap<=last_alph; first_ap++)
    {
        printf("Enter value for %c: ", first_ap);
        scanf("%c",first_ap);
    }

    result=user_exp;
    printf("%d", result);

return 0;
}