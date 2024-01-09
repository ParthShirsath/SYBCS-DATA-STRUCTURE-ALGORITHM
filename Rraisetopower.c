#include<stdio.h>
int raisetopower(int x,int y)
{
	if(y==0)
	return 1;
	else
	return x*raisetopower(x,y-1);
}
int main()
{
	int x,y;
	printf("Enter Value of x and y");
	scanf("%d%d",&x,&y);
	printf("x^y=%d",raisetopower(x,y));
}
