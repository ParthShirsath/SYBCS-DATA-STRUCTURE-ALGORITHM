#include<stdio.h>
int perfect(int n)
{
    static int i=1,s=0;
    if(i<n)
    {
    if(n%i==0)
	 s=s+i;
	 i++;
     perfect(n);
    }
    if(s==n)
        return s;
    else	
        return 0;
}
int main()
{
	int n,p;
	printf("Enter Number to check the Number Is Perfect or Not=");
	scanf("%d",&n);
	p=perfect(n);
	if(p==0)
	printf("Number is not Perfect");
	else
	printf("Number is Perfect");
}
