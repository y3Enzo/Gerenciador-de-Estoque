#ifndef ESTOQUE_H
#define ESTOQUE_H

#define TAM 50
#define nomeTAM 100
#define marcaTAM 100

struct dadosEstoque{
    int id;
    char nome[nomeTAM];
    char marca[marcaTAM];
    float preco;
};

typedef struct dadosEstoque dadosEstoque;

void limparBuffer();
void adicionarProduto();
void removerProduto();
void editarProduto();
void listarProdutos();

#endif