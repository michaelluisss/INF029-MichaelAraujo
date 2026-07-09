#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "trabalho2.h"

PosicaoPrincipal vetorPrincipal[TAM];


/*Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1'*/

int criarEstruturaAuxiliar(int posicao, int tamanho)
{

    int retorno = 0;
    
    
    // o tamanho nao pode ser menor que 1
    if(tamanho < 1){
        
        return TAMANHO_INVALIDO;
    }
        
    // se posição é um valor válido {entre 1 e 10}
    if(posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }
    int indice = posicao - 1;


    // a posicao pode já existir estrutura auxiliar
    if(vetorPrincipal[indice].auxiliar != NULL){
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }
    vetorPrincipal[indice].auxiliar = malloc((size_t)tamanho * sizeof(int));
    // o tamanho ser muito grande / sem memória
    if(vetorPrincipal[indice].auxiliar == NULL){
        return SEM_ESPACO_DE_MEMORIA;
    }

    /* inicializa metadados da estrutura auxiliar */
    vetorPrincipal[indice].tamanhoMax = tamanho;
    vetorPrincipal[indice].qtdatual = 0;

    retorno = SUCESSO;

    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    if(posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }
    
    int indice = posicao - 1;
    
    if(vetorPrincipal[indice].auxiliar == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    
    if(vetorPrincipal[indice].qtdatual >= vetorPrincipal[indice].tamanhoMax){
        return SEM_ESPACO;
    }
    
    vetorPrincipal[indice].auxiliar[vetorPrincipal[indice].qtdatual] = valor;
    vetorPrincipal[indice].qtdatual++;
    
    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
SUCESSO - excluido com sucesso
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    if(posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }
    
    int indice = posicao - 1;
    
    if(vetorPrincipal[indice].auxiliar == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    
    if(vetorPrincipal[indice].qtdatual == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }
    
    vetorPrincipal[indice].qtdatual--;
    
    return SUCESSO;
}
/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    if(posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }
    
    int indice = posicao - 1;
    
    if(vetorPrincipal[indice].auxiliar == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    
    if(vetorPrincipal[indice].qtdatual == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }
    
    int pos = -1;
    int i;
    for(i = 0; i < vetorPrincipal[indice].qtdatual; i++){
        if(vetorPrincipal[indice].auxiliar[i] == valor){
            pos = i;
            break;
        }
    }
    
    if(pos == -1){
        return NUMERO_INEXISTENTE;
    }
    
    for(i = pos; i < vetorPrincipal[indice].qtdatual - 1; i++){
        vetorPrincipal[indice].auxiliar[i] = vetorPrincipal[indice].auxiliar[i + 1];
    }
    
    vetorPrincipal[indice].qtdatual--;
    
    return SUCESSO;
}

// se posição é um valor válido {entre 1 e 10}
/*
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
    retorno = SUCESSO;
    
    return retorno;
}
*/
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    if(posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }
    
    int indice = posicao - 1;
    
    if(vetorPrincipal[indice].auxiliar == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    
    int i;
    for(i = 0; i < vetorPrincipal[indice].qtdatual; i++){
        vetorAux[i] = vetorPrincipal[indice].auxiliar[i];
    }
    
    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    if(posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }
    
    int indice = posicao - 1;
    
    if(vetorPrincipal[indice].auxiliar == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    
    int i, j, temp;
    for(i = 0; i < vetorPrincipal[indice].qtdatual; i++){
        vetorAux[i] = vetorPrincipal[indice].auxiliar[i];
    }
    
    for(i = 0; i < vetorPrincipal[indice].qtdatual - 1; i++){
        for(j = 0; j < vetorPrincipal[indice].qtdatual - i - 1; j++){
            if(vetorAux[j] > vetorAux[j + 1]){
                temp = vetorAux[j];
                vetorAux[j] = vetorAux[j + 1];
                vetorAux[j + 1] = temp;
            }
        }
    }
    
    return SUCESSO;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int totalElementos = 0;
    int indice = 0;
    int i, j;
    
    for(i = 0; i < TAM; i++){
        totalElementos += vetorPrincipal[i].qtdatual;
    }
    
    if(totalElementos == 0){
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    
    for(i = 0; i < TAM; i++){
        for(j = 0; j < vetorPrincipal[i].qtdatual; j++){
            vetorAux[indice] = vetorPrincipal[i].auxiliar[j];
            indice++;
        }
    }
    
    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int totalElementos = 0;
    int indice = 0;
    int i, j, temp;
    
    for(i = 0; i < TAM; i++){
        totalElementos += vetorPrincipal[i].qtdatual;
    }
    
    if(totalElementos == 0){
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    
    for(i = 0; i < TAM; i++){
        for(j = 0; j < vetorPrincipal[i].qtdatual; j++){
            vetorAux[indice] = vetorPrincipal[i].auxiliar[j];
            indice++;
        }
    }
    
    for(i = 0; i < totalElementos - 1; i++){
        for(j = 0; j < totalElementos - i - 1; j++){
            if(vetorAux[j] > vetorAux[j + 1]){
                temp = vetorAux[j];
                vetorAux[j] = vetorAux[j + 1];
                vetorAux[j + 1] = temp;
            }
        }
    }
    
    return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    if(posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }
    
    int indice = posicao - 1;
    
    if(vetorPrincipal[indice].auxiliar == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    
    int tamanhoResultante = vetorPrincipal[indice].tamanhoMax + novoTamanho;
    
    if(tamanhoResultante < 1){
        return NOVO_TAMANHO_INVALIDO;
    }
    
    int *novoAuxiliar = (int *)realloc(vetorPrincipal[indice].auxiliar, (size_t)tamanhoResultante * sizeof(int));
    
    if(novoAuxiliar == NULL){
        return SEM_ESPACO_DE_MEMORIA;
    }
    
    vetorPrincipal[indice].auxiliar = novoAuxiliar;
    vetorPrincipal[indice].tamanhoMax = tamanhoResultante;
    
    if(vetorPrincipal[indice].qtdatual > vetorPrincipal[indice].tamanhoMax){
        vetorPrincipal[indice].qtdatual = vetorPrincipal[indice].tamanhoMax;
    }
    
    return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    if(posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }
    
    int indice = posicao - 1;
    
    if(vetorPrincipal[indice].auxiliar == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    
    if(vetorPrincipal[indice].qtdatual == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }
    
    return vetorPrincipal[indice].qtdatual;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
    int i, j, temElementos = 0;
    No *cabecote = (No *)malloc(sizeof(No));
    No *atual;
    No *novoNo;
    
    if(cabecote == NULL){
        return NULL;
    }
    
    cabecote->prox = NULL;
    atual = cabecote;
    
    for(i = 0; i < TAM; i++){
        for(j = 0; j < vetorPrincipal[i].qtdatual; j++){
            novoNo = (No *)malloc(sizeof(No));
            if(novoNo == NULL){
                return NULL;
            }
            novoNo->conteudo = vetorPrincipal[i].auxiliar[j];
            novoNo->prox = NULL;
            atual->prox = novoNo;
            atual = novoNo;
            temElementos = 1;
        }
    }
    
    if(temElementos == 0){
        free(cabecote);
        return NULL;
    }
    
    return cabecote;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    int indice = 0;
    No *atual;
    
    atual = inicio->prox;
    while(atual != NULL){
        vetorAux[indice] = atual->conteudo;
        indice++;
        atual = atual->prox;
    }
}
/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    No *atual;
    No *temp;
    
    atual = *inicio;
    while(atual != NULL){
        temp = atual;
        atual = atual->prox;
        free(temp);
    }
    
    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
    int i;
    printf("inicializando...");
    for(i = 0; i < TAM;i++){
        vetorPrincipal[i].auxiliar = NULL;
        vetorPrincipal[i].tamanhoMax = 0;
        vetorPrincipal[i].qtdatual = 0;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
    int i;
    for(i = 0; i < TAM; i++){
        if(vetorPrincipal[i].auxiliar != NULL){
            free(vetorPrincipal[i].auxiliar);
            vetorPrincipal[i].auxiliar = NULL;
        }
    }
}

void dobrar(int *x)
{
    *x = *x * 2;
}
