[12:51, 20/03/2024] 🌹: #include <stdio.h>
#include <stdlib.h>
//N->Number Of Students
int N,size,i,j;
//Defining a Structure named Student
struct student{
    char name[30];
    int reg_no;
    int marks[3];
    float avg;
};
//Function Prototypes
void read(struct student *);
void disp(struct student *);
void avg(struct student *);
//Main Function
void main()
{
    //Declaring Pointer to Student Structure
    struct student *st;
    printf("Enter the size:");
    scanf("%d",&size);
    //Dynamically Allocating Memory for array of Structures
    st = (struct student *) malloc(size*sizeof(struct student));
    int choice;
    for(;;)
    {
        printf("Enter Your Choice:\n");
        printf("1.Input\n2.Display\n3.Average\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : read(st);
                     break;
            case 2 : disp(st);
                     break;
            case 3 : avg(st);
                     break;
            case 4 : printf("!!THANK YOU!!\n");
                     exit(0);
            default : printf("Invalid Choice\n!!Thank You!!\n");
                      free(st); st=NULL;             
        }
    }
}
//Function to read Student Details
void read(struct student *st)
{
    
    printf("Enter the number of Students:\n");
    scanf("%d",&N);
    if(N>size)
    {
        printf("insufficient Space\n");
        printf("Creating space by reallocating memory\n");
        st = (struct student *) realloc(st,(N-size)*sizeof(struct student));
    }
    for(i=0;i<N;i++)
    {
        printf("Enter the Name and Reg_no of Student %d\n",i+1);
        scanf("%s%d",(st+i)->name,&(st+i)->reg_no);
        printf("Enter the marks Scored in three tests:\n");
        for(j=0;j<3;j++)
        {
            scanf("%d",&(st+i)->marks[j]);
        } 
    }
}
//Function to display Student Details
void disp(struct student *st)
{
    if(N==0)
    {
        printf("List is Empty!");
        return;
    }
    printf("The details of %d students are:\n",N);
    printf("Reg-No\tName\tTest1\tTest2\tTest3\t\n");
    for(i=0;i<N;i++)
    {
        printf("%d\t%s\t",(st+i)->reg_no,(st+i)->name);
        for(j=0;j<3;j++)
        {
            printf("%d\t",(st+i)->marks[j]);
        }
        printf("\n");
    }
} 
//Function to calculate average of Students and display 
void avg(struct student *st)
{
    int k,temp,sum[N]; 
    //temp : variable used for swapping
    //sum[N] : Array to Store Total marks of N students
    for(i=0;i<N;i++)
    {
        for(j=0;j<3;j++)
        {
            for(k=0;k<3-j-1;k++)
            {
                if((st+i)->marks[k]>(st+i)->marks[k+1])
                {
                    temp = (st+i)->marks[k];
                    (st+i)->marks[k] = (st+i)->marks[k+1];
                    (st+i)->marks[k+1] = temp;
                }
            }
        }
    }
    for(i=0;i<N;i++)
    {
        sum[i] = (st+i)->marks[1] + (st+i)->marks[2];
        (st+i)->avg = (float)sum[i]/2;
    }
    printf("The details of %d students are:\n",N);
    printf("Reg-No\tName\t\tTest1\tTest2\tTest3\tAverage\n");
    for(i=0;i<N;i++)
    {
        printf("%d\t%s\t\t",(st+i)->reg_no,(st+i)->name);
        for(j=0;j<3;j++)
        {
            printf("%d\t",(st+i)->marks[j]);
        }
        printf("%.2f",(st+i)->avg);
        printf("\n");
    }
}
[12:51, 20/03/2024] 🌹: 1 b)
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
