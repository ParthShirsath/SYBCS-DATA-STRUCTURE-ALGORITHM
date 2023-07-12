#include<stdio.h>
#define MAX 100
struct Stack{
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
void push(char nm)
{
    if(isfull())
    printf("\nStack Is Full Don't Push......!");
    else
    {
        s1.top++;
        s1.a[s1.top]=nm;
    }
}
void disp()
{
    int i;
    for(i=s1.top;i>=0;i--)
    printf("%c",s1.a[i]);
}
int main()
{
    int i;
    char c[100];
    printf("Enter String=");
    gets(c);
    for(i=0;c[i]!='\0';i++)
    {
        if(c[i]==' ')
        {
            disp();
            init();
        }
        else
        {
            push(c[i]);
        }
    }
    disp();
}