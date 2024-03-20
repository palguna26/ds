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
void InsertRear(NODE);

NODE SearchByKey(NODE);

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
        printf("\nEnter your choice:\n1:Insert by front\n2:Display\n3:Insert by rear\n4:Search by key\n5:Delete by position\n");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1: InsertFront(Header); Display(Header); break;
            case 2: Display(Header); break;
            case 3: InsertRear(Header); Display(Header); break;
           
            case 4: if(Header->info == 0)
                    {
                        printf("List is empty!!\n");
                        break;
                    }
                    NS = SearchByKey(Header);
                    if(NS == NULL)
                    {
                        printf("Key element does not exist!!\n");
                    }
                    else
                        printf("The key element %d is found\n",NS->info);
                    break;
           
            case 5: DeleteByPosition(Header); Display(Header); break;
            
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

void InsertRear(NODE H)
{
    NODE NN = createNode();
    NN->RL = H;
    NN->LL = H->LL;
    H->LL = NN;
    NN->LL->RL = NN;
    H->info ++;
}

NODE SearchByKey(NODE H)
{
    NODE TP;
    int key;
   
    printf("Enter the key element: ");
    scanf("%d",&key);
    TP = H->RL;
    while(TP != H)
    {
        if(TP->info == key)
        {
            return TP;
        }
        TP = TP->RL;
    }
    return NULL;
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
