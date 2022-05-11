#include <stdio.h>

int main() {
    
    int a, b, c, i, e = 0;

    scanf("%d", &c);

    for (i = 2; i < c; i++) {
        a = 1;
        b = i;

        while (a <= b) {
            if ((a*a) + (b*b) == (c*c)) {
                e = 1;
                printf("%d %d\n", a, b);
            }
            a++;
        }
    }

    if (e == 0) printf("Nao ha\n");

    return 0;
}
