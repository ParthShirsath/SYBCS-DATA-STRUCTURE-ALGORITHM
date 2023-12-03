#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 6
typedef struct queue{
	int data[MAX];
	int count;
	int front;
	int rear;
}QUEUE;
void init(QUEUE *q)
{
	q->front=q->count=0;
	q->rear=-1;
}
int isempty(QUEUE *q)
{
	if(q->count==-1)
	return 1;
	else
	return 0;
}
int isfull(QUEUE *q)
{
	if(q->count==MAX)
	return 1;
	else
	return 0;
}
void insertr(QUEUE *q,int num)
{
	if(isfull(q))
	{
		printf("QUEUE IS OVERFLOW");
		return;
	}
	q->rear=(q->rear+1)%MAX;
	q->data[q->rear]=num;
	q->count++;
	printf("After Insertion front=%d,rear=%d",q->front,q->rear);
}
void insertf(QUEUE *q,int num)
{
	if(isfull(q))
	{
		printf("QUEUE IS OVERFLOW");
		return;
	}
	if(q->front==0)
	{
		q->front=MAX-1;
	}
	else
	{
		q->front=q->front-1;
	}
	q->data[q->front]=num;
	q->count++;
	printf("\nAfter Insertion front=%d,rear=%d",q->front,q->rear);
}
void deletef(QUEUE *q)
{
	int val;
	if(isempty(q))
	{
		printf("\nQUEUE IS UNDERFLOW");
		return;
	}
	val=q->data[q->front];
	q->front=(q->front+1)%MAX;
	q->count--;
	printf("\nAfter Deletion front=%d,rear=%d",q->front,q->rear);
	printf("\nDeleted Value=%d",val);
}
void deleter(QUEUE *q)
{
	int val;
	if(isempty(q))
	{
		printf("\nQUEUE IS UNDERFLOW");
		return;
	}
	val=q->data[q->rear];
	if(q->rear==0)
	{
		q->rear=MAX-1;
	}
	else
	{
		q->rear=q->rear-1;
	}
	q->count--;
	printf("\nAfter Deletion front=%d,rear=%d",q->front,q->rear);
	printf("\nDeleted Value=%d",val);
}
void display(QUEUE *q)
{
	int i;
	if(isempty(q))
	{
		printf("\nQUEUE IS UNDERFLOW");
		return;
	}
	for(i=q->front;i!=q->rear;i=(i+1)%MAX)
	{
		printf("%d    ",q->data[i]);
	}
	printf("%d",q->data[i]);
}
int main()
{
	int ch,num;
	QUEUE q;
	init(&q);
	do{
		printf("\n1-Enter Data At rear position\n2-Enter Data At front position");
		printf("\n3-Delete Data At rear position\n4-Delete Data At front position");
		printf("\n5-DISPLAY\nEnter choice=");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter Number=");
					scanf("%d",&num);
					insertr(&q,num);
					break;
			case 2:printf("Enter Number=");
					scanf("%d",&num);
					insertf(&q,num);
					break;
			case 3:deleter(&q);
					break;
			case 4:deletef(&q);
					break;
			case 5:display(&q);
					break;
		}
	}while(ch<6);
}
