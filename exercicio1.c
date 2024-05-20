#include <stdio.h>

int main() {
    int n, i; // n para armazenar o numero de elementos na array e i para o indice do loop
    int soma = 0; //onde vai armazenar os elementos, por isso começa com 0

    // Solicita ao usuário o número de elementos no array
    printf("Digite o número de elementos no array: "); //mostra para o usuario a informação a ser digitada
    scanf("%d", &n); // recebe do usuario o numero de elementos da array

    // Declaração do array com o tamanho fornecido pelo usuário
    int array[n];

    // Solicita ao usuário para inserir os elementos do array
    printf("Digite %d elementos:\n", n); //mostra para o usuario a informação a ser digitada
    for(i = 0; i < n; i++) { // para criar o loop solicitando o numero de elementos até chegar no numero digitado na array
        printf("Elemento %d: ", i + 1); //mostra para o usuario a informação a ser digitada
        scanf("%d", &array[i]); //recebe a informação solicitada
    }

    // Calcula a soma dos elementos do array
    for(i = 0; i < n; i++) { // para criar o loop dos elementos a serem armazenados na array
        soma += array[i]; // armazena-los na soma
    }

    // Exibe a soma dos elementos
    printf("A soma dos elementos do array é: %d\n", soma); // mostra para o usuario a soma dos elementos.

    return 0;
}
