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
void reverse(NODE *head)
{
	int cnt=0,i;
	NODE *temp;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		cnt++;
	}
	while(cnt>0)
	{
		for(i=0,temp=head;i<cnt;i++)
		{
			temp=temp->next;
		}
		printf("%d->",temp->data);
		cnt--;
	}
}
int main()
{
	NODE *head=NULL;
	head=create(head);
	disp(head);
	printf("\n\n");
	reverse(head);
}
