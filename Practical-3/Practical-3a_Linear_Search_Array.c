#include <stdio.h>

int main() {
    int a[50], n, i, key, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Enter data to search: ");
    scanf("%d",&key);

    for(i=0;i<n;i++) {
        if(a[i] == key) {
            printf("Data found at position %d", i+1);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Data not found");

    return 0;
}
