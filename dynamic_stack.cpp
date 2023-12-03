#include<stdio.h>
#include<stdlib.h>
#define MEMORY (struct node*)malloc(sizeof(struct node))
typedef struct node{
	int data;
	struct node *next;
}NODE;
NODE *top;
void init()
{
	top=NULL;
}
int isempty()
{
	if(top==NULL)
	return 1;
	else
	return 0;
}
void push(int num)
{
	NODE *newnode;
	newnode=MEMORY;
	newnode->next=top;
	newnode->data=num;
	top=newnode;
	printf("PUSH Successfully");
}
int pop()
{
	int num;
	NODE *temp;
	if(isempty())
	printf("stack is Empty");
	else
	{
		temp=top;
		num=temp->data;
		top=top->next;
		free(temp);
		return num;
	}
}
int peek()
{
	return top->data;
}
void disp()
{
	NODE *temp;
	for(temp=top;temp!=NULL;temp=temp->next)
	{
		printf("%d     ",temp->data);
	}
}
int main()
{
	NODE *temp;
	int ch,num;
	init();
	do{
	printf("\n1-PUSH DATA\n2-POP DATA\n3-PEEK DATA\n4-DISPLAY");
	printf("Enter Choice=");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:printf("enter Number=");
		       scanf("%d",&num);
		       push(num);
		       break;
		case 2:printf("\nDeleted Value=%d",pop());
			   break;
		case 3:printf("\nTop Position Value=%d",peek());
		       break;
		case 4:disp();
	}
}while(ch<5);
}
