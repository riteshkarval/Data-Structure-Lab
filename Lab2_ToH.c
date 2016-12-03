#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int disc;
    struct Node *next;
}*TowerA, *TowerB, *TowerC;
int t1=0,t2=0,t3=0;
void push(struct Node *top, int d,int t);
int pop(struct Node *tower, int t);
void PrintTowers();
int main()
{
    int n,moves=1,i;
    printf("Enter no of Disks:");
    scanf("%d", &n);
    for(i=n;i>=1;i--)
    {
        push(TowerA,i,1);
        moves=moves*2;
    }
    printf("Towers =>\n");
    PrintTowers();
    printf("\n");
    for(i=1;i<=moves;i++)
    {
        if(i%3==1)
        {
           // if(TowerC==NULL || TowerA->disc < TowerC->disc)
                push(TowerC,pop(TowerA,1),3);
         //   else
          //      push(TowerA,pop(TowerC,3),1);
        }
        else if(i%3==2)
        {
           // if(TowerB==NULL || TowerA==NULL || TowerA->disc < TowerB->disc)
                push(TowerB,pop(TowerA,1),2);
          //  else
          //      push(TowerA,pop(TowerB,2),1);
        }
        else if(i%3==0)
        {
          //  if(TowerC==NULL || TowerB->disc < TowerC->disc)
                push(TowerC,pop(TowerB,2),3);
            //else
             //   push(TowerB,pop(TowerC,3),2);
        }
        printf("Move %d:-\n", i);
        printf("=========================\n");
       PrintTowers();
        printf("=========================\n");
    }
    printf("%d %d %d",t1,t2,t3);
    struct Node *temp=TowerC;
    while(temp!=NULL)
    {
        printf("%d ", temp->disc);
        temp=temp->next;
     }
     return 0;
    
    
}
void push(struct Node *tower,int d,int t)
{
    if(d!=0)
    {
        struct Node *temp;
        temp=(struct Node *)malloc(sizeof(struct Node));
        temp->disc=d;
        if (tower==NULL)
            {
                tower=temp;
                tower->next=NULL;
            }
        else
            {
                temp->next=tower;
                tower=temp;
            }
        if(t==1)
        {
            TowerA=tower;
            t1++;
        }
        else if(t==2)
        {
            TowerB=tower;
            t2++;
        }
        else
        {
            TowerC=tower;
            t3++;
        }
     }
}
int pop(struct Node *tower, int t)
{
    if(tower==NULL)
        return 0;
    struct Node *temp=tower;
    char x=temp->disc;
    temp=temp->next;
    free(tower);
    tower=temp;
    if(t==1)
    {
        TowerA=tower;
        t1--;
    }
    else if(t==2)
    {
        TowerB=tower;
        t2--;
    }
    else
    {
        TowerC=tower;
        t3--;
    }
    return x;
}
void PrintTowers()
{
    struct Node *temp1,*temp2,*temp3;
    temp1=TowerA;
    temp2=TowerB;
    temp3=TowerC;
    printf("A\tB\tc\n");
    printf("_________________\n");
    while(1)
    {
        if(temp1==NULL && temp2==NULL && temp3==NULL)
            break;
        if(temp1==NULL)
            printf(" \t");
        else
        {
            printf("%d\t",temp1->disc);
            temp1=temp1->next;
            t1--;
        }
        if(temp2==NULL)
            printf(" \t");
        else
        {
            printf("%d\t",temp2->disc);
            temp2=temp2->next;
            t2--;
        }
        if(temp3==NULL)
            printf(" \t");
        else
        {
            printf("%d\t",temp3->disc);
            temp3=temp3->next;
            t3--;
        }
        printf("\n");
    }
            
}
        

