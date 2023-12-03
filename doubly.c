#include<stdio.h>
#define MEMORY (struct node *)malloc(sizeof(struct Node *))
typedef struct node{
	struct node *next,*prev;
	int data;
}NODE;
NODE *create(NODE *head)
{
	NODE *temp,*newnode;
	int i,n;
	printf("Enter Limit=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=MEMORY;
		newnode->next=NULL;
		printf("Enter Number=");
		scanf("%d",&newnode->data);
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
	{
		printf("%d\t",temp->data);
	}
}
int main()
{
	NODE *head=NULL;
	head=create(head);
	disp(head);
}
