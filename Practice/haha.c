#include<stdio.h>
#include<stdlib.h>

int *ht;
int hashindex,m,n,keys[20],elecount=0;

void createHT()
{
    ht=(int*)malloc(sizeof(int));
    if(ht==NULL)
    {
        printf("No memeory");
        return;
    }
    else
    {
        for(int i=1;i<=m;i++)
            ht[i]=-1;
    }
}


void insertHT(int key)
{
    hashindex=key%m;
    if(ht[hashindex]!=-1)
    {
        hashindex=(hashindex+1)%m;
    }
    ht[hashindex]=key;
    elecount++;

}


void display()
{
    if(elecount==0)
    {
        printf("NO data");
        return;
    }
    else
    {
        for(int i=1;i<=m;i++)
        {
            printf("T[%d]-->%d\n",i,ht[i]);
        }
    }
}


void main()
{
    printf("Enter the number of employess\n");
    scanf("%d",&n);

    printf("ENter the memory location\n");
    scanf("%d",&m);

    printf("Enter the keys\n");
    for(int i=0;i<n;i++)
    scanf("%d",&keys[i]);

    createHT();
    printf("Creating the HT....\n");
    for(int i=0;i<n;i++)
    {
        if(elecount==m)
        {
            printf("Cananot insert\n");
            return;
        }
        else
        insertHT(keys[i]);
    }

    display();
}