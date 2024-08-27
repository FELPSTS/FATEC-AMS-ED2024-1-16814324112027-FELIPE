/*--------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados            */
/*                         Prof Veríssimo                                   */
/*             Objetivo: Exercícios envolvendo ponteiros e arrays           */
/*             Paradigama: Programação Modular                              */
/*                                                                          */
/*                                                          Data:18/03/2024 */
/*--------------------------------------------------------------------------*/
#include <stdio.h>

int main() {
  int tamanho = 5;
  float Nota[tamanho];
  float *p = Nota;

  printf("Insira 5 Notas:\n");

  for (int i = 0; i < tamanho; ++i) {
    printf("Nota %d: ", i + 1);
    scanf("%f", p); 
    p++; 
  }
  p = Nota; 

  printf("\nAs Notas inseridas são: \n");
  for (int i = 0; i < tamanho; ++i) {
    printf("%f ", *p);
    p++; 
  }

  return 0;
}
