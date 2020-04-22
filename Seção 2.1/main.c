#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodoLivro {
  char titulo[20];
  struct nodoLivro* ant;
  struct nodoLivro* prox;
};

typedef struct nodoLivro NodoLivro;

NodoLivro* inicializar (void) {
    return NULL;
}

NodoLivro* inserir (NodoLivro* l, char v[20]) {
  NodoLivro* novo = (NodoLivro*) malloc(sizeof(NodoLivro));
  strcpy(novo -> titulo, v);
  novo -> prox = l;
  novo -> ant = NULL;
  if (l != NULL)
    l -> ant = novo;
  return novo;
}

void ordenar (NodoLivro* l){
  NodoLivro* p;
  NodoLivro* aux;
  char v[20];
  for (p = l; p != NULL; p = p -> prox) {
    for (aux = p -> prox; aux != NULL; aux = aux -> prox) {
      if ( strcmp(p -> titulo, aux -> titulo) == 1 ) {
        strcpy(v, p -> titulo);
        strcpy(p -> titulo, aux -> titulo);
        strcpy(aux -> titulo, v);
      }
    }
  }
}

void imprimir (NodoLivro* l, int ordem) {
  NodoLivro* p;
  printf("Elementos:\n");
  if(ordem == 0)
    for (p = l; p != NULL; p = p -> prox)
      printf(" %s -> ", p -> titulo);
  else
    if(ordem == 1){
      for (p = l; p -> prox != NULL; p = p -> prox);
      for (l = p; l != NULL; l = l -> ant)
        printf(" %s -> ", l -> titulo);
    }
  printf("NULL\n");
}

int main(void) {
  int opcao;
  char titulo[20];
  NodoLivro* lista;

  lista = inicializar();

  do{
    printf("============================== \n");
    printf("MENU \n");
    printf("---- \n");
    printf("1 - Remover um livro da prateleira \n");
    printf("9 - Encerrar \n");
    printf("---- \n");
    printf("Informe a opção desejada: ");
    scanf("%d",&opcao);

    switch(opcao){
      case 1:
        printf("============================== \n");
        printf("\t Qual o Título do livro? ");
        scanf("%s",titulo);
        lista = inserir(lista, titulo);
        ordenar(lista);
        imprimir(lista, 0);
        printf(" * \n * \n * \n");
        break;
      case 9:
        printf("============================== \n");
        printf("\t Encerrando... \n");
        printf(" * \n * \n * \n");
        break;
      default:
        printf("\t Erro: Opção inválida. \n");
        printf(" * \n * \n * \n");
        break;
    }
  }while(opcao!=9);
  
  return 0;
}