#include <stdio.h>
#include <stdlib.h>

/* Core */
void generate(int N, int b, int c, int r, int f, int v);
void printM(); /*TODO*/
void printS(int *lines, int N);

/* Util */
void clearArr(int *array, int size);

int main(int argc, char *argv[]) {
    int N = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);
    int r = atoi(argv[4]);
    int f = atoi(argv[5]);
    int v = atoi(argv[6]);
    generate(N, b, c, r, f, v);
    return 0;
}

void generate(int N, int b, int c, int r, int f, int v) {
    int lines[N];
    int i, qtdsol = 0;

    /* Loop Logic */

    /*
     *  - Only one Queen in each line
     *  - ... 
     * 
     */

    for(i = 0; i < N; i++) {
        clearArr(lines, N);

        lines[N-1] = N-1;

        if (v == 1) printS(lines, N);
        qtdsol++;
    }

    if(qtdsol == 0)
        printf("Nao ha solucao");
    
    if (f == 1) 
        printM();
}

void clearArr(int *array, int size) {
    int i;
    for(i = 0; i < size; i++) {
        array[i] = -1;
    }
}

void printM() {
/* 
 * deve imprimir uma matriz onde cada uma das N2 posições é a razão q/T, 
 * onde q é o número de vezes, considerando to as as soluções possíveis, 
 * em que uma rainha foi colocada naquela posição e 
 * T é o número total de soluções
 */

    /*TODO: IMPLEMENT*/
}

void printS(int *lines, int N) {
    /* deve imprimir uma solução, para em conjunto, imprimir todas*/
    int i, j;
    char line[N];

    for (j = 0; j < N; j++) {
        line[j] = '-';
    }

    for (i = 0; i < N; i++) {
        line[lines[i]] = 'X';
        for (j = 0; j < N; j++) {
            printf("%c", line[j]);
        }
        printf("\n");
        line[lines[i]] = '-';
    }
}
