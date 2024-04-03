#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void insert(struct node* root, int key) {
    struct node* prev = NULL;
    while(root!=NULL) {
        prev = root;
    if(key == root->data) {
        printf("cannot insert %d, already in BST",key);
        return;
    }
    else if(key < root->data) {
        root = root->left;
    }
    else {
        root = root->right;
    }
    }

    struct node* new = createnode(key);
    if(key < prev->data){
        prev->left = new;
    }
    else{
        prev->right = new;
    }

    

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

    insert(p,7);
    printf("%d", p->right->left->data);
    return 0;

}