#include<stdlib.h>
#include<stdio.h>
int main()
{
    int G[10][10];
    int stack[10],top,n;
    scanf("%d",&n);
    int i,j,k;
    int ele,count;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);
    for(j=0;j<n;j++)
    {
        stack[0]=j;
        count=n;
        top=0;
        while(top>=0)
        {
            ele=stack[top--];
            count--;
            printf("%d\t",ele+1);
            for(i=0;i<n;i++)
            {
                if(G[ele][i]==1)
                {
                    stack[++top]=i;
                }
            }
            if(count==0)
                break;
        }
        printf("\n");
        if(count<=0)
            break;
    }
    if(count>0)
    printf("\nDisconnected %d\n",count);
    else
    printf("\nConnected\n");
    
}
