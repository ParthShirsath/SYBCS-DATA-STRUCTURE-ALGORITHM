#include<stdio.h>
int factorial(int n)
{
	if(n==0)
	return 1;
	else
	return n*factorial(n-1);
}
int main()
{
	int n;
	printf("Enter Number=");
	scanf("%d",&n);
	printf("Factorial of %d=%d",n,factorial(n));
}

