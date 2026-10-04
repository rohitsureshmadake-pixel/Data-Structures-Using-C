#include <stdio.h>
#include <string.h>

int main() {
    char a[50][100], temp[100];
    int n, i, j;

    printf("Enter number of strings: ");
    scanf("%d", &n);

    printf("Enter strings:\n");
    for (i = 0; i < n; i++)
        scanf("%99s", a[i]);

    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (strcmp(a[j], a[j + 1]) > 0) {
                strcpy(temp, a[j]);
                strcpy(a[j], a[j + 1]);
                strcpy(a[j + 1], temp);
            }

    printf("Sorted strings:\n");
    for (i = 0; i < n; i++)
        printf("%s\n", a[i]);

    return 0;
}
