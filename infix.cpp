#include<stdio.h>
#define MAX 100
struct stack{
    int top;
    char data[MAX];
}s1;
void init()
{
    top=-1;
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
void push(char ch)
{
    if(isfull())
    {
        printf("stack is full now");
    }
    else
    {
        s1.data[s1.top]=ch;
        s1.top++;
    }
}
char pop()
{
    char ch;
    if(isempty())
    {
        printf("Stack Is Empty");
    }
    else
    {
        ch=s1.data[s1.top];
        s1.top--;
        return ch;
    }
}
int priority(char ch)
{
    if(ch=='(')
    return 0;
    if(ch=='+'||ch=='-')
    return 1;
    else if(ch=='/'||ch=='*')
    return 2;
    else if(ch=='$'||ch=='|')
    return 3;
    return 0;
}

int main()
{
    chae infix[100];
    int i;
    printf("Enter Postfix Expression");
    scanf("%s",infix);
    for(i=0;infix[i]!='\0';i++)
    {
        if(isalnum(infix[i]))
        printf("%c",infix[i]);
        else if(infix[i]=='(')
        push(infix[i]);
        else if(infix[i]==')')
        {
            while((ch=pop())!='(')
            print("%c",ch);
        }
        else
        {
            while(priority(s1.data[s1.top])>=priority(infix[i]))
            printf("%c",pop());
        }
    }
    while(!isempty())
    {
        printf("%c",pop());
    }
}
