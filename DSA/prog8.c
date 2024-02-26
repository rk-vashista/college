#include<stdio.h>
#include<stdlib.h>

struct DLL{
    int ssn,sal,phno;
    char name[20],dept[20],desgn[20];
    struct DLL *prev;
    struct DLL *next;
};

typedef struct DLL node;
node *start =NULL;
int count =0;

node *getnode()
{
    node *temp;
    temp=(node*)malloc(sizeof(struct DLL));
    printf("Enter the ssn, name. dept, desgn,sal,phno\n");
    scanf("%d %s %s %s %d %d",&temp->ssn,temp->name,temp->dept,temp->desgn,&temp->sal,&temp->phno);
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}

void insert_front()
{
    node *nn;
    nn=getnode();
    if(start==NULL)
    {
        start=nn;
        return;
    }

    else
    {
        nn->next=start;
        start->prev=nn;
        start=nn;
    }
    count++;
}

void insert_end()
{
    node *temp=start;
    node *nn=getnode();

    if(start==NULL)
    {
        start=nn;
        return;
    }

    else
    {
        while (temp->next!=NULL)    
        {
            temp=temp->next;
        }
        temp->next=nn;
        nn->prev=temp;
    }
    count++;
}

void delete_front()
{
    node *temp=start;
    if(start==NULL)
    {
        printf("EMPTY LIST");
        return;
    }

    else
    {
        start=start->next;
        temp->next=NULL;
        start->prev=NULL;
        free(temp);
    }
    count--;
}

void delete_end()
{
    node *temp=start;
    node *prevv;
    if(start==NULL)
    {
        printf("Empty LIst");
        return;
    }

    else
    {
        if(start->next==NULL)
        {
            free(start);
            return;
        }
        else
        {
            while (temp->next!=NULL)
        {
            prevv=temp;
            temp=temp->next;
        }
        prevv->next=NULL;
        temp->prev=NULL;
        free(temp);
        }
    }
}


void display()
{
    node *temp=start;
    if(start==NULL)
    {
        printf("EMPTY LIST");
        return;
    }
    else
    {
        printf("SSN\tNAME\tDept\tDesgn\tsal\tphno\n");
        while (temp!=NULL)
        {
            printf("%d\t%s\t%s\t%s\t%d\t%d\n",temp->ssn,temp->name,temp->dept,temp->desgn,temp->sal,temp->phno);
            temp=temp->next;
        }
        
    }
}


void main()
{
    int ch,n,i;
    printf("MENU\n1.Create\n2.insert_front\n3.insert_end\n4.delete_front\n5.delete_end\n6.display\n7.exit\n");
    while (1)
    {
        printf("Enter your choice\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:printf("Enter the number of emps\n");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                insert_end();
            }
            break;

            case 2:insert_front(); break;
            case 3:insert_end(); break;
            case 4:delete_front(); break;
            case 5:delete_end(); break;
            case 6:display(); break;
            case 7: exit(0); break;
        }
    }
    
}
