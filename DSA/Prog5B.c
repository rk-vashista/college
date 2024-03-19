#include<stdio.h>

void towers(int num,char from,char to, char aux)
{
    if(num==1)
    {
        printf("MOVE DISK 1 from %c to %c\n",from,to);
        return;
    }
    else
    {
        towers(num-1,from,aux,to);
        printf("MOVE DISK %d from %c to %c\n",num,from,to);
        towers(num-1,aux,to,from);
    }
}

void main()
{
    printf("Enter the number of disks\n");
    int n;
    scanf("%d",&n);
    towers(n,'a','c','b');
}