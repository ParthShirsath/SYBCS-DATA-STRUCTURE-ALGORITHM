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
NODE *addpoly(NODE *head1,NODE *head2,NODE *head3)
{
	NODE *newnode,*temp1,*temp2,*temp3;
	temp1=head1;
	temp2=head2;
	temp3=head3;
	while((temp1!=NULL)&&(temp2!=NULL))
	{
		newnode=MEMORY;
		newnode->next=NULL;
		if(temp1->expo>temp2->expo)
		{
			newnode->coef=temp1->coef;
			newnode->expo=temp1->expo;
			temp1=temp1->next;
		}
		else if(temp1->expo<temp2->expo)
		{
			newnode->coef=temp2->coef;
			newnode->expo=temp2->expo;
			temp2=temp2->next;
		}
		else
		{
			newnode->coef=temp1->coef+temp2->coef;
			newnode->expo=temp2->expo;
			temp2=temp2->next;
			temp1=temp1->next;
		}
		temp3->next=newnode;
		newnode->prev=temp3;
		temp3=newnode;
	}
	while(temp1!=NULL)
	{
		newnode=MEMORY;
		newnode->next=NULL;
		newnode->coef=temp1->coef;
		newnode->expo=temp1->expo;
		temp1=temp1->next;
		temp3->next=newnode;
		newnode->prev=temp3;
		temp3=newnode;
	}
	while(temp2!=NULL)
	{
		newnode=MEMORY;
		newnode->next=NULL;
		newnode->coef=temp2->coef;
		newnode->expo=temp2->expo;
		temp2=temp2->next;
		temp3->next=newnode;
		newnode->prev=temp3;
		temp3=newnode;
	}
	return head3;
}
void dispadd(NODE *head)
{
	NODE *temp;
	for(temp=head->next;temp->next!=NULL;temp=temp->next)
	{
		printf("%dx^%d+",temp->coef,temp->expo);
	}
		printf("%dx^%d",temp->coef,temp->expo);
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
	NODE *head1=NULL,*head2=NULL;
	NODE *head3;
	head3=MEMORY;
	head3->next=NULL;
	
	head1=create(head1);
	disp(head1);
	printf("\n\n");
	head2=create(head2);
	disp(head2);
	printf("\n\nAddition of Polynomial\n");
	head3=addpoly(head1,head2,head3);
	dispadd(head3);
	
}

