#include<stdio.h>
#include<malloc.h>
#include<ctype.h>
#define MEMORY (struct node *)malloc(sizeof(struct node))
typedef struct node{
    int data;
    struct node *next,*prev;
}NODE;
NODE *create(NODE *head)
{
    NODE *newnode,*temp;
    int n,i;
     printf("Enter limit=");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newnode=MEMORY;
        newnode->next=newnode->prev=NULL;
        printf("enter number");
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
    {
        printf("%d    ",temp->data);
    }
}
void even(NODE *head)
{
    NODE *temp;
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        if(temp->data%2==0)
        {
            printf("%d\t",temp->data);
        }
    }
}
int main()
{
    NODE *head=NULL;
    head=create(head);
    disp(head);
    printf("\n\n");
    even(head);
}