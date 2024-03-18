#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
char postfix[20];
int top=-1,stack[20];
void push(int item)
{
    stack[++top]=item;
}

int pop()
{
    return stack[top--];
}

void main()
{
    printf("Enter the postfix expression\n");
    scanf("%s",postfix);
    int i=0,res;
    char symb;
    for(i=0;postfix[i]!='\0';i++)
    {
        symb=postfix[i];

        if(isdigit(symb))
        {
            push(symb-'0');
        }
        else
        {
            int op2=pop();
            int op1=pop();

            switch(symb)
            {
                case '+':push(op1+op2);
                break;
                case '-':push(op1-op2);
                break;
                case '*':push(op1*op2);
                break;
                case '/':push(op1/op2);
                break;
                case'$':push(pow(op1,op2));
                break;
            }

        }
    }
    res=pop();
    printf("Result: %d",res);
    
}