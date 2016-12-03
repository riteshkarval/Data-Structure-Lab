#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main()
{
    int i,j=0,n,r,comb[200];
    char pool[10],str[]={'1','2','3','4','5','6','7','8','9'};
    char input[10];
    int cc,pc=1,tc;
    printf("Enter N and R : ");
    scanf("%d %d",&n,&r);
    printf("%s",input);
    for(i=0;i<n;i++)
    {
        pool[0]=str[i];
        if(i==n-1)
            cc=0;
        else
            cc=i+1;
        while(cc!=i)
        {
            tc=cc;
            while(pc<r)
            {
                pool[pc]=str[cc];
                pc++;
                cc++;
                if(cc==n-1)
                    cc=0;
             }
            printf("%s\n",pool);
            strcpy(pool,"");
            pool[0]=str[i];
            pc=1;
            //cc=tc+1;
        }
    }
    return 0;
}
