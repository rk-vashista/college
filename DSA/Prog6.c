#include<stdio.h>
#include<stdlib.h>

#define max 3

char cq[max];
int front=-1,rear=-1;

void insert(int item)
{
    if(front==rear+1%max)
    {
        printf("CQ overflow\n");
        return;
    }
    else
    {
        if(front==-1)
        front=rear=0;
        else
        rear=rear+1%max;
    }
    cq[rear]=item;
}

int delete()
{
    int temp;
    if(front==-1)
    {
        printf("CQ underflow\n");
        return-1;
    }
    else
    {
        temp=cq[front];
        if(front==rear)
        front=rear=-1;
        else
        front=front+1%max;
    }
    return temp;
}

void display()
{
    if(front==-1)
    {
        printf("empty CQ\n");
        return;
    }

    else
    for(int i=front;i!=rear+1%max;i=i+1%max)
    {
        printf("|%d|",cq[i]);
    }
}

void main()
{
    int ch;
    printf("MENU\n1.Insert\n2.Delete\n3.Display\n4.exit\n");
    while(1)
    {
        printf("\nEnter your choice\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:int item;
            printf("enter the item to be inserted\n");
            scanf("%d",&item);
            insert(item);
            break;

            case 2: int temp =delete();
                    printf("the deleted item is %d\n",temp);
                    break;

            case 3: display();
            break;

            case 4:exit(0);
            break;
        }
    }
}