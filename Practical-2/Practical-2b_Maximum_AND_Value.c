#include <stdio.h>

int main() {
    int a[50], n, i, j, max = 0, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            value = a[i] & a[j];
            if(value > max)
                max = value;
        }
    }

    printf("Maximum AND value = %d", max);

    return 0;
}
