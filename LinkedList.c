#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * next;
}NODE;
NODE * front = NULL;
NODE * rear = NULL;
void printList(NODE * front);
NODE * push(NODE * front, NODE * rear, int data); // adds a new node in the beginning 
NODE * insertAfter(NODE * front,NODE * rear, int data, int value);   //inserts a new node after a node
void append(NODE * front,NODE * rear, int data);  //inserts a new node at the end of LL
void deleteNode(NODE * front, NODE * rear, int value); //deletes a node
void pop(NODE * front, NODE * rear); //deletes the node at the end

int main(){
    int ch, data, value;
    do{
        printf("\n***MENU***\n");
        printf("\n1. Push");
        printf("\n2. Insert after a node");
        printf("\n3. Append");
        printf("\n4. Delete a node");
        printf("\n5. Pop");
        printf("\n6. Display linked list");
        printf("\n7. Peek");
        printf("\n8. Exit");
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter value to be pushed: ");
                scanf("%d", &data);
                front = push(front,rear,data);
                break;
            case 2:
                printf("\nEnter value to be inserted: ");
                scanf("%d", &data);
                printf("\nEnter Value of previous node: ");
                scanf("%d", &value);
                front = insertAfter(front,data,value);
                break;
            case 6:
                printList(front);
                break;
        }
    }while(ch!=8);
}
NODE * push(NODE * front, NODE * rear, int data){
    NODE * newnode = malloc(sizeof(NODE));
    newnode->data = data;
    newnode->next = NULL;
    if(front==NULL){
        front = newnode;
        rear = newnode;
        return front;
    }
    else{
        newnode->next = front;
        front = newnode;
        return front;
    }
}
NODE * insertAfter(NODE * front,NODE * rear ,int data, int value){

    if(front==NULL){
        printf("\nValue not found");
        return front;
    }
    else{
        NODE * temp = front;
        if(temp->next==NULL && temp->data == value){
            NODE * newnode = malloc(sizeof(NODE));
            newnode->data = data;
            newnode->next = NULL;
            rear = newnode;
            front->next = newnode;
            return front;
        }
        while(temp->data!=value && temp!=NULL){
            temp = temp->next;
        }
        if(temp==NULL){
            printf("\nValue not found");
        }

    }









}
void printList(NODE * front){
    NODE * temp;
    temp = front;
    if(front == NULL){
        printf("\nList is empty!");
    }
    else{
        printf("\nThe elements in the list are\n");
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n\n");
    }   
}


