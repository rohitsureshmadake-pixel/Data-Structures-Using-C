/*
Practical No. 12
Title: Parenthesis Checker Using Stack
Purpose: Check whether (), {}, and [] are balanced in an expression.
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    if (top < MAX - 1)
    {
        top++;
        stack[top] = ch;
    }
}

char pop(void)
{
    char ch = stack[top];
    top--;
    return ch;
}

int isMatchingPair(char opening, char closing)
{
    if (opening == '(' && closing == ')')
        return 1;

    if (opening == '{' && closing == '}')
        return 1;

    if (opening == '[' && closing == ']')
        return 1;

    return 0;
}

int isBalanced(char exp[])
{
    int i;
    char ch;

    top = -1;

    for (i = 0; exp[i] != '\0'; i++)
    {
        ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            if (top == MAX - 1)
                return 0;

            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (top == -1)
                return 0;

            if (!isMatchingPair(pop(), ch))
                return 0;
        }
    }

    return top == -1;
}

int main(void)
{
    char exp[MAX];

    printf("Enter an expression: ");

    if (fgets(exp, sizeof(exp), stdin) == NULL)
    {
        printf("Input error.\n");
        return 1;
    }

    /* Remove the newline added by fgets, if present. */
    exp[strcspn(exp, "\n")] = '\0';

    if (isBalanced(exp))
        printf("Expression is Correct\n");
    else
        printf("Expression is Incorrect\n");

    return 0;
}

/*
Sample Output 1:
Enter an expression: (A+B)*(C-D)
Expression is Correct

Sample Output 2:
Enter an expression: ((A+B)
Expression is Incorrect

Sample Output 3:
Enter an expression: [(A+B)*{C-D}]
Expression is Correct

Time Complexity: O(n)
Space Complexity: O(n)
*/
