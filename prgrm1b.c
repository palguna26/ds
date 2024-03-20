#include <stdio.h>
#include <stdlib.h>
//TIME Structure containing 3 members
struct TIME {
    int hr,min,sec;
};
//Type Defining struct TIME
typedef struct TIME Time;
//Function Prototypes
void read(Time *);
void disp(Time *);
void update(Time *);
void add(Time *, Time *, Time *);
//Main Function
void main()
{
    int choice;
    //Declaring 4 Pointers to Structure TIME
    Time T1,T2,T3,T4;
    for(;;)
    {
        printf("\nEnter your Choice : \n");
        printf("1.Read\n2.Update\n3.Add\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : printf("Reading T1..\n");
                     read(&T1);
                     printf("Reading T2..\n");
                     read(&T2);
                     printf("The Time you entered are :\n");
                     printf("T1 = ");
                     disp(&T1);
                     printf("\nT2 = ");
                     disp(&T2);
                     printf("\n");
                     break;
            case 2 : printf("Enter the Time to be Updated\n");
                     read(&T3);
                     printf("The time before Updation = ");
                     disp(&T3);
                     update(&T3);
                     printf("\nThe time before Updation = ");
                     disp(&T3);
                     break;
            case 3 : printf("Adding Two Times:\n");
                     printf("T1 = ");
                     disp(&T1);
                     printf("\nT2 = ");
                     disp(&T2);
                     add(&T1, &T2, &T4);
                     printf("\nThe added time is = ");
                     disp(&T4);
                     break;
            case 4 : printf("\nExecution Successfull\n!!THANK YOU!!\n");
                     exit(0);
            default : printf("\nInvalid Choice\nEnter Again\n");
        }
    }
}
//Function to read Time
void read(Time *T)
{
    printf("Enter the time in Hours:Minutes:Seconds : ");
    scanf("%d%d%d",&T->hr,&T->min,&T->sec);
}
//Function to display Time
void disp(Time *T)
{
    printf("%d:%d:%d",T->hr,T->min,T->sec);
}
//Function to Update Time by 1 second
void update(Time *T)
{
    T->sec++;
    if(T->sec>=60)
    {
        T->min++;
        T->sec=T->sec%60;
        if(T->min>=60)
        {
            T->hr++;
            T->min = T->min % 60;
            if(T->hr>=24)
                T->hr=T->min=T->sec=0;
        }
    }
}
//Function to add 2 Times
//T3 stores the added time
void add(Time *T1,Time *T2,Time *T3)
{
    T3->hr=T3->min=T3->sec=0;
    T3->hr = T1->hr + T2->hr;
    T3->min = T1->min + T2->min;
    T3->sec = T1->sec + T2->sec;
    if(T3->sec>=60)
    {
        T3->min++;
        T3->sec=T3->sec%60;
        if(T3->min>=60)
        {
            T3->hr++;
            T3->min = T3->min % 60;
            if(T3->hr>=24)
                T3->hr=T3->min=T3->sec=0;
        }
    }
    if(T3->min>=60)
    {
        T3->hr++;
        T3->min = T3->min % 60;
        if(T3->hr>=24)
            T3->hr=T3->min=T3->sec=0;
    }
    if(T3->hr>=24)
        T3->hr=T3->min=T3->sec=0;
}
