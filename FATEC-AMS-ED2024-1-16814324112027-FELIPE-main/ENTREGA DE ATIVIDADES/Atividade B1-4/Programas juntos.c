#include <stdio.h>
#include <stdlib.h>

struct lista {
  int info;
  struct lista *prox;
};

/* -------------------------------------------------------*
 * FATEC-São Caetano do Sul Estrutura de Dados     *
 *                                     Avaliação N1 - Parte I       *
 * Objetivo: Controlar Estoque de produtos            *
 *                                                                              *
 * Autores: <nomes que compõem a dupla>          *
 *                                                   Data:02/04/2024*
 *------------------------------------------------------*
 */

typedef struct lista Lista;

Lista *lst_cria(void) { return NULL; }

Lista *lst_insere(Lista *l, int i) {
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  if (novo == NULL) {
    printf("Erro: impossível alocar memória\n");
    exit(1);
  }
  novo->info = i;
  novo->prox = l;
  return novo;
}

void lst_imprime(Lista *l) {
  printf("Valores na lista:\n");
  for (Lista *p = l; p != NULL; p = p->prox)
    printf("%d\n", p->info);
}

void lst_libera(Lista *l) {
  Lista *p = l;
  while (p != NULL) {
    Lista *t = p->prox;
    free(p);
    p = t;
  }
}

void lst_deleta(Lista **l, int v) {
  Lista *ant = NULL;
  Lista *p = *l;
  while (p != NULL && p->info != v) {
    ant = p;
    p = p->prox;
  }
  if (p == NULL) {
    printf("Elemento não encontrado para deletar: %d\n", v);
    return;
  }
  if (ant == NULL) {
    *l = p->prox;
  } else {
    ant->prox = p->prox;
  }
  free(p);
}

int lst_busca(Lista *l, int v) {
  for (Lista *p = l; p != NULL; p = p->prox) {
    if (p->info == v) {
      printf("Encontrou: %d\n", v);
      return 1;
    }
  }
  printf("Não encontrou: %d\n", v);
  return 0;
}

int main(void) {
  Lista *l = lst_cria();
  int choice, num;

  do {
    printf("\nMenu:\n");
    printf("1. Inserir número\n");
    printf("2. Deletar número\n");
    printf("3. Buscar número\n");
    printf("4. Imprimir lista\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Digite o número a ser inserido: ");
      scanf("%d", &num);
      l = lst_insere(l, num);
      break;
    case 2:
      printf("Digite o número a ser deletado: ");
      scanf("%d", &num);
      lst_deleta(&l, num);
      break;
    case 3:
      printf("Digite o número a ser buscado: ");
      scanf("%d", &num);
      lst_busca(l, num);
      break;
    case 4:
      lst_imprime(l);
      break;
    case 0:
      printf("Encerrando o programa...\n");
      break;
    default:
      printf("Opção inválida! Tente novamente.\n");
    }
  } while (choice != 0);

  lst_libera(l);

  return 0;
}
