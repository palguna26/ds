#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node*link;
};
struct linkedlist
{
    struct node *head;
};
struct node* createnode(int value)
{
    struct node newnode=(struct node)malloc (sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory allocation is failed\n");
    }
    newnode->data=value;
    newnode->link=NULL;
    return(newnode);
};
void createlist(struct linkedlist *mylist)
{
    mylist->head=createnode(0);
}
void insertatbeginning(struct linkedlist *list,int value)
{
    struct node *current=list->head;
    struct node *newnode=createnode(value);
    newnode->link=current->link;
    current->link=newnode;
}
void insertatend(struct linkedlist *list,int value)
{
    struct node *current=list->head;
    struct node *newnode=createnode(value);
    while(current->link!=NULL)
    {
        current=current->link;
    }
    current->link=newnode;
}
void  insertatposition(struct linkedlist *list,int pos,int value)
{
    int i;
    struct node *newnode=createnode(value);
    struct node *current=list->head;
    if(pos==0)
    {
        newnode->link=current->link;
        current->link=newnode;
        return;
    }
    for(i=0;i<pos-1&&current!=NULL;i++)
   {
      current=current->link;
     }
     if(current==NULL)
     {
         printf("Invalid position\n");
     }
     newnode->link=current->link;
     current->link=newnode;
}
void display(struct linkedlist *list)
{
    struct node *current=list->head->link;
    while(current!=NULL)
    {
        printf("%d->",current->data);
        current=current->link;
    }
    printf("\n");
}
void deleteatstart(struct linkedlist *list)
{
   struct node *current=list->head->link;
   list->head->link=current->link;
   free(current);
}
void deleteatend(struct linkedlist *list)
{
    struct node *current=list->head;
    struct node *prev=NULL;
    while(current->link!=NULL)
    {
      prev=current;
      current=current->link;
    }
    prev->link=NULL;
    free(current);
}
void deleteatposition(struct linkedlist *list,int pos)
{
   int i;
   struct node *current=list->head->link;
   struct node *prev=NULL;
   if(pos==0)
   {
       list->head->link=current->link;
       free(current);
   }
   for(i=1;i<pos-1&&current!=NULL;i++)
   {
       prev=current;
       current=current->link;
    }
    if(current==NULL)
    {
        printf("Invalid position\n");
        return;
    }
    prev->link=NULL;
    free(current);
}
void deletebykey(struct linkedlist *list,int key)
{
   struct node *current=list->head->link;
   struct node *prev= list->head;
   if(list->head==NULL)
   {
       printf("Empty list,delete by key is not possible\n");
       return;
   }
   if(current!=NULL&&current->data==key)
   {
       list->head->link=current->link;
       free(current);
       return;
   }
   while(current!=NULL&&current->data!=key)
   {
     prev=current;
     current=current->link;

   }
   if(current==NULL)
   {
       printf("key not found in the list\n");
       return ;
   }
   prev->link=current->link;
   free(current);
}
struct node* searchbykey(struct linkedlist *list,int key)
{
  struct node *current=list->head->link;
  int i=0;
    if(current==NULL)
   {
       printf("Empty list,search by key is not possible\n");
       return;
   }
   while(current!=NULL)
   {
       i++;
       if(current->data==key){
        printf("Key found at %d position\n",i);
        return current;
       }
       current=current->link;
   }
    return NULL;
}
void insertorderlist(struct linkedlist *list,int value)
{
    struct node *newnode=createnode(value);
    struct node *current=list->head;
    while(current->link!=NULL&&current->link->data<value)
    {
      current=current->link;
    }
    newnode->link=current->link;
    current->link=newnode;
}
void copylist(struct linkedlist *list,struct linkedlist *copy)
{
  struct node *current=list->head;
  struct node *tail=NULL;
  struct node *newnode;
  while(current!=NULL)
  {
      newnode=createnode(current->data);
      if(tail==NULL)
      {
          copy->head=newnode;
          tail=copy->head;
      }
      else
      {
          tail->link=newnode;
          tail=newnode;
      }
      current=current->link;
  }
}



void reverselist(struct linkedlist *list)
{
    struct node *current ,*prev,*next;
    prev=NULL;
    current=next=list->head->link;
    while(next!=NULL)
    {
        next=next->link;
        current->link=prev;
        prev=current;
        current=next;
    }
    list->head->link=prev;
}
void freelist(struct linkedlist *list)
{
    struct node *current=list->head;
    struct node *next=NULL;
    while(current!=NULL)
    {
        next=current->link;
        free(current);
        current=next;
    }
}

int main()
{
    struct linkedlist *list;
    int val,pos,n,res,key,i;
    list=(struct linkedlist*)malloc(sizeof(struct linkedlist));
    createlist(list);
    struct linkedlist *copiedlist,*orderedlist;
    copiedlist=(struct linkedlist*)malloc(sizeof(struct linkedlist));
    createlist(copiedlist);
    orderedlist=(struct linkedlist*)malloc(sizeof(struct linkedlist));
    createlist(orderedlist);


    while(1)
    {
        printf("Enter\n 1.Insert at beginning\n2.Insert at position\n 3.display\n 4.delete at start\n 5.delete at end\n 6.search by key\n");
        scanf("%d",&n);
        {
        switch(n){
            case 1:printf("Enter the value to be inserted\n");
                   scanf("%d",&val);
                   insertatbeginning(list,val);
                   break;
          
            case 2:printf("Enter the value to be inserted\n");
                   scanf("%d",&val);
                   printf("Enter the position to insert:\n");
                   scanf("%d",&pos);
                   insertatposition(list,pos,val);
                   break;
            case 3:display(list);
                   break;
            case 4:deleteatstart(list);
                   break;

            case 5:deleteatend(list);
                   break;
            
            case 6:
                    printf("Enter the key to search:\n");
                    scanf("%d",&val);
                    res=searchbykey(list,val);
                    if(res!=NULL)
                    {
                        printf("the address of the node at which key %d is present is %d\n ",val,res);
                    }
                    else
                        printf("key is not found in the list\n");
                    break;
            
            default:free(list);
            return 0;
        }
    }
    }
}
