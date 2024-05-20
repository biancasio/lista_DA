#include <stdio.h>
#include <stdlib.h>

// Função para inverter um array
int* inverterArray(int *array, int tamanho) {
    // Aloca dinamicamente memória para o novo array invertido
    int *arrayInvertido = (int *)malloc(tamanho * sizeof(int));
    if (arrayInvertido == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    // Preenche o novo array com os elementos em ordem inversa
    for (int i = 0; i < tamanho; i++) {
        arrayInvertido[i] = array[tamanho - 1 - i];
    }

    return arrayInvertido;
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(array) / sizeof(array[0]);

    printf("Array original:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Inverte o array
    int *arrayInvertido = inverterArray(array, tamanho);

    printf("Array invertido:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arrayInvertido[i]);
    }
    printf("\n");

    // Libera a memória alocada para o array invertido
    free(arrayInvertido);

    return 0;
}
