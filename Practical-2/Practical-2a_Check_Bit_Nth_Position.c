#include <stdio.h>

int main() {
    int n, pos, bit;

    printf("Enter number: ");
    scanf("%d", &n);
    printf("Enter bit position: ");
    scanf("%d", &pos);

    bit = (n >> pos) & 1;

    if(bit == 1)
        printf("Bit at position %d is SET", pos);
    else
        printf("Bit at position %d is CLEAR", pos);

    return 0;
}
