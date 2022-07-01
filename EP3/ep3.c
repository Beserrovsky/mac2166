#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define N_MAX 15

/* Core */
void generate(int N, int b, int c, int r, int f, int v);
int check(int *lines, int N, int x, int y, int b, int c, int r);
int checkTower(int *lines, int N, int x);
int checkBixopp(int *lines, int N, int x, int y);
int checkHorse(int *lines, int N, int x, int y);
int checkKing(int *lines, int N, int x, int y);
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

/* Core */

void generate(int N, int b, int c, int r, int f, int v) {
    int lines[N_MAX];
    int i, back, x = 0, y = 0, qtdsol = 0;

    clearArr(lines, N);

    /* Loop Logic */

    /*
     *  - N Queens
     *  - Only one Queen in each line
     *  - When adding a Queen, if it can kill, it can die
     *  - When found a solution, go back and try other until first line change
     *  - ... 
     */

    for (i = 0; i < N; i++) { /* Go through each first line position */
        lines[0] = i;
        x = 0;
        y = 1;
        back = 1;
        while(y != 1 || x < N) {
            if(check(lines, N, x, y, b, c, r)) {
                lines[y] = x;
                x = 0;
                if(y < N - 1) y++;
                else { 
                    if(v == 1) printS(lines, N);
                    /* Backtrace */
                    lines[y] = -back;
                    y-= back;
                    x = lines[y];
                    if(back < N) back++;
                }
            }
            else if(x < N - 1 || y == 1) x++;
        }
    }

    if(qtdsol == 0)
        printf("Nao ha solucao");
    else
        printf("Total de solucoes: %d\n", qtdsol);
    
    if (f == 1) 
        printM(lines, qtdsol);
}

int check(int *lines, int N, int x, int y, int b, int c, int r) {
    int res = 0;
    res += checkTower(lines, N, x);
    if(b) res+= checkBixopp(lines, N, x, y);
    if(c) res+= checkHorse(lines, N, x, y);
    if(r) res+= checkKing(lines, N, x, y);

    if(res < 1 + b + c + r) return FALSE;
    return TRUE;
}

int checkTower(int *lines, int N, int x) {
    int i;
    for (i = 0; i < N; i++) {
        if(lines[i] == x) return FALSE;
    }
    return TRUE;
}

int checkBixopp(int *lines, int N, int x, int y) {
    /*TODO*/
    return TRUE;
}

int checkHorse(int *lines, int N, int x, int y) {
    /*TODO*/
    return TRUE;
}

int checkKing(int *lines, int N, int x, int y) {
   /*TODO*/ 
    return TRUE;
}

void printM(int *lines, int qtdsol) {
/* 
 * deve imprimir uma matriz onde cada uma das N2 posições é a razão q/T, 
 * onde q é o número de vezes, considerando todas as soluções possíveis, 
 * em que uma rainha foi colocada naquela posição e 
 * T é o número total de soluções
 */

    /*
    int i, j;
    double fr[N];

    printf("Mapa de frequencias\n");
    */
    /* TODO */
}

void printS(int *lines, int N) {
    /* deve imprimir uma solução, para em conjunto, imprimir todas*/
    int i, j;
    char line[N_MAX];

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
    printf("\n");
}

/* Util */

void clearArr(int *array, int size) {
    int i;
    for(i = 0; i < size; i++) {
        array[i] = -1;
    }
}
