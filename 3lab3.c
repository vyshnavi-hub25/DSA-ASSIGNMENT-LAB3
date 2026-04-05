#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 20
char stack[MAX];
int top=-1;

void push(char ch){
    if(top==MAX-1){
        printf("the list is empty\n");
        return;
    }else{
        top++;
        stack[top]=ch;
    }
}

char pop(){
    char ch;
    ch=stack[top];
    top--;
    return ch;
}

int precedence(char ch){
    if(ch=='^'){
        return 3;
    }else if(ch=='*'  || ch=='/'){
        return 2;
    }else if(ch=='+' || ch=='-'){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    char infix[100];
    char postfix[100];
    printf("enter the infix:");
    scanf("%s", infix);
    int j=0;
    for(int i=0;i<strlen(infix);i++){
        if(isalnum(infix[i])){
            postfix[j]=infix[i];
            j++;
        }else if(infix[i]=='('){
            push(infix[i]);
        }else if(infix[i]==')'){
            while(stack[top]!='('){
                postfix[j]=pop();
                j++;
            }
            pop();
        }else{
            while(top!=-1 && precedence(stack[top])>=precedence(infix[i])){
                postfix[j]=pop();
                j++;
            }
            push(infix[i]);
        }
    }
    while(top!=-1){
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';
    printf("postfix of the given infix is:%s",postfix);
    return 0;
}
