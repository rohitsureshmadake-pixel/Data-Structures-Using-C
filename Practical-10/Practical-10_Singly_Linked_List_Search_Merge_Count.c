#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createList(int n) {
    struct Node *head = NULL, *temp, *newNode;
    int i, value;

    for (i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    return head;
}

void display(struct Node *head) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void search(struct Node *head, int key) {
    int pos = 1;

    while (head != NULL) {
        if (head->data == key) {
            printf("Element found at position %d\n", pos);
            return;
        }
        head = head->next;
        pos++;
    }
    printf("Element not found.\n");
}

int countNodes(struct Node *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int countEven(struct Node *head) {
    int count = 0;
    while (head != NULL) {
        if (head->data % 2 == 0)
            count++;
        head = head->next;
    }
    return count;
}

int countOdd(struct Node *head) {
    int count = 0;
    while (head != NULL) {
        if (head->data % 2 != 0)
            count++;
        head = head->next;
    }
    return count;
}

struct Node *merge(struct Node *head1, struct Node *head2) {
    struct Node *temp;

    if (head1 == NULL)
        return head2;

    temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}

void freeList(struct Node *head) {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node *list1, *list2;
    int n, choice, key;

    printf("Enter number of nodes in List 1: ");
    scanf("%d", &n);
    list1 = createList(n);

    printf("Enter number of nodes in List 2: ");
    scanf("%d", &n);
    list2 = createList(n);

    do {
        printf("\n--- LINKED LIST MENU ---\n");
        printf("1. Search Element\n");
        printf("2. Merge Lists\n");
        printf("3. Count Total Nodes\n");
        printf("4. Count Even Nodes\n");
        printf("5. Count Odd Nodes\n");
        printf("6. Display List\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &key);
                search(list1, key);
                break;

            case 2:
                list1 = merge(list1, list2);
                list2 = NULL;
                printf("Lists merged successfully.\n");
                display(list1);
                break;

            case 3:
                printf("Total nodes = %d\n", countNodes(list1));
                break;

            case 4:
                printf("Even nodes = %d\n", countEven(list1));
                break;

            case 5:
                printf("Odd nodes = %d\n", countOdd(list1));
                break;

            case 6:
                display(list1);
                break;

            case 7:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 7);

    freeList(list1);
    freeList(list2);
    return 0;
}
