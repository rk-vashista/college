#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int i;

typedef struct{
    char *name;
    char *activity;
    int date;
}cal;

cal *create()
{
    cal *temp;
    temp=(cal*)malloc(7*sizeof(cal));
    for(i=0;i<7;i++)
    {
        temp[i].name=NULL;
        temp[i].activity=NULL;
        temp[i].date=0;
    }

    return temp;
}


void readcal(cal *temp)
{
    char ch;
    for(i =0;i<7;i++)
    {
        printf("Do you want to enter the deets of day %d?[y/n]\n",i+1);
        scanf("%c",&ch);
        getchar();
        if(tolower(ch)=='n')
        {
            continue;
        }

        else
        {
            char buffer[50];
            printf("Date:\n");
            scanf("%d",&temp[i].date);
            printf("Name:\n");
            scanf("%s",buffer);
            temp[i].name=strdup(buffer);
            printf("ACTIVITY:\n");
            scanf("%s",buffer);
            temp[i].activity=strdup(buffer);
            getchar();
        }
    }
}


void display(cal *temp)
{
    for(i=0;i<7;i++)
    {
        if(temp[i].date==0)
        {
            printf("\nNo activity on day %d\n",i+1);
        
        }
        else
        {
            printf("Date:%d\tName:%s\tActivity:%s\n\n",temp[i].date,temp[i].name,temp[i].activity);
        }
    }
}

void main()
{
    cal* week=create();
    readcal(week);
    display(week);
    free(week);
}