#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Criação ou definição da estrutura de uma lista
struct produto {
  char produto[25];
  char mercado[30];
  float valor;
  struct produto* ant;
  struct produto* prox;
};

typedef struct produto Pesquisa;

// Inicialização da lista
Pesquisa* inicializar (void) {
    return NULL;
}

struct registro{ 
  char produto[25];
  char mercado[30];
  float valor;
};

// Inserção de itens no inicio
Pesquisa* inserir (Pesquisa* l, struct registro r) {
  Pesquisa* novo = (Pesquisa*) malloc(sizeof(Pesquisa));
  strcpy(novo -> produto, r.produto);
  strcpy(novo -> mercado, r.mercado);
  novo -> valor = r.valor;
  novo -> prox = l;
  novo -> ant = NULL;
  if (l != NULL)
    l -> ant = novo;
  return novo;
}

void ordenar (Pesquisa* l){
  Pesquisa* p;
  Pesquisa* aux;
  struct registro temp;
  for (p = l; p != NULL; p = p -> prox) {
    for (aux = p -> prox; aux != NULL; aux = aux -> prox) {
      if ((p -> produto) > (aux -> produto)) {
        strcpy(temp.produto, p -> produto);
        strcpy(temp.mercado, p -> mercado);
        temp.valor = p -> valor;
        strcpy(p -> produto, aux -> produto);
        strcpy(p -> mercado, aux -> mercado);
        p -> valor = aux -> valor;
        strcpy(aux -> produto, temp.produto);
        strcpy(aux -> mercado, temp.mercado);
        aux -> valor = temp.valor;
      }
    }
  }
}

// Impressão da lista
void imprimir (Pesquisa* l, int ordem) {
  Pesquisa* p;
  printf("Elementos:\n");
  if(ordem == 0)
    for (p = l; p != NULL; p = p -> prox)
      printf(" %s -> ", p -> produto);
  else
    if(ordem == 1){
      for (p = l; p -> prox != NULL; p = p -> prox);
      for (l = p; l != NULL; l = l -> ant)
        printf(" %s -> ", l -> produto);
    }
  printf("NULL\n");
}

int main(void) {
  struct registro registroProduto;
  int ordem;

  // Criação ou definição da estrutura de uma lista
  printf("Criando Lista... \n");
  Pesquisa* lista;
  printf("Lista criada com sucesso \n");

  // Inicialização da lista
  printf("Inicializando Lista... \n");
  lista = inicializar();
  printf("Lista inicializada com sucesso \n");

  // Inserção de itens no inicio
  printf("Inserindo no inicio... \n");
  printf("-> Informe o nome do produto: ");
  fflush(stdin);
  scanf("%s",registroProduto.produto);
  printf("-> Informe o nome do mercado: ");
  fflush(stdin);
  scanf("%s",registroProduto.mercado);
  printf("-> Informe o valor do produto: ");
  fflush(stdin);
  scanf("%f",&registroProduto.valor);
  lista = inserir(lista, registroProduto);
  printf("Item inserido com sucesso \n");

  // Dados de teste
  printf("Inserindo dados de teste... \n");
  strcpy(registroProduto.produto, "p8");
  strcpy(registroProduto.mercado, "m8");
  registroProduto.valor = 8;
  lista = inserir(lista, registroProduto);
  strcpy(registroProduto.produto, "p9");
  strcpy(registroProduto.mercado, "m9");
  registroProduto.valor = 9;
  lista = inserir(lista, registroProduto);
  printf("dados de teste inseridos com sucesso \n");

  // Ordenação de itens de maneira crescente
  printf("Ordenando de itens... \n");
  ordenar(lista);
  printf("Lista ordenada com sucesso \n");

  // Impressão da lista
  printf("Imprimindo a lista. \n");
  printf("-> Informe a ordem dos itens (0-Crescente ou 1-Decrescente)? ");
  fflush(stdin);
  scanf("%d",&ordem);
  imprimir(lista, ordem);
  printf("Lista impressa com sucesso \n");
  
  return 0;
}