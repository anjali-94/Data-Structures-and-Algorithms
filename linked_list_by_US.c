#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;


//function to create a node
Node* createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//insert at the beginning of a list
void insertAtBeginning(Node **head,int data) {
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;

}

//insert at the end of the list
void insertAtEnd(Node **head,int data) {
    Node *newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node *last = *head;
    while(last->next!= NULL)
    {
        last = last->next;
    }
    last->next = newNode;
}

//insert after a specific node
void insertAfterNOde(Node* prevNode, int data) {
    if (prevNode == NULL)
    {
        printf("Previous node cannot be NULL\n");
        return;
    }
    Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

//Delete a node by value
void deleteNodeByValue(Node **head, int key){
    Node *temp = *head;
    Node *prev = NULL;
    //if the node to be deleted as per the value of the node is the head node
    if(temp!= NULL && temp->data == key){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!=key){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        return;
    }
    else{
    prev->next = temp->next;
    free(temp);
    }
}

//Delete a Node by position
void deleteNodeByPosition(Node **head, int position) {
    if(*head == NULL) {
        return;
    }

    Node* temp = *head;
    if(position ==0) {
        *head = temp->next;
        free(temp);
        return;
    }

    for(int i = 0;temp!=NULL && i<position-1;i++){
        temp = temp->next;
    }
    if(temp == NULL || temp->next == NULL)
    return;

    Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}



//Delete a node from the beginning of the list
void deleteAtBeginning(Node **head) {
    Node *temp = *head;
    *head = temp->next;
    free(temp);

}


//Delete a node from the end of the list
void deleteAtEnd(Node **head) {
    Node *temp = *head;
    Node *prev = NULL;
    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);

}


//search the key int the linked list
int search(Node *head, int key){
    Node *current = head;
    while(current!=NULL) {
        if(current->data == key)
        return 1;
        current = current->next;
    }
    return 0;
}


//print linked list
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ->", node->data);
        node = node->next;
    }
    printf("NULL\n");
}


int main()
{

    Node * head = NULL;
    insertAtEnd(&head, 1);
    insertAtBeginning(&head,2);
    insertAtBeginning(&head,3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 9);
    insertAfterNOde(head->next, 5);
    

    printf("Create Linked List: ");
    printList(head);

    deleteNodeByValue(&head,4);
    printf("Linked List after deleting 4: ");
    printList(head);

    deleteAtEnd(&head);
    printf("Linked List after deleting a node from end: ");
    printList(head);

     deleteAtBeginning(&head);
     printf("Linked List after deleting a node from beginning: ");
     printList(head);

     deleteNodeByPosition(&head, 2);
     printf("Linked List after deleting position 2: ");
     printList(head);

     int item_to_find = 7;
     if(search(head,item_to_find))
     printf("%d is in the list\n", item_to_find);
     else
    printf("%d is not in the list\n", item_to_find);

    return 0;

}