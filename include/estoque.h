#ifndef ESTOQUE_H
#define ESTOQUE_H

#define TAM 50

struct dadosEstoque{
    int id;
    char nome[100];
    char marca[100];
    float preco;
};

typedef struct dadosEstoque dadosEstoque;

void limparBuffer();
void adicionarProduto();
void removerProduto();
void editarProduto();
void listarProdutos();

#endif