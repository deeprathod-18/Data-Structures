#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
} *head, *newNode;

void create(){
    newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp;
    int value;
    
    printf("Enter the value to be put in the node: ");
    scanf("%d", &value);
    newNode -> data = value;

    if(head == NULL){
        head = newNode;
        newNode -> next = head;
    }
    else{
        temp = head;
        while(temp -> next != head){
            temp = temp -> next;
        }
        newNode -> next = head;
        temp -> next = newNode;
    }
}

void insert_start(){
    newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp;
    int value;

    printf("\nEnter the value to be inserted at the start: ");
    scanf("%d", &value);
    newNode -> data = value;
    newNode -> next = head;

    temp = head;
    while(temp -> next != head){
        temp = temp -> next;
    }
    temp -> next = newNode;
    head = newNode;
    printf("Inserted!\n");
}

void insert_end(){
    newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp;
    int value;

    printf("\nEnter the value to be inserted at the end: ");
    scanf("%d", &value);
    newNode -> data = value;
    newNode -> next = head;

    temp = head;
    while(temp -> next != head){
        temp = temp -> next;
    }
    temp -> next = newNode;
    printf("Inserted!\n");
}

void insert_between(){
    newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp;
    int value, position, i = 1;

    printf("\nEnter the value to be inserted in between: ");
    scanf("%d", &value);
    printf("Enter the position at which it has to be inserted: ");
    scanf("%d", &position);

    temp = head;
    while(temp -> next != head){
        temp = temp -> next;
        i++;
    }

    if(position > 1 && position <= i + 1){
        newNode -> data = value;
        temp = head;
        for(i = 0; i < position - 2; i++){
            temp = temp -> next;
        }
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
    temp = head -> next;
    pretemp = head;

    printf("\nEnter the value to be deleted: ");
    scanf("%d", &value);

    while(temp -> data != value && temp != head){
        temp = temp -> next;
        pretemp = pretemp -> next;
    }
    if(temp == head && head -> data != value){
        printf("\nVaue not found!\n");
    }
    else{
        pretemp -> next = temp -> next;
        if(temp == head){
            head = pretemp -> next;
        }
        free(temp);
        printf("Deleted!\n");
    }
}

void display(){
    struct Node *temp;
    temp = head;
    printf("\nThe elements in the Linked list are :-\n");
    do{
        printf("%d  ", temp -> data);
        temp = temp -> next;
    } while(temp != head);
    printf("\n");
}

int main(){
    int len, i = 0, choice;
    printf("Enter the length of the Linked list: ");
    scanf("%d", &len);
    printf("\n");
    while(i < len){
        create();
        i++;
    }
    display();
    
    do{
        printf("\n1. Insert at Start\n2. Insert at End\n3. Insert in Between\n4. Delete\n5. Display\n6. Exit\n");
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
    } while (choice != 6);

    return 0;
}