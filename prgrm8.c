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
void DeleteFront(NODE);
void DeleteRear(NODE);
void SearchByKey(NODE);
void InsertByPosition(NODE);
void main()
{
    NODE Header,CopyHeader;
    int choice;
    Header = (NODE)malloc(sizeof(struct node));
    Header->info = 0;
    Header->link = Header;
    for(;;)
    {
        printf("\nEnter your choice:\n1:Insert by front\n2:Display\n3:Delete by front\n4:Delete bt rear\n5:Search by key\n6:Insert by position\n");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1: InsertFront(Header); Display(Header); break;
            case 2: Display(Header); break;
            case 3: DeleteFront(Header); Display(Header); break;
            case 4: DeleteRear(Header); Display(Header); break;
            case 5: SearchByKey(Header); break;
            case 6: InsertByPosition(Header); Display(Header); break;
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



void DeleteFront(NODE H)
{
    NODE FN;
    if(H->info == 0)
    {
        printf("List is empty!!\n");
        return;
    }
    FN = H->link;
    H->link = FN->link;
    printf("Deleted element is %d\n",FN->info);
    free(FN);
    H->info--;
}

void DeleteRear(NODE H)
{
    NODE LN, PL;
    if(H->info == 0)
    {
        printf("List is empty!!\n");
        return;
    }
    LN = H->link;
    PL = H;
    while(LN->link != H)
    {
        PL = LN;
        LN = LN->link;
    }
    PL->link = LN->link;
    printf("Deleted element is %d\n",LN->info);
    free(LN);
    H->info--;
}

void SearchByKey(NODE H)
{
    int key;
    NODE TP;
    if(H->info == 0)
    {
        printf("List is empty!!\n");
        return;
    }
    printf("Enter the key element: ");
    scanf("%d",&key);
    TP = H->link;
    while(TP != H)
    {
        if(TP->info == key)
        {
            printf("key element %d is found\n",TP->info);
            return;
        }
        TP = TP->link;
    }
    printf("Key element does not exist!!\n");
}


void InsertByPosition(NODE H)
{
    int pos, count = 0;
    NODE NN = createNode();
    NODE TP;
    do{
        printf("Enter a valid position between 1 and %d: ",H->info + 1);
        scanf("%d",&pos);
    }while(pos<1 || pos>H->info + 1);
    TP = H;
    while(count < pos-1)
    {
        TP = TP->link;
        count++;
    }
    NN->link = TP->link;
    TP->link = NN;
    H->info ++;
}

