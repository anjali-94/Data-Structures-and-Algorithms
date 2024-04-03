//preorder - root -> left_node -> right_node
//postorder - left_node -> right_node ->  root
//inorder - left_node -> root -> right_node

#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;

};

struct node* createNode(int data) {
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));
    n->left = NULL;
    n->right = NULL;
    n->data = data;
    return n;

}

void preorder(struct node *root) {
    if(root!=NULL) {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root) {
    if(root!=NULL) {
        postorder(root->left);
        postorder(root->right);  //postorder - left_node -> right_node ->  root // 5 2 1 6 4
        printf("%d ",root->data);
    }
} 

void inorder(struct node *root) {
    if(root!=NULL) {
        inorder(root->left);
        printf("%d ",root->data); 
        inorder(root->right);
    }
}

void insert(struct node *root, int data) {
    if(root->left!=NULL) {
        printf("ROOT EXISTS ALREADY");
    }
    else
    root->left = createNode(data);

}

int main() {
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);

    //        4
    //       / \
    //      1   6
    //     / \    
    //    5   2
    //
    
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    preorder(p);
    printf("\n");
    postorder(p);
    printf("\n");
    inorder(p);
    //insert(p,7);

    return 0;

}