#include <stdio.h>

int preco;
int desconto;
float valorfinal;

int main(void) {
  printf("digite o preço \n");
  scanf("%d", &preco);

  printf("digite o desconto \n");
  scanf("%d", &desconto);
  
  valorfinal = preco -(preco * desconto/100.0);
  
  printf("preco%d\n deconto aplicado: %d%%\n  e valor final: %.2f", preco,desconto, valorfinal);

  return 0;
}