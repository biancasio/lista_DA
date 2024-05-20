#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para converter uma string para maiúsculas usando ponteiros
void paraMaiusculas(char *str) {
    while (*str != '\0') {
        *str = toupper(*str);
        str++;
    }
}

int main() {
    char str[100];

    // Solicita ao usuário que insira uma string
    printf("Digite uma Palavra: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove o caractere de nova linha, se presente
    str[strcspn(str, "\n")] = 0;

    // Converte a string para maiúsculas
    paraMaiusculas(str);

    // Exibe a string convertida
    printf("Palavra em maiúsculas: %s\n", str);

    return 0;
}
