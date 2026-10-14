/*
Practical No. 13 (B)
Title: Print a Given String in Reverse Using Recursion
*/

#include <stdio.h>
#include <string.h>

void reverse(char str[])
{
    if (str[0] == '\0')
        return;

    reverse(str + 1);
    printf("%c", str[0]);
}

int main(void)
{
    char str[100];

    printf("Enter String: ");

    if (fgets(str, sizeof(str), stdin) == NULL)
    {
        printf("Input error.\n");
        return 1;
    }

    str[strcspn(str, "\n")] = '\0';

    printf("\nReverse String = ");
    reverse(str);
    printf("\n");

    return 0;
}

/*
Sample Output:
Enter String: DATA

Reverse String = ATAD

Time Complexity: O(n)
Space Complexity: O(n), due to recursive calls.
*/
