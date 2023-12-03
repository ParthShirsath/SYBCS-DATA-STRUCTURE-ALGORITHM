/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>
#include<ctype.h>
#define MAX 25
struct stack{
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
void push(char x)
{
	if(isfull())
	printf("Stack Is Full Now");
	else
	{
	   s1.top++;
	   s1.a[s1.top]=x;
	}
}
char pop()
{
	char ch;
	if(isempty())
	printf("Stack Is Empty Now");
	else
	{
	  ch=s1.a[s1.top];
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
	if(ch=='*'||ch=='/')
	return 2;
	if(ch=='$'||ch=='^')
	return 3;
	return 0;
}
int main()
{
	char s[100],ch;
	int i;
	printf("Enter Infix Expression");
	scanf("%s",s);
	init();
	for(i-0;s[i]!='\0';i++)
	{
		if(isalnum(s[i]))
		printf("%c",s[i]);
		else if(s[i]=='(')
		push(s[i]);
		else if(s[i]==')')
		{
			while((ch=pop())!='(')
			printf("%c",ch);
		}
		else
		{
			while(priority(s1.a[s1.top])>=priority(s[i]))
			printf("%c",s1.a[s1.top]);
			push(s[i]);
		}
	}
	while(!isempty())
	{
		printf("%c",pop());
	}
}
