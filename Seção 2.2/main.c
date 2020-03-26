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
      if ( strcmp(p -> titulo, aux -> titulo) == 1 ) {
        strcpy(v, p -> titulo);
        strcpy(p -> titulo, aux -> titulo);
        strcpy(aux -> titulo, v);
      }
    }
  }
}

/*
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
*/

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
  printf("%d \n",p -> topo);
  p -> topo+=20;
  printf("%d \n",p -> topo);
  printf("%s \n",v);
  for(i=0;i<20;i++){
    p -> proxElem [p -> topo] =  v[i];
    p -> topo++;
  }
/*
//  *p = 'A';
  *p -> proxElem = v[0];
  p+=1;
  *p -> proxElem = v[1];
  p-=1;
*/
}

char desempilhar(Pilha *p, char aux[20]){
  int i;
  for(i=0;i<20;i++){
    aux[i] = p -> proxElem [p -> topo];
    p -> topo++;
  }
  p -> topo-=20;
  return aux[20];
}

int main(void) {
  int opcao;
  char titulo[20];
  NodoLivro* lista;
  NodoLivro* p;
  char primLetra;
  Pilha* pilhaA;

  lista = inicializarLista();
  pilhaA = inicializarPilha(pilhaA, 100);

  do{
    printf("============================== \n");
    printf("MENU \n");
    printf("---- \n");
    printf("1 - Remover um livro da prateleira \n");
    printf("2 - Colocar livros em sua pilha específica \n");
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
//        imprimir(lista, 0);
        printf(" * \n * \n * \n");
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
/*
*/
              break;
          }
        }
        printf(" * \n * \n * \n");
        break;
      case 9:
        printf("============================== \n");
        desempilhar(pilhaA,titulo);
        printf("%s \n",titulo);

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




/*
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct pilha {
  int topo;
  int capacidade;
  char* proxElem;
};

typedef struct pilha Pilha;

Pilha* inicializar(Pilha *p, int c){
  p = (Pilha*) malloc (sizeof(Pilha));
  p -> proxElem = (char*) malloc (c * sizeof(char[20]));
  p -> topo = -1;
  p -> capacidade = c;
  return p;
}

void empilhar(Pilha *p, char v){
  p -> topo++;
  p -> proxElem [p -> topo] = v;
}

char desempilhar(Pilha *p){
  char aux = p -> proxElem [p -> topo];
  p -> topo--;
  return aux;
}

int main(void) {
  int opcao;
  char titulo[20];
  char primLetra;
  Pilha* livrosA;
  do{
    printf("\t MENU \n");
    printf("\t ---- \n");
    printf("\t 1 - Remover um livro da prateleira \n");
    printf("\t 9 - Encerrar \n");
    printf("\t ---- \n");
    printf("\t Informe a opção desejada: ");
    scanf("%d",&opcao);
    switch(opcao){
      case 1:
        printf("Qual o Título do livro \n");
        scanf("%s",titulo);
        primLetra = titulo[0];
        primLetra = toupper(primLetra);
        switch(primLetra){
          case 'A':
            if( !(livrosA->topo >= -1) )
              livrosA = inicializar(livrosA, 26);
//            empilhar(livrosA,titulo);
//            empilhar(livrosA,'W');
            break;
        }
        printf(" * \n * \n * \n");
        break;
      case 9:
//        titulo = desempilhar(livrosA);
//        printf("%c \n",titulo);
        printf("Encerrando... \n");
        printf(" * \n * \n * \n");
        break;
      default:
        printf("Erro: Opção inválida. \n");
        printf(" * \n * \n * \n");
        break;
    }
  }while(opcao!=9);
  
  return 0;
}
*/
