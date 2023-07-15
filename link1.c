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
    printf("\nEnter Limit");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter Value=");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            temp=newnode;
            head=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    return head;
}
void disp(struct node * head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("\t%d",temp->data);
        temp=temp->next;
    }
}
struct node * insertbeg(struct node *head,int num)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=head;
    head=newnode;
    return head;
}
struct node * insertlast(struct nkde *head,int num)
{
    struct node *newnode,*temp;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=NULL;
    for(temp=head;temp->next!=NULL;temp=temp->next);
    temp->next=newnode;
    return head;
}
int main()
{
    struct node *head=NULL;
    int ch,num;
    do{
    printf("\nMENU:-\n1-CREATE NEWNODES\n2-DISPLAY DATA");
    printf("\n3-INSERT DATA AT BEGINNING\n4-INSERT DATA AT LAST");
    printf("\nENTER YOUR CHOICE=");
    scanf("%d",&ch);
    switch(ch)
      {
        case 1:head=create(head);
               break;
        case 2:disp(head);
               break;
        case 3:printf("Enter Number To add");
               scanf("%d",&num);
               head=insertbeg(head,num);
               break;
        case 4:printf("Enter Number To add");
               scanf("%d",&num);
               head=insertlast(head,num);
               break;
        default:printf("\nINVALID CHOICE");
      }
    }while(ch<5);
}