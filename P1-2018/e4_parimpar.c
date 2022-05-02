#include <stdio.h>

int main() {

    int n, num, i, pa = 0;

    printf("N (N>=2)= ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
    
        printf("num= ");
        scanf("%d", &num);

        if (num % 2 == 0) pa++;
    }

    if (pa == n || pa == 0) printf("SIM");
    else printf("NAO");

    return 0;
}
