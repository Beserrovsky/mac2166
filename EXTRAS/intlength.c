#include <stdio.h>

int main() {

    int n, temp, l = 1;

    printf("n= ");
    scanf("%d", &n);

    temp = n;
    while (temp > 9) {
        l++;
        temp /= 10;
    }

    printf("n has %d characters\n", l);
    return 0;
}
