#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct Node* inOrderSuccessor(struct Node* root, struct Node* n) {
    if (n->right != NULL) {
        return findMin(n->right);
    }

    struct Node* successor = NULL;
    while (root != NULL) {
        if (n->data < root->data) {
            successor = root;  
            root = root->left;
        } else if (n->data > root->data) {
            root = root->right;
        } else {
            break;
        }
    }
    return successor;
}

void printNode(struct Node* node) {
    if (node != NULL) {
        printf("In-order Successor: %d\n", node->data);
    } else {
        printf("No in-order successor found.\n");
    }
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);
    insert(root, 25);
    insert(root, 35);

    struct Node* target = root->left->right; 
    struct Node* successor = inOrderSuccessor(root, target);

    printNode(successor);

    return 0;
}
