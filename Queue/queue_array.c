#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else {
        if (front == -1)
            front = 0;
        queue[++rear] = value;
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("Queue Underflow\n");
    else
        printf("Deleted: %d\n", queue[front++]);
}

void display() {
    int i;
    if (front == -1 || front > rear)
        printf("Queue is empty\n");
    else {
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, value;

    do {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(value);
        } else if (choice == 2)
            dequeue();
        else if (choice == 3)
            display();

    } while (choice != 4);

    return 0;
}
