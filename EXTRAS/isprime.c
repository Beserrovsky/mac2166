#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int num = atoi(argv[1]), i;

    for (i = 2; i < num && i != -1; i++) {
        if (num % i == 0) {
            i = -1;
            break;
        }
    }

    if (num == 1) i = -1;

    if (i == -1) printf("NAO\n");
    else printf("SIM\n");

    return 0;
}
