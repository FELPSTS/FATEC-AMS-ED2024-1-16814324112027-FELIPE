#include <stdio.h>

int main() {
  int tamanho = 5;
  int Numeros[tamanho];
  int *p = Numeros;

  printf("Insira 5 números:\n");

  for (int i = 0; i < tamanho; ++i) {
    printf("Número %d: ", i + 1);
    scanf("%d", p); 
    p++; 
  }
  p = Numeros; 

  printf("\nOs números inseridos são: \n");
  for (int i = 0; i < tamanho; ++i) {
    printf("%d ", *p);
    p++; 
  }

  return 0;
}