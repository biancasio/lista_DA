#include <stdio.h>
#include <stdlib.h>

// Função para comparar dois inteiros (usada por qsort)
int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Função para calcular a média
double calcularMedia(int *array, int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += array[i];
    }
    return (double)soma / tamanho;
}

// Função para calcular a mediana
double calcularMediana(int *array, int tamanho) {
    qsort(array, tamanho, sizeof(int), comparar);
    if (tamanho % 2 == 0) {
        return (array[tamanho / 2 - 1] + array[tamanho / 2]) / 2.0;
    } else {
        return array[tamanho / 2];
    }
}

// Função para calcular a moda
int calcularModa(int *array, int tamanho) {
    qsort(array, tamanho, sizeof(int), comparar);

    int moda = array[0];
    int maxContagem = 1;
    int contagemAtual = 1;

    for (int i = 1; i < tamanho; i++) {
        if (array[i] == array[i - 1]) {
            contagemAtual++;
        } else {
            if (contagemAtual > maxContagem) {
                maxContagem = contagemAtual;
                moda = array[i - 1];
            }
            contagemAtual = 1;
        }
    }

    if (contagemAtual > maxContagem) {
        maxContagem = contagemAtual;
        moda = array[tamanho - 1];
    }

    return moda;
}

int main() {
    int tamanho;
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int *array = (int *)malloc(tamanho * sizeof(int));
    if (array == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array[i]);
    }

    double media = calcularMedia(array, tamanho);
    double mediana = calcularMediana(array, tamanho);
    int moda = calcularModa(array, tamanho);

    printf("Media: %.2f\n", media);
    printf("Mediana: %.2f\n", mediana);
    printf("Moda: %d\n", moda);

    free(array);
    return 0;
}
