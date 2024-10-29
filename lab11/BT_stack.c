#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void iterativePreorder(struct Node* root) {
    if (root == NULL) return;
    
    struct Node* stack[100];
    int top = -1;
    
    stack[++top] = root;
    
    while (top != -1) {
        struct Node* node = stack[top--];
        printf("%d ", node->data);
        
        if (node->right) stack[++top] = node->right;
        if (node->left) stack[++top] = node->left;
    }
}

void iterativeInorder(struct Node* root) {
    if (root == NULL) return;
    
    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;
    
    while (top != -1 || current != NULL) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

void iterativePostorder(struct Node* root) {
    if (root == NULL) return;
    
    struct Node* stack[100];
    int top = -1;
    struct Node* lastVisited = NULL;
    
    while (top != -1 || root != NULL) {
        while (root != NULL) {
            stack[++top] = root;
            root = root->left;
        }
        
        root = stack[top];
        if (root->right == NULL || root->right == lastVisited) {
            printf("%d ", root->data);
            lastVisited = stack[top--];
            root = NULL;
        } else {
            root = root->right;
        }
    }
}

void levelOrder(struct Node* root) {
    if (root == NULL) return;
    
    struct Node* queue[100];
    int front = 0, rear = 0;
    
    queue[rear++] = root;
    
    while (front < rear) {
        struct Node* node = queue[front++];
        printf("%d ", node->data);
        
        if (node->left) queue[rear++] = node->left;
        if (node->right) queue[rear++] = node->right;
    }
}

int main() {

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Preorder Traversal: ");
    iterativePreorder(root);
    printf("\n");

    printf("Inorder Traversal: ");
    iterativeInorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    iterativePostorder(root);
    printf("\n");

    printf("Level-order Traversal: ");
    levelOrder(root);
    printf("\n");

    return 0;
}
