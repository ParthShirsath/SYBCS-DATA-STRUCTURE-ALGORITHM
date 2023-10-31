#include<stdio.h>
#include<malloc.h>
#define MEMORY (struct node *)malloc(sizeof(struct node *))
typedef struct node
{
	int data;
	struct node *next,*prev;
}NODE;
int n;
NODE * create(NODE * head)
{
	NODE *newnode,*temp;
	int i;
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
NODE *bubblesort(NODE * head)
{
	NODE *pass,*temp1,*i;
	for(pass=head;pass!=NULL;pass=pass->next)
	{
		for(i=head;i!=pass;i=i->next)
		{
		    if((pass->data)<(i->data))
			{
			    temp1=pass->data;
			    pass->data=i->data;
			    i->data=temp1;
			}
		}
	}
	return head;
}

int main()
{
	NODE *head=NULL;
	head=create(head);
	disp(head);
	printf("\n\n");
	head=bubblesort(head);
	disp(head);
}
