#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}*root;
struct Stack
{
  struct Node *elem;
  struct Stack *next;
}*Top,*Top1;
void push(struct Node *t,int stn);
void inorder(struct Node *r);
void preorder(struct Node *r);
void postorder(struct Node *r);
void display(struct Stack *top);
struct Node * pop(int stn);
void insert(int value);
int main()
{
    int value,n;
    printf("Enter Number of Nodes:");
    scanf("%d",&n);
    printf("Enter values\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&value);
        insert(value);
    }
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    printf("Postorder: ");
    postorder(root);
    printf("\n");
}
void insert(int num)
{
    struct Node *temp = root, *prev = root;
 
    if (root == NULL)
    {
        root = (struct Node *)malloc(sizeof(struct Node));
        root->data=num;
        root->left = root->right = NULL;
    }
    else
    {
        while (temp != NULL)
        {
            if (num > temp->data)
            {
                prev = temp;
                temp = temp->right;
            }
            else
            {
                prev = temp;
                temp = temp->left;
            }
        }
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = num;
        if (num >= prev->data)
        {
            prev->right = temp;
        }
        else
        {
            prev->left = temp;
        }
    }
}
void inorder(struct Node *r)
{
  struct Node *current = r;
  struct Stack *s = NULL;
  Top=NULL;
  while (1)
  {
    if(current !=  NULL)
    {
      push(current,1);                                               
      current = current->left;  
    }
    else                                                             
    {
      if (Top!=NULL)
      {
        current = pop(1);
        printf("%d ", current->data);
        current = current->right;
      }
      else
        return;
    }
  }
} 
void preorder(struct Node *r)
{
    if (r == NULL)
       return;
    Top=NULL;
    struct Stack *s = NULL;
    struct Node *current = r;
    push(current,1);
    while (Top!=NULL)
    {
        current = pop(1);
        printf ("%d ",current->data);
        if (current->right)
            push(current->right,1);
        if (current->left)
            push(current->left,1);
    }
}
void postorder(struct Node *r)
{
    if(r==NULL)
        return;
    Top=Top1=NULL;
    struct Node *current = r;
    push(current,1);
    while(Top!=NULL)
    {
        current = pop(1);
        push(current,2);
        if (current->left)
            push(current->left,1);
        if (current->right)
            push(current->right,1);
    }
    display(Top1);
}
void push(struct Node *t, int stn)
{  
  struct Stack * node =(struct Stack*) malloc(sizeof(struct Stack));  
  node->elem=t;
  if(stn==1)
  {
      if(Top==NULL)
      {
          Top=node;
          Top->next=NULL;
      }
      else
      {
        node->elem = t;
        node->next =Top;   
        Top=node;
      }
  }
  else
  {
    if(Top1==NULL)
      {
          Top1=node;
          Top1->next=NULL;
      }
      else
      {
        node->elem = t;
        node->next =Top1;   
        Top1=node;
      }
  }
}
struct Node *pop(int stn)
{
    struct Stack *temp;
    if(stn==1)
        temp=Top;
    else
        temp=Top1;
    struct Node *x=temp->elem;
    temp=temp->next;
    if(stn==1)
    {
        free(Top);
        Top=temp;
    }
    else
    {
        free(Top);
        Top=temp;
    }    
    return x;
}
void display(struct Stack *top)
{
    struct Stack * temp =(struct Stack*) malloc(sizeof(struct Stack));  
    temp=top;
    while(temp!=NULL)
    {
        printf("%d ",temp->elem->data);
        temp=temp->next;
    }
    printf("\n");
}
