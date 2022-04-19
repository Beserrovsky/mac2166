/***************************************************************/
/**                                                           **/
/**   Felipe Beserra de Oliveira                 13683702     **/
/**   Exercício-Programa 1                                    **/
/**   Professor: Yoshiharu Kohayakawa                         **/
/**   Turma: 03                                               **/
/**                                                           **/
/***************************************************************/

#include <stdio.h>

int main() {
    
    int seed, attempts;
    int pass, p0, p1, p2, p3, p4;
    int guess, g0, g1, g2, g3, g4;
    int u0, u1, u2, u3, u4;

    printf("Bem vinda(o) ao Numle\n");

    printf("Digite a semente para sortear a senha (0 a 10000): \n");
    scanf("%d", &seed);
    pass = ((8121 * seed + 28411) % 134456) % 100000;
    printf("Quantidade de tentativas (1 a 10): \n");
    scanf("%d", &attempts);

    p0 = (pass / 10000) % 10;
    p1 = (pass / 1000) % 10;
    p2 = (pass / 100) % 10;
    p3 = (pass / 10) % 10;
    p4 = (pass / 1) % 10;

    while (attempts > 0) {
    
        printf("\nDigite a tentativa (0 a 99999): \n");
        scanf("%d", &guess);

        if (guess == pass) {
            printf("Voce acertou! A senha eh de fato %d.", pass);
            break;
        }

        g0 = (guess / 10000) % 10;
        g1 = (guess / 1000) % 10;
        g2 = (guess / 100) % 10;
        g3 = (guess / 10) % 10;
        g4 = (guess) % 10;

        u0 = 0; u1 = 0; u2 = 0; u3 = 0; u4 = 0;

        if (g0 == p0) u0 = 1;
        if (g1 == p1) u1 = 1;
        if (g2 == p2) u2 = 1;
        if (g3 == p3) u3 = 1;
        if (g4 == p4) u4 = 1;

        if (g0 == p0) { 
            printf("Primeiro digito certo!\n");
        }
        else {
            if (g0 == p1 && u1 == 0) {
                printf("Primeiro digito em posicao incorreta.\n");
                u1 = 1;
            }
            else if (g0 == p2 && u2 == 0) {
                printf("Primeiro digito em posicao incorreta.\n");
                u2 = 1;
            }
            else if (g0 == p3 && u3 == 0) {
                printf("Primeiro digito em posicao incorreta.\n");
                u3 = 1;
            }
            else if (g0 == p4 && u4 == 0) {
                printf("Primeiro digito em posicao incorreta.\n");
                u4 = 1;
            }
        }

        if (g1 == p1) { 
            printf("Segundo digito certo!\n");
        }
        else {
            if (g1 == p0 && u0 == 0) {
                printf("Segundo digito em posicao incorreta.\n");
                u0 = 1;
            }
            else if (g1 == p2 && u2 == 0) {
                printf("Segundo digito em posicao incorreta.\n");
                u2 = 1;
            }
            else if (g1 == p3 && u3 == 0) {
                printf("Segundo digito em posicao incorreta.\n");
                u3 = 1;
            }
            else if (g1 == p4 && u4 == 0) {
                printf("Segundo digito em posicao incorreta.\n");
                u4 = 1;
            }
        }
        
        if (g2 == p2) { 
            printf("Terceiro digito certo!\n");
        }
        else {
            if (g2 == p0 && u0 == 0) {
                printf("Terceiro digito em posicao incorreta.\n");
                u0 = 1;
            }
            else if (g2 == p1 && u1 == 0) {
                printf("Terceiro digito em posicao incorreta.\n");
                u1 = 1;
            }
            else if (g2 == p3 && u3 == 0) {
                printf("Terceiro digito em posicao incorreta.\n");
                u3 = 1;
            }
            else if (g2 == p4 && u4 == 0) {
                printf("Terceiro digito em posicao incorreta.\n");
                u4 = 1;
            }
        }
        
        if (g3 == p3) { 
            printf("Quarto digito certo!\n");
        }
        else {
            if (g3 == p0 && u0 == 0) {
                printf("Quarto digito em posicao incorreta.\n");
                u0 = 1;
            }
            else if (g3 == p1 && u1 == 0) {
                printf("Quarto digito em posicao incorreta.\n");
                u1 = 1;
            }
            else if (g3 == p2 && u2 == 0) {
                printf("Quarto digito em posicao incorreta.\n");
                u2 = 1;
            }
            else if (g3 == p4 && u4 == 0) {
                printf("Quarto digito em posicao incorreta.\n");
                u4 = 1;
            }
        }
        
        if (g4 == p4) { 
            printf("Quinto digito certo!\n");
        }
        else {
            if (g4 == p0 && u0 == 0) {
                printf("Quinto digito em posicao incorreta.\n");
                u0 = 1;
            }
            else if (g4 == p1 && u1 == 0) {
                printf("Quinto digito em posicao incorreta.\n");
                u1 = 1;
            }
            else if (g4 == p2 && u2 == 0) {
                printf("Quinto digito em posicao incorreta.\n");
                u2 = 1;
            }
            else if (g4 == p3 && u3 == 0) {
                printf("Quinto digito em posicao incorreta.\n");
                u3 = 1;
            }
        }

        attempts--;
    }

    if (attempts == 0) {
        printf("Voce perdeu! A senha era %d.", pass);
    }

    return 0;
}
