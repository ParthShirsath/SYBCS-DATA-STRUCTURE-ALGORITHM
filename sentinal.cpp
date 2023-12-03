#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct city{
    char cname[20];
    int stdcode;
}c1[100];
void sentinal(struct city c1[100],int j)
{
    char cityname[100];
    int i;
    printf("Enter City Name to Found=");
    scanf("%s",cityname);
    strcpy(c1[j].cname,cityname);
    while(strcmp(cityname,c1[i].cname)!=0)
    i++;
    if(i<j)
    printf("Std Code=%o",c1[i].stdcode);
    else
    printf("city Not Found in the file");
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
        fscanf(fp1,"%s%o",&c1[i].cname,&c1[i].stdcode);
        i++;
    }
    int j=i-1;
    fclose(fp1);
    sentinal(c1,j);
}
