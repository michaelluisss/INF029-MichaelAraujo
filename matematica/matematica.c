#include "matematica.h"

int somar(int a, int b){
    return a + b;
}

int calcularPotencia(int base, int expoente){
    int resultado =1;
    for(int i=0;i< expoente;i++){
        resultado*= base;
    }
    return resultado;
}

int fatorial(int n){
    int resultado = 1;
    for(int i = n; i > 0;i--){
        resultado*= i;
    }
    return resultado;
}

void subirDeNivel(int *xpAtual){
    *xpAtual = *xpAtual + 500;
}