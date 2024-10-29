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

struct Node* constructTree(int* preOrder, int* postOrder, int* preIndex, int leftIndex, int rightIndex, int size) {

    if (*preIndex >= size || leftIndex > rightIndex) {
        return NULL;
    }

    struct Node* root = createNode(preOrder[*preIndex]);
    (*preIndex)++;

    if (leftIndex == rightIndex) {
        return root;
    }

    int nextNodeIndex = -1;
    for (int i = leftIndex; i <= rightIndex; i++) {
        if (postOrder[i] == preOrder[*preIndex]) {
            nextNodeIndex = i;
            break;
        }
    }

    if (nextNodeIndex != -1) {
        root->left = constructTree(preOrder, postOrder, preIndex, leftIndex, nextNodeIndex, size);
        root->right = constructTree(preOrder, postOrder, preIndex, nextNodeIndex + 1, rightIndex - 1, size);
    }

    return root;
}

void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    int preOrder[] = {1, 2, 4, 5, 3, 6, 7};
    int postOrder[] = {4, 5, 2, 6, 7, 3, 1};
    int size = sizeof(preOrder) / sizeof(preOrder[0]);

    int preIndex = 0;

    struct Node* root = constructTree(preOrder, postOrder, &preIndex, 0, size - 1, size);

    printf("In-order Traversal of the constructed tree: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
