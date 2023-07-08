#include<stdio.h>
#define MAX 100
struct stack{
    char a[MAX];
    int top;
}s1;
void init()
{
    s1.top=-1;
}
int isempty()
{
    if(s1.top==-1)
    return 1;
    else
    return 0;
}
int isfull()
{
    if(s1.top==MAX-1)
    return 1;
    else
    return 0;
}
void push(char c)
{
    if(isfull())
    printf("\nStack Is Full.....!");
    else
    {
        s1.top++;
        s1.a[s1.top]=c;
    }
}
char pop()
{
    char ch;
    if(isempty())
    printf("\nStack IS Empty.....!");
    else
    {
        ch=s1.a[s1.top];
        s1.top--;
        return ch;
    }
}
int main()
{
    int i;
    char s[MAX];
    printf("Enter String=");
    scanf("%s",s);
    init();
    for(i=0;s[i]!='\0';i++)
    {
        push(s[i]);
    }
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]!=pop())
        break;
    }
    if(isempty())
    printf("\nString Is Palindrome.....");
    else
    printf("\nString Is Not Palindrome.....");
}