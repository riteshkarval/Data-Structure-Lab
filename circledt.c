#include<stdlib.h>
#include<stdio.h>
int main()
{
    int G[10][10];
    int stack[10],top,n;
    int visited[10];
    scanf("%d",&n);
    int i,j,k;
    int ele,count;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);
    for(j=0;j<n;j++)
    {
        stack[0]=j;
        k=0;
        count=n;
        top=0;
        while(top>=0)
        {
            ele=stack[top--];
            count--;
            visited[k++]=ele;
            printf("%d\t",ele+1);
            for(i=0;i<n;i++)
            {
                if(G[ele][i]==1)
                {
                    stack[++top]=i;
                    for(int l=0;l<k;l++)
                        if(visited[l]==i)
                        {
                            printf("Circular\n");
                            return 0;
                        }
                }
            }
            if(count==0)
                break;
        }
        printf("\n");
        if(count<=0)
            break;
    }
    printf("\nNo\n");   
}
