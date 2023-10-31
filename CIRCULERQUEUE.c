#include<stdio.h>
#define MAX 6
typedef struct queue{
   int data[MAX];
   int front,rear;
}QUEUE;
void init(QUEUE *q)
{
   q->front=q->rear=-1;
}
int isempty(QUEUE *q)
{
   if(q->front==-1)
	return 1;
   else
	return 0;
}
int isfull(QUEUE *q)
{
   if((q->front==0&&q->rear==MAX-1)||(q->front==q->rear+1))
	return 1;
   else
	return 0;
}
void insert(QUEUE *q,int num)
{
   if(isfull(q))
   {
        printf("\nQueue is Full");
   }
   else
   {
	if(q->front==-1)
	{
	   q->front=0;
	}
	q->rear=(q->rear+1)%MAX;
	q->data[q->rear]=num;
	printf("\nInsert successfully");
   }
}
void delq(QUEUE *q)
{
   int val;
   if(isempty(q))
   {
	printf("\nQueue Is Empty");
   }
   else
   {
	val=q->data[q->front];
	   if(q->front==q->rear)
	   {
		q->front=q->rear=-1;
	   }
	q->front=(q->front+1)%MAX;
	printf("Deleted Value=%d",val);
   }
}
void display(QUEUE *q)
{
   int i;
   if(isempty(q))
   {
	printf("\nQueue Is Empty");
   }
   for(i=q->front;i!=q->rear;i=(i+1)%MAX)
   {
	printf("%d\t",q->data[i]);
   }
  printf("%d",q->data[i]);
}
int main()
{
   int ch,num;
   QUEUE q;
   init(&q);
   do{
	printf("\nMENU:-\n1:-INSERT\n2:-DELETE\n3:-DISPLAY\n");
	printf("Enter Choice=");
	scanf("%d",&ch);
	switch(ch)
	{
	   case 1:printf("Enter Value=");
		  scanf("%d",&num);
		  insert(&q,num);
		  break;
	   case 2:delq(&q);
		  break;
	   case 3:display(&q);
  		  break;
	}
   }while(ch<4);
}
