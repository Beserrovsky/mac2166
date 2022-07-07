#include <stdio.h>

char conta_char(int *n_upper, int *n_lower, int *n_digs, int *n_others);

int main() {
    int n_upper = 0, n_lower = 0, n_digs = 0, n_others = 0;
    conta_char(&n_upper, &n_lower, &n_digs, &n_others);
    printf("Upper: %d\n", n_upper);
    printf("Lower: %d\n", n_lower);
    printf("Digits: %d\n", n_digs);
    printf("Others: %d\n", n_others);
    return 0;
}

char conta_char(int *n_upper, int *n_lower, int *n_digs, int *n_others) {
    char c = '\0';
    while (c != ' ' && c!= '.') {
        scanf("%c", &c);
        if (c >= 'A' && c <= 'Z') (*n_upper)++;
        else if (c >= 'a' && c <= 'z') (*n_lower)++;
        else if (c >= '0' && c <= '9') (*n_digs)++;
        else if (c!= ' ' && c!= '.') (*n_others)++; 
    }
    return c;
}

