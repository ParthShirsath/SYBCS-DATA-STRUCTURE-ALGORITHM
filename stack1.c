#include<stdio.h>
#include<string.h>
#define MAX 5
struct Stack{
    char name[MAX][30];
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
void push(char sname[30])
{
    if(isfull())
    printf("\nStack Is Full Don't PUSH.........!");
    else
    {
        s1.top++;
        strcpy(s1.name[s1.top],sname);
        printf("\nName Inserted Successfully");
    }
}
void pop()
{
    char nm[20];
    if(isempty())
    printf("Stack Is Empty Don't Pop Now.........!");
    else
    {
        strcpy(nm,s1.name[s1.top]);
        printf("Deleted String=%s",nm);
        s1.top--;
    }
}
void display()
{
    int i;
    for(i=s1.top;i>=0;i--)
    printf("%s\n",s1.name[i]);
}
void main()
{
    int ch;
    char sname[20];
    init();
    do{
        printf("\nMENU:-\n1-Push Name In Stack\n2-Pop Name From Stack\n3-Display Names Of Stack");
        printf("\nEnter Your Choice=");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter Name To Add=");
                   scanf("%s",&sname);
                   push(sname);
                   break;
            case 2:pop();
                   break;
            case 3:display();
                   break;
            default:printf("Invalid Choice.........!");
        }
    }while(ch<4);
}
