#include<stdio.h>
#include<string.h>
#define MAX 100
struct stack{
    char a[MAX];
    int top;
}s1;
struct stack1{
    char b[MAX];
    int top;
}s2;
void init()
{
    s1.top=-1;
    s2.top=-1;
}
int isempty()
{
    if(s1.top==-1||s2.top==-1)
    return 1;
    else
    return 0;
}
int isfull()
{
    if(s1.top==MAX-1||s2.top==MAX-1)
    return 1;
    else
    return 0;
}
void push(char ch,char c)
{
    if(isfull())
    printf("Stack IS Fulll");
    else
    {
        s1.top++;
        s1.a[s1.top]=ch;
        s2.top++;
        s2.b[s2.top]=c;
    }
}
void compare()
{
    int flag=0,i,j;
    for(i=s1.top,j=s2.top;i>=0&&j>=0;i--,j--)
    if(s1.a[i]!=s2.b[j])
    {
        flag=1;
    }
    if(flag==0)
    printf("\nSTRINGS ARE SAME.....");
    else
    printf("\nSTRINGS IS NOT EQUAL.....!");
}
int main()
{
    int i;
    char s[100],st[100];
    printf("ENTER FIRST STRING=");
    gets(s);
    printf("ENTER SECOND STRING=");
    gets(st);
    for(i=0;s[i]!='\0'||st[i]!='\0';i++)
    {
        push(s[i],st[i]);
    }
    compare();
}