#include<stdio.h>
#define MEMORY (struct node *)malloc(sizeof(struct node*))
typedef struct node{
    int data;
    struct node *next;
}NODE;
NODE *create(NODE *head)
{
    NODE *temp,*newnode;
    int n,i;
    printf("enter how many numbers of node=");
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
            temp=newnode;
        }
    }
    printf("\nLinklist create successfully");
    return head;
}
void disp(NODE *head)
{
    NODE *temp;
    for(temp=head;temp!=NULL;temp=temp->next)
    printf("%d\t",temp->data);
}
NODE *merge(NODE *head1,NODE *head2,NODE *head3)
{
	NODE *temp1,*temp2,*temp3,*newnode;
	temp1=head1;
	temp2=head2;
	temp3=head3;
	while((temp1!=NULL) && (temp2!=NULL))
	{
		newnode=MEMORY;
		newnode->next=NULL;
		if((temp1->data)<(temp2->data))
		{
			newnode->data=temp1->data;
			temp1=temp1->next;
		}
		else
		{
			newnode->data=temp2->data;
			temp2=temp2->next;
		}
	temp3->next=newnode;
	temp3=newnode;
	}
	while(temp1!=NULL){
	newnode=MEMORY;
	newnode->next=NULL;
	newnode->data=temp1->data;
	temp1=temp1->next;
	temp3->next=newnode;
	temp3=newnode;
	}
	while(temp2!=NULL){
	newnode=MEMORY;
	newnode->next=NULL;
	newnode->data=temp2->data;	
	temp2=temp2->next;
	temp3->next=newnode;
	temp3=newnode;
	}
	return head3;
}
void dispmerge(NODE *head3)
{
	NODE *temp;
    for(temp=head3->next;temp!=NULL;temp=temp->next)
    printf("%d\t",temp->data);
}
int main()
{
    NODE *head1=NULL,*head2=NULL,*head3;
    head3=MEMORY;
    head3->next=NULL;
    head1=create(head1);
    printf("\n\n");
    disp(head1);
    head2=create(head2);
    printf("\n\n");
    disp(head2);
    printf("\n\n");
    head3=merge(head1,head2,head3);
    dispmerge(head3);
}
