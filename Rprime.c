#include<stdio.h>
int prime(int n)
{
	static int i=2;
	if(n%i==0)
	{
	    i++;
	    return 0;
	}
	return 1;
}
int main()
{
	int n,p;
	printf("Enter Number to check the Number Is Prime or Not");
	scanf("%d",&n);
	p=prime(n);
	if(p==1)
	printf("Number is Prime");
	else
	printf("Number is not Prime");
}
