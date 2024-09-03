#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node *NODE;

NODE createNode();
void InsertFront(NODE);
void Display(NODE);
void InsertRear(NODE);
void SearchByPosition(NODE);
void DeleteByKey(NODE);

void main()
{
    NODE Header;
    int choice;
    Header = (NODE)malloc(sizeof(struct node));
    Header->info = 0;
    Header->link = Header;
    
    for(;;)
    {
        printf("\nEnter your choice:\n1:Insert by front\n2:Display\n3:Insert by rear\n4:Search by position\n5:Delete by key\n");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1: InsertFront(Header); Display(Header); break;
            case 2: Display(Header); break;
            case 3: InsertRear(Header); Display(Header); break;
            case 4: SearchByPosition(Header); break;
            case 5: DeleteByKey(Header); Display(Header); break;
            default: exit(0);
        }
    }
}

NODE createNode()
{
    NODE NN = (NODE)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&NN->info);
    NN->link = NN;
    return NN;
}

void InsertFront(NODE H)
{
    NODE NN = createNode();
    NN->link = H->link;
    H->link = NN;
    H->info ++;
}

void Display(NODE H)
{
    NODE TP;
    if(H->info == 0)
    {
        printf("List is empty!!\n");
        return;
    }
    TP = H->link;
    printf("Entered elements are: \n");
    while(TP != H)
    {
        printf("%d\t",TP->info);
        TP = TP->link;
    }
}

void InsertRear(NODE H)
{
    NODE TP;
    NODE NN = createNode();
    TP = H->link;
    while(TP->link != H)
        TP = TP->link;
    NN->link = TP->link;
    TP->link = NN;
    H->info++;
}




void SearchByPosition(NODE H)
{
    int pos,count = 1;
    NODE TP;
    if(H->info == 0)
    {
        printf("List is empty!!\n");
        return;
    }
    do{
       printf("Enter a valid position between 1 and %d: ",H->info);
       scanf("%d",&pos);
    }while(pos<1 || pos>H->info);
    TP = H->link;
    while(count < pos)
    {
        TP = TP->link;
        count++;
    }
    printf("Element at position %d is %d\n",pos,TP->info);
}





void DeleteByKey(NODE H)
{
    int key;
    NODE TP,PN;
    if(H->info == 0)
    {
        printf("List is empty!!\n");
        return;
    }
    printf("Enter the key element: ");
    scanf("%d",&key);
    TP = H->link;
    PN = H;
    while(TP != H)
    {
        if(TP->info == key)
        {
           PN->link = TP->link;
           printf("Deleted element is %d\n",TP->info);
           free(TP);
           H->info--;
           return;
        }
        PN = TP;
        TP = TP->link;
    }
    printf("Key element does not exist!!\n");
}
