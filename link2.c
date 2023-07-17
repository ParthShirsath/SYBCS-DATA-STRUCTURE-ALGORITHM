#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
    int data;
    struct node *next;
};
struct node *create(struct node *head)
{
    int i,n;
    struct node *newnode,*temp;
    printf("Enter Limit=");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter Value=");
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
struct node * insertbeg(struct node *head,int num)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=head;
    head=newnode;
    return head;
}
struct node * insertend(struct node *head,int num)
{
    struct node *newnode,*temp;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=NULL;
    for(temp=head;temp->next!=NULL;temp=temp->next);
    temp->next=newnode;
    return head;
}
struct node * insertmid(struct node *head,int pos,int num)
{
    int i;
    struct node *newnode,*temp;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    for(i=1,temp=head;i<(pos-1)&&temp->next!=NULL;temp=temp->next,i++);
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}
struct node * deletebeg(struct node *head)
{
    struct node *temp;
    temp=head;
    head=head->next;
    free(temp);

    printf("\ndelete record successfully....");
    return head;
}
struct node * deletelast(struct node *head)
{
    struct node * temp,*temp1;
    for(temp=head;temp->next->next!=NULL;temp=temp->next);
    temp1=temp->next;
    temp->next=NULL;
    free(temp1);
    printf("Delete Record successfully.....");
    return head;
}
struct node * deletemid(struct node * head,int pos)
{
    struct node *temp,*temp1;
    int i;
    for(i=1,temp=head;i<(pos-1)&&temp->next!=NULL;i++,temp=temp->next);
    temp1=temp->next;
    temp->next=temp1->next;
    free(temp1);
    return head;
}
int main()
{
    int ch,num,pos;
    struct node * head=NULL;
    do{
        printf("\n\nMENU:-\n1:-create linklist\n2:-insert at Begining");
        printf("\n3:-inset at End\n4:-insert at Mid");
        printf("\n5:-delete at start\n6:-delete at last");
        printf("\n7:-delete at Mid\n8:-Display\n");
        printf("ENter Choice=");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:head=create(head);
                   break;
            case 2:printf("\nEnter Number To Add");
                   scanf("%d",&num);
                   head=insertbeg(head,num);
                   break;
            case 3:printf("\nEnter Number To Add");
                   scanf("%d",&num);
                   head=insertend(head,num);
                   break;
            case 4:printf("\nEnter Number To Add");
                   scanf("%d",&num);
                   printf("\nEnter position");
                   scanf("%d",&pos);
                   head=insertmid(head,pos,num);
                   break;
            case 5:head=deletebeg(head);
                   break;
            case 6:head=deletelast(head);
                   break;
            case 7:printf("Enter Position=");
                   scanf("%d",&pos);
                   head=deletemid(head,pos);
                   break;
            case 8:disp(head);
                   break;
            default:printf("Invalid choice");
        }
    }while(ch<9);
}