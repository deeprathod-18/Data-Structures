#include <stdio.h>
#include <conio.h>
#define MAX_SIZE 10

int top = -1, stack[MAX_SIZE];

void push (int a){
    if(top == MAX_SIZE - 1){
        printf("Stack is full\n");
    }
    else{
        ++top;
        stack[top] = a;
        printf("%d is pushed\n", a);
    }
}

int pop(){
    int x;
    if(top == -1){
        return -1;
    }
    else{
        x = stack[top];
        top--;
        return x;
    }
}

void TOP(){
    if(top == -1){
        printf("stack is empty\n");
    }
    else{
        printf("%d is at the top\n", stack[top]);
    }
}

void display(){
    int i;
    if(top == -1){
        printf("stack is empty\n");
    }
    else{
        for(i = top; i >= 0; i--){
            printf("%d\n", stack[i]);
        }
    }
}

void main(){
    int choice, x;
    do{
        printf("1.Push\n2.Pop\n3.Top\n4.Display\n5.Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1 : printf("Enter the number to be pushed: ");
                     scanf("%d", &x);
                     push(x);
                     break;
            case 2 : x = pop();
                     if(x == -1){
                        printf("stack is empty\n");
                     }
                     else{
                        printf("%d is popped\n", x);
                     }
                     break;
            case 3 : TOP();
                     break;
            case 4 : display();
                     break;
            case 5 : break;
            default : printf("Invalid input\n");
        }
    }while(choice != 5);
    getch();
    //clrscr();
}