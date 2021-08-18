#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* link;
};

//Function to insert the Parenthesis in the stack
void Push(struct Node** top, int new_data){

    //Creates a new node to insert in the stack 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    if(top == NULL){
        printf("Stack Overflow\n");
        getchar();
        exit(0);
    }
    new_node -> data = new_data;
    new_node -> link = (*top);
    (*top) = new_node;
}

// Function to remove the closing the Parenthesis
int Pop(struct Node** top){

    char res;
    struct Node* top_data;

    if (top == NULL){
        printf("Stack Overflow\n");
        getchar();
        exit(0);
    }
    else{
        top_data = *top;
        res = top_data -> data;
        *top = top_data-> link;
        free(top_data);
        return res;
    }
}

// Function to check if the Pairs of Parenthesis are of same type
int Pairs(char bracket1, char bracket2){
    if(bracket1 == '(' && bracket2==')')
    return 1;
    else if(bracket1 == '{' && bracket2=='}')
    return 1;
    else if(bracket1 == '[' && bracket2==']')
    return 1;
    else
    return 0;
}

//Function to check if the whole string has balanced parenthesis
int BalancedParenthesis(char str[]){

    int i = 0;
    struct Node* stack = NULL;

    while(str[i]){
        if (str[i] == '{' || str[i] =='(' || str[i] =='['){
            Push(&stack, str[i]);
        }
        if (str[i] == '}' || str[i] == ')' || str[i] == ']'){
            if (stack==NULL){
                return 0;
            }
            else if (!Pairs(Pop(&stack), str[i])){
                return 0;
            }
        }
        i++;
    }

    if (stack==0)
        return 1;
    else
        return 0;
}

int main(){

    char str[100];
    printf("Enter Parenthesis: ");
    scanf("%[^\n]%*c", str);
    if(BalancedParenthesis(str)){
        printf("True");
    }
    else{
        printf("False");
    }
    return 0;
}