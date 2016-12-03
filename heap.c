#include<stdio.h>
#include<stdlib.h>
int heapsize,N;
void swap(int *a,int *b);
void maxHeapify(int *A,int i);
void buildMaxHeap(int *A);
void heapsort(int *A);
int main()
{
    int A[20],l,r,p;
    A[0]=0;
    scanf("%d",&N);
    int i,j;
    for(i=1;i<=N;i++)
        scanf("%d",&A[i]);
    heapsort(A);
    printf("\n");
    for(i=1;i<=N;i++)
        printf("%d\t",A[i]);
    printf("\n");
    
}
void maxHeapify(int *A,int i)
{
    int l=2*i;
    int r=2*i+1;
    int largest;
    if(l<=heapsize && A[l]>A[i])
        largest=l;
    else largest=i;
    if(r<=heapsize && A[r]>A[largest])
        largest=r;
    if(largest != i)
    {
        swap(&A[i],&A[largest]);
        maxHeapify(A,largest);
    }
}
void buildMaxHeap(int *A)
{
    heapsize=N;
    for(int i=N/2;i>=1;i--)
        maxHeapify(A,i);
}
void heapsort(int *A)
{
    buildMaxHeap(A);
    for(int i=N;i>=2;i--)
    {
        swap(&A[1],&A[i]);
        heapsize=heapsize-1;
        maxHeapify(A,1);
    }
}
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    
}
