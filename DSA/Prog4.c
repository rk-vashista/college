#include<stdio.h>
#include<stdlib.h>

void evaluate();
int prec(char);
char pop();
void push(char);

char stack[20],infix[20],postfix[20];
int top=-1;

void main()
{
    printf("Enter the infix expressions\n");
    scanf("%s",infix);
    evaluate();
    printf("INFIX Expression: %s\n",infix);
    printf("POSTFIX Expression: %s\n",postfix);
}

void evaluate()
{
    int i,j=0;
    char symb,temp;
    push('#');
    for(i=0;infix[i]!='\0';i++)
    {
        symb=infix[i];
        switch (symb)
        {
        case '(':
            push(symb);
            break;

        case ')':temp=pop();
            while(temp!='(')
            {
                postfix[j]=temp;
                j++;
                temp=pop();
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
        case '$':
        while (prec(stack[top])>= prec(symb))
        {
            temp=pop();
            postfix[j]=temp;
            j++;
        }
        push(symb);
        break;
        
        default: postfix[j]=symb;
            j++;
            break;
        }
    }

    while(top>0)
    {
        temp=pop();
        postfix[j]=temp;
        j++;
    }
}

void push(char symb)
{
    stack[++top]=symb;
}

char pop()
{
    return stack[top--];
}

int prec(char symb)
{
    int p;
    switch(symb)
    {
        case '#':p=-1;
        break;
        case '(':
        case ')':p=0;
        break;
        case '+':
        case '-':p=1;
        break;
        case '*':
        case '/':
        case '%':p=2;
        break;
        case '^':
        case '$':p=3;
        break;
    }
    return p;
}