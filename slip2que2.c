#include<stdio.h>
#define MAX 20
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
void push(char ch)
{
	if(isfull())
	printf("stack is overflow");
	else
	{
		s1.top++;
		s1.a[s1.top]=ch;
	}
}
char pop()
{
	char ch;
	if(isempty())
	printf("stack is underflow");
	else
	{
		ch=s1.a[s1.top];
		s1.top--;
		return ch;
	}
}
/*int peek()
{
	return s1->a[s1->top];
}*/
void disp()
{
	int i;
	for(i=s1.top;i>=0;i--)
	printf("%c",s1.a[i]);
}
int main()
{
int ch,n,val,i,k;
char name[20],temp[20];
init();

printf("Enter Name");
scanf("%s",name);
for(i=0;name[i]!='\0';i++)
push(name[i]);
while(!isempty())
{
temp[k]=pop();
k++;
}
temp[k]='\0';
printf("second string=");
for(i=0;temp[i]!='\0';i++)
push(temp[i]);

while(!isempty())
{
printf("%c",pop());
}
}