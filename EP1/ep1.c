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
    int temp;

    printf("Bem vinda(o) ao Numle\n");

    printf("Digite a semente para sortear a senha (0 a 10000): ");
    scanf("%d", &seed);
    pass = ((8121 * seed + 28411) % 134456) % 100000;
    printf("Quantidade de tentativas (1 a 10): ");
    scanf("%d", &attempts);

    p0 = (pass / 10000) % 10;
    p1 = (pass / 1000) % 10;
    p2 = (pass / 100) % 10;
    p3 = (pass / 10) % 10;
    p4 = (pass / 1) % 10;

    while (attempts > 0) {
    
        printf("Digite a tentativa (0 a 99999): ");
        scanf("%d", &guess);

        if (guess == pass) {
            printf("Voce acertou! A senha eh de fato %d.", pass);
            break;
        }}

        g0 = (guess / 10000) % 10;
        g1 = (guess / 1000) % 10;
        g2 = (guess / 100) % 10;
        g3 = (guess / 10) % 10;
        g4 = (guess) % 10;

        /* TODO: Game logic */

        attempts--;
    }

    if (attempts == 0) {
        printf("Voce perdeu! A senha era %d.", pass);
    }

    return 0;
}
