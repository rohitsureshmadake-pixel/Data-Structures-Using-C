/*
Practical No. 15
Title: INSERT and DELETE Operations on Linear Queue Using Array

Exercise:
1. Implement a Queue using an Array.
2. Count and Display Queue Elements.
*/

#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void insert(void)
{
    int value;

    if (rear == MAX - 1)
    {
        printf("Queue Overflow! Queue is full.\n");
        return;
    }

    printf("Enter value to insert: ");
    if (scanf("%d", &value) != 1)
    {
        printf("Invalid input.\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;

    printf("%d inserted into the queue.\n", value);
}

void deleteElement(void)
{
    if (front == -1)
    {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
}

void countElements(void)
{
    if (front == -1)
        printf("Number of queue elements: 0\n");
    else
        printf("Number of queue elements: %d\n", rear - front + 1);
}

void display(void)
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    printf("\n");
}

int main(void)
{
    int choice;

    do
    {
        printf("\n--- LINEAR QUEUE USING ARRAY ---\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Count Queue Elements\n");
        printf("4. Display Queue Elements\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Program terminated.\n");
            return 1;
        }

        switch (choice)
        {
            case 1:
                insert();
                break;
            case 2:
                deleteElement();
                break;
            case 3:
                countElements();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

/*
Sample Output:
--- LINEAR QUEUE USING ARRAY ---
1. Insert (Enqueue)
2. Delete (Dequeue)
3. Count Queue Elements
4. Display Queue Elements
5. Exit
Enter your choice: 1
Enter value to insert: 10
10 inserted into the queue.

Enter your choice: 1
Enter value to insert: 20
20 inserted into the queue.

Enter your choice: 3
Number of queue elements: 2

Enter your choice: 4
Queue elements: 10 20

Enter your choice: 2
Deleted element: 10

Time Complexity:
Insert: O(1)
Delete: O(1)
Count: O(1)
Display: O(n)

Note: This is a linear queue. Freed array positions at the front are not reused
until the queue becomes empty; a circular queue can reuse those positions.
*/
