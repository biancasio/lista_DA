#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para simular um trecho de código que queremos medir o tempo de execução
void executarTrechoCodigo() {
    int soma = 0;
    for (int i = 0; i < 100000000; i++) {
        soma += i;
    }
    printf("Soma: %d\n", soma);
}

int main() {
    clock_t inicio, fim;
    double tempoGasto;

    // Marca o tempo de início
    inicio = clock();

    // Executa o trecho de código
    executarTrechoCodigo();

    // Marca o tempo de fim
    fim = clock();

    // Calcula o tempo gasto em segundos
    tempoGasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo de execução: %f segundos\n", tempoGasto);

    return 0;
}
