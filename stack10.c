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
int pop()
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
int main()
{
    char c[100];
    int i,p,q,r,s,val1,val2,res=0;
    printf("Enter Postfix Expression in P Q R S form=");
    scanf("%s",c);
    printf("Enter Value For P Q R S=");
    scanf("%d%d%d%d",&p,&q,&r,&s);
    init();
    for(i=0;c[i]!='\0';i++)
    {
        if(isalpha(c[i]))
        switch(c[i])
        {
            case 'P':push(p);
                     break;
            case 'Q':push(q);
                     break;
            case 'R':push(r);
                     break;
            case 'S':push(s);
                     break;
        }
        else
        {
            val1=pop();
            val2=pop();
            switch(c[i])
            {
            case '+':res=val2+val1;
                     push(res);
                     break;
            case '-':res=val2-val1;
                     push(res);
                     break;
            case '*':res=val2*val1;
                     push(res);
                     break;
            case '/':res=val2/val1;
                     push(res);
                     break;    
            }
        }
    }
    printf("\nRESULT=%d",res);
}