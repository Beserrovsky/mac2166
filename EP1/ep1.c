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
    int seed, attempts, pass, guess, temp, i, temp2, j, count;
    int used[5] = {0};

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

            if (((guess / temp) % 10) == (((pass / temp) % 10))) {

                printf("%s digito certo!\n", positions[i]);
                used[i] = 1;
            }

            temp2 = 10000;
            j = 0;
            while (temp2 >= 1) {

                if (used[i] == 0) {
                        
                    if (((guess / temp) % 10) == (((pass / temp2) % 10))) {

                        printf("%s digito em posicao incorreta.\n", positions[i]);
                        used[i] = 1;
                    }
                }

                j++;
                if (temp2 == 1) temp2--;
                else temp2 /= 10;
            }

            i++;
            if (temp == 1) temp--;
            else temp /= 10;
        }
        
        for (count = 0; count < 5; count++) {
            used[count] = 0;
        }

        attempts--;
    }

    /* FIXME: Its gotta be two separate loops, pipe in/test1.txt and analyze results*/

    if (attempts == 0) {
        printf("Voce perdeu! A senha era %d.", pass);
    }
    return 0;
}
