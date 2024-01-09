#include<stdio.h>
int armstrong(int n)
{
	static int d,s=0;
	if(n>0)
	{
		d=n%10;
		s=s+(d*d*d);
		n=n/10;
		armstrong(n);
	}
	return s;
}
int main()
{
	int n,n1,n2;
	printf("Enter the number");
	scanf("%d",&n);
	n1=n;
	n2=armstrong(n);
	if(n1==n2)
	printf("Number is Armstrong");
	else
	printf("Number is Not Armstrong");
	
}
