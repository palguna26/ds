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
NODE SearchByPosition(NODE);
void InsertByOrder(NODE);
void DeleteByKey(NODE);
void DeleteByPosition(NODE);


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
        printf("\nEnter your choice:\n1:Insert by front\n2:Display\n3:Search by position\n4:Insert by order\n5:Delete by key\n6:Delete by position\n");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1: InsertFront(Header); Display(Header); break;
            case 2: Display(Header); break;

            case 3: NS = SearchByPosition(Header);
                    if(NS == NULL)
                        printf("List is empty!!\n");
                    else
                        printf("Element present at the entered position is %d\n",NS->info);
                    break;
            
            case 4: InsertByOrder(Header); Display(Header); break;
            case 5: DeleteByKey(Header); Display(Header); break;
            case 6: DeleteByPosition(Header); Display(Header); break;
            
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

void DeleteByKey(NODE H)
{
    NODE TP;
    int key;
    if(H->info == 0)
    {
        printf("List is empty!!\n");
        return;
    }
    printf("Enter the key element: ");
    scanf("%d",&key);
    TP = H->RL;
    while(TP != H)
    {
        if(TP->info == key)
        {
            TP->LL->RL = TP->RL;
            TP->RL->LL = TP->LL;
            printf("Deleted element is %d\n",TP->info);
            free(TP);
            H->info--;
            return;
        }
        TP = TP->RL;
    }
    printf("Key is not found!!\n");
}

void DeleteByPosition(NODE H)
{
    NODE TP;
    int pos,count;
    if(H->info == 0)
    {
        printf("List is empty!!\n");
        return;
    }
    do{
        printf("Enter a valid position between 1 and %d: ",H->info);
        scanf("%d",&pos);
    }while(pos<1 || pos>H->info);
    count = 1;
    TP = H->RL;
    while(count != pos)
    {
        TP = TP->RL;
        count++;
    }
    TP->LL->RL = TP->RL;
    TP->RL->LL = TP->LL;
    printf("Deleted element is %d\n",TP->info);
    H->info --;
    free(TP);
}

