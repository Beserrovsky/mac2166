#include <stdio.h>
typedef enum { false, true } bool;

int genRandomNumber(int seed){
    return ((8121 * seed + 28411) % 134456) % 10;
}

/* Asks for a seed and saves it in int seed pointer, also checks if it is a valid value */
void askSeed(int* seed) {
    printf("Digite a semente para sortear a senha (0 a 10000): ");
    scanf("%d", seed);
    if(*seed < 0 || *seed > 10000) { askSeed(seed); return;}
    *seed = *seed % 134456;
}

/* Asks for the number of attempts and saves it in int seed pointer, also checks if it is a valid value */
void askAttempts(int* attempts) {
    printf("Quantidade de tentativas (1 a 10): ");
    scanf("%d", attempts);
    if(*attempts < 1 || *attempts > 10) { askAttempts(attempts); }
}

bool tryGuess(int correct){
    int guess;
    printf("Digite a tentativa (0 a 9): ");
    scanf("%d", &guess);
    return guess == correct;
}

int main(){
    int seed, attempts, randomNumber;
    bool winner = false;

    printf("Bem vinda(o) ao Numle\n");
    askSeed(&seed);
    askAttempts(&attempts);
    randomNumber = genRandomNumber(seed);
    while(attempts > 0) {
        if(tryGuess(randomNumber)) {      
            winner = true;
            break;
        }
        else {
            attempts--;
        }
    }

    if(winner) { 
        printf("Voce acertou! A senha eh de fato %d.", randomNumber); 
    }
    else {
        printf("Voce perdeu! A senha era %d.", randomNumber);
    }

    return 0;
}
