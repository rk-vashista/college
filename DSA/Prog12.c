#include<stdio.h>
#include<stdlib.h>

int * ht;
int elecount=0;
int hashindex,keys[20],m,n;

void createHT()
{
    ht=(int*)malloc(sizeof(int));
    if(ht==NULL)
    {
        printf("No memory");
        return;
    }
    else
    {
        for(int i=0;i<m;i++)
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


void displayHT()
{
    if(elecount==0)
    {
        printf("HT is empty\n");
        return;
    }
    
    else
    {
        printf("Hash Table contents\n");
            for(int i=0;i<m;i++)
            {
                printf("T[%d]-->%d \n",i,ht[i]);
            }
    }
}

void main()
{
    printf("Enter the number of emp \n");
    scanf("%d",&n);

    printf("Enter the memory location\n");
    scanf("%d",&m);

    printf("Enter the 4 digit id\n");
    for(int i=0;i<n;i++)
    scanf("%d",&keys[i]);

    createHT();
    
    printf("Creating the hashtable......\n");
    int i;
    for( i=0;i<n;i++)
    {
        if(elecount==m)
        {
            printf("cannot insert");
            return;
        }
        insertHT(keys[i]);
    }

    displayHT();
}