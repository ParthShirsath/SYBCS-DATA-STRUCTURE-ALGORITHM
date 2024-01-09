#include<stdio.h>
int sumofn(int n)
{
	if(n==0)
	return 0;
	else
	return n+sumofn(n-1); 
}
int main()
{
	int n;
	printf("Enter Limit=");
	scanf("%d",&n);
	printf("Sum Of %d Natural Numbers=%d",n,sumofn(n));
	}
