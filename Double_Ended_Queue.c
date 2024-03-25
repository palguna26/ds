/Double ended queue with dynamic memory allocation/

#include<stdio.h>
#include<stdlib.h>
int size;

struct Queue
{
    int *items;
    int Front, Rear;
};
typedef struct Queue QUE;

void InsertRear(QUE *);
void DeleteFront(QUE *);
void InsertFront(QUE *);
void DeleteRear(QUE *);
void Display(QUE *);
void QFront(QUE *);
void QRear(QUE *);

void main()
{
    QUE Q;
    int choice;
    Q.Front = 0;
    Q.Rear = -1;
    
    printf("Enter the size of the queue: ");
    scanf("%d",&size);
    Q.items = (int *)malloc(size*sizeof(int));
    
    for(;;)
    {
        printf("\nEnter your choice:\n1:Insert by rear\n2:Delete by front\n3:Display\n4:Insert by front\n5:Delete by rear\n6:Display first item of the queue\n7:Display last item of the queue\n");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1: InsertRear(&Q); Display(&Q); break;
            case 2: DeleteFront(&Q); Display(&Q); break;
            case 3: Display(&Q); break;
            case 4: InsertFront(&Q); Display(&Q); break;
            case 5: DeleteRear(&Q); Display(&Q); break;
            case 6: QFront(&Q); break;
            case 7: QRear(&Q); break;
            default: exit(0);
        }
    }
}

void InsertRear(QUE *PQ)
{
    int item, choice;
    if(PQ->Rear == size-1)
    {
        if(PQ->Front != 0)
        {
            printf("Front insertion is possible\n");
            return;
        }
        else
        {
            printf("Queue overflow!! Insertion is not possible!! Do you want to go for reallocation??\n");
            printf("Enter your choice:\n1:Yes\n2:No\n");
            scanf("%d",&choice);
            if(choice == 1)
            {
                size = size*2;
                PQ->items = (int *)realloc(PQ->items,size*sizeof(int));
            }
            else
            {
                printf("No more insertion is possible!!\n");
                return;
            }
            
        }
    }
    printf("Enter the item to be inserted: ");
    scanf("%d", &item);
    PQ->Rear++;
    *(PQ->items + PQ->Rear) = item;
    
}

void DeleteFront(QUE *PQ)
{
    if(PQ->Front > PQ->Rear)
    {
        printf("Queue underflow!! Deletion is not possible!!\n");
        return;
    }
    printf("Deleted element is %d\n",*(PQ->items + PQ->Front));
    PQ->Front++;
    if(PQ->Front > PQ->Rear)
    {
        PQ->Front = 0;
        PQ->Rear = -1;
    }
}

void Display(QUE *PQ)
{
    int i;
    if(PQ->Front > PQ->Rear)
    {
        printf("Queue is empty!!\n");
        return;
    }
    printf("The entered queue is :\n");
    for(i=PQ->Front; i<=PQ->Rear; i++)
        printf("%d\t",*(PQ->items + i));
    printf("\n");
}

void InsertFront(QUE *PQ)
{
    int item, choice;
    if(PQ->Front == 0 && PQ->Rear == -1)
    {
        printf("Enter the item to be inserted: ");
        scanf("%d", &item);
        *(PQ->items + ++PQ->Rear) = item;
        return;
    }
    if(PQ->Front != 0)
    {
        printf("Enter the item to be inserted: ");
        scanf("%d", &item);
        *(PQ->items + --PQ->Front) = item;
        return;
    }
    if(PQ->Rear == size-1 && PQ->Front == 0)
    {
        printf("No more insertion is possible!! Do you want to go for reallocation??\n");
        printf("Enter your choice:\n1:Yes\n2:No\n");
        scanf("%d",&choice);
        if(choice == 1)
        {
            size = size*2;
            PQ->items = (int *)realloc(PQ->items,size*sizeof(int));
        }
        else
        {
            printf("No more insertion is possible!!\n");
            return;
        }
    }
    if(PQ->Rear != size-1)
        printf("Rear insertion is possible\n");
}

void DeleteRear(QUE *PQ)
{
    if(PQ->Front > PQ->Rear)
    {
        printf("Queue is empty!!\n");
        return;
    }
    printf("Deleted item is %d\n",*(PQ->items + PQ->Rear));
    PQ->Rear--;
    if(PQ->Front > PQ->Rear)
    {
        PQ->Front = 0;
        PQ->Rear = -1;
    }
}

void QFront(QUE *PQ)
{
    if(PQ->Front > PQ->Rear)
    {
        printf("Queue is empty!!\n");
        return;
    }
    printf("Front most item of the queue is : %d\n",*(PQ->items + PQ->Front));
}

void QRear(QUE *PQ)
{
    if(PQ->Front >  PQ->Rear)
    {
        printf("Queue is empty!!\n");
         return;
    }
    printf("Last element of the queue is %d\n", *(PQ->items + PQ->Rear));
}
