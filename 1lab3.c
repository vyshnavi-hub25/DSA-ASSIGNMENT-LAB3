#include <stdio.h>
#define MAX 5
int stack[MAX];
int top=-1;

void push(){
    int value;
    if(top==MAX-1){
        printf("the list is overflow!\n");
        return;
    }else{
        printf("enter the value:");
        scanf("%d",&value);
        top++;
        stack[top]=value;
        printf("%d value succesfully inserted\n",value);
    }
}

void pop(){
    if(top==-1){
        printf("the list is underflow!\n");
        return;
    }else{
        printf("%d popped sucessfully\n",stack[top]);
        top--;
    }
}

void peek(){
    if(top==-1){
        printf("the list is empty]\n");
        return;
    }else{
        printf("the peek element is:%d",stack[top]);
    }
}

void display(){
    if(top==-1){
        printf("the list is empty\n");
        return;
    }
    printf("you entered the list is:\n");
    for(int i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
}

int main(){
    int choice;
    do{
        printf("\n___MENU___\n");
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.peek\n");
        printf("4.display\n");
        printf("5.EXist\n");
        printf("enter which choise do u want to select:");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
            break;
            case 5:
            printf("Existing");
            break;
            default:
            printf("invalid character\n");
        
        }
    }while(choice!=5);
    return 0;
}

