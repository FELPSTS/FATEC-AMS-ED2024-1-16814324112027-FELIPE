#include <stdio.h>

void calcularDES(int *preco,int *desconto,float *valorfinal){
  
  *valorfinal = *preco - (*preco * *desconto/100.0);
}

int preco;
int desconto;
float valorfinal;

int main(void) {
  printf("digite o preço \n");
  scanf("%d", &preco);

  printf("digite o desconto \n");
  scanf("%d", &desconto);

  calcularDES(&preco, &desconto, &valorfinal);
  
  printf("preco%d\n deconto aplicado: %d%%\n  e valor final: %.2f", preco,desconto, valorfinal);

  return 0;
}
