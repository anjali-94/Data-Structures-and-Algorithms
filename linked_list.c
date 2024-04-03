#include<stdio.h>
#include<stdlib.h> 

struct Node
{
    int data;
    struct Node *next;

};

void linkedlistTraversal(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    //allocate memory for nodes in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third= (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    //link first and second node
    head->data = 7;
    head->next = second;

    //link first and second node
    second->data = 17;
    second->next = third;

    //link first and second node
    third->data = 77;
    third->next = fourth;

    //link first and second node
    fourth->data = 27;
    fourth->next = NULL;

    linkedlistTraversal(head);

    return 0;

}