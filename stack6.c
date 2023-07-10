#include<stdio.h>
#include<ctype.h>
#define MAX 100
struct stack{
    char a[MAX];
    int top;
}s1:
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
    printf("Stack Is EMPTY......!");
    else
    {
        ch=s1.a[s1.top];
        s1.top--;
        return ch;
    }
}
int precedence(char c)
{
    if(c=='(')
    return 0;
    if(c=='+'||c=='-')
    return 1;
    if(c=='/'||c=='*')
    return 2;
    if(c=='$'||c=='^')
    return 3;
   return 0 ;
}
int main()
{
    char s[100],x;
    int i;
    printf("Enter Infix condition=");
    scanf("%s",s);
    init();
    for(i=0;s[i]!='\0';i++)
    {
        if(isalnum(s[i]))
        printf("%c",s[i]);
        else if(s[i]=='(')
        push(s[i]);
        else if(s[i]==')')
        {
            while((x=pop())!='(')
            printf("%c",x);
        }
        else
        {
            while(precedence(s1.a[s1.top])>=precedence(s[i]))
            {
                printf("%c",pop());
            }
            push(s[i]);
        }
    }
    while(!isempty())
    {
        printf("%c",pop());
    }
}
