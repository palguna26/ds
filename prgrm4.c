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
void SearchByKey(NODE);
void InsertByOrder(NODE);
void DeleteByPosition(NODE);
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
        printf("\nEnter your choice:\n1:Insert by front\n2:Display\n3:Search by key\n4:Insert by order\n5:Delete by position\n6:Delete by key\n");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1: InsertFront(Header); Display(Header); break;
            case 2: Display(Header); break;
            case 3: SearchByKey(Header); break;
            case 4: InsertByOrder(Header); Display(Header); break;
            case 5: DeleteByPosition(Header); Display(Header); break;
            case 6: DeleteByKey(Header); Display(Header); break;
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


void InsertByOrder(NODE H)
{
    NODE NN = createNode();
    NODE TP,PN;
    TP = H->link;
    PN = H;
    while(TP != H && TP->info < NN->info)
    {
        PN = TP;
        TP = TP->link;
    }
    NN->link = TP;
    PN->link = NN;
    H->info++;
}

void DeleteByPosition(NODE H)
{
    NODE TP,ND;
    int pos,count = 0;
    if(H->info == 0)
    {
        printf("List is empty!!\n");
        return;
    }
    do{
        printf("Enter a valid position between 1 and %d: ",H->info);
        scanf("%d",&pos);
    }while(pos<1 || pos>H->info);
    TP = H;
    while(count < pos-1)
    {
        TP = TP->link;
        count++;
    }
    ND = TP->link;
    TP->link = ND->link;
    printf("Deleted element is %d\n",ND->info);
    free(ND);
    H->info--;
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
