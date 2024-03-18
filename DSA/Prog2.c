#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
    char str[50],pat[50],rep[50],ans[50];

    int i,j,m,c,k;

    printf("Enter the string\n");
    gets(str);

    printf("Enter the pattern\n");
    gets(pat);
    
    printf("Enter the replacemnt\n");
    gets(rep);

    i=c=m=j=0;
    while(str[c]!='\0')
    {
        if(str[m]==pat[i])
        {
            i++;
            m++;
            if(pat[i]=='\0')
            {
                for(k=0;rep[k]!='\0';k++,j++)
                    ans[j]=rep[k];
                    c=m;
                    i=0;
            }
        }

        else
        {
        ans[j]=str[c];
        j++;
        c++;
        m=c;
        i=0;
        }
        
    }
    ans[j]='\0';
    printf("Result:\n%s",ans);
}