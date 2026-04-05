#include <stdio.h>
#include <string.h>
#define MAX 10
char stack[MAX];
int top=-1;

char push(char ch){
    if(top==MAX-1){
        return '#';
    }else{
        top+=1;
        stack[top]=ch;
    }
}

char pop(){
    if(top==-1){
        printf("the list is empty");
        return 0;
    }else{
        char ch;
        ch=stack[top];
        top--;
        return ch;
    }
}

int ismatching(char open,char closed){
    if(open=='(' && closed==')'){
        return 1;
    }else if(open=='[' && closed==']'){
        return 1;
    }else if(open=='{' && closed=='}'){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    char exp[100];
    printf("enter the expression:");
    scanf("%s", exp);
    for(int i=0;i<strlen(exp);i++){
        if (exp[i]=='('  || exp[i]=='[' || exp[i]=='{'){
            push(exp[i]);
        }else if(exp[i]==')' || exp[i]==']' || exp[i]=='}'){
            char popped=pop();
            if (popped=='#' || !ismatching(popped,exp[i])){
                printf("INVALID EXPRESSION\n");
                return 0;
            }
        }
    }
    if(top==-1){
        printf("Valid expression\n");
    }else{
        printf("invalid expression");
    }
}
