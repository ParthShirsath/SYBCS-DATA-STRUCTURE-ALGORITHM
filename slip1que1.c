#include<stdio.h>
#include<malloc.h>
#define MEMORY (struct node *)malloc(sizeof(struct node *))
typedef struct node
{
	int data;
	struct node *next,*prev;
}NODE;
NODE * create(NODE * head)
{
	NODE *newnode,*temp;
	int i,n;
	printf("Enter Limit=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=MEMORY;
		printf("Enter Number=");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(head==NULL)
		{
			temp=head=newnode;
		}
		else
     		{
			temp->next=newnode;
			newnode->prev=temp;
			temp=newnode;
		}
	}
	return head;
}
void disp(NODE *head)
{
	NODE *temp;
	for(temp=head;temp!=NULL;temp=temp->next)
	printf("%d\t",temp->data);
}
int main()
{
	NODE *head=NULL;
	int ch;
	do{
	printf("\nMENU:-\n1:-create\n2:-display\n3:-Exit");
	printf("Enter Choice=");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:head=create(head);
		       break;
		case 2:disp(head);
		       break;
	}
	}while(ch<3);
}
