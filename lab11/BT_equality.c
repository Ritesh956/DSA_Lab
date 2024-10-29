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

struct Node* copyTree(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }
    struct Node* newRoot = createNode(root->data);
    newRoot->left = copyTree(root->left);
    newRoot->right = copyTree(root->right);
    return newRoot;
}

int areEqual(struct Node* root1, struct Node* root2) {

    if (root1 == NULL && root2 == NULL) {
        return 1;
    }

    if (root1 == NULL || root2 == NULL) {
        return 0;
    }
 
    return (root1->data == root2->data) &&
           areEqual(root1->left, root2->left) &&
           areEqual(root1->right, root2->right);
}

void printInOrder(struct Node* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%d ", root->data);
        printInOrder(root->right);
    }
}

int main() {

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Original tree (In-order): ");
    printInOrder(root);
    printf("\n");

    struct Node* copiedTree = copyTree(root);

    printf("Copied tree (In-order): ");
    printInOrder(copiedTree);
    printf("\n");

    if (areEqual(root, copiedTree)) {
        printf("The original tree and the copied tree are equal.\n");
    } else {
        printf("The original tree and the copied tree are not equal.\n");
    }

    return 0;
}
