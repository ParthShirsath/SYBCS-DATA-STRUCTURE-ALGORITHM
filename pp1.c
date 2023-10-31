#include<stdio.h>
#define MAX 6
struct queue{
   int data[MAX];
   int front,rear;
}*q;
void init(struct queue *q)
{
   q->front=q->rear=-1;
}
int isempty(struct queue *q)
{
   if(q->front==-1||q->front>q->rear)
	return 1;
   else
	return 0;
}
int isfull(struct queue *q)
{
   if(q->rear==MAX-1)
	return 1;
   else
	return 0;
}
void insert(struct queue *q,int num)
{
   if(isfull(q))
	printf("\n\nQueue Is Overflow");
   else
   {
	if(q->front==-1)
	{
           q->front=0;
	}
   q->rear++;
   q->data[q->rear]=num;
   printf("\n\nInsert Successfully");
   }
}
int delq(struct queue *q)
{
   int val;
   if(isempty(q))
	printf("\n\nQueue Is Undererflow");
   else
   {
   val=q->data[q->front];
   q->front++;
   return val;
   }
}
void display(struct queue *q)
{
   int i;
   if(isempty(q))
   printf("\n\nQueue is underflow");
   else
   {
	for(i=q->front;i<=q->rear;i++)
	printf("%d\t",q->data[q->front]);
   }
}
void displayr(struct queue *q)
{
   int cnt=0,i;
   if(isempty(q))
   printf("\n\nQueue is underflow");
   else
      for(i=q->front;i<=q->rear;i++)
	{
	   cnt++;
	}
      for(i=cnt;i>=q->rear;i--)
	{
	   printf("%d\t",q->data[i]);
	}
}
int main()
{
   struct queue q;
   int ch,val;
   do{
	printf("\nMENU:-\n1:-INSERT\n2:-DELETE\n3:-DISPLAY\n4:-DISPLAY IN REVRESE ORDER");
	printf("\nEnter Choice=");
	scanf("%d",&ch);
	switch(ch)
	{
	   case 1:printf("Enter Value=");
		  scanf("%d",&val);
		  insert(&q,val);
		  break;
	   case 2:val=delq(&q);
		  printf("Deleted Value=%d",val);
		  break;
	   case 3:display(&q);
		  break;
	   case 4:displayr(&q);
		  break;
	}
   }while(ch<5);
}
