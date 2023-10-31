#include<stdio.h>
#include<malloc.h>
#include<ctype.h>
#define MEMORY (struct node *)malloc(sizeof(struct node))
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
		newnode->next=newnode->prev=NULL;
		printf("Enter Number=");
		scanf("%d",&newnode->data);
		if(head==NULL)
		{
			temp=head=newnode;
		}
		else
     		{
			temp->next=newnode;
			newnode->prev=newnode;
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
void reverse(NODE *head)
{
	int cnt=0;
	NODE *temp;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		cnt++;
	}
	while(cnt>0)
	{
		for(i=1,temp=head;i<cnt;i++)
		{
			temp=temp->next;
		}
		printf("%d->",temp->data);
		cnt--;
	}
}
1
int main()
{
	NODE *head=NULL;
	head=create(head);
	disp(head);
	printf("\n\n");
	reverse(head);
	disp(head);
}
