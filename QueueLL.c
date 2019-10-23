#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next ;
};
struct node *front, *rear, *temp;;
int count = 0;
int peek();
void enQueue();
void deQueue();
void display();
void empty();
void create();
void QueueSize();

void main(){
    int val, ch, e;
    create();
    do{
        printf("\n1. EnQueue");
        printf("\n2. DeQueue");
        printf("\n3. Peek");
        printf("\n4. Empty");
        printf("\n5. Exit");
        printf("\n6. Display");
        printf("\n7. QueueSize");
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enQueue(val);
                break;
            case 2:
                deQueue();
                break;
            case 3:
            
                val = peek();
                if(val!=0){
                    printf("\nFront element is %d", val);
                }
                else{
                    printf("\nQueue is empty");
                }
            
                break;
            case 4:
                empty();
                break;
            case 5:
                exit(0);
            case 6:
                display();
                break;
            case 7:
                QueueSize();
                break;
            default:
                printf("\nInvalid choice");
                break;
        }
    }while(ch!=5);
}

//Creating an empty queue
void create()
{
    front = NULL;
    rear = NULL;
}
void QueueSize(){
    printf("\nQueue Size is %d", count);
}

void enQueue(int data){
    if(rear==NULL){
        rear= (struct node *)malloc(sizeof(struct node));
        rear->next = NULL;
        rear->data = data;
        front = rear;
    }
    else{
        temp = (struct node *)malloc(sizeof(struct node));
        rear->next = temp;
        temp->data = data;
        temp->next = NULL;
        rear = temp;
    }
    count++;  
}

void display(){
    temp = front;
    if(front==NULL){
        printf("Queue is empty");
        return;
    }
    printf("\nThe elements in the queue are\n");
    while(temp!=rear){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    if(temp==rear)
    {
        printf("%d\n", rear->data);
    }
}

void deQueue(){
    temp = front;
    if(temp==NULL){
        printf("\nQueue is empty");
        return;
    }
    else{
        if(temp->next!=NULL){
            temp = temp->next;
            printf("\nDeleted value: %d", front->data);
            free(front);
            front = temp;
        }
        else{
            printf("\nDeleted value: %d", front->data);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
    }
}
/*
int peek()
{
    if ((front != NULL) && (rear != NULL))
        return(front->info);
    else
        return 0;
}

void empty()
{
     if ((front == NULL) && (rear == NULL))
        printf("\n Queue empty");
    else
       printf("Queue not empty");
}
*/