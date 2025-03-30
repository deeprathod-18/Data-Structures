#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
} *head, *newNode;

void insert_start(){
    int value;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter the element to be inserted at the start: ");
    scanf("%d", &value);
    newNode -> data = value;
    newNode -> next = head;
    head = newNode;
    printf("Inserted!\n");
}

void insert_end(){
    int value;
    struct Node *temp;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter the element to be inserted at the end: ");
    scanf("%d", &value);
    newNode -> data = value;
    newNode -> next = NULL;
    temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
    printf("Inserted!\n");
}

void create(){
    if(head == NULL){
        insert_start();
    }
    else{
        insert_end();
    }
}

void insert_between(){
    int value, position;
    int i = 1;
    struct Node *temp;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter the element to be inserted in between: ");
    scanf("%d", &value);
    printf("Enter the position at which it has to be inserted: ");
    scanf("%d", &position);
    temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
        i++;
    }
    if(position > 1 && position <= i + 1){
        temp = head;
        i = 0;
        while(i != position - 2){
            temp = temp -> next;
            i++;
        }
        newNode -> data = value;
        newNode -> next = temp -> next;
        temp -> next = newNode;
        printf("Inserted!\n");
    }
    else{
        printf("\nInvalid position to insert at!\n");
    }
}

void delete(){
    int value;
    struct Node *temp, *pretemp;
    printf("Enter the value to be deleted: ");
    scanf("%d", &value);
    if(head -> data == value){
        temp = head;
        head = temp -> next;
        free(temp);
        printf("Deleted!\n");
    }
    else{
        pretemp = head;
        temp = head -> next;
        while(temp != NULL && temp -> data != value){
            pretemp = pretemp -> next;
            temp = temp -> next;
        }
        if(temp == NULL){
            printf("\nValue not found\n");
        }
        else if(temp -> next == NULL){
            pretemp -> next = NULL;
            free(temp);
            printf("Deleted!\n");
        }
        else{
            pretemp -> next = temp -> next;
            free(temp);
            printf("Deleted!\n");
        }
    }
}

void display(){
    struct Node *temp;
    temp = head;
    printf("\nThe elements in the Linked List are :-\n");
    while(temp != NULL){
        printf("%d - ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

int main(){
    int len;
    int i = 0;
    printf("Enter the length of the Linked List: ");
    scanf("%d", &len);
    while(i < len){
        create();
        i++;
    }
    display();
    
    int choice;
    while(choice != 6){
        printf("\n1.Insert at Start\n2.Insert at End\n3.Insert in Between\n4.Delete\n5.Display\n6.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1 : insert_start();
                     break;
            case 2 : insert_end();
                     break;
            case 3 : insert_between();
                     break;
            case 4 : delete();
                     break;
            case 5 : display();
                     break;
            case 6 : printf("\nDo Visit Again!");
                     break;
            default : printf("\nInvalid choice!\n");
        }
    }

    return 0;
}