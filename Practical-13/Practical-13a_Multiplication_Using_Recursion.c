/*
Practical No. 13 (A)
Title: Multiplication of Two Numbers Using Recursion
*/

#include <stdio.h>

int multiply(int a, int b)
{
    if (b == 0)
        return 0;
    else
        return a + multiply(a, b - 1);
}

int main(void)
{
    int a, b, result;

    printf("Enter First Number: ");
    scanf("%d", &a);

    printf("Enter Second Number: ");
    scanf("%d", &b);

    if (b < 0)
    {
        printf("Please enter a non-negative second number.\n");
        return 1;
    }

    result = multiply(a, b);
    printf("\nMultiplication = %d\n", result);

    return 0;
}

/*
Sample Output:
Enter First Number: 5
Enter Second Number: 4

Multiplication = 20

Time Complexity: O(b)
Space Complexity: O(b), due to recursive calls.
*/
