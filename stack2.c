#include<stdio.h>
#define MAX 10
struct Stack{
    char s[MAX];
    int top;
}s1;
void init()
{
    s1.top=-1;
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
    {

    }
    else
    {
        s1.top++;
        s1.s[s1.top]=c;
    }
}
void disp()
{
    int i;
    for(i=s1.top;i>=0;i--)
    {
        printf("%c",s1.s[i]);
    }
}

int main()
{
    int i;
    char s2[100];
    printf("Enter The String=");
    scanf("%s",s2);
    init();
    for(i=0;s2[i]!='\0';i++)
    {
        push(s2[i]);
    }
    printf("\nString=");
    disp();
}