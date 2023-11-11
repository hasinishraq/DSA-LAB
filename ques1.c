#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
}*head = NULL;

//Creating the node

struct node* createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    } else {
        newNode->data = data;
        newNode->link = NULL;
        return newNode;
    }
}
//insert first

void insertFirst(int data) {
    struct node *newNode = createNode(data);
    newNode->link = head;
    head = newNode;
}

//insert last

void insertLast(int data) {
    struct node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    } else {
        struct node *current = head;
        while (current->link != NULL) {
            current = current->link;
        }
        current->link = newNode;
    }
}
//delete first
void deleteFirst() {
    if (head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return;
    } else {
        struct node *temp = head;
        head = head->link;
        free(temp);
    }
}

//Print the list

void printList() {
    struct node *current = head;
    printf("Linked list: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->link;
    }
    printf("NULL\n");
}

//delete kth element
void deleteAt(int position) {
    if (position < 0) {
        printf("Invalid position.\n");
        return;
    } else if (position == 0 && head != NULL) {
        deleteFirst();
        return;
    } else {
        struct node* current = head;
        struct node* prev = NULL;
        int currentPosition = 0;
        while (current != NULL && currentPosition < position) {
            prev = current;
            current = current->link;
            currentPosition++;
        }
        if (current == NULL) {
            printf("Position exceeds the length of the list. Node not deleted.\n");
        } else {
            prev->link = current->link;
            free(current);
        }
    }
}
//insert mid
void insertMid(int data) {
    struct node *newNode = createNode(data);

    if(head == NULL) {
        insertFirst(data);
        return;
    }
    else if(head->link == NULL) {
        insertLast(data);
        return;
    }
    else{
        struct node *temp = head;
        int count = 0;
        while(temp) {
            count++;
            temp = temp->link;
        }
        int mid = count/2;
        temp = head;
        for(int i = 0; i < mid-1; i++) {
            temp = temp->link;
        }
        newNode->link = temp->link;
        temp->link = newNode;
    }
    }

    //Add all elements of an array at the end of the LL
    void addArray(int arr[], int n) {
        for(int i = 0; i < n; i++) {
            insertLast(arr[i]);
        }
    }
  //Replace the last element of a LL using the sum of the LL
  void replaceLast() {
      struct node *temp = head;
      int sum = 0;
      while(temp) {
          sum += temp->data;
          temp = temp->link;
      }
      temp = head;
      while(temp->link) {
          temp = temp->link;
      }
      temp->data = sum;
  }

  //Search all the even numbers of a LL and put them into an array 
    void searchEven() {
        struct node *temp = head;
        int count = 0;
        while(temp) {
            if(temp->data % 2 == 0) {
                count++;
            }
            temp = temp->link;
        }
        int arr[count];
        temp = head;
        int i = 0;
        while(temp) {
            if(temp->data % 2 == 0) {
                arr[i] = temp->data;
                i++;
            }
            temp = temp->link;
        }
        printf("The even numbers are: ");
        for(int i = 0; i < count; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

int main()
{
    int option, data, position, item,n;

    while (1) {
        printf("\n!!!  MENU  !!!\n");
        printf("1. Insert First\n");
        printf("2. Insert Last\n");
        printf("3. Delete At\n"); 
        printf("4. Print the list\n");
        printf("5. Insert Mid\n");
        printf("6.Add all elements of an array at the end of the LL\n");
        printf("7.Replace the last element of a LL using the sum of the LL\n");
        printf("8.Search all the even numbers of a LL and put them into an array\n");
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
               printf("Enter position to delete at: ");
               scanf("%d", &position);
               deleteAt(position);
               break;
            case 4:
                printList();
                break;
            case 5:
                printf("Enter data to insert at the middle: ");
                scanf("%d", &data);
                insertMid(data);
                break;
            case 6:
                printf("Enter the size of the array: ");
                scanf("%d", &n);
                int arr[500];
                printf("Enter the elements of the array: ");
                for(int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                addArray(arr, n);
                break;
            case 7:
                replaceLast();
                break;
            case 8:
                searchEven();
                break;
            
            case 9:
                while (head != NULL) {
                    struct node* temp = head;
                    head = head->link;
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid option. Please select a valid option.\n");
        }
    }




}
