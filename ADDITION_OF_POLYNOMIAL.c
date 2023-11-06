#include<stdio.h>
#include<malloc.h>
#define MEMORY (struct node *)malloc(sizeof(struct node))
typedef struct node
{
	int c,e;
	struct node *next;
}NODE;
NODE * create(NODE * head)
{
	NODE *newnode,*temp;
	int i,n;
	printf("Enter Limit of polynomial=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=MEMORY;
		newnode->next=NULL;
		printf("Enter Value of coefficient and exponant=");
		scanf("%d%d",&newnode->c,&newnode->e);
		if(head==NULL)
		{
			temp=head=newnode;
		}
		else
     		{
			temp->next=newnode;
			temp=newnode;
		}
	}
	return head;
}

void disp(NODE *head)
{
	NODE *temp;
	for(temp=head;temp!=NULL;temp=temp->next)
	printf("%dx^%d+",temp->c,temp->e);
}

void dispadd(NODE *head)
{
	NODE *temp;
	for(temp=head->next;temp!=NULL;temp=temp->next)
	printf("<%dx^%d>+",temp->c,temp->e);
}

NODE * addpoly(NODE * head1,NODE *head2,NODE *head3)
{
	NODE *newnode,*temp1,*temp2,*temp3;
	temp1=head1;
	temp2=head2;
	temp3=head3;
	while((temp1!=NULL)&&(temp2!=NULL))
	{
		newnode=MEMORY;
		newnode->next=NULL;
		if(temp1->e>temp2->e)
		{
		   newnode->c=temp1->c;
		   newnode->e=temp1->e;
		   temp1=temp1->next;
 		}
		else if(temp1->e<temp2->e)
		{
		   newnode->c=temp2->c;
		   newnode->e=temp2->e;
		   temp2->next=temp2->next;
		}
		else
		{
		   newnode->c=temp1->c+temp2->c;
		   newnode->e=temp1->e;
		   temp1=temp1->next;
		   temp2=temp2->next;
		}
	temp3->next=newnode;
	temp3=newnode;
	}
	while(temp1!=NULL)
	{
		newnode=MEMORY;
		newnode->next=NULL;
		newnode->e=temp1->e;
		newnode->c=temp1->c;
		temp3->next=newnode;
		temp3=newnode;
		temp1=temp1->next;
	}
	
	while(temp2!=NULL)
	{
		newnode=MEMORY;
		newnode->next=NULL;
		newnode->e=temp2->e;
		newnode->c=temp2->c;
		temp3->next=newnode;
		temp3=newnode;
		temp2=temp2->next;
	}
	return head3;
}
int main()
{
	NODE *head1=NULL,*head2=NULL,*head3;
	head3=MEMORY;
	head3->next=NULL;
	head1=create(head1);
	disp(head1);
	printf("\n\n");
	head2=create(head2);
	disp(head2);
	head3=addpoly(head1,head2,head3);
	dispadd(head3);
}
