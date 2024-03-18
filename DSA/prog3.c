#include<stdio.h>
#include<stdlib.h>
#define max 3

int stack[max];
int top=-1;

void push(int item)
{
    if(top==max-1)
    {
        printf("stack full\n");
        return;
    }

    top=top+1;
    stack[top]=item;
}

int pop()
{
    if(top<0)
    {
        printf("Stack empty\n");
        //return;
    }
    int item=stack[top];
    top=top-1;
    return item;
}

void palin()
{
    printf("Stack:\n");
    for(int i=top;i>=0;i--)
    {
        printf("|%d|\t",stack[i]);
    }
    printf("\n Reverse stack:\n");
    for(int i=0;i<=top;i++)
    {
        printf("|%d|\t",stack[i]);
    }
   

    for(int i=0;i<=top/2;i++)
    {
        if(stack[i]!=stack[top-i])
        {
            printf("Not palindrome\n");
            return;
        }
        else
        {
            printf("Palindrome\n");
            return;
        }
    }
}

void display()
{
    printf("Stack:\n");
    for(int i=top;i>=0;i--)
    {
        printf("|%d|\t",stack[i]);
    }
}

void main()
{
    printf("Menu\n1.push\n2.pop\n3.display\n4.palindrom\n5.exit\n");
    int ch;
    int item;
    while(1)
    {
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    printf("Enter the item\n");
                    scanf("%d",&item);
                    push(item);
                    break;

            case 2: if(top==-1)
                    {
                        printf("empty stack\n");
                        continue;
                    }
                    item=pop();
                    printf("the item poped is %d\n",item);
                    printf("TOP:%d\n",top);
                    break;

            case 3:display();
            break;

            case 4:palin();
            break;
            
            case 5:exit(0);
            break;
        }
    }
}