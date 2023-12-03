#include<stdio.h>
#include<stdlib.h>
#define MEMORY (struct node *)malloc(sizeof(struct Node *))
typedef struct node{
	struct node *next,*prev;
	int expo,coef;
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
		newnode->next=newnode->prev=NULL;
		printf("Enter Value of Coefficient and exponant=");
		scanf("%d%d",&newnode->expo,&newnode->coef);
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
NODE *insert(NODE *head,int res1,int res2)
{
	NODE *newnode,*temp;
	newnode=MEMORY;
	newnode->next=NULL;
	newnode->coef=res1;
	newnode->expo=res2;
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
	return head;
}
NODE *poly_mul(NODE *head1,NODE *head2,NODE *head3)
{
	NODE *newnode,*temp1,*temp2;
	int res1,res2;
	temp1=head1;
	temp2=head2;
	while(temp1!=NULL)
	{
		while(temp2!=NULL)
		{
			res1=temp1->coef*temp2->coef;
			res2=temp1->expo+temp2->expo;
			head3=insert(head3,res1,res2);
			temp2=temp2->next;
		}
		temp1=temp1->next;
	}
	return head3;
}
void disp(NODE *head)
{
	NODE *temp;
	for(temp=head;temp->next!=NULL;temp=temp->next)
	{
		printf("%dx^%d+",temp->coef,temp->expo);
	}
		printf("%dx^%d",temp->coef,temp->expo);
}
int main()
{
	NODE *head1=NULL,*head2=NULL,*head3=NULL;
		
	head1=create(head1);
	disp(head1);
	printf("\n\n");
	head2=create(head2);
	disp(head2);
	printf("\n\nMultiplication of Polynomial\n");
	head3=poly_mul(head1,head2,head3);
	disp(head3);
	
}

