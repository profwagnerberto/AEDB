#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct nodoLivro {
  char titulo[20];
  struct nodoLivro* ant;
  struct nodoLivro* prox;
};

typedef struct nodoLivro NodoLivro;

NodoLivro* inicializarLista (void) {
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
      if ( strcmp(p -> titulo, aux -> titulo) > 0 ) {
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

struct pilha {
  int topo;
  int capacidade;
  char* proxElem;
};

typedef struct pilha Pilha;

Pilha* inicializarPilha(Pilha *p, int c){
  p = (Pilha*) malloc (sizeof(Pilha));
  p -> proxElem = (char*) malloc (c * sizeof(char[20]));
  p -> topo = -1 * 20;
  p -> capacidade = c;
  return p;
}

void empilhar(Pilha *p, char v[20]){
  int i;
  p -> topo+=20;
  for(i=0;i<20;i++){
    p -> proxElem [p -> topo] =  v[i];
    p -> topo++;
  }
}

void desempilhar(Pilha *p, char ptitulo[20]){
  p -> topo-=20;
  int i;
  for(i=0;i<20;i++){
    ptitulo[i] = p -> proxElem [p -> topo];
    p -> topo++;
  }
  p -> topo-=20;
}

int estahVazia(Pilha *p){
  if( p -> topo == -20 )
    return 1;
  else
    return 0;
}

void liberar(Pilha *p){
  free(p);
}

///

struct Fila{
  int posicaoInicial;
  int posicaoFinal;
  int capacidade;
  char* proxElem;
};

void criarFila(struct Fila *endFila, int c){
  endFila -> posicaoInicial = 0;
  endFila -> posicaoFinal = -1 * 20;
  endFila -> capacidade = c;
  endFila -> proxElem = (char*) malloc (c * sizeof(char[20]));
}

void enfileirar(struct Fila *endFila, char v[20]){
  endFila -> posicaoFinal+=20;
  int i;
  for(i=0;i<20;i++){
    endFila -> proxElem [endFila -> posicaoFinal] =  v[i];
    endFila -> posicaoFinal++;
  }

}

int tahVazia(struct Fila *endFila){
  if(endFila -> posicaoInicial > endFila -> posicaoFinal )
    return 1;
  else
    return 0;
}

void desenfileirar(struct Fila *endFila, char ptitulo[20]){
  endFila -> posicaoInicial-=20;
  int i;
  for(i=0;i<20;i++){
    ptitulo[i] = endFila -> proxElem [endFila -> posicaoInicial];
    endFila -> posicaoInicial++;
  }
  endFila -> posicaoInicial-=20;
}

/**/

int main(void) {
  int opcao;
  char titulo[20];
  NodoLivro* lista;
  NodoLivro* p;
  char primLetra;
  Pilha* auxiliar;
  Pilha* pilhaA;
  Pilha* pilhaB;
  struct Fila Aux;
  struct Fila filaDeLivros;

  lista = inicializarLista();
  pilhaA = inicializarPilha(pilhaA, 100);
  pilhaB = inicializarPilha(pilhaB, 100);
  criarFila(&filaDeLivros,1000);

  do{
    printf("============================== \n");
    printf("MENU \n");
    printf("---- \n");
    printf("1 - Remover um livro da prateleira \n");
    printf("2 - Colocar os livros em sua pilha específica \n");
    printf("3 - Enfileirar todos livros de cada pilha em uma única fila \n");
    printf("7 - Listar a fila de livros.\n");
    printf("8 - Listar pilhas de livros.\n");
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
        printf("\t Livro inserido na lista. \n");
        printf("\t Ordenando lista... \n");
        ordenar(lista);
        printf("\t Pronto. \n");
        imprimir(lista, 0);
        printf("\n * \n * \n");
        break;
      case 2:
        printf("============================== \n");
        for (p = lista; p != NULL; p = p -> prox){
          printf("\t %s -> ", p -> titulo);
          primLetra = p -> titulo[0];
          primLetra = toupper(primLetra);
          switch(primLetra){
            case 'A':
              empilhar(pilhaA,p -> titulo);
              break;
            case 'B':
              empilhar(pilhaB,p -> titulo);
              break;
          }
        }
        printf("\n * \n * \n");
        break;
      case 3:
        printf("============================== \n");
        desempilhar(pilhaA, titulo);
        printf("%s\n",titulo);
        enfileirar(&filaDeLivros, titulo);

        printf("\n * \n * \n");
        break;
      case 7:
        criarFila(&Aux,1000);

        printf("Fila de livros\n");
        printf("--------------\n");
        while(tahVazia(&filaDeLivros)!=1){
          desenfileirar(&filaDeLivros, titulo);
          printf("%s\n",titulo);
/*
          empilhar(auxiliar, titulo);
*/
        }
/*
        while(estahVazia(auxiliar)!=1){
          desempilhar(auxiliar, titulo);
          empilhar(pilhaA,titulo);
        }
*/
        printf("\n * \n * \n");
        break;
      case 8:
        auxiliar = inicializarPilha(auxiliar, 100);

        printf("Pilha de livros A\n");
        printf("-----------------\n");
        while(estahVazia(pilhaA)!=1){
          desempilhar(pilhaA, titulo);
          printf("%s\n",titulo);
          empilhar(auxiliar, titulo);
        }
        while(estahVazia(auxiliar)!=1){
          desempilhar(auxiliar, titulo);
          empilhar(pilhaA,titulo);
        }
        printf("===\n");

        printf("Pilha de livros B\n");
        printf("-----------------\n");
        while(estahVazia(pilhaB)!=1){
          desempilhar(pilhaB, titulo);
          printf("%s\n",titulo);
          empilhar(auxiliar, titulo);
        }
        while(estahVazia(auxiliar)!=1){
          desempilhar(auxiliar, titulo);
          empilhar(pilhaB,titulo);
        }
        printf("===\n");

        liberar(auxiliar);
        printf("\n * \n * \n");
        break;
      case 9:
        printf("============================== \n");
        desempilhar(pilhaA,titulo);
        printf("%s \n",titulo);

        printf("\t Encerrando... \n");
        printf("\n * \n * \n");
        break;
      default:
        printf("\t Erro: Opção inválida. \n");
        printf("\n * \n * \n");
        break;
    }
  }while(opcao!=9);
  
  return 0;
}
