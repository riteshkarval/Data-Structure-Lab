#include<stdio.h>
#include<stdlib.h>
struct Node
{
    char alpha;
    struct Node *next;
}*Stop,*Qhead,*Qrear;
void push(char a);
void enqueue(char a);
char pop();
char dequeue();
int main()
{
    char input[100];
    int i=0;
    printf("Enter a string:\n");
    scanf("%s",input);
    //printf("%s\n",input);
    while(input[i]!='\0')
        {
            push(input[i]);
            enqueue(input[i]);
            i++;
        }
    struct Node *temps,*tempq;
    while(Qhead!=NULL && Stop!=NULL)
        {
            printf("%c %c\n",Qhead->alpha,Stop->alpha);
            if(pop()!=dequeue())
            {
                printf("String is not palindrome\n");
                return 0;
            }
        }
    printf("String is palindrome\n");
    
    return 0;
}
void push(char a)
{
    struct Node *temp;
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->alpha=a;
    if (Stop==NULL)
        {
            Stop=temp;
            Stop->next=NULL;
        }
    else
        {
            temp->next=Stop;
            Stop=temp;
        }
}
char pop()
{
    struct Node *temp=Stop;
    char x=temp->alpha;
    temp=temp->next;
    free(Stop);
    Stop=temp;
    return x;
}
void enqueue(char a)
{
    struct Node *temp;
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->alpha=a;
    if (Qrear==NULL)
        {
            Qrear=temp;
            Qrear->next=NULL;
            Qhead=Qrear;
        }
    else
        {
            Qrear->next=temp;
            temp->next=NULL;
            Qrear=temp;
        }
}
char dequeue()
{
    char x;
    struct Node *temp=Qhead;
    if(temp->next!=NULL)
        {
            x=Qhead->alpha;
            temp=temp->next;
            free(Qhead);
            Qhead=temp;
        }
    else
        {
            x=Qhead->alpha;
            free(Qhead);
            Qhead=Qrear=NULL;
        }
    return x;
}
        
        
