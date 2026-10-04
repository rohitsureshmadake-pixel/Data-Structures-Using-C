#include <stdio.h>
#include <string.h>

int main() {
    char a[50][50], key[50], t[50];
    int n, i, j, low, high, mid, found=0;

    printf("Enter number of strings: ");
    scanf("%d",&n);
    printf("Enter strings:\n");
    for(i=0;i<n;i++) scanf("%s",a[i]);

    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(strcmp(a[i],a[j])>0) {
                strcpy(t,a[i]); strcpy(a[i],a[j]); strcpy(a[j],t);
            }

    printf("Enter string to search: ");
    scanf("%s",key);

    low=0; high=n-1;
    while(low<=high) {
        mid=(low+high)/2;
        if(strcmp(a[mid],key)==0) {
            printf("String found at position %d",mid+1);
            found=1; break;
        }
        if(strcmp(a[mid],key)<0) low=mid+1;
        else high=mid-1;
    }

    if(!found) printf("String not found");
    return 0;
}
