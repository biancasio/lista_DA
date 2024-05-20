#include <stdio.h>
#include <string.h>

// Definição da estrutura Produto
typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

// Função para cadastrar um produto
void cadastrarProduto(Produto *p) {
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", p->nome);
    printf("Digite o preco do produto: ");
    scanf("%f", &p->preco);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &p->quantidade);
}

// Função para exibir as informações de um produto
void exibirProduto(Produto p) {
    printf("Nome: %s\n", p.nome);
    printf("Preco: %.2f\n", p.preco);
    printf("Quantidade em estoque: %d\n", p.quantidade);
}

// Função para calcular o valor total em estoque de um produto
float calcularValorEstoque(Produto p) {
    return p.preco * p.quantidade;
}

int main() {
    int n, i;
    float valorTotalEstoque = 0.0;

    printf("Digite o numero de produtos: ");
    scanf("%d", &n);

    Produto produtos[n];

    // Cadastra os produtos
    for(i = 0; i < n; i++) {
        printf("\nCadastro do produto %d:\n", i + 1);
        cadastrarProduto(&produtos[i]);
    }

    // Exibe os produtos e calcula o valor total em estoque
    printf("\nInformacoes dos produtos cadastrados:\n");
    for(i = 0; i < n; i++) {
        printf("\nProduto %d:\n", i + 1);
        exibirProduto(produtos[i]);
        valorTotalEstoque += calcularValorEstoque(produtos[i]);
    }

    printf("\nValor total em estoque: %.2f\n", valorTotalEstoque);

    return 0;
}
