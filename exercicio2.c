#include <stdio.h>
#include <string.h>
#include <ctype.h>  // Necessário para a função tolower

// Função para verificar se um caractere é uma vogal
int ehVogal(char c) {
    // Converte o caractere para minúsculo para facilitar a comparação
    c = tolower(c);
    // Verifica se o caractere é uma das vogais
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    char str[100];
    int i, numVogais = 0;

    // Solicita ao usuário que insira uma string
    printf("Digite uma palavra: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove o caractere de nova linha, se presente
    str[strcspn(str, "\n")] = 0;

    // Conta o número de vogais na string
    for (i = 0; i < strlen(str); i++) {
        if (ehVogal(str[i])) {
            numVogais++;
        }
    }

    // Exibe o número de vogais
    printf("O número de vogais na string é: %d\n", numVogais);

    return 0;
}
