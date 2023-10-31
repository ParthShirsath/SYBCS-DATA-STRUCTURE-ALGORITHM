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
	if(ch=='/'||ch=='*')
	return 2;
	if(ch=='|'||ch=='^')
	return 3;
return 0;
}
int main()
{
	char rev[30],prefix[30],s[30],x;
	int i,j=0,k=0;
	init();
	printf("Enter Infix String=");
	scanf("%s",s);
	
	for(i=0;s[i]!='\0';i++);
	
	for(i=i-1;i>=0;i--)
	{
		rev[j++]=s[i];
	}
	rev[j++]='\0';
	for(i=0;rev[i]!='\0';i++)
	  {
	     if(rev[i]=='(')
	     rev[i]=')';
	     else if(rev[i]==')')
	     rev[i]='(';
	  }
	for(i=0;rev[i]!='\0';i++)
	{
	  if(isalnum(rev[i]))
	  prefix[k++]=rev[i];
	  else if(rev[i]=='(')
	  push(rev[i]);
	  else if(rev[i]==')')
	  {
		while((x=pop())!='(')
		prefix[k++]=x;
	  }
	  else
	  {
		while(priority(s1.a[s1.top])>=priority(rev[i]))
		{
			prefix[k++]=pop();
		}
	  push(rev[i]);
	  }
	}
	while(!isempty())
	{
	   prefix[k++]=pop();
	}
	prefix[k++]='\0';
	for(i=0;prefix[i]!='\0';i++)
	for(i=i-1;i>=0;i--)
	{
		printf("%c",prefix[i]);
	}
}