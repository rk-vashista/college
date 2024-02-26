#include<stdio.h>
#include<stdlib.h>

struct ssl{
    char usn[20],name[20],brach[20];
    int sem, phno;
    struct ssl *link;
};

typedef struct ssl node;
int count=0;
node *start=NULL;

node *getnode()
{
    node *nn;
    nn=(node*)malloc(sizeof(node));
    if(nn==NULL)
    printf("Memory Overflow");
    else
    {
    printf("Enter the name usn branch sem and phno");
    scanf("%s %s %s %d %d",nn->name,nn->usn,nn->brach,&nn->sem,&nn->phno);
    nn->link=NULL;
    return nn;
    }

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
        nn->link=start;
        start=nn;
    }
    count++;
}


void insert_end()
{
    node *nn;
    node *temp;
    nn=getnode();
    temp=start;
    if(start==NULL)
    {
        start=nn;
        return;
    }
    else
    {
        while(temp->link!=NULL)
        temp=temp->link;
        temp->link=nn;
    }
    count++;

}


void delete_front()
{
    node *temp;
    temp=start;
    if(start==NULL)
    {
        printf("empty list");
        return;
    }
    else
    {
        start=start->link;
    }
    free(temp);
    count--;
}

void delete_end()
{
    node *temp,*prev;
    temp=start;
    if(start==NULL)
    {
        printf("empty list");
        return;
    }
    else
    {
        while(temp->link!=NULL)
        {
            prev=temp;
            temp=temp->link;
        }
        prev->link=NULL;
    }
    free(temp);
    count--;
}

void display()
{
    node *temp;
    temp=start;
    if(start==NULL)
    {
        printf("the SLL is empty");
        return;
    }
    else
    {
        printf("Name\tusn\tbranch\tsem\tphno\n");
        while(temp!=NULL)
        {
            
            printf("%s\t%s\t%s\t%d\t%d\n",temp->name,temp->usn,temp->brach,temp->sem,temp->phno);
            temp=temp->link;
        }
    }
    printf("The number of node :%d ",count+1);
}

void stack_demo()
{
    int ch;
    printf("Menu\n 1.push\n2.pop\n3.display\n4.exit\n");
    while(1)
    {
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("push operation\n");
                    insert_front();
                    break;
            case 2: printf("POP operation\n");
                    delete_front();
                    break;
            case 3: printf("DIsplay\n");
                    display();
                    break;
            case 4: printf("Exit\n");
                    return;
            
        }
    }
}

void queue_demo()
{
    int ch;
    while(1)
    {
        printf("Menu\n 1.insert\n2.delete\n3.display\n4.exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("insert operation\n");
                    insert_end();
                    break;
            case 2: printf("delete operation\n");
                    delete_front();
                    break;
            case 3: printf("DIsplay\n");
                    display();
                    break;
            case 4: printf("Exit\n");
                    return;
            
        }
    }
}


void main()
{
    int ch;
    while(1)
    {
        printf("Menu \n1.Create Node\n2.insert_end\n3.delete_end\n4.display\n5.stack_demo\n6.Queue_demo\n7.exit\n");
        printf("Enter your choice");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter the number of nodes");
                    int n;
                    
                    scanf("%d",&n);
                    for(int i=0;i<n;i++)
                    {
                        insert_front();
                    }
                    break;

            case 2:printf("Inster_end\n");
                    insert_end();
                    break;

            case 3: printf("delete_end\n");
                    delete_end();
                    break;
            case 4: display(); 
                    break;
            case 5: stack_demo(); 
                    break;
            case 6: queue_demo(); break;
            case 7: exit(0);
            
        }
    }
}

