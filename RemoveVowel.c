//A C program to read whole string entered by user and to print it after removing vowels.      © Ishav Verma 14/June/2021
#include<stdio.h>
#include<stdlib.h>
int main()
{
    char str[100];
    int i=0, j, chk;
    printf("Enter String: ");
    gets(str); //This will read the string entered by user.
    while(str[i]!='\0')
    {
        chk=0;
        //if-else statement will read each alphabet of the string nd determine whether it's vowel or not.
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
        {
            //This process will remove the vowel and shift the elements in string a step back.
            j=i;
            while(str[j-1]!='\0')
            {
                str[j] = str[j+1];
                j++;
            }
            chk = 1;
        }
        if(chk==0)
            i++;
    }
    printf("\nAfter removing vowels from the entered string: '%s' ", str);
    exit(0);
    return 0;
}