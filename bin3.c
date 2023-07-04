#include<stdio.h>
#include<string.h>
int main(){
    int n,i,flag;
    int search(int n,char s1[30][30],char name[20]);
    printf("Enter Limit=");
    scanf("%d",&n);
    char s1[30][30];
    printf("Enter N Cities Name in Alphabetical order=");
    for(i=0;i<n;i++)
    scanf("%s",s1[i]);
    char name[20];
    printf("Enter Name To found=");
    scanf("%s",name);
    flag=search(n,s1,name);
    if(flag==1)
    printf("Name Is Found");
    else
    printf("Name Is Not Found.........");
}
int search(int n,char s1[30][30],char name[20])
{
    int top=0,bottom=n-1,mid,flag=0;
    while(top<=bottom)
    {
        mid=(top+bottom)/2;
        if(strcmp(s1[mid],name)==0)
        {
            flag=1;
            break;
        }
        if(strcmp(s1[mid],name)<0)
        top=mid+1;
        else
        bottom=mid-1;
    }
    return flag;
}
