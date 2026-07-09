#include <stdio.h>
#include <stdlib.h>

#include "trabalho2.h"

int menu();

int menu()
{
    int op;
    printf("\n======================================\n");
    printf("Digite a opcao desejada\n");
    printf("0 - Sair\n");
    printf("1 - Inserir numero\n");
    printf("2 - Excluir numero\n");
    printf("3 - Listar estrutura auxiliar\n");
    printf("4 - Listar todas as estruturas\n");
    printf("5 - Listar ordenado (estrutura auxiliar)\n");
    printf("6 - Listar todos ordenados\n");
    printf("7 - Aumentar tamanho de estrutura\n");
    printf("8 - Dobrar numero\n");
    printf("======================================\n");
    scanf("%d", &op);
    return op;
}
    
int main()
{
    inicializar();
    int op;
    int sair = 0;
    int ret;
    int posicao, valor, tamanho, novoTamanho;
    int i;
    
    while (!sair)
    {
        op = menu();
        switch (op)
        {
        
        case 0:
        {
            sair = 1;
            finalizar();
            printf("Programa finalizado!\n");
            break;
        }
        case 1:
        { 
            printf("Qual a posicao (1-10)? ");
            scanf("%d", &posicao);
            
            if(posicao < 1 || posicao > 10){
                printf("Posicao invalida!\n");
                break;
            }
            
            ret = getQuantidadeElementosEstruturaAuxiliar(posicao);
            
            if(ret == SEM_ESTRUTURA_AUXILIAR || ret == ESTRUTURA_AUXILIAR_VAZIA){
                printf("Qual o tamanho da estrutura? ");
                scanf("%d", &tamanho);
                
                ret = criarEstruturaAuxiliar(posicao, tamanho);
                if(ret != SUCESSO){
                    printf("Erro ao criar estrutura!\n");
                    break;
                }
            }
            
            printf("Digite o numero a inserir: ");
            scanf("%d", &valor);
            
            ret = inserirNumeroEmEstrutura(posicao, valor);
            
            if (ret == SUCESSO){
                printf("Inserido com sucesso!\n");
            }
            else if (ret == SEM_ESPACO){
                printf("Sem espaco na estrutura!\n");
            }
            else if (ret == SEM_ESTRUTURA_AUXILIAR){
                printf("Sem estrutura auxiliar!\n");
            }
            else if (ret == POSICAO_INVALIDA){
                printf("Posicao invalida!\n");
            }
            break;
        }
        case 2:
        {
            printf("Qual a posicao (1-10)? ");
            scanf("%d", &posicao);
            
            printf("Digite o numero a excluir: ");
            scanf("%d", &valor);
            
            ret = excluirNumeroEspecificoDeEstrutura(posicao, valor);
            
            if(ret == SUCESSO){
                printf("Excluido com sucesso!\n");
            }
            else if(ret == NUMERO_INEXISTENTE){
                printf("Numero nao encontrado!\n");
            }
            else if(ret == ESTRUTURA_AUXILIAR_VAZIA){
                printf("Estrutura vazia!\n");
            }
            else if(ret == SEM_ESTRUTURA_AUXILIAR){
                printf("Sem estrutura auxiliar!\n");
            }
            else if(ret == POSICAO_INVALIDA){
                printf("Posicao invalida!\n");
            }
            break;
        }

        case 3:
        {
            printf("Qual a estrutura a ser listada (1-10)? ");
            scanf("%d", &posicao);

            int qtd = getQuantidadeElementosEstruturaAuxiliar(posicao);

            if (qtd == POSICAO_INVALIDA){
                printf("Posicao invalida!\n");
            }
            else if(qtd == SEM_ESTRUTURA_AUXILIAR){
                printf("Sem estrutura auxiliar!\n");
            }
            else if(qtd == ESTRUTURA_AUXILIAR_VAZIA){
                printf("Estrutura auxiliar vazia!\n");
            }
            else {
                int vetorAux[100];
                ret = getDadosEstruturaAuxiliar(posicao, vetorAux);

                if (ret == SUCESSO){
                    printf("Elementos da estrutura %d: ", posicao);
                    for (i = 0; i < qtd; i++){
                        printf("%d ", vetorAux[i]);
                    }
                    printf("\n");
                }
            }
            break;
        }

        case 4:
        {
            int vetorAux[100];
            ret = getDadosDeTodasEstruturasAuxiliares(vetorAux);
            
            if(ret == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS){
                printf("Todas as estruturas estao vazias!\n");
            }
            else if(ret == SUCESSO){
                int totalElementos = 0;
                for(i = 0; i < 10; i++){
                    totalElementos += getQuantidadeElementosEstruturaAuxiliar(i + 1);
                    if(getQuantidadeElementosEstruturaAuxiliar(i + 1) > 0 && 
                       getQuantidadeElementosEstruturaAuxiliar(i + 1) != ESTRUTURA_AUXILIAR_VAZIA &&
                       getQuantidadeElementosEstruturaAuxiliar(i + 1) != SEM_ESTRUTURA_AUXILIAR){
                        totalElementos++;
                    }
                }
                printf("Todos os elementos: ");
                for(i = 0; i < 100 && vetorAux[i] != 0; i++){
                    printf("%d ", vetorAux[i]);
                }
                printf("\n");
            }
            break;
        }

        case 5:
        {
            printf("Qual a estrutura (1-10)? ");
            scanf("%d", &posicao);

            int qtd = getQuantidadeElementosEstruturaAuxiliar(posicao);

            if (qtd == POSICAO_INVALIDA){
                printf("Posicao invalida!\n");
            }
            else if(qtd == SEM_ESTRUTURA_AUXILIAR){
                printf("Sem estrutura auxiliar!\n");
            }
            else if(qtd == ESTRUTURA_AUXILIAR_VAZIA){
                printf("Estrutura auxiliar vazia!\n");
            }
            else {
                int vetorAux[100];
                ret = getDadosOrdenadosEstruturaAuxiliar(posicao, vetorAux);

                if (ret == SUCESSO){
                    printf("Elementos ordenados da estrutura %d: ", posicao);
                    for (i = 0; i < qtd; i++){
                        printf("%d ", vetorAux[i]);
                    }
                    printf("\n");
                }
            }
            break;
        }

        case 6:
        {
            int vetorAux[100];
            ret = getDadosOrdenadosDeTodasEstruturasAuxiliares(vetorAux);
            
            if(ret == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS){
                printf("Todas as estruturas estao vazias!\n");
            }
            else if(ret == SUCESSO){
                printf("Todos os elementos ordenados: ");
                for(i = 0; i < 100 && vetorAux[i] != 0; i++){
                    printf("%d ", vetorAux[i]);
                }
                printf("\n");
            }
            break;
        }

        case 7:
        {
            printf("Qual a estrutura (1-10)? ");
            scanf("%d", &posicao);
            
            printf("Quantas posicoes extras? ");
            scanf("%d", &novoTamanho);
            
            ret = modificarTamanhoEstruturaAuxiliar(posicao, novoTamanho);
            
            if(ret == SUCESSO){
                printf("Tamanho modificado com sucesso!\n");
            }
            else if(ret == SEM_ESTRUTURA_AUXILIAR){
                printf("Sem estrutura auxiliar!\n");
            }
            else if(ret == POSICAO_INVALIDA){
                printf("Posicao invalida!\n");
            }
            else if(ret == NOVO_TAMANHO_INVALIDO){
                printf("Novo tamanho invalido!\n");
            }
            else if(ret == SEM_ESPACO_DE_MEMORIA){
                printf("Sem espaco de memoria!\n");
            }
            break;
        }

        case 8:
        {
            int numero;
            printf("Digite um numero para dobrar: ");
            scanf("%d", &numero);
            
            dobrar(&numero);
            
            printf("Numero dobrado: %d\n", numero);
            break;
        }

        default:
        {
            printf("Opcao invalida!\n");
        }
        }
    }

    return 0;
}
