#include <stdio.h>
#include <stdlib.h>
void prm(int* a,int end, int r, int n)
{
	if(end==r)
	{	for(int i=0;i<r;i++)
			printf("%d ", a[i]);
		printf("\n");
		return;
	}
	
	for(int i=1;i<=n;i++)
	{
		int insertable =1;	
		for(int j=0;j<end;j++)
			if(a[j]==i)
				insertable = 0;
		if(insertable)
		{	a[end] = i;
			prm(a,end+1,r,n);
		}
	}
}

int main(void) {
	int r,n;
	int list[20];
	printf("Enter N and R : ");
    scanf("%d %d",&n,&r);
    for(int i=1;i<=n;i++)
        list[i]=0;
	prm(list,0,r,n);
	return 0;
}
