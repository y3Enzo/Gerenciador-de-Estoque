#ifndef ESTOQUE_H
#define ESTOQUE_H

#define TAM 50
#define idTAM 20
#define nomeTAM 100
#define marcaTAM 100

struct dadosEstoque{
    char id[idTAM];
    char nome[nomeTAM];
    char marca[marcaTAM];
    float preco;
};

typedef struct dadosEstoque dadosEstoque;

int buscarId(FILE *arquivo, char *idBuscado);
void limparBuffer();
void adicionarProduto();
void removerProduto();
void editarProduto();
void listarProdutos();

#endif