#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
typedef struct{
    int top;
    char arr[50];
}stack1;
stack1 *s;
typedef struct{
    int top2;
    double arr2[50];
}stack2;
stack2 *s2;
void push(char data){
    s->arr[++s->top]=data;
}
char pop(){
    return s->arr[s->top--];
}
char peek(){
    return s->arr[s->top];
}
void push2(char data){
    s2->arr2[++s2->top2]=data;
}
double pop2(){
    return s2->arr2[s2->top2--];
}
double peek2(){
    return s2->arr2[s2->top2];
}
int precedence(char ch){
    switch(ch){
        case '+':
        case '-':return 2;
        case '*':
        case '/':return 4;
        case '$':
        case '^':return 6;
        case '(':
        case ')':return 0;
    }
}
char associativity(char ch){
    if(ch=='$' || ch=='^'){
        return 'R';
    }
    return 'L';
}
double compute(char ch,double op1,double op2){
    switch(ch){
        case '+':return op1+op2;
        case '-':return op1-op2;
        case '*':return op1*op2;
        case '/':return op1/op2;
        case '$':
        case '^':return pow(op1,op2);
    }
}
void reverse(char prefix[]){
    int n=strlen(prefix);
    for(int i=0;i<n/2;i++){
        char ch=prefix[i];
        prefix[i]=prefix[n-i-1];
        prefix[n-i-1]=ch;
    }
}
void infixtoprefix(char infix[],char prefix[]){
    int j=0;
    reverse(infix);
    for(int i=0;i<strlen(infix);i++){
        char ch=infix[i];
        if(isalnum(ch)){
            prefix[j++]=ch;
        }else if(ch==')'){
            push(ch);
        }else if(ch=='('){
            while(peek()!=')'){
                prefix[j++]=pop();
            }
            pop();
        }else{
            while(precedence(peek())>precedence(ch) || precedence(peek())==precedence(ch) && associativity(ch)=='R'){
                prefix[j++]=pop();
            }
            push(ch);
        }
    }
    while(s->top!=-1){
        prefix[j++]=pop();
    }
    prefix[j] = '\0';
    reverse(prefix);
    printf("%s\n",prefix);
}
void evaluation(char prefix[]){
    for(int i=strlen(prefix)-1;i>=0;i--){
        char ch=prefix[i];
        if(isdigit(ch)){
            push2(ch-'0');
        }else if(isalnum(ch)){
            double val;
            printf("Enter %c value :\n",ch);
            scanf("%lf",&val);
            push2(val);
        }else{
            double op1=pop2();
            double op2=pop2();
            double result=compute(ch,op1,op2);
            push2(result);
        }
    }
    printf("%lf is answer\n",peek2());
}
int main(){
    char infix[20];
    char prefix[20];
    s=(stack1*)malloc(sizeof(stack1));
    s->top=-1;
    s2=(stack2*)malloc(sizeof(stack2));
    s2->top2=-1;
    printf("Enter Infix Expression\n");
    scanf("%s",infix);
    int choice;
    do{
        printf("MENU\n1.conversion\n2.evaluation\n3.exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1 : infixtoprefix(infix,prefix);
            break;
            case 2 : evaluation(prefix);
            break;
            case 3 : exit(0);
            default : printf("Enter valid choice\n");
        }
    }while(choice!=3);
}
