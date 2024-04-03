// BST
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure for the binary search tree
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

// Insert a new node in the binary search tree
Node* insert(Node* node, int data) {
    if (node == NULL) return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}


// Find the minimum value node
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Delete a node from the binary search tree
Node* deleteNode(Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Search for a node in the binary tree
int search(Node* root, int data) {
    if (root == NULL) return 0;
    if (root->data == data) return 1;
    if (root->data < data) return search(root->right, data);
    return search(root->left, data);
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
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("In-order traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Post-order traversal: ");
    postorderTraversal(root);
    printf("\n");

    printf("Deleting 20\n");
    root = deleteNode(root, 20);
    printf("In-order traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

    int num_to_search = 40;
    if (search(root, num_to_search))
        printf("%d is found in the tree\n", num_to_search);
    else
        printf("%d is not found in the tree\n", num_to_search);

    return 0;
}

