#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
    int data;
    struct node *next;
};
struct node * create(struct node *head)
{
    int i,n;
    struct node *newnode,*temp;
    printf("Enter Limit=");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
         newnode=(struct node *)malloc(sizeof(struct node *));
        printf("Enter VALUE=");
        scanf("%d",&newnode->data);
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
void disp(struct node *head)
{
    struct node *temp;
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        printf("%d\t",temp->data);
    }
}
int main()
{
    struct node *head;
    head=NULL;
    head=create(head);
    disp(head);
}