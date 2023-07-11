#include<stdio.h>
#include<ctype.h>
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
    printf("Stack Is Empty Now.......!");
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
    int i,j=0;
    char infix[100],postfix[100],c;
    printf("Enter Sting=");
    scanf("%s",infix);
    init();
    for(i=0;infix[i]!='\0';i++)
    {
        if(isalpha(infix[i]))
        {
            postfix[j++]=infix[i];
        }
        else if(infix[i]=='(')
        push(infix[i]);
        else if(infix[i]==')')
        {
            while((c=pop())!='(')
            {
                postfix[j++]=c;
            }
        }
        else
        {
            while(precedence(s1.a[s1.top])>=precedence(infix[i]))
            {
                postfix[j++]=pop();
            }
            push(infix[i]);
        }
    }
    while(!isempty())
    {
        postfix[j++]=pop();
    }
    postfix[j++]='\0';
    printf("\nPostfix Output=%s",postfix);
}