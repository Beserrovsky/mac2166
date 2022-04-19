#include <stdio.h>

int main() {
    
    int seed, attempts;
    int pass, p1, p2, p3, p4, p5;
    int guess, g1, g2, g3, g4, g5;
    int temp;

    printf("Bem vinda(o) ao Numle\n");

    printf("Digite a semente para sortear a senha (0 a 10000): ");
    scanf("%d", &seed);
    pass = ((8121 * seed + 28411) % 134456) % 100000;
    printf("Quantidade de tentativas (1 a 10): ");
    scanf("%d", &attempts);
    
    while (attempts > 0) {
    
        if (guess == pass) {
            printf("Voce acertou! A senha eh de fato %d.", pass);
            break;
        }

        temp = 10000;
        

        attempts--;
    }

    if (attempts == 0) {
        printf("Voce perdeu! A senha era %d.", pass);
    }

    return 0;
}
