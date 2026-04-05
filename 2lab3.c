#include <stdio.h>
#define MAX 50
int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(){
    if(rear==MAX-1){
        printf("the list is full\n");
        return;
    }else{
        int value;
        printf("enter the value:");
        scanf("%d",&value);
        if(front==-1){
            front=0;
        }
        rear++;
        queue[rear]=value;
        printf("%d value is succesfully pushed\n",value);
    }
}

void dequeue(){
    if(rear==-1 || front>rear){
        printf("the list is empty\n");
        return;
    }
    printf("%d value is poped\n",queue[front]);
    front++;
}

void peek(){
    if(front==-1 || front>rear){
        printf("the list is empty\n");
        return;
    }
    printf("%d value is the peek element\n",queue[front]);
}

void display(){
    if(front==-1 || rear<front){
        printf("thelist is empty\n");
        return;
    }
    printf("you entered the list is:\n");
    for(int i=front;i<=rear;i++){
        printf("%d\n",queue[i]);
    }
}

int main(){
    int choice;
    do{
        printf("\n___MENU___\n");
        printf("1.enqueue\n");
        printf("2.dequeue\n");
        printf("3.peek\n");
        printf("4.display\n");
        printf("5,exit\n");
        printf("enter the choice:");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
            break;
            case 5:
            printf("Existing\n");
            break;
            default:
            printf("invalid character\n");
        }
    }while(choice!=5);
    return 0;
}
