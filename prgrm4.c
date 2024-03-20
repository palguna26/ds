#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;
struct node * link;
};
typedef struct node* NODE;

int N=0;
NODE createnode();
void Display(NODE);
NODE insertrear(NODE);
NODE insertfront(NODE);
NODE deletefront(NODE);
NODE deleterear(NODE);
NODE insertbypos(NODE);
NODE deletebypos(NODE);
NODE deletebykey(NODE);
NODE insertbyorder(NODE);
NODE sort(NODE);
NODE search(NODE);
NODE reverse(NODE);
NODE cop(NODE);
void main()
{ 
  NODE First=NULL;
  NODE SN,copy,rev;
  int choice;
  system ("clear");
for(;;)
{
  printf("Enter choice\n 1.insertfront\n 2.Display\n 3.search by key\n 4.insertbyorder\n 5.deletebykey\n 6.delete by position\n ");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:First=insertfront(First);Display(First);break;
    case 2:Display(First);break;
    case 3:SN =search(First);
            if(SN==NULL)
            printf("Not present\n");
            else
            printf("Node info is  %d\n",SN->info);
            break;
    
    case 4:First=insertbyorder(First);Display(First);break;
    case 5:First=deletebykey(First);Display(First);break;
    case 6:First=deletebypos(First);Display(First);break;
    default:exit(0);
  }
}
}

NODE insertfront(NODE pf)
{
	NODE NN;
	NN=createnode();
	printf("Enter the data\n");
	scanf("%d",&NN->info);
	NN->link=pf;
	pf=NN;
	N++;
	return pf;
}

void Display(NODE pf)
{       
	if(pf==NULL)
	{
	printf("Empty");
	return;
	}
        printf("DATA is\n");
	while(pf!=NULL)
	{
	printf("%d\n",pf->info);
	pf=pf->link;
	}
}

NODE createnode()
{
	NODE NN;
	NN=(NODE)malloc(sizeof(struct node));
	return NN;
}






NODE search(NODE pf)
{
	int key;
	printf("Enter key");
	scanf("%d",&key);
	while(pf!=NULL)
	{
	if(pf->info=key)
	{return pf;
	}
	pf=pf->link;
	}
	return NULL;
}


NODE insertbyorder(NODE pF)
{
 	NODE NN,TP,PN;
	NN=createnode();
        printf("Enter the data\n");
	scanf("%d",&NN->info);
	NN->link=NULL;
	TP=pF; PN=NULL;
	while(TP!=NULL && TP->info<NN->info)
	  {
	   PN=TP;
	   TP=TP->link;
	  }
	if(PN==NULL)
	  {
	   NN->link=TP;
           return NN;
	  }
	NN->link=TP;
	PN->link=NN;
	N++;
	return pF;
}

NODE deletebykey(NODE pf)
{
	NODE ND,PN;
	int key;	
	if(pf==NULL)
	{
	printf("Empty");
	return NULL;
	}
	printf("Enter key");
	scanf("%d",&key);
	ND=pf;
	PN=NULL;
	while(ND!=NULL&&ND->info!=key)
	{PN=ND;
	ND=ND->link;
	}
	if(ND==NULL)
	printf("Not found");
	else if(PN==NULL)
	pf=pf->link;
	else 
	PN->link=ND->link;
	printf("Deleted item is %d",ND->info);
	N--;
	free(ND);
	return pf;
}


NODE deletebypos(NODE pf)
{
	NODE ND,PN;
	int pos,cnt;
	if(pf==NULL)
	{
	printf("Empty");
	return NULL;
	}
	L1:printf("Enter position between 1 to %d",N);
	scanf("%d",&pos);
	if(pos<1||pos>N) goto L1;
	ND=pf;
	PN=NULL;
	cnt=1;
	while(cnt!=pos)
	{PN=ND;
	ND=ND->link;
	cnt++;
	}
	if(PN==NULL)
	pf=pf->link;
	else 
	PN->link=ND->link;
	printf("Deleted item is %d",ND->info);
	N--;
	free(ND);
	return pf;
}

