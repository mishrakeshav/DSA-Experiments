#include<stdio.h>
#define Max 100
int queue[Max];
int f = -1, r = -1;

void insert(){
    int val;
    printf("Enter value to insert: \n");
    scanf("%d", &val);
    if(r == Max-1){
        printf("\nOverload");
    }
    else if(r==-1 && f==-1){
        f=0;
        r=0;
        queue[r]=val;
    }
    else{
        r++;
        queue[r]=val;
    }
}

int delete(){
    if(f==-1 || f > r){
        printf("\nUnderflow");
        return -1;
    }
    else{
        int val = queue[f];
        f++;
        if(f>r){
            f =r = -1;
            
        }
        return val;
    }
    
}
int peek(){
    if(f==-1 || f>r){
        printf("\nQueue is empty");
        return -1;
    }
    else{
        return queue[f];
    }
}
void display(){
    int i;
    if(f==-1 || f>r){
        printf("\nQueue is empty");
    }
    else{
        printf("\n");
        for(i=f; i<=r; i++){
            printf("%d\n", queue[i]);
        }
    }
}
int main(){
    int ch, val;
    do{
        printf("\n***Main Menu***");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit\n");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                insert();
                break;
            case 2:
                val = delete();
                if(val!=-1){
                    printf("The number deleted is %d", val);
                }
                break;
            case 3:
                val = peek();
                if(val!=-1){
                    printf("The first value in the queue is %d", val);
                }
                break;
            case 4:
                display();
                break;
            
        }
    }while(ch!=5);

    return 0;
}