#include <stdio.h>
#include <locale.h>
#include <string.h>

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
    dadosEstoque produto[TAM];
    FILE *arquivoOriginal, *arquivoEdit;
    char linha[100] = {'\0'}, idParaExcluir[20] = {'\0'};
    arquivoOriginal = fopen("estoque.txt", "r");
    arquivoEdit = fopen("estoque(1).txt", "w");
    
    printf("Escreva o id do produto a ser removido: ");
    scanf(" %s", idParaExcluir);
    limparBuffer();
    while (fgets(linha, sizeof(linha), arquivoOriginal) != NULL){
        char id[20] = {'\0'};
        int coluna = 0;
        for (coluna; coluna < sizeof(id); coluna++){
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

    remove("estoque.txt");
    rename("estoque(1).txt", "estoque.txt");
}

void editarProduto(){}

void listarProdutos(){
    dadosEstoque produto[TAM];
    FILE *arquivo;
    arquivo = fopen("estoque.txt", "r");
    char linha[100];
    if (arquivo == NULL){
        printf("Erro ao ler arquivo!\n");
    }

    printf("\n----- Lista de Produtos -----\n");

    while (fgets(linha, sizeof(linha), arquivo) != NULL){
        int coluna = 0;

        printf("Id: ");
        for (coluna; coluna < sizeof(linha); coluna++){
            if ((linha[coluna] != ';') && (linha[coluna] != '\n')){
                printf("%c\n", linha[coluna]);
            }
        }
    }
}