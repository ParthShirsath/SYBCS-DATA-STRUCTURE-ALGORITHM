#include<stdio.h>
#include<string.h>
struct Student{
    int rno;
    char sname[30];
    float per;
}s1[100];
int main()
{
    int top,mid,bottom,n,i,flag=0;
    char name[30];
    printf("Enter Limit");
    scanf("%d",&n);
    printf("Enter Student Roll_no,name,percentage=\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%s%f",&s1[i].rno,&s1[i].sname,&s1[i].per);
    }
    printf("enter Student Name to Search record=");
    scanf("%s",&name);
    while(top<=bottom)
    {
        mid=(top+bottom)/2;
        if(strcmp(name,s1[mid].sname)==0)
        {
            flag=1;
            break;
        }
        if(strcmp(name,s1[mid].sname)>0)
        top=mid+1;
        else
        bottom=mid-1;
    }
    if(flag==1)
    printf("Record Is Found....");
    else
    printf("Record Not Found......!");
}
