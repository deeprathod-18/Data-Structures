#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

char infix[100], prefix[100];
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

void reverseString(char *str){
    int len = strlen(str);
    int i, j;
    char temp;
    for(i = 0, j = len - 1; i < j; i++, j--){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infixtoprefix(){
    int i = 0, j = 0;
    char x;

    strcpy(prefix, infix);
    
    reverseString(prefix);
    
    x = prefix[i];
    while(x != '\0'){
        if(isalpha(x) || isdigit(x)){
            prefix[j++] = x;
        } 
        else if(x == ')'){
            push(x);
        } 
        else if(isOperator(x)){
            while(top != -1 && priority(x) < priority(stack[top])){
                  prefix[j++] = pop();
            }
            push(x);
        } 
        else if(x == '('){
            while(stack[top] != ')'){
                prefix[j++] = pop();
            }
            pop();
        } 
        else{
            printf("\nIncorrect Expression!\n");
        }
        x = prefix[++i];
    }
    while(top != -1){
        prefix[j++] = pop();
    }

    prefix[j] = '\0';

    reverseString(prefix);
}

int evaluatePrefix(char *prefix){
    top = -1;
    int i, operand1, operand2, result;
    char ch;

    reverseString(prefix);

    for(i = 0; prefix[i] != '\0'; i++){
        ch = prefix[i];
        if(isdigit(ch)){
            push(ch - '0');
        } 
        else if(isOperator(ch)){
            operand1 = pop();
            operand2 = pop();

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
    scanf("%s", infix);
    
    printf("\nInfix Statement: %s\n", infix);
    
    infixtoprefix();
    printf("\nPrefix Statement: %s\n", prefix);

    int result = evaluatePrefix(prefix);
    printf("\nResult of evaluation: %d\n", result);
    return 0;
}