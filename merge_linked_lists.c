#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to merge two sorted linked lists
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    struct Node* mergedList = NULL;
    struct Node* current = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            if (mergedList == NULL) {
                mergedList = current = list1;
            } else {
                current->next = list1;
                current = current->next;
            }
            list1 = list1->next;
        } else {
            if (mergedList == NULL) {
                mergedList = current = list2;
            } else {
                current->next = list2;
                current = current->next;
            }
            list2 = list2->next;
        }
    }

    // If one of the lists is not empty, append the remaining elements
    if (list1 != NULL) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    return mergedList;
}

// Function to print a linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create sorted linked lists
    struct Node* list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(5);

    struct Node* list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);

    // Merge and print the sorted linked lists
    struct Node* mergedList = mergeSortedLists(list1, list2);
    printf("Merged Sorted List: ");
    printList(mergedList);

    // Free allocated memory
    free(list1);
    free(list2);
    free(mergedList);

    return 0;
}
