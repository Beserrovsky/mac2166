#include <stdio.h>

int main() {

    int n, sum = 0, i;

    printf("N (>=2)= ");
    scanf("%d", &n);

    for (i = 1; i < n; i++) {
        if (n % i == 0) sum += i;
    }

    if (sum == n) printf("SIM");
    else printf("NAO");

    return 0;
}
