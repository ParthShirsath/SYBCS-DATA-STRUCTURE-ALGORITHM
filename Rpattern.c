#include<stdio.h>
void pattern(int n)
{
      int i,j,k=1;
	for(i=0;i<n;i++)
	{
	    for(j=0;j<i;j++)
	     {
	     printf("%d  ",k%2);
	     k++;
	     }
	     printf("\n");
	}
}
int main()
{
	int n;
	printf("enter the limit=");
	scanf("%d",&n);
	pattern(n);
}
