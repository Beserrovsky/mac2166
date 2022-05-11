#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *args[]) {
    int n1 = atoi(args[1]), n2 = atoi(args[2]), r;

    r = n2 % n1;
    while (r != 0) {
        r = n1 % n2;
        n1 = n2;
        n2 = r;
    }

    printf("%d\n", n1);
    return 0;
}
