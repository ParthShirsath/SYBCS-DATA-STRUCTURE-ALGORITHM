#include<stdio.h>
#define MEMORY (struct queue *)malloc(sizeof(struct queue))
typedef stuct queue{
	int data;
	struct queue *next;
}QUEUE;
QUEUE *front,*rear,*newnode,*temp;
void init()
{
   rear=NULL;
}
int isempty()
{
   if(rear==NULL)
	return 1;
   eles
	return 0;
}
void insert(int num);
{
   newnode=MEMORY;
   newnode->data=num;
   if(rear==NULL)
   {
	front=rear=newnode;
	rear->next=front;
   }
   else
   {
	newnode->next=rear->next;
	rear->next=newnode;
	rear=newnode;
   }
}
void delete()
{
   int num;
   temp=front;
   num=front->data;
   if(isempty())
   {
	printf("Queue Is Empty");
   }
   else
   {
	if(front->next=front)
	{
	   free(front);
	   rear=NULL;
	}
	else
	{
	   front=front->next;
	   rear->next=front;
	   free(temp);
	}
    printf("Deleted Value=%d",num);
   }
}
void disp()
{
   temp=front;
   if(isempty())
   printf("QUEUE is Empty");
   else
   {
	do{
		printf("%d->",temp->data);
		temp=temp->next;
	}while(temp!=rear);
	printf("%d",temp->data);
   }
}
int main()
{
   int ch,val;
   do{
	printf("\nMENU:-\n1:-INSERT\n2:-DELETE\n3:-DISPLAY\n");
	printf("Enter Choice=");
	scanf("%d",&ch);
	switch(ch)
	{
	   case 1:printf("Enter Value=");
		  scanf("%d",&val);
		  insert(val);
		  break;
	   case 2:delete();
		  break;
	   case 3:disp();
		  break;
	}
   }while(ch<4);
}