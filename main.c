#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "include/estoque.h"

int main(){
    int opcao = 0;
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    while (opcao != 5){
        printf("\n----- Sistema de Gerenciamento de Estoque -----\n");
        printf("  [1] Adicionar Produto                          \n");
        printf("  [2] Remover Produto                            \n");
        printf("  [3] Editar Produto                             \n");
        printf("  [4] Listar Produtos                            \n");
        printf("  [5] Encerrar Programa                          \n\n");
        printf("  Selecione uma opção por seu respectivo número: ");
        scanf("%d", &opcao);
        limparBuffer();
        
        switch (opcao){
            case 1:
                adicionarProduto();
                break;
            case 2:
                removerProduto();
                break;
            case 3:
                editarProduto();
                break;
            case 4:
                listarProdutos();
                break;
            case 5:
                printf("----- Programa finalizado! ------\n\n");
                break;
            default:
                printf("    Opção inválida! Tente novamente.\n");
                break;
        }
    }
    
    return 0;
}