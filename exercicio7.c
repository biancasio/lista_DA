#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Funcionario
typedef struct {
    char nome[50];
    int idade;
    float salario;
} Funcionario;

// Função de comparação para qsort, comparando a idade dos funcionários
int compararIdade(const void *a, const void *b) {
    Funcionario *funcA = (Funcionario *)a;
    Funcionario *funcB = (Funcionario *)b;
    return (funcA->idade - funcB->idade);
}

// Função para imprimir a lista de funcionários
void imprimirFuncionarios(Funcionario *funcionarios, int n) {
    for (int i = 0; i < n; i++) {
        printf("Nome: %s, Idade: %d, Salario: %.2f\n", funcionarios[i].nome, funcionarios[i].idade, funcionarios[i].salario);
    }
}

int main() {
    Funcionario funcionarios[] = {
        {"Aline", 30, 50000.0},
        {"Bianca", 22, 45000.0},
        {"Carla", 25, 55000.0},
        {"Davi", 35, 60000.0},
        {"Elena", 28, 48000.0}
    };
    int n = sizeof(funcionarios) / sizeof(funcionarios[0]);

    printf("Lista de funcionarios antes da ordenacao:\n");
    imprimirFuncionarios(funcionarios, n);

    // Ordena o array de structs usando qsort e a função de comparação
    qsort(funcionarios, n, sizeof(Funcionario), compararIdade);

    printf("\nLista de funcionarios apos a ordenacao por idade:\n");
    imprimirFuncionarios(funcionarios, n);

    return 0;
}
