#include<stdio.h>
int reverse(int n)
{
	static int r=0;
	int d;
	if(n>0)
	{
		d=n%10;
		r=(r*10)+d;
		n=n/10;
		return reverse(n);
	}
	return r;
}
int main()
{
	int n;
	printf("Enter Number=");
	scanf("%d",&n);
	printf("reverse of %d=%d",n,reverse(n));
}
