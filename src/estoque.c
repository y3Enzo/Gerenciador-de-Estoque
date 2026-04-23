#include <stdio.h>
#include <string.h>
#include "../include/estoque.h"

void limparBuffer(){
    int buffer;
    while((buffer = getchar()) != '\n' && buffer != EOF);
}

int buscarId(FILE *arquivo, char *idBuscado){ // Retorna quantas vezes existe o id na lista
    char linha[100] = {'\0'};
    int validacao = 0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL){
        char id[20] = {'\0'};

        for (int coluna = 0; coluna < 20; coluna++){
            if (linha[coluna] != ';'){
                id[coluna] = linha[coluna];
            } else {
                id[coluna] = '\0';
                break;
            }
        }
        printf("%s x %s\n", id, idBuscado);
        if (strcmp(id, idBuscado) == 0){
            validacao++;
        }
    }
    printf("%d\n", validacao);
    rewind(arquivo);
    return validacao;
}

void adicionarProduto(){
    FILE *arquivo = fopen("estoque.txt", "a");
    FILE *arquivoLeitura = fopen("estoque.txt", "r");
    dadosEstoque produto[TAM];
    char idBuscado[20] = {'\0'};

    printf("\n----- Adição de produto -----\n");
    
    while (1){
        printf("  Id do produto: ");
        scanf(" %19[^\n]s", idBuscado);
        limparBuffer();
        if (buscarId(arquivoLeitura, idBuscado) != 0){
            printf("    O id digitado já está registrado em outro produto! Tente novamente.\n");
        } else {
            break;
        }
    }
    fprintf(arquivo, "%s;", produto->id);
    
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
    fclose(arquivoLeitura);
}

void removerProduto(){
    FILE *arquivoOriginal = fopen("estoque.txt", "r");

    if (arquivoOriginal == NULL){
        printf("Erro: arquivo de dados inexistente.\n");
    }

    FILE *arquivoEdit = fopen("estoque(1).txt", "w");
    char linha[100] = {'\0'};
    char idParaExcluir[20] = {'\0'};

    printf("  Escreva o id do produto a ser removido: ");
    scanf(" %19[^\n]s", idParaExcluir);
    limparBuffer();

    if (buscarId(arquivoOriginal, idParaExcluir) != 0){
        fprintf(arquivoEdit, "%s", linha);
    }

    fclose(arquivoEdit);
    fclose(arquivoOriginal);

    remove("estoque.txt");
    rename("estoque(1).txt", "estoque.txt");
}

void editarProduto(){
    FILE *arquivoOriginal = fopen("estoque.txt", "r");

    if (arquivoOriginal == NULL){
        printf("Erro: arquivo de dados inexistente.\n");
    }

    FILE *arquivoEdit = fopen("estoque(2).txt", "w");

    char linha[100] = {'\0'};
    char idParaEditar[20] = {'\0'};
    char novoId[20] = {'\0'};
    char novoProduto[nomeTAM] = {'\0'};
    char novaMarca[marcaTAM] = {'\0'};
    char novoPreco[10] = {'\0'};

    printf("\n----- Edição de Produto -----\n");
    printf("    Escreva o id do produto a ser editado: ");
    scanf(" %19[^\n]s", idParaEditar);
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
            scanf(" %19[^\n]s", novoId);
            fprintf(arquivoEdit, "%s;", novoId);

            printf("    Produto: ");
            scanf(" %99[^\n]s", novoProduto);
            fprintf(arquivoEdit, "%s;", novoProduto);

            printf("    Marca: ");
            scanf(" %99[^\n]s", novaMarca);
            fprintf(arquivoEdit, "%s;", novaMarca);

            printf("    Preço: ");
            scanf(" %9[^\n]s", novoPreco);
            fprintf(arquivoEdit, "%s;\n", novoPreco);
        
            printf("\nProduto editado com sucesso!\n");
        }
    }

    fclose(arquivoEdit);
    fclose(arquivoOriginal);

    remove("estoque.txt");
    rename("estoque(2).txt", "estoque.txt");
}

void listarProdutos(){
    FILE *arquivo = fopen("estoque.txt", "r");

    if (arquivo == NULL){
        printf("Erro: arquivo de dados inexistente.\n");
    }

    char linha[100] = {'\0'};

    printf("\n----- Lista de Produtos -----\n");

    while (fgets(linha, sizeof(linha), arquivo) != NULL){
        char id[20] = {'\0'};
        char produto[nomeTAM] = {'\0'};
        char marca[marcaTAM] = {'\0'};
        char preco[10] = {'\0'};
        int item = 0;
        int index = 0;
        int idIndex = 0;
        int produtoIndex = 0;
        int marcaIndex = 0;
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
        idIndex = 0;
        produtoIndex = 0;
        marcaIndex = 0;
        precoIndex=0;
        index = 0;
        item = 0;

        printf("  Id: %s\n", id);
        printf("  Produto: %s\n", produto);
        printf("  Marca: %s\n", marca);
        printf("  Preço: %s\n\n", preco);
    }

    fclose(arquivo);
}     