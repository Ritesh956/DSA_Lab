#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int evaluate(struct Node* root) {
    if (root == NULL) return 0;

    if (!isOperator(root->data)) {
        return root->data - '0'; 
    }

    int leftValue = evaluate(root->left);
    int rightValue = evaluate(root->right);

    switch (root->data) {
        case '+': return leftValue + rightValue;
        case '-': return leftValue - rightValue;
        case '*': return leftValue * rightValue;
        case '/': return leftValue / rightValue;
    }
    return 0;
}

struct Node* constructTree(char* postfix) {
    struct Node* stack[100]; 
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i])) {
            stack[++top] = createNode(postfix[i]);
        } else if (isOperator(postfix[i])) {
            struct Node* node = createNode(postfix[i]);
            node->right = stack[top--];
            node->left = stack[top--];
            stack[++top] = node;
        }
    }
    return stack[top];
}

int main() {
    char postfix[] = "23*54*+9-"; 

    struct Node* root = constructTree(postfix);

    int result = evaluate(root);

    printf("The result of the expression is: %d\n", result);

    return 0;
}
