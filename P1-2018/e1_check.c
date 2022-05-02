#include <stdio.h>

int main() {
    int x, y, conta;

    printf("Digite o digito final do seu Numero USP: ");
    scanf("%d", &x);

    printf("Primeiro x= %d \n", x);
    y = 2*x + 1;

    conta = 1;
    printf("Primeiro y= %d \n", y);

    while (conta < 6 && (x <= 5 || y > 3)) {
        printf("conta= %d\n", conta);
        if (x%2 == 0) {
            x = x/2;
            y = y-4;
            printf("* x= %d\n", x);
        } else {
            x = 3*x + 1;
            y = y + 5;
            printf("x= %d\n", x);
        }
        printf("y= %d\n", y);
        conta = conta + 1;
    }

    printf("Ultimo x= %d\n", x);
    printf("Ultimo y= %d\n", y);
    return 0;
}
