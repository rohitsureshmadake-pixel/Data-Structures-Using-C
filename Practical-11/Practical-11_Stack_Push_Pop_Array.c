/*
Practical No. 11
Aim: Write a C Program to Perform PUSH and POP Operations on Stack Using Array.
*/

#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push()
{
    int item;

    if (top == MAX - 1)
    {
        printf("\nStack Overflow!\n");
    }
    else
    {
        printf("Enter element: ");
        scanf("%d", &item);

        top++;
        stack[top] = item;

        printf("Element pushed successfully.\n");
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow!\n");
    }
    else
    {
        printf("\nDeleted Element = %d\n", stack[top]);
        top--;
    }
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("\nStack Empty\n");
    }
    else
    {
        printf("\nStack Elements (TOP to bottom):\n");

        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    int ch;

    do
    {
        printf("\n--- STACK MENU ---");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nProgram ended.\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (ch != 4);

    return 0;
}

/*
Result:
Successfully implemented PUSH and POP operations on Stack using Array.

Time Complexity:
PUSH  - O(1)
POP   - O(1)
DISPLAY - O(n)
*/
