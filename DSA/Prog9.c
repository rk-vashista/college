#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define COMPARE(x,y)  ((x==y)?0:(x>y)?1:-1)

struct node{
    int coef;
    int xexpon,yexpon,zexpon;
    struct node *link;
};

typedef struct node *NODE;

NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("NO MEMORY\n");
        return NULL;
    }
    return temp;
}


NODE attach(int coef,int xexpon,int yexpon,int zexpon,NODE head)
{
    NODE temp,cur;
    temp=getnode();
    temp->coef=coef;
    temp->xexpon=xexpon;
    temp->yexpon=yexpon;
    temp->zexpon=zexpon;
    cur=head->link;
    while(cur->link!=head)
    {
        cur=cur->link;
    }

    cur->link=temp;
    temp->link=head;
    return head;
}


NODE read(NODE head)
{
    int n;
    int x,y,z,coef;
    printf("Enter the number of node\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("ENter the coef, x, y, z exponents for term %d ",i);
        scanf("%d",&coef);
        scanf("%d",&x);
        scanf("%d",&y);
        scanf("%d",&z);
        head=attach(coef,x,y,z,head);
    }
    return head;
}


void display(NODE head)
{
    NODE temp;
    if(head->link==head)
    {
        printf("No terms\n");
        return;
    }

    temp=head->link;
    while(temp!=head)
    {
        printf("%dx^%dy^%dz^%d ",temp->coef,temp->xexpon,temp->yexpon,temp->zexpon);
        temp=temp->link;
        if(temp!=head)
        printf("+");
    }
}

int evaluate(NODE head)
{
    int x,y,z;
    printf("\nENter the x,y,z values for evaluation\n");
    scanf("%d",&x);
    scanf("%d",&y);
    scanf("%d",&z);
    int res=0;
    NODE temp=head->link;

    while(temp!=head)
    {
        res+=temp->coef*pow(x,temp->xexpon)*pow(y,temp->yexpon)*pow(z,temp->zexpon);
        temp=temp->link;
    }
    return res;
}


NODE add(NODE head1,NODE head2, NODE head3)
{
    NODE a=head1->link;
    NODE b=head2->link;
    int coef;

    while(a!=head1 && b!=head2)
    {
        while(1)
        {
            if(a->xexpon==b->xexpon && a->yexpon==b->yexpon && a->xexpon==b->zexpon)
            {
                coef=a->coef+b->coef;
                head3=attach(coef,a->xexpon,a->yexpon,a->zexpon,head3);
                a=a->link;
                b=b->link;
                break;
            }

            if(a->xexpon!=0 || b->xexpon!=0)
            {
                switch(COMPARE(a->xexpon,b->xexpon))
                {
                    case -1: head3=attach(b->coef,b->xexpon,b->yexpon,b->zexpon,head3);
                            b=b->link;
                            break;


                    case 0: if(a->yexpon>b->yexpon)
                            {
                                head3=attach(a->coef,a->xexpon,a->yexpon,a->zexpon,head3);
                                a=a->link;
                            }

                            else if(a->yexpon<b->yexpon)
                            {
                                head3=attach(b->coef,b->xexpon,b->yexpon,b->zexpon,head3);
                                b=b->link;
                                break;
                            }

                            else if(a->zexpon>b->zexpon)
                            {
                                head3=attach(a->coef,a->xexpon,a->yexpon,a->zexpon,head3);
                                a=a->link;
                                break;
                            }
                            
                            else if(a->zexpon<b->zexpon)
                            {
                                head3=attach(b->coef,b->xexpon,b->yexpon,b->zexpon,head3);
                                b=b->link;
                                break;
                            }

                    case 1:head3=attach(a->coef,a->xexpon,a->yexpon,a->zexpon,head3);
                            a=a->link;
                            break;
                }
            }


            if(a->yexpon!=0 || b->yexpon!=0)
            {
                switch(COMPARE(a->yexpon,b->yexpon))
                {
                    case -1:head3=attach(b->coef,b->xexpon,b->yexpon,b->zexpon,head3);
                            b=b->link;
                            break;

                    case 0: if(a->zexpon>b->zexpon)
                            {
                                head3=attach(a->coef,a->xexpon,a->yexpon,a->zexpon,head3);
                                a=a->link;
                                break;
                            }

                            else if(a->zexpon<b->zexpon)
                            {
                                head3=attach(b->coef,b->xexpon,b->yexpon,b->zexpon,head3);
                                b=b->link;
                                break;
                            }

                    case 1:head3=attach(a->coef,a->xexpon,a->yexpon,a->zexpon,head3);
                            a=a->link;
                            break;
                }
            }

            if(a->zexpon!=0 || b->zexpon!=0)
            {
                switch(COMPARE(a->zexpon,b->zexpon))
                {
                    case -1:head3=attach(b->coef,b->xexpon,b->yexpon,b->zexpon,head3);
                            b=b->link;
                            break;

                    case 1:head3=attach(a->coef,a->xexpon,a->yexpon,a->zexpon,head3);
                            a=a->link;
                            break;
                }
            }

        }
    }

    while(a!=head1)
    {
        head3=attach(a->coef,a->xexpon,a->yexpon,a->zexpon,head3);
        a=a->link;
    }

    while(b!=head2)
    {
        head3=attach(b->coef,b->xexpon,b->yexpon,b->zexpon,head3);
        b=b->link;
    }
    return head3;
}

void main()
{
    NODE head,head1,head2,head3;
    int res,ch;

    head=getnode();
    head1=getnode();
    head2=getnode();
    head3=getnode();
    
    head->link=head;
    head1->link=head1;
    head2->link=head2;
    head3->link=head3;


   while(1)
   {
     printf("MENU\n1.Evaluate\n2.Add\n3.exit\n");
    printf("Enter the choice\n");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:head=read(head);
                printf("POLYNOMIAL:\n");
                display(head);
                res= evaluate(head);
                printf("The result : %d\n",res);
                break;

        case 2: head1=read(head1);
                printf("POLY1:\n");
                display(head1);
                head2=read(head2);
                printf("POLY 2:\n");
                display(head2);

                head3=add(head1,head2,head3);
                printf("THe sum of Poly1 and Poly2:\n");
                display(head3);
                break;

        case 3: exit(0);
                break;
    }
   }
}