#include <stdio.h>

int main() {
    int a[100], n, i, choice, pos, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\n1. Display\n2. Insert\n3. Delete\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
    } else if (choice == 2) {
        printf("Enter position and value: ");
        scanf("%d%d", &pos, &value);
        for (i = n; i >= pos; i--)
            a[i] = a[i - 1];
        a[pos - 1] = value;
        n++;
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
    } else if (choice == 3) {
        printf("Enter position: ");
        scanf("%d", &pos);
        for (i = pos - 1; i < n - 1; i++)
            a[i] = a[i + 1];
        n--;
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
    } else {
        printf("Invalid choice");
    }

    return 0;
}
