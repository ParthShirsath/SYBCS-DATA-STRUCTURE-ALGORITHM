#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct city{
    char cname[20];
    int stdcode;
}c1[100];
void binarysearch(struct city c1[100],int top,int bottom)
{
    int mid;
    char cityname[100];
    printf("Enter City Name To Search");
    scanf("%s",&cityname);
    while(top<=bottom)
    {
        mid=(top+bottom)/2;
        if(strcmp(c1[mid].cname,cityname)==0)
        {
            printf("stdcode=%d",c1[mid].stdcode);
			break;
        }
        if(strcmp(c1[mid].cname,cityname)<0)
        top=mid+1;
        else
        bottom=mid-1;
    }
    if(top>bottom)
    printf("City NOT FOUND in the File");
}
int main()
{
    FILE *fp1;
    fp1=fopen("cities.txt","r");
    if(fp1==NULL)
    {
        printf("File Is Empty");
        exit(0);
    }
    int i=0;
    while(!feof(fp1))
    {
        fscanf(fp1,"%s%d",&c1[i].cname,&c1[i].stdcode);
        i++;
    }
    int j=i;
    fclose(fp1);
    binarysearch(c1,0,j-1);
}
