#include<stdio.h>
#define MAX 6
typedef struct{
   int data[MAX],front,rear,cnt;
}DEQueue;
void init(DEQueue *q)
{
   q->front=q->cnt=0;
   q->rear=-1;
}
int isempty(DEQueue *q)
{
   int empty=0;
   if(q->rear==-1)
   empty=1;
	return empty;
}
int isfull(DEQueue *q)
{
   int full=0;
   if(q->cnt==MAX)
   full=1;
	return full;
}
void insertf(DEQueue *q,int num)
{
   if(isfull(q))
   {
        printf("Queue Is Full Now");
        return;
   }
   else
   {
	if(q->front==0)
	q->front=MAX-1;
	else
	q->front=q->front-1;
	q->data[q->front]=num;
	q->cnt--;
	printf("\nAfter Insertion FRONT::%d\nREAR::%d",q->front,q->rear);
	printf("\nInserted Value::%d",num);
   }
}
void insertr(DEQueue *q,int num)
{
   if(isfull(q))
   {
        printf("Queue Is Full Now");
        return;
   }
  
	q->rear=(q->rear+1)%MAX;
	q->data[q->rear]=num;
	q->cnt++;
	printf("\nAfter Insertion FRONT::%d\nREAR::%d",q->front,q->rear);
	printf("\nInserted Value::%d",num);

}
int deletef(DEQueue *q)
{
   int val;
   if(isempty(q))
   {
	printf("Queue Is empty Now");
	return -1;
   }
   val=q->data[q->front];
   q->front=(q->front+1)%MAX;
   q->cnt--;
   printf("\nAfter Insertion FRONT::%d\nREAR::%d",q->front,q->rear);
   return val;
}
int deleter(DEQueue *q)
{
   int val;
   if(isempty(q))
   {
	printf("Queue Is empty Now");
	return -1;
   }
   val=q->data[q->rear];
   if(q->rear==0)
   q->rear=MAX-1;
   else
   q->rear=q->rear-1;
   q->cnt--;
   printf("\nAfter Insertion FRONT::%d\nREAR::%d",q->front,q->rear);
   return val;
}
int main()
{
   int ch,val;
   DEQueue q;
   init(&q);
   do{
	printf("\nMENU:-\n1:-INSERT AT REAR\n2:-INSERT AT FRONT\n3:-DELETE AT REAR\n");
   	printf("DELETE AT FRONT");
	printf("Enter Choice=");
	scanf("%d",&ch);
	switch(ch)
	{
	   case 1:printf("\nEnter Value=");
		  scanf("%d",&val);
		  insertr(&q,val);
		  break;
    	   case 2:printf("\nEnter Value=");
		  scanf("%d",&val);
		  insertf(&q,val);
		  break;  
	   case 3:val=deleter(&q);
		  printf("\nDeleted Value=%d",val);
		  break;
	   case 4:val=deletef(&q);
  		  printf("\nDeleted Value=%d",val);
		  break;
	}
   }while(ch<5);
}
