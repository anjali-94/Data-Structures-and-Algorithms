#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

//function to create a node
struct Node* createnode(int data)
{
    struct Node *n;
    n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    return n;
}

// Insert a node in the beginning
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// Insert a node in between
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Insert a node at the end
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Insert a node after a node
struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;

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
    fourth->next = NULL;

    printf("Linked list before insertion\n");
    linkedlistTraversal(head);

    head = insertAtFirst(head, 56);
    printf("Linked list After insertion in beginning\n");
    linkedlistTraversal(head);

    head = insertAtIndex(head, 12, 1);
    printf("Linked list After insertion in between\n");
    linkedlistTraversal(head);

    head = insertAtEnd(head, 33);
    printf("Linked list After insertion at the end\n");
    linkedlistTraversal(head);

    head = insertAfterNode(head, second, 18);
    printf("Insertion After node\n");
    linkedlistTraversal(head);

    return 0;
}