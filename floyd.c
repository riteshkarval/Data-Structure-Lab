#include<stdio.h>
#include<stdlib.h>
#define INF 1000
void copy(int a[][10],int b[][10],int n);
int min(int a,int b)
{
    if(a>b)
        return b;
    else return a;
}
int main()
{
    int n,D[10][10],S[10][10];
    int tD[10][10],tS[10][10];
    int G[10[10];
    scanf("%d",&n);
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&D[i][j]);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(D[i][j]==INF || D[i][j]==0)
                S[i][j]=0;
            else
                S[i][j]=i+1;
        }
    copy(D,G,n);
    for(k=0;k<n;k++)
    {
         copy(D,tD,n);
         copy(S,tS,n);
         for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                D[i][j]=min(tD[i][j],tD[i][k]+tD[k][j]);  
                if(tD[i][j]<=(tD[i][k]+tD[k][j]))
                    S[i][j]=tS[i][j];
                else
                    S[i][j]=tS[k][j];
            }
    }   
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",D[i][j]);
        printf("\n");
    }
    printf("\n\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",S[i][j]);
            printf("\n");
    }
    printf("\n\n");
    return 0;
}
void copy(int a[][10],int b[][10],int n)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            b[i][j]=a[i][j];
}
