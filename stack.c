#include<stdio.h>
#define MAX 5
struct Stack{
    int a[MAX];
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
void push(int num)
{
    if(isfull())
    printf("\nStack Is Full Don't Push......!");
    else
    {
        s1.top++;
        s1.a[s1.top]=num;
        printf("\nNumber Push Successfully");
    }
}
void pop()
{
    int num;
    if(isempty())
    printf("Stack Is Empty...Don't Pop Now.........!");
    else{
        num=s1.a[s1.top];
        s1.top--;
        printf("Deleted Element=%d",num);
    }
}
void display()
{
    int i;
    for(i=s1.top;i>=0;i--)
    printf("%d\n",s1.a[i]);
}
int main()
{
    int num,ch;
    init();
    do{
        printf("\nMENU:-\n1-Push Elements In Stack\n2-Pop Elements From Stack\n3-Display Elements Of Stack");
        printf("\nEnter Your Choice=");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("\nEnter Number=");
                   scanf("%d",&num);
                   push(num);
                   break;
            case 2:pop();
                   break;
            case 3:display();
                   break;
            default:printf("Invalid Choice");
        }
    }while(ch<4);
}