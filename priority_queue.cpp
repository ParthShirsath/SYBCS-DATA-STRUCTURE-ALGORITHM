#include<stdio.h>
#define MAX 7
#include<stdlib.h>
	int front,rear;
	int data[MAX];
void init()
{
	front=rear=-1;
}
int isfull()
{
	if(rear>=MAX-1)
	return 1;
	else
	return 0;
}
int isempty()
{
	if(rear==-1)
	return 1;
	else
	return 0;
}
void check(int num)
{
	int i,j;
	for(i=0;i<=rear;i++)
	{
		if(data[i]>num)
		{
			for(j=rear+1;j>i;j--)
			{
				data[j]=data[j-1];
			}
			data[i]=num;
			return;
		}
	}
	data[i]=num;
}
void insert(int num)
{
	if(isfull())
	{
		printf("QUEUE IS OVERFLOW");
		return;
	}
	if(front==-1||rear==-1)
	{
		front=rear=0;
		data[rear]=num;
		return;
	}
	else
	{
		check(num);
	}
	rear++;
}
void deleteq()
{
	int num,i,k;
	printf("Enter number TO delete");
	scanf("%d",&num);
	if(isempty())
	{
		printf("QUEUE IS UNDEERFLOW");
		return;
	}
	for(i=0;i<=rear;i++)
	{
		if(data[i]==num)
		{
			for(k=i;k<rear;k++)
			{
				data[k]=data[k+1];
			}
			data[k]=-1;
			rear--;
			if(rear==-1)
			front=-1;
		}
	}
}
void display()
{
	int i;
	if(isempty())
	{
		printf("\nQUEUE IS UNDERFLOW");
		return;
	}
	for(i=front;i!=rear;i++)
	{
		printf("%d    ",data[i]);
	}
	printf("%d",data[i]);
}

int main()
{
	int ch,num;
	init();
	do{
	printf("\n1-Insert\n2-Delete\n3-Display\nEnter Your choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:printf("Enter Number=");
				scanf("%d",&num);
				insert(num);
				break;
		case 2:deleteq();
				break;
		case 3:display();
	}
	}while(ch<4);
}
