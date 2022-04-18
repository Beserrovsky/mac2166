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
    int seed, attempts, pass, guess, temp, i;

    char *positions[] = {
                            "Primeiro",
                            "Segundo",
                            "Terceiro",
                            "Quarto",
                            "Quinto"
                        };

    printf("Bem vinda(o) ao Numle\n");

    printf("Digite a semente para sortear a senha (0 a 10000): ");
    scanf("%d", &seed);
    pass = ((8121 * seed + 28411) % 134456) % 100000;
    printf("Quantidade de tentativas (1 a 10): ");
    scanf("%d", &attempts);

    while (attempts > 0) {

        printf("Digite a tentativa (0 a 99999): ");
        scanf("%d", &guess);
  
        if (pass == guess) {
            printf("Voce acertou! A senha eh de fato %d.", pass);
            break;
        }
         
        i = 0;
        temp = 10000;
        while (temp >= 1) {

            /* positions[i] -> PT-BR position */

            /* ((guess / temp) % 10) -> guess value at that position */
            
            /* ((pass / temp) % 10) -> pass value at that position */
            
            if (((guess / temp) % 10) == (((pass / temp) % 10))) {

                printf("%s digito certo!\n", positions[i]);
            }

            /* printf("%s digito em posicao incorreta.\n", positions[i]); */

            i++;
            if (temp == 1) temp--;
            else temp /= 10;
        }

        /* TODO: Check if digit is at the wrong place */

        attempts--;
    }

    if (attempts == 0) {
        printf("Voce perdeu! A senha era %d.", pass);
    }
    return 0;
}
