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
    printf("Linklist create successfully");
    return head;
}
void disp(NODE *head)
{
    NODE *temp;
    for(temp=head;temp!=NULL;temp=temp->next)
    printf("%d",temp->data);
}
int main()
{
    NODE head1=NULL,head2=NULL,head3;
    head1=create(head1);
    disp(head1);
    head2=create(head2);
    disp(head2);
}
