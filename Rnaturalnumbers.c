#include<stdio.h>
int naturalnumbers(int n)
{
	static int i=1;
	if(n==0)
	return 0;
	else
	{
	printf("%d\t",i);
	i++;
	return naturalnumbers(n-1);
	}
}
int main()
{
	int n;
	printf("Enter Limit=");
	scanf("%d",&n);
	printf("1 to %d numbers=",n);
	naturalnumbers(n);
}
