#include <stdio.h>
#include <stdlib.h>

// Função para alocar dinamicamente uma matriz
int** alocarMatriz(int linhas, int colunas) {
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    for(int i = 0; i < linhas; i++) {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
    }
    return matriz;
}

// Função para liberar a memória alocada para uma matriz
void liberarMatriz(int **matriz, int linhas) {
    for(int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

// Função para ler uma matriz do usuário
void lerMatriz(int **matriz, int linhas, int colunas) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            printf("Digite o elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

// Função para imprimir uma matriz
void imprimirMatriz(int **matriz, int linhas, int colunas) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para multiplicar duas matrizes
int** multiplicarMatrizes(int **matriz1, int linhas1, int colunas1, int **matriz2, int linhas2, int colunas2) {
    if(colunas1 != linhas2) {
        printf("Erro: Não é possível multiplicar as matrizes.\n");
        return NULL;
    }

    int **resultado = alocarMatriz(linhas1, colunas2);
    for(int i = 0; i < linhas1; i++) {
        for(int j = 0; j < colunas2; j++) {
            resultado[i][j] = 0;
            for(int k = 0; k < colunas1; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
    return resultado;
}

// Função para transpor uma matriz
int** transporMatriz(int **matriz, int linhas, int colunas) {
    int **transposta = alocarMatriz(colunas, linhas);
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }
    return transposta;
}

int main() {
    int linhas1, colunas1, linhas2, colunas2;

    // Leitura das dimensões da primeira matriz
    printf("Digite o número de linhas da primeira matriz: ");
    scanf("%d", &linhas1);
    printf("Digite o número de colunas da primeira matriz: ");
    scanf("%d", &colunas1);

    int **matriz1 = alocarMatriz(linhas1, colunas1);
    printf("Digite os elementos da primeira matriz:\n");
    lerMatriz(matriz1, linhas1, colunas1);

    // Leitura das dimensões da segunda matriz
    printf("Digite o número de linhas da segunda matriz: ");
    scanf("%d", &linhas2);
    printf("Digite o número de colunas da segunda matriz: ");
    scanf("%d", &colunas2);

    int **matriz2 = alocarMatriz(linhas2, colunas2);
    printf("Digite os elementos da segunda matriz:\n");
    lerMatriz(matriz2, linhas2, colunas2);

    // Multiplicação das matrizes
    int **resultadoMultiplicacao = multiplicarMatrizes(matriz1, linhas1, colunas1, matriz2, linhas2, colunas2);
    if (resultadoMultiplicacao != NULL) {
        printf("Resultado da multiplicação das matrizes:\n");
        imprimirMatriz(resultadoMultiplicacao, linhas1, colunas2);
        liberarMatriz(resultadoMultiplicacao, linhas1);
    }

    // Transposição da primeira matriz
    int **transposta1 = transporMatriz(matriz1, linhas1, colunas1);
    printf("Transposta da primeira matriz:\n");
    imprimirMatriz(transposta1, colunas1, linhas1);
    liberarMatriz(transposta1, colunas1);

    // Transposição da segunda matriz
    int **transposta2 = transporMatriz(matriz2, linhas2, colunas2);
    printf("Transposta da segunda matriz:\n");
    imprimirMatriz(transposta2, colunas2, linhas2);
    liberarMatriz(transposta2, colunas2);

    // Libera a memória das matrizes originais
    liberarMatriz(matriz1, linhas1);
    liberarMatriz(matriz2, linhas2);

    return 0;
}
