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
int pop2(){
    return s2->arr2[s2->top2--];
}
int peek2(){
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
void infixtopostfix(char infix[],char postfix[]){
    int j=0;
    for(int i=0;i<strlen(infix);i++){
        char ch=infix[i];
        if(isalnum(ch)){
            postfix[j++]=ch;
        }else if(ch=='('){
            push(ch);
        }else if(ch==')'){
            while(peek()!='('){
                postfix[j++]=pop();
            }
            pop();
        }else{
            while(precedence(peek())>precedence(ch) || precedence(peek())==precedence(ch) && associativity(ch)=='L'){
                postfix[j++]=pop();
            }
            push(ch);
        }
    }
    while(s->top!=-1){
        postfix[j++]=pop();
    }
    postfix[j] = '\0';
    printf("%s\n",postfix);
}
void evaluation(char postfix[]){
    for(int i=0;i<strlen(postfix);i++){
        char ch=postfix[i];
        if(isdigit(ch)){
            push2(ch-'0');
        }else if(isalnum(ch)){
            int val;
            printf("Enter %c value :\n",ch);
            scanf("%d",&val);
            push2(val);
        }else{
            double op1=pop2();
            double op2=pop2();
            double result=compute(ch,op2,op1);
            push2(result);
        }
    }
    printf("%d is answer\n",peek2());
}
int main(){
    char infix[20];
    char postfix[20];
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
            case 1 : infixtopostfix(infix,postfix);
            break;
            case 2 : evaluation(postfix);
            break;
            case 3 : exit(0);
            default : printf("Enter valid choice\n");
        }
    }while(choice!=3);
}
