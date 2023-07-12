#include<stdio.h>
#include<ctype.h>
#include"prefix.h"
int main()
{
    int i,j=0,k=0;
    char infix[100],prefix[100],rev[100],x;
    printf("Enter string");
    scanf("%s",infix);
    for(i=0;infix[i]!='\0';i++);
    for(i=i-1;i>=0;i--)
    {
        rev[j++]=infix[i];
    }
    rev[j++]='\0';
    init();
    for(i=0;rev[i]!='\0';i++)
    {
        if(rev[i]=='(')
        rev[i]=')';
        else if(rev[i]==')')
        rev[i]='(';
    }
    for(i=0;rev[i]!='\0';i++)
    {
        if(isalpha(rev[i]))
        prefix[k++]=rev[i];
        else if(rev[i]=='(')
        push(rev[i]);
        else if(rev[i]==')')
        {
            while((x=pop())!='(')
            prefix[k++]=x;
        }
        else
        {
            while(precedence(s1.a[s1.top])>=precedence(rev[i]))
            prefix[k++]=pop();
            push(rev[i]);
        }
    }
    while(!isempty())
        {
            prefix[k++]=pop();
        }
    prefix[k++]='\0';
    for(i=0;rev[i]!='\0';i++);
    for(i=i-1;i>=0;i--)
    printf("%c",prefix[i]);
}