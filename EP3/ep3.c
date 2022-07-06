#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define N_MAX 15

/* Testing */
void testing(int N, int b, int c, int r, int f, int v);

/* Core */
void generate(int N, int b, int c, int r, int f, int v);
int check(int lines[], int N, int x, int y, int b, int c, int r);
int checkTower(int lines[], int N, int x);
int checkBixopp(int lines[], int N, int x, int y);
int checkHorse(int lines[], int N, int x, int y);
int checkKing(int lines[], int N, int x, int y);
void printM(int fr[N_MAX][N_MAX], int N, int qtdsol);
void printS(int lines[], int N);

/* Util */
void fillArr(int array[], int size, int value);
void fillMatrix(int array[N_MAX][N_MAX], int size, int value);

int main(int argc, char *argv[]) {
    int N = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);
    int r = atoi(argv[4]);
    int f = atoi(argv[5]);
    int v = atoi(argv[6]);
    testing(N, b, c, r, f, v); /*FIXME REMOVE*/
    generate(N, b, c, r, f, v);
    return 0;
}

/* Testing */

void testing(int N, int b, int c, int r, int f, int v) {
    int lines[N_MAX];
    int fr[N_MAX][N_MAX];
    int x = 4, y = 4, qtdsol = 10;

    N = 10;

    fillArr(lines, N, -1);
    fillMatrix(fr, N, 0);

    lines[y] = x;
    printS(lines, N);

    x = 6;
    y = 3;

    if(check(lines, N, x, y, b, c, r)) { 
        lines[y] = x;
        printS(lines, N);
    }
    else printf("NAO PODE");

}

/* Core */

void generate(int N, int b, int c, int r, int f, int v) {
    int lines[N_MAX];
    int fr[N_MAX][N_MAX];
    int i, back, x = 0, y = 0, qtdsol = 0;

    fillArr(lines, N, -1);
    fillMatrix(fr, N, 0);

    /* Loop Logic */

    /*
     *  - N Queens
     *  - Only one Queen in each line
     *  - When adding a Queen, if it can kill, it can die
     *  - When found a solution, go back and try other until first line change
     *  - ... 
     */

    /* TODO BACKTRAKING */

    if(!qtdsol)
        printf("Nao ha solucao");
    else
        printf("Total de solucoes: %d\n", qtdsol);
    
    if(f) 
        printM(fr, N, qtdsol);
}

int check(int lines[], int N, int x, int y, int b, int c, int r) {
    int res = 0;
    res += checkTower(lines, N, x);
    if(b) res+= checkBixopp(lines, N, x, y);
    if(c) res+= checkHorse(lines, N, x, y);
    if(r) res+= checkKing(lines, N, x, y);

    if(res < 1 + b + c + r) return FALSE;
    return TRUE;
}

int checkTower(int lines[], int N, int x) {
    int i;
    for (i = 0; i < N; i++) {
        if(lines[i] == x) return FALSE;
    }
    return TRUE;
}

int checkBixopp(int lines[], int N, int x, int y) {
    /*FIXME*/
    int i;
    for(i = y; i >= 0; i--) {
        if(y - i >= 0 && lines[y - i] >= 0)
            if(lines[y - i] == x - i || lines[y - i] == x + i)
                return FALSE;
    }
    for(i = N - y; i >= y; i--) {
        if(y + i < N && lines[y + i] >= 0)
            if(lines[y + i] == x - i || lines[y + i] == x + i)
                return FALSE;
    }
    return TRUE;
}

int checkHorse(int lines[], int N, int x, int y) {
    if(y - 2 >= 0) {
        if(lines[y - 2] >= 0 && 
                ( lines[y - 2] == x - 1 || lines[y - 2] == x + 1))
            return FALSE;
    }
    if(y - 1 >= 0) {
        if(lines[y - 1] >= 0 && 
                ( lines[y - 1] == x - 2 || lines[y - 1] == x + 2))
            return FALSE;
    }
    if(y + 2 < N) {
        if(lines[y + 2] >= 0 && 
                ( lines[y + 2] == x - 1 || lines[y + 2] == x + 1))
            return FALSE;
    }
    if(y + 1 < N) {
        if(lines[y + 1] >= 0 && 
                ( lines[y + 1] == x - 2 || lines[y + 1] == x + 2))
            return FALSE;
    }

    return TRUE;
}

int checkKing(int lines[], int N, int x, int y) {
    if(y - 1 >= 0) {
        if(lines[y - 1] >= 0 && lines[y - 1] >= x - 1 && lines[y - 1] <= x + 1)
            return FALSE;
    }
    if(lines[y] == x) return FALSE;
    if(y + 1 < N) {
        if(lines[y + 1] >= 0 && lines[y + 1] >= x - 1 && lines[y + 1] <= x + 1)
            return FALSE;
    }

    return TRUE;
}

void printM(int fr[N_MAX][N_MAX], int N, int qtdsol) {
    /* 
     * deve imprimir uma matriz onde cada uma das N^2 posições é a razão q/T, 
     * onde q é o número de vezes, considerando todas as soluções possíveis, 
     * em que uma rainha foi colocada naquela posição e 
     * T é o número total de soluções
     */

    int i, j;

    printf("Mapa de frequencias\n");

    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            printf("%f", ((double)fr[i][j] / (double)qtdsol));
            if(j + 1 < N) printf(" ");
            else printf("\n");
        }
    }
}

void printS(int lines[], int N) {
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

void fillArr(int array[], int size, int value) {
    int i;
    for(i = 0; i < size; i++) {
        array[i] = value;
    }
}

void fillMatrix(int matrix[N_MAX][N_MAX], int size, int value) {
    int i, j;
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            matrix[i][j] = value;
        }
    }
}
