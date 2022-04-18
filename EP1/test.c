/* Testing divisions and shit in C */

#include <stdio.h>

void testNumber(int num) {
    
    int template = 10000;

    printf("Printing %d\n", num);

    while (template >= 1) {

        printf("%d ", (num / template) % 10);
        
        if (template == 1) template--;
        else template /= 10;
    }

    printf("\n");
}

int main() {

    testNumber(9);
    testNumber(0);
    testNumber(29);
    testNumber(10002);
    testNumber(29302);
    testNumber(99092138);

    return 0;
}

