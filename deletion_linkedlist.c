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

// delete a node in the beginning
struct Node *deleteAtFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// delete a node in between(at a given index)
struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
}

// delete the last node
struct Node *deleteAtEnd(struct Node *head)
{

    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

// delete a node after a node
struct Node *deleteAfterNode(struct Node *head, struct Node *prevNode)
{
    struct Node *q = prevNode->next;
    prevNode->next = q->next;
    free(q);
    return head;
}

// delete a node with a given value
struct Node *deleteByValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    int i = 0;
    while (q->data != value && q != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
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

    printf("Linked list before deleteion: \n");
    linkedlistTraversal(head);

    // head = deleteAtFirst(head);
    // printf("Linked list After deleteion in beginning: \n");
    // linkedlistTraversal(head);

    //  head = deleteAtIndex(head, 1);
    // printf("Linked list After deleteion in between: \n");
    // linkedlistTraversal(head);

    // head = deleteAtEnd(head);
    // printf("Linked list After deleteion at the end\n");
    // linkedlistTraversal(head);

    // head = deleteAfterNode(head, second);
    // printf("deleteion After node\n");
    // linkedlistTraversal(head);

    head = deleteByValue(head, 17);
    printf("deleteion of a given value: \n");
    linkedlistTraversal(head);

    return 0;
}