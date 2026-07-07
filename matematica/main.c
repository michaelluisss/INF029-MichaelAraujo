#include <stdio.h>
#include "matematica.h"

int main() {
   int n1 = 2, n2 = 3;

   int rSomar = somar(n1,n2);
   int rPotencia = calcularPotencia(n1, n2);
   int rFatorial = fatorial(n1);


   printf("\tprimeiro numero = %d\tSegundo numero = %d\n",n1,n2);
   printf("resultado da soma = %d\n",rSomar);
   printf("resultado da potencia = %d\n",rPotencia);
   printf("resutado do fatorial 1 = %d\n",rFatorial);


   int meuXP = 100;
   subirDeNivel(&meuXP);
   printf("\n meu xp:%d\n",meuXP);
   return 0;
}