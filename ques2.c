#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
}*head = NULL;


//New node creation
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
//Insert first
void insertFirst(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}


//Insert last
void insertLast(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

//Insert into k-th position
void insertAt(int data, int position) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    if (position == 1) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }
    struct Node* current = head;
    int i = 1;
    while (i < position - 1 && current->next != NULL) {
        current = current->next;
        i++;
    }
    if (current->next == NULL) {
        current->next = newNode;
        newNode->prev = current;
        return;
    }
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
}

//Insert into the second last position
void insertSecondLast(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    if (head->next == NULL) {
        head->next = newNode;
        newNode->prev = head;
        return;
    }
    struct Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
}

//Find the maximum element
void findMax() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    int max = current->data;
    while (current != NULL) {
        if (current->data > max) {
            max = current->data;
        }
        current = current->next;
    }
    printf("Maximum element: %d\n", max);
}

//Delete all the odd elements from the LL
void deleteOdd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    while (current != NULL) {
        if (current->data % 2 != 0) {
            if (current == head) {
                head = head->next;
                free(current);
                current = head;
            } else {
                current->prev->next = current->next;
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
                struct Node* temp = current;
                current = current->next;
                free(temp);
            }
        } else {
            current = current->next;
        }
    }
}
//Search all occurrences of a specific element
void searchAll(int item) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    int count = 0;
    while (current != NULL) {
        if (current->data == item) {
            count++;
        }
        current = current->next;
    }
    if (count == 0) {
        printf("Element not found.\n");
    } else {
        printf("Element found %d times.\n", count);
    }
}

void printList() {
    struct Node* current = head;
    printf("Doubly linked list (forward): ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


//Main function
int main() {
    int option, data, position, item;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert First\n");
        printf("2. Insert Last\n");
        printf("3. Insert At kth position\n"); 
        printf("4. Insert into the second last position\n");
        printf("5. Find the maximum\n");
        printf("6. Delete all the odd elements from the LL\n");
        printf("7. Search all occurrences of a specific element\n");
        printf("8. Print the list\n");
        printf("9. Quit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertFirst(data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertLast(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAt(data, position);
                break;
            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertSecondLast(data);
                break;
            case 5:
                findMax();
                break;
            case 6:
                deleteOdd();
                break;
            case 7:
                printf("Enter the item to search: ");
                scanf("%d", &item);
                searchAll(item);
                break;
                
            case 8:
                printList();
                break;
            case 9:
                // Clean up memory
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid option. Please select a valid option.\n");
        }
    }
}

