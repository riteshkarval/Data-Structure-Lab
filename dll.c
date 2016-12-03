#include<stdlib.h>
#include<stdio.h>
struct Node
{
    int data;
    struct Node *prev,*next;
}*head,*tail;
void insertfront(int key);
void insertend(int key);
void insertpos(int key,int pos);
void insertafter(int number,int value);
void deletefront();
void deleteend();
void deletepos(int position);
void deletekey(int value);
void printlist();
int main()
{
    int ch=1, elem,pos;
    while(ch>0 && ch <10)
    {
        printf("1-Insert in front\n"); 
        printf("2-Insert at the end\n");
        printf("3-Insert at position\n");
        printf("4-Insert after an element\n");
        printf("5-Delete front\n");
        printf("6-Delete last\n");
        printf("7-Delete at position\n");
        printf("8-Delete element\n");
        printf("Enter Choice\n");   
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter element to insert\n");
                    scanf("%d",&elem);
                    insertfront(elem);
                    break;
            case 2: printf("Enter element to insert\n");
                    scanf("%d",&elem);
                    insertend(elem);
                    break;
            case 3: printf("Enter element to insert\n");
                    scanf("%d",&elem);
                    printf("Enter position\n");
                    scanf("%d",&pos);
                    insertpos(elem,pos);
                    break;
            case 4: printf("Enter element to insert\n");
                    scanf("%d",&elem);
                    printf("Enter key\n");
                    scanf("%d",&pos);
                    insertafter(elem,pos);
                    break;
            case 5: deletefront();
                    break;
            case 6: deleteend();
                    break; 
            case 7: printf("Enter position\n");
                    scanf("%d",&pos);
                    deletepos(pos);
                    break;
            case 8: printf("Enter element\n");
                    scanf("%d",&elem);
                    deletekey(elem);
                    break;
            default: return 0;
        } 
        printlist();
    }
}
void insertfront(int key)
{
    struct Node *temp;
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=key;
    if(head==NULL)
    {
       head=temp;
       head->next=head->prev=NULL;
       return; 
    }
    temp->next=head;
    head->prev=temp;
    head=temp;
    return;    
}
void insertend(int key)
{
    struct Node *temp,*temp1;
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=key;
    if(head==NULL)
    {
       head=temp;
       head->next=head->prev=NULL;
       return; 
    }
    temp1=(struct Node *)malloc(sizeof(struct Node));
    temp1=head;
    while(temp1->next!=NULL)
        temp1=temp1->next;
    temp1->next=temp;
    temp->prev=temp1;
    temp->next=NULL;
    return;    
}
void insertpos(int number,int position)
{
    int i;
	struct Node *temp,*new_node;
	if(head==NULL)
	{
		new_node=(struct Node *)malloc(sizeof(struct Node));
		new_node->data=number;
		new_node->next=NULL;
		new_node->prev=NULL;
		head=new_node;
	}
	else
	{
		if(position==1)
		{
			new_node=(struct Node *)malloc(sizeof(struct Node));
			new_node->data=number;
			new_node->next=head;
			new_node->prev=NULL;
			head->prev=new_node;
			head=new_node;
		}
		else
		{
			for(i=2,temp=head;i<=position && temp!=NULL;i++,temp=temp->next)
			{
				if(i==position)
				{
					new_node=(struct Node *)malloc(sizeof(struct Node));
					new_node->data=number;
					new_node->next=temp->next;
					temp->next=new_node;
					new_node->prev=temp;
					break;
				}
			}
			if(position>i)
				printf("Position out of range\n");
		}
	}    
}
void insertafter(int number,int value)
{
    struct Node *temp,*new_node;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		if(temp->data==value)
		{
			new_node=(struct Node *)malloc(sizeof(struct Node));
			new_node->data=number;
			new_node->next=temp->next;
			new_node->prev=temp;
			if(new_node->next!=NULL)
				new_node->next->prev=new_node;
			temp->next=new_node;
			break;
		}
	}
	if(temp==NULL)
		printf("\nKey not found");
}
void deletefront()
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(head->next==NULL)
    {
        free(head);
        head=NULL;
        return;
    }
    struct Node *temp;
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
    
}
void deleteend()
{
    struct Node *temp;
	if(head!=NULL)
	{
		if(head->next!=NULL)
		{
			for(temp=head;temp->next->next!=NULL;temp=temp->next)
				;
			temp->next=NULL;
			temp=temp->next;
		}
		else 
		{
			temp=head;
			head=NULL;
		}
		free(temp);
	}
    
}
void deletepos(int position)
{
    int i;
	struct Node *del_node,*temp;
	if(head!=NULL)
	{
		if(position==1) 
		{
			del_node=head;
			head=del_node->next;
			if(del_node->next!=NULL) 
				del_node->next->prev=NULL;
			free(del_node);
		}
		else 
		{
			for(i=2,temp=head;temp->next!=NULL;temp=temp->next,i++)
			{
				if(i==position) 
				{
					del_node=temp->next;
					temp->next=del_node->next;
					if(del_node->next!=NULL)
						del_node->next->prev=temp;
					free(del_node);
					break;
				}	
			}
			if(position>i) 
				printf("\nPosition out of range\n");
		}
	}
}
void deletekey(int value)
{
    struct Node *temp,*del_node;
	if(head->data==value) 
	{
		del_node=head;
		head=NULL;
	}
	else 
	{
		for(temp=head;temp!=NULL;temp=temp->next)
		{
			if(temp->next==NULL)
			{
				printf("Key not found\n");
				return;
			}
			if(temp->next->data==value)
			{
				del_node=temp->next;
				temp->next=del_node->next;
				if(del_node->next!=NULL)
					del_node->next->prev=temp;
				break;
			}
		}
	}
	free(del_node);
}
void printlist()
{
    if(head==NULL)
    {   
        printf("List is empty\n");
        return;
    }
    struct Node *temp;
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}








