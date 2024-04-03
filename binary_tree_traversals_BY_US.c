// Binary Tree
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure for a binary tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert left child
void insertLeft(Node* parent, int data) {
    if (parent->left != NULL) {
        printf("Left child already exists\n");
        return;
    }
    parent->left = createNode(data);
}

// Function to insert right child
void insertRight(Node* parent, int data) {
    if (parent->right != NULL) {
        printf("Right child already exists\n");
        return;
    }
    parent->right = createNode(data);
}

// Search for a node in the binary tree
int search(Node* root, int data) {
    if (root == NULL) return 0;
    if (root->data == data) return 1;

    int res1 = search(root->left, data);
    if (res1) return 1; // node found, no need to look further

    int res2 = search(root->right, data);
    if(res2) return 1;
}

// In-order traversal of the binary tree
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Pre-order traversal of the binary tree
void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Post-order traversal of the binary tree
void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Main function
int main() {
    Node* root = createNode(1);
    insertLeft(root, 2);
    insertRight(root, 3);
    insertLeft(root->left, 4);
    insertRight(root->left, 5);

    printf("In-order traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Post-order traversal: ");
    postorderTraversal(root);
    printf("\n");

    int num_to_search = 3;
    if (search(root, num_to_search))
        printf("%d is found in the tree\n", num_to_search);
    else
        printf("%d is not found in the tree\n", num_to_search);

    return 0;
}

