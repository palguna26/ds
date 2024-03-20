#include<stdio.h>
#include<stdlib.h>
int ne=0; //Initializing Number of Elements in Array
//Function to read an Array
void read(int *x)
{	
    int i,n;
    printf("Enter The number of elements\n");
    scanf("%d",&n);
    printf("Enter The elements into The Array\n");
    for(i=0;i<n;i++)
    scanf("%d",(x+i));
    ne=n;
}
//Function to display elements of an Array
void disp(int *x)
{
    int i;
    if(ne==0)
    {
        printf("Array empty\n");
        return;
    }
    printf("The Array elements you Entered are : \n");
    for(i=0;i<ne;i++)
    printf("%d\t",*(x+i));
    printf("\n");
}
//Function to insert an element into Array at specified position
void insert_by_pos(int *x,int size)
{
    int i,pos,ele;
    if(ne==size)
    {
        printf("Array is full.\n");
        printf("Reallocating Array\n");
        size++;
        x=(int*)realloc(x,size*sizeof(int));
    }
    printf("Enter The element to be inserted : \n");
    scanf("%d",&ele);
    printf("Enter The position where The elements should be inserted\n");
    scanf("%d",&pos);
    if(pos>=1&&pos<=ne+1)
    {
        for(i=ne;i>=pos;i++)
        {
            (x+i)=(x+i-1);
        }
        *(x+i)=ele;
        ne++;
    }
    else
    printf("invalid position\n");
}
void delete_by_ele(int *x)
{
    int i,ele;
    if(ne==0)
    {
        printf("Array is empty.\n");
        return;
    }
    printf("Enter The elements that should be deleted\n");
    scanf("%d",&ele);
    for(i=0;i<ne&&*(x+i)!=ele;i++);
    if(i==ne)
    {
        printf("element not found in The Array list\n");
        return;
    }
    for(;i<ne-1;i++)
    {
        (x+i)=(x+i+1);
    }
    ne--;
}
void search_by_pos(int *x)
{
    int pos,i;
    if(ne==0)
    {
        printf("Array is empty\n");
        return;
    }
    printf("Enter The position from where element should be searched\n");
    scanf("%d",&pos);
    if(pos>=1&&pos<=ne)
    {
        i=pos-1;
        printf("element at %d is %d\n",pos,*(x+i));
    }
    else
    printf("invalid position\n");
}
//Function to reverse The elements of Array
void reverse(int *x)
{
    int t,i;
    if(ne==0)
    {
        printf("Array is empty\n");
        return;
    }
    for(i=0;i<ne/2;i++)
    {
        t=*(x+i);
        (x+i)=(x+ne-i-1);
        *(x+ne-i-1)=t;
    }
}
void main()
{
    int *a; //Base Address of Array
    int choice,size;
    printf("Enter The size\n");
    scanf("%d",&size);
    a=(int *)malloc(size*sizeof(int)); //Dynamically Allocating memory for Array
    printf("Menu\n1.Read\n2.Display\n3.Insert by position\n4.Delete by element\n5.Search by position\n6.Reverse\n7.Exit\n");
    for(;;)
    {
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: read(a);
                    disp(a);
                    break;
            case 2: disp(a);
                    break;
            case 3: insert_by_pos(a,size);
                    disp(a);
                    break;
            case 4: delete_by_ele(a);
                    disp(a);
                    break;
            case 5: search_by_pos(a);
                    break;
            case 6: reverse(a);
                    disp(a);
                    break;
            case 7 : free(a);
                     a=NULL;
                     exit(0);
            default: printf("Invalid Choice\n");
        }
    }
}
