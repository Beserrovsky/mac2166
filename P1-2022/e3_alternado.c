#include <stdio.h>

int main() {

    int n, temp, last;

    printf("n(>=10)= ");
    scanf("%d", &n);
     
    last = n % 10;
    temp = n / 10;

    while (temp > 0) {
        if ((temp % 10) % 2 == last % 2)
            break;
        last = temp % 10;
        temp /= 10;
    }

    if (temp > 0)
        printf("%d nao e alternado\n", n);
    else
        printf("%d e alterando\n", n);

    return 0;
}
