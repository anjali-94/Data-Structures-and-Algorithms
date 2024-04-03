#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

// insert at first node in circular linked list
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *p;

    // allocate memory for nodes in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    p = (struct Node *)malloc(sizeof(struct Node));

    // link first and second node
    head->data = 7;
    head->next = second;

    // link first and second node
    second->data = 17;
    second->next = third;

    // link first and second node
    third->data = 77;
    third->next = fourth;

    // link first and second node
    fourth->data = 27;
    fourth->next = head;

    printf("Circular Linked list before insertion\n");
    linkedlistTraversal(head);

    head = insertAtFirst(head, 80);
    printf("Circular Linked list after insertion\n");
    linkedlistTraversal(head);

    return 0;
}