#include <stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *RL;
    struct node *LL;
};

typedef struct node *NODE;

NODE createNode();
void InsertFront(NODE);
void Display(NODE);

void DeleteFront(NODE);
void DeleteRear(NODE);

NODE SearchByPosition(NODE);

void InsertByOrder(NODE);
v

void main()
{
    NODE Header = (NODE)malloc(sizeof(struct node));
    NODE CopyHeader = (NODE)malloc(sizeof(struct node));
    NODE NS;
    int choice;
    Header->info = 0;
    Header->LL = Header->RL = Header;
    CopyHeader->info = 0;
    CopyHeader->RL = CopyHeader->LL = CopyHeader;
    
    for(;;)
    {
        printf("\nEnter your choice:\n1:Insert by front\n2:Display\n3:Delete by front\n4:Delete by rear\n5:Search by position\n6:Insert by order\n");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1: InsertFront(Header); Display(Header); break;
            case 2: Display(Header); break;
           
            case 3: DeleteFront(Header); Display(Header); break;
            case 4: DeleteRear(Header); Display(Header); break;
            
            case 5: NS = SearchByPosition(Header);
                    if(NS == NULL)
                        printf("List is empty!!\n");
                    else
                        printf("Element present at the entered position is %d\n",NS->info);
                    break;
           
            case 6: InsertByOrder(Header); Display(Header); break;
            
            default: exit(0);
        }
    }
}

NODE createNode()
{
    NODE NN = (NODE)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&NN->info);
    NN->RL = NN->LL = NN;
}

void InsertFront(NODE H)
{
    NODE NN = createNode();
    NN->RL = H->RL;
    NN->LL = H;
    H->RL = NN;
    NN->RL->LL = NN;
    H->info++;
}

void Display(NODE H)
{
    NODE TP;
    if(H->info == 0)
    {
        printf("List is empty!!\n");
        return;
    }
    TP = H->RL;
    printf("Entered elements are: \n");
    while(TP != H)
    {
        printf("%d\t",TP->info);
        TP = TP->RL;
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
    FN = H->RL;
    H->RL = FN->RL;
    FN->RL->LL = H;
    H->info--;
    printf("Deleted element is %d\n",FN->info);
    free(FN);
}

void DeleteRear(NODE H)
{
    NODE LN;
    if(H->info == 0)
    {
        printf("List is empty!!\n");
        return ;
    }
    LN = H->LL;
    H->LL = LN->LL;
    LN->LL->RL = H;
    H->info --;
    printf("Deleted element is %d\n",LN->info);
    free(LN);
}



NODE SearchByPosition(NODE H)
{
    NODE TP;
    int pos,count;
    if(H->info == 0)
    {
        return NULL;
    }
    do{
        printf("Enter a valid position between 1 and %d: ",H->info);
        scanf("%d",&pos);
    }while(pos<1 || pos>H->info);
    TP = H->RL;
    count = 1;
    while(count != pos)
    {
        TP = TP->RL;
        count++;
    }
    return TP;
}


void InsertByOrder(NODE H)
{
    NODE NN = createNode();
    NODE TP;
    TP = H->RL;
    while(TP != H && TP->info<NN->info)
    {
        TP = TP->RL;
    }
    NN->RL = TP;
    NN->LL = TP->LL;
    NN->LL->RL = NN;
    TP->LL = NN;
    H->info ++;
}
