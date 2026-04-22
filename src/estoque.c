#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "../include/estoque.h"

void limparBuffer(){
    int buffer;
    while((buffer = getchar()) != '\n' && buffer != EOF);
}

void adicionarProduto(){
    dadosEstoque produto[TAM];
    FILE *arquivo;
    arquivo = fopen("estoque.txt", "a");

    if (arquivo == NULL){
        printf("Erro ao abrir arquivo!\n");
    }
    
    printf("\n----- Adição de produto -----\n");
    
    printf("  Id do produto: ");
    scanf("%d", &produto->id);
    fprintf(arquivo, "%d;", produto->id);
    limparBuffer();
    
    printf("  Produto: ");
    scanf("%99[^\n]", produto->nome);
    fprintf(arquivo, "%s;", produto->nome);
    limparBuffer();
    
    printf("  Marca do produto: ");
    scanf("%99[^\n]", produto->marca);
    fprintf(arquivo, "%s;", produto->marca);
    limparBuffer();
    
    printf("  Preço do produto: R$ ");
    scanf("%f", &produto->preco);
    fprintf(arquivo, "%.2f;\n", produto->preco);
    limparBuffer();
    
    printf("\nProduto adicionado com sucesso!\n");
    
    fclose(arquivo);
    
}

void removerProduto(){
    FILE *arquivoOriginal, *arquivoEdit;
    char linha[100] = {'\0'}, idParaExcluir[20] = {'\0'};
    arquivoOriginal = fopen("estoque.txt", "r");
    arquivoEdit = fopen("estoque(1).txt", "w");
    
    printf("  Escreva o id do produto a ser removido: ");
    scanf(" %s", idParaExcluir);
    limparBuffer();
    while (fgets(linha, sizeof(linha), arquivoOriginal) != NULL){
        char id[20] = {'\0'};
        for (int coluna = 0; coluna < 20; coluna++){
            if (linha[coluna] != ';'){
                id[coluna] = linha[coluna];
            } else {
                id[coluna] = '\0';
                break;
            }
        }
        if (strcmp(id, idParaExcluir) != 0){
            fprintf(arquivoEdit, "%s", linha);
        }   
    }

    fclose(arquivoEdit);
    fclose(arquivoOriginal);

    remove("estoque.txt");
    rename("estoque(1).txt", "estoque.txt");
}

void editarProduto(){
    FILE *arquivoOriginal, *arquivoEdit;
    char linha[100] = {'\0'}, idParaEditar[20] = {'\0'}, novoId[20] = {'\0'};
    char novoProduto[nomeTAM] = {'\0'}, novaMarca[marcaTAM] = {'\0'}, novoPreco[10] = {'\0'};
    arquivoOriginal = fopen("estoque.txt", "r");
    arquivoEdit = fopen("estoque(2).txt", "w");

    printf("\n----- Edição de Produto -----\n");
    printf("    Escreva o id do produto a ser editado: ");
    scanf(" %s", idParaEditar);
    limparBuffer();

    while(fgets(linha, sizeof(linha), arquivoOriginal)){
        char id[20] = {'\0'};

        for (int index = 0; index < 20; index++){
            if (linha[index] != ';'){
                id[index] = linha[index];
            } else {
                break;
            }
        }

        if (strcmp(id, idParaEditar) != 0){
            fprintf(arquivoEdit, "%s", linha);
        } else {
            printf("    Id do produto (id antigo: %s): ", idParaEditar);
            scanf(" %s", novoId);
            fprintf(arquivoEdit, "%s;", novoId);

            printf("    Produto: ");
            scanf(" %s", novoProduto);
            fprintf(arquivoEdit, "%s;", novoProduto);

            printf("    Marca: ");
            scanf(" %s", novaMarca);
            fprintf(arquivoEdit, "%s;", novaMarca);

            printf("    Preço: ");
            scanf(" %s", novoPreco);
            fprintf(arquivoEdit, "%s;\n", novaMarca);
        
            printf("\nProduto editado com sucesso!\n");
        }
    }

    fclose(arquivoEdit);
    fclose(arquivoOriginal);

    remove("estoque.txt");
    rename("estoque(2).txt", "estoque.txt");
}

void listarProdutos(){
    FILE *arquivo;
    arquivo = fopen("estoque.txt", "r");
    char linha[100] = {'\0'};

    if (arquivo == NULL){
        printf("Erro ao ler arquivo!\n");
    }

    printf("\n----- Lista de Produtos -----\n");

    while (fgets(linha, sizeof(linha), arquivo) != NULL){
        int item = 0, index = 0;
        char id[20] = {'\0'}, produto[nomeTAM] = {'\0'}, marca[marcaTAM] = {'\0'}, preco[10] = {'\0'};
        int idIndex = 0, produtoIndex = 0, marcaIndex = 0;
        int precoIndex = 0;
        
        while ((linha[index] != '\0') && (linha[index] != '\n')){
            if (linha[index] == ';'){
                item++;
            } else {
                switch(item){
                    case 0: id[idIndex] = linha[index]; idIndex++; break;
                    case 1: produto[produtoIndex] = linha[index]; produtoIndex++; break;
                    case 2: marca[marcaIndex] = linha[index]; marcaIndex++; break;
                    case 3: preco[precoIndex] = linha[index]; precoIndex++; break;
                    default: break;
                }
            }
            index++;
        }
        idIndex = 0, produtoIndex = 0, marcaIndex = 0;
        precoIndex=0, index = 0, item = 0;
        printf("  Id: %s\n", id);
        printf("  Produto: %s\n", produto);
        printf("  Marca: %s\n", marca);
        printf("  Preço: %s\n\n", preco);
    }

    fclose(arquivo);
}     