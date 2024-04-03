#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct node* inorderpredecessor(struct node* root) {
    root = root->left;
    while(root->right != NULL) {
        root = root->right;
    }
    return root;
}

struct node *createnode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
}

struct node *deletenode(struct node *root, int value)
{
    struct node* ipre;
    if(root == NULL) {
        return NULL;
    }
    if(root->left == NULL && root->right == NULL) {
        free(root);
        return NULL; //free memory of leaf node
    }
    // search for the node to be deleted

    if (value < root->data)
    {
        root->left = deletenode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deletenode(root->right, value);
    }

    // delete strategy: when the node is found
    else{
        ipre = inorderpredecessor(root);
        root->data = ipre->data;
        root->left = deletenode(root->left, ipre->data);
    }
    return root;
}

int main()
{
    struct node *p = createnode(8);
    struct node *p1 = createnode(3);
    struct node *p2 = createnode(10);
    struct node *p3 = createnode(1);
    struct node *p4 = createnode(6);
    struct node *p5 = createnode(14);
    struct node *p6 = createnode(4);
    struct node *p7 = createnode(7);
    struct node *p8 = createnode(13);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;
    p5->left = p8;
    p4->left = p6;
    p4->right = p7;

    inorder(p);
    deletenode(p,8);
    printf("\n");
    inorder(p);

}