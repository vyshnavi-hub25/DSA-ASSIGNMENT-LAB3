#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 10
int stack[MAX];
int top=-1;
int push(int value){
    if(top==MAX-1){
        printf("the list is full\n");
        return 0;
    }else{
        top++;
        stack[top]=value;

    }
}
int pop(){
    if(top==-1){
        printf("the list is an empty\n");
        return 0;
    }else{
        int value;
        value=stack[top];
        top--;
        return value;
    }
    
}

int main(){
    char postfix[100];
    printf("enter the postfix expression:");
    scanf("%s", postfix);
    int A,B,result;
    for(int i=0;i<strlen(postfix);i++){
        if(isdigit(postfix[i])){
            push(postfix[i]-'0');
        }else{
            A=pop();
            B=pop();
            if(postfix[i]=='+'){
                result=B+A;
            }else if(postfix[i]=='-'){
                result=B-A;
            }else if(postfix[i]=='*'){
                result=B*A;
            }else{
                result=B/A;
            }
            push(result);
        }
    }
    printf("result:%d",pop());
    return 0;

}
