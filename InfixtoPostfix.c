#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int top;
int stack[100];
char infix_str[100], postfix_str[100];

int pop();
int precedence(char symbol);
int isEmpty();
void infix_to_postfix();
void push(int symbol);

void infixtopostfix(){
    int count = 0, temp = 0;
    char next;
    for(count = 0; count < strlen(infix_str); count++){
        switch(infix_str[count]){

            case '(':
            push(infix_str[count]);
            break;

            case ')':
            while((next = pop()) != '(')
            {
                postfix_str[temp++] = next;
            }
            break;

            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
            while(!isEmpty() && precedence(stack[top]) >= precedence(infix_str[count]))
            postfix_str[temp++] = pop();
            push(infix_str[count]);
            break;

            default:
            postfix_str[temp++] = infix_str[count];
        }
    }
    while(!isEmpty){
        postfix_str[temp++] = pop();
    }
    postfix_str[temp] = '\0';
}

//Function to check precedence of operators
int precedence(char symbol){
    switch(symbol){
        case '(':
        return 0;

        case '+':
        case '-':
        return 1;

        case '*':
        case '/':
        case '%':
        return 2;

        case '^':
        return 3;

        default:
        return 0;
    }
}

//Function to add element to the stack
void push(int symbol){
    if (top > 100){
        printf("Stack Overflow\n");
        getchar();
        exit(1);
    }
    top = top + 1;
    stack[top] = symbol;
}

//Funciton to check if stack is empty
int isEmpty()
{
if(top == -1)
{
return 1;
}
else
{
return 0;
}
}

//Function to remove element form stack
int pop()
{
if(isEmpty())
{
printf("Stack is Empty\n");
exit(1);
}
return(stack[top--]);  
}

int main(){
    top = -1;
    printf("Enter Arithmetic Expression: ");
    scanf("%[^\n]%*c", infix_str);
    infixtopostfix();
    printf("%s", postfix_str);
    return 0;
}