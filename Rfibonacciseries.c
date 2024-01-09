#include<stdio.h>
void fibonacci(int n)
{
	static int f=0,s=1,t;
	if(n>0)
	{
	        t=f+s;
	        printf("%d\t",t);
	        f=s;
	        s=t;
	        fibonacci(n-1);
	}
}
int main()
{
	int n;
	printf("Enter The Limit=");
	scanf("%d",&n);
	printf("0\t1\t");
	fibonacci(n);	
}
