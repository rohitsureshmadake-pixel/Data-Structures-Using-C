#include <stdio.h>
#include <string.h>

int main() {
    char a[50][100], temp[100];
    int n, i, j, min;

    printf("Enter number of strings: ");
    scanf("%d", &n);

    printf("Enter strings:\n");
    for (i = 0; i < n; i++)
        scanf("%99s", a[i]);

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (strcmp(a[j], a[min]) < 0)
                min = j;

        strcpy(temp, a[i]);
        strcpy(a[i], a[min]);
        strcpy(a[min], temp);
    }

    printf("Sorted strings:\n");
    for (i = 0; i < n; i++)
        printf("%s\n", a[i]);

    return 0;
}
