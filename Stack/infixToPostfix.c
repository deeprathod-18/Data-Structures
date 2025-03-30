#include <stdio.h>
#include <ctype.h>
#include <math.h>

char infix[100], postfix[100];
int top = -1;
int stack[100];

void push(int val){
    if(top == 99){
        printf("\nStack Overflow!\n");
    } 
    else{
        stack[++top] = val;
    }
}

int pop(){
    if(top == -1){
        return -1; 
    } 
    else{
        return stack[top--];
    }
}

int isOperator(char ch){
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%');
}

int priority(char a){
    if(a == '^' || a == '%') {
        return 3;
    }
    else if(a == '/' || a == '*') {
        return 2;
    }
    else if(a == '+' || a == '-') {
        return 1;
    }
    else{
        return -1;
    }
}

void infixtopost(){
    int i = 0, j = 0;
    char x;

    x = infix[i];
    while (x != '\0'){
        if(isalpha(x) || isdigit(x)){
            postfix[j++] = x;
        } 
        else if(x == '('){
            push(x);
        } 
        else if(isOperator(x)){
            while(top != -1 && priority(x) <= priority(stack[top])){
                  postfix[j++] = pop();
            }
            push(x);
        } 
        else if(x == ')'){
            while(stack[top] != '('){
                postfix[j++] = pop();
            }
            pop();
        } 
        else{
            printf("\nIncorrect Expression!\n");
        }
        x = infix[++i];
    }
    while(top != -1){
        postfix[j++] = pop();
    }
}

int evaluatePostfix(char *postfix){
    top = -1;
    int i, operand1, operand2, result;
    char ch;

    for(i = 0; postfix[i] != '\0'; i++){
        ch = postfix[i];
        if(isdigit(ch)){
            push(ch - '0');
        } 
        else if(isOperator(ch)){
            operand2 = pop();
            operand1 = pop();

            switch (ch){
                case '%':
                    result = operand1 % operand2;
                    break;
                case '^':
                    result = pow(operand1, operand2);
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
            }
            push(result);
        }
        else{
            printf("\nInvalid Input!\n");
        }
    }
    return pop();
}

int main(){
    printf("Enter the infix expression: ");
    scanf("%s", &infix);
    printf("\nInfix Statement: %s\n", infix);
    infixtopost();
    printf("\nPostfix Statement: %s\n", postfix);
    int result = evaluatePostfix(postfix);
    printf("\nResult of evaluation: %d\n", result);
    return 0;
}