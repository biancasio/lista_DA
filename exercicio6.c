#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Funcionario
typedef struct {
    char nome[50];
    int idade;
    float salario;
} Funcionario;

// Função para adicionar um novo registro de funcionário
void adicionarFuncionario(FILE *file) {
    Funcionario funcionario;

    printf("Digite o nome do funcionario: ");
    scanf(" %[^\n]", funcionario.nome);
    printf("Digite a idade do funcionario: ");
    scanf("%d", &funcionario.idade);
    printf("Digite o salario do funcionario: ");
    scanf("%f", &funcionario.salario);

    fseek(file, 0, SEEK_END);
    fwrite(&funcionario, sizeof(Funcionario), 1, file);

    printf("Funcionario adicionado com sucesso!\n");
}

// Função para listar todos os registros de funcionários
void listarFuncionarios(FILE *file) {
    Funcionario funcionario;
    rewind(file);

    printf("\nLista de Funcionarios:\n");
    printf("Nome\t\tIdade\tSalario\n");
    printf("-----------------------------------\n");

    while (fread(&funcionario, sizeof(Funcionario), 1, file) == 1) {
        printf("%s\t\t%d\t%.2f\n", funcionario.nome, funcionario.idade, funcionario.salario);
    }
}

// Função para buscar um funcionário pelo nome
void buscarFuncionario(FILE *file) {
    char nome[50];
    Funcionario funcionario;
    int encontrado = 0;

    printf("Digite o nome do funcionario que deseja buscar: ");
    scanf(" %[^\n]", nome);

    rewind(file);

    while (fread(&funcionario, sizeof(Funcionario), 1, file) == 1) {
        if (strcmp(funcionario.nome, nome) == 0) {
            printf("\nFuncionario encontrado:\n");
            printf("Nome: %s\n", funcionario.nome);
            printf("Idade: %d\n", funcionario.idade);
            printf("Salario: %.2f\n", funcionario.salario);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Funcionario nao encontrado.\n");
    }
}

int main() {
    FILE *file;
    int escolha;

    file = fopen("funcionarios.bin", "rb+");
    if (file == NULL) {
        file = fopen("funcionarios.bin", "wb+");
        if (file == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }
    }

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar Funcionario\n");
        printf("2. Listar Funcionarios\n");
        printf("3. Buscar Funcionario\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                adicionarFuncionario(file);
                break;
            case 2:
                listarFuncionarios(file);
                break;
            case 3:
                buscarFuncionario(file);
                break;
            case 4:
                fclose(file);
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (escolha != 4);

    return 0;
}
