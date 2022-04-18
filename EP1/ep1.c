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
    int seed, attempts, pass, guess, temp, i, temp2, j;
    int correct[5] = {0};
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

            if (((guess / temp) % 10) == ((pass / temp) % 10)) {

                correct[i] = 1;
                used[i] = 1;
            }

            i++;
            if (temp == 1) temp--;
            else temp /= 10;
        }

        i = 0;
        temp = 10000;
        while (temp >= 1) { 
            
            if (correct[i] == 1) printf("%s digito certo!\n", positions[i]);
            else if (((guess / temp) % 10) != ((pass / temp) % 10)) {

                j = 0;
                temp2 = 10000;
                while (temp2 >= 1) {
                
                    if (used[j] == 0 && ((guess / temp) % 10) == ((pass / temp2) % 10)) {
                            
                        printf("%s digito em posicao incorreta.\n", positions[i]);
                        used[j] = 1;
                        break;
                    }

                    j++;
                    if (temp2 == 1) temp2--;
                    else temp2 /= 10;
                }
            }

            i++;
            if (temp == 1) temp--;
            else temp /= 10;
        }
        
        for (i = 0; i < 5; i++) {
            used[i] = 0;
            correct[i] = 0;
        }
        
        attempts--;
    }

    /* TODO: Clear code */

    if (attempts == 0) {
        printf("Voce perdeu! A senha era %d.", pass);
    
    }
    return 0;
}
