#include <stdio.h>

int main() {

    int n, num, temp, inv, p = 1;

    printf("n= ");
    scanf("%d", &n);

    while (n > 0) {
        
        printf("num= ");
        scanf("%d", &num);

        inv = 0;
        temp = num;
        while (temp > 0) {
            inv = (inv * 10) + (temp % 10);
            temp /= 10;
        }

        if (inv != num) p = 0; 
        n--;
    }

    if (p != 1) printf("NAO");
    else printf("SIM");

    return 0;
}
