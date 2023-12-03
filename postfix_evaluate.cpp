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
int main()
{
	char s[30];
	int a,b,c,d,val1,val2,res=0,i;
	init();
	printf("Enter Postfix String=");
	scanf("%s",&s);
	printf("Enter The Value Of A,B,C,D");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(i=0;s[i]!='\0';i++)
	{
		if(isalnum(s[i]))
		  {
		     switch(s[i])
			{
			    case 'A':push(a);
				   break;
			    case 'B':push(b);
				   break;
			    case 'C':push(c);
				   break;
			    case 'D':push(d);
				   break;
			}
		  }
		 else
		   {
		       val1=pop();
		       val2=pop();
		       switch(s[i])
			  {
	    		 case '+':res=val2+val1;
				      break;
			     case '-':res=val2-val1;
				      break;
 			     case '*':res=val2*val1;
				      break;
  			     case '/':res=val2/val1;
				      break;
			  }
		  push(res);
		   }
	}
	printf("\nRESULT=%d",res);
}
