#include <stdio.h>

int main() {
    int a[50], n, i, j, t, key, low, high, mid, found=0;

    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++) scanf("%d",&a[i]);

    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(a[i]>a[j]) {
                t=a[i]; a[i]=a[j]; a[j]=t;
            }

    printf("Enter data to search: ");
    scanf("%d",&key);

    low=0; high=n-1;
    while(low<=high) {
        mid=(low+high)/2;
        if(a[mid]==key) {
            printf("Data found at position %d",mid+1);
            found=1; break;
        }
        if(a[mid]<key) low=mid+1;
        else high=mid-1;
    }

    if(!found) printf("Data not found");
    return 0;
}
