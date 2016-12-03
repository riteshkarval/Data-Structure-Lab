#include<stdio.h>
#include<stdlib.h>
struct Node
{
	char alpha;
	struct Node *next;
}*Stop1,*Stop2,*Stop3;
struct Node * push(struct Node *top,char a);
int main()
{
	char input[100];
	int i=0;
	printf("Enter a string: ");
	scanf("%s",input);
	printf("%s\n",input);
	while(input[i]!='\0')
	{
	    Stop1=push(Stop1,input[i]);
	    Stop2=push(Stop2,input[i]);
	    i++;
	}
	while(Stop1!=NULL)
	{
	    struct Node *temp=Stop1;
	    Stop3=push(Stop3,temp->alpha);
	    //printf("%c %c \n",Stop1->alpha,Stop3->alpha);
	    Stop1=Stop1->next;
	    free(temp);
	}
	while(Stop2!=NULL && Stop3!=NULL)
	{
	    struct Node *temp3,*temp2;
	    temp2=Stop2;
	    temp3=Stop3;
	    printf("%c %c \n",Stop2->alpha,Stop3->alpha);
	    if(Stop2->alpha!=Stop3->alpha)
	    {
	        printf("String is not palindrome\n");
	        return 0;
	    }
	    Stop2=Stop2->next;
	    free(temp2);
	    Stop3=Stop3->next;
	    free(temp3);
	}
	printf("String is Palindrome\n");
	    
	return 0;
}
struct Node * push(struct Node *top,char a)
{
    struct Node *temp;
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->alpha=a;
    if (top==NULL)
        {
            top=temp;
            top->next=NULL;
        }
    else
        {
            temp->next=top;
            top=temp;
        }
    return top;
}
