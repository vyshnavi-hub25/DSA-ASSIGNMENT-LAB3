#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *top=NULL;
void push(){
    struct node *newnode=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    int value;
    printf("enter the value:");
    scanf("%d",&value);
    newnode->data=value;
    newnode->next=top;
    top=newnode;
    printf("%d value is inserted succesfully",value);
}
void pop(){
    struct node *temp=NULL;
    if(top==NULL){
        printf("the list is empty\n");
        return;
    }
    temp=top;
    top=top->next;
    printf("%d value is deleted successfully\n",temp->data);
    free(temp);
}

void peek(){
    struct node *temp=NULL;
    if(top==NULL){
        printf("the list is empty\n");
        return;
    }else{
        temp=top;
        printf("%d is the peek value of the list",temp->data);
    }
}
void display(){
    struct node *temp=NULL;
    if(top==NULL){
        printf("the list is empty\n");
        return;
    }else{
        temp=top;
        while(temp!=NULL){
            printf("%d\n",temp->data);
            temp=temp->next;
        }
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
        printf("5.Exist\n");
        printf("enter the choice:");
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
            printf("EXISTING");
            break;
            default:
            printf("invalid character");
        }
    }while(choice!=5);
    return 0;
}
