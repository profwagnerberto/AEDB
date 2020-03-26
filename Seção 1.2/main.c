#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Criação ou definição da estrutura de uma lista
struct livro { 
  char titulo[40];
  struct livro* prox; 
};

typedef struct livro Livro;

// Inicialização da lista
Livro* inicializar (void) {
    return NULL;
}

// Inserção de itens no inicio
Livro* inserir (Livro* l, char* v) {
  Livro* novo = (Livro*) malloc(sizeof(Livro));
  strcpy(novo -> titulo, v);
  novo -> prox = l;
  return novo;
}

// Impressão da lista
void imprimir (Livro* l) {
  Livro* p;
  printf("Elementos:\n");
  for (p = l; p != NULL; p = p -> prox) {
    printf(" %s -> ", p -> titulo);
  }
  printf("NULL\n");
}

// Busca de item
Livro* buscar(Livro* l, char* v){
  Livro* p;
  for (p = l; p != NULL; p = p -> prox) {
    if (strcmp(p -> titulo, v) == 0)
      return p;
  }
  return NULL;
}

// Remoção de item
Livro* remover (Livro* l, char* v) {
  Livro* anterior = NULL;
  Livro* p = l;
  while (p != NULL && strcmp(p -> titulo, v) != 0) {
    anterior = p;
    p = p -> prox;
  }
  if (p == NULL )
    return l;
  if (anterior == NULL) {
    l = p -> prox;
  } else {
    anterior -> prox = p -> prox;
  }
  return l;
}

// Inserção no fim
Livro* inserirFim(Livro* l, char* v){
  Livro *p = l;
  int cont;
  Livro* novo = (Livro*)malloc(sizeof(Livro));
  while (p -> prox != NULL){
    p = p -> prox;
    cont++;
  }
  strcpy(novo -> titulo, v);
  novo -> prox = p -> prox;
  p -> prox = novo;
  return l;
}

// Inserção numa posição
Livro* inserirPosicao(Livro* l, int pos, char* v){
  int cont = 1;
  Livro *p = l;
  Livro* novo = (Livro*)malloc(sizeof(Livro));
  while (cont != pos){
    p = p -> prox;
    cont++;
  }
  strcpy(novo -> titulo, v);
  novo -> prox = p -> prox;
  p -> prox = novo;
  return l;
}

int main(void) {
  int opcao,posicao;
  struct { 
    char titulo[40];
  } registroLivro;
  do{
    printf("MENU \n");
    printf("---- \n");
    printf("1 - Criar lista pontos de parada \n");
    printf("2 - Inicializar lista \n");
    printf("3 - Inserir item no INICIO da lista \n");
    printf("4 - Inserir item no MEIO da lista \n");
    printf("5 - Inserir item no FIM da lista \n");
    printf("6 - Remover item da lista \n");
    printf("7 - Buscar item na lista \n");
    printf("8 - Imprimir lista \n");
    printf("9 - Encerrar \n");
    printf("---- \n");
    printf("*** Informe a opção desejada: ");
    fflush(stdin);
    scanf("%d",&opcao);

    switch(opcao){
      case 1:
        // Criação ou definição da estrutura de uma lista
        printf("Criando Lista... \n");
        Livro* listaDeLivros;
        printf("Lista criada com sucesso \n");
        printf(" * \n * \n * \n");
        break;
      case 2:
        // Inicialização da lista
        printf("Inicializando Lista... \n");
        listaDeLivros = inicializar();
        printf("Lista inicializada com sucesso \n");
        printf(" * \n * \n * \n");
        break;
      case 3:
        // Inserção de itens no inicio
        printf("Inserindo no inicio... \n");
        printf("Informe o título do livro: ");
        fflush(stdin);
        scanf("%s",registroLivro.titulo);
        listaDeLivros = inserir(listaDeLivros, registroLivro.titulo);
        printf("Item inserido com sucesso \n");
        printf(" * \n * \n * \n");
        break;
      case 4:
        // Inserção numa posição
        printf("Inserindo após o 1o... \n");
        printf("Informe o título do livro: ");
        fflush(stdin);
        scanf("%s",registroLivro.titulo);
        printf("Em qual posição da lista (Z*+)?: ");
        fflush(stdin);
        scanf("%d",&posicao);
        listaDeLivros = inserirPosicao(listaDeLivros, posicao, registroLivro.titulo);
        printf("Item inserido com sucesso \n");
        printf(" * \n * \n * \n");
        break;
      case 5:
        // Inserção no fim
        printf("Inserindo no fim... \n");
        printf("Informe o título do livro: ");
        fflush(stdin);
        scanf("%s",registroLivro.titulo);
        listaDeLivros = inserirFim(listaDeLivros, registroLivro.titulo);
        printf("Item inserido com sucesso \n");
        printf(" * \n * \n * \n");
        break;
      case 6:
        // Remoção de item
        printf("Removendo... \n");
        printf("Informe o título do livro: ");
        fflush(stdin);
        scanf("%s",registroLivro.titulo);
        listaDeLivros = remover(listaDeLivros, registroLivro.titulo);
        printf(" * \n * \n * \n");
        break;
      case 7:
        // Busca de item
        printf("Informe o título do livro: ");
        fflush(stdin);
        scanf("%s",registroLivro.titulo);
        if (buscar(listaDeLivros, registroLivro.titulo) == NULL) {
          printf("Elemento não encontrado\n");
        } else {
          printf("Elemento encontrado\n");
        }
        printf(" * \n * \n * \n");
        break;
      case 8:
        // Impressão da lista
        printf("Imprimindo... \n");
        imprimir(listaDeLivros);
        printf("Lista impressa com sucesso \n");
        printf(" * \n * \n * \n");
        break;
      case 9:
        // Destruição da lista
        printf("Encerrando... \n");
        if(listaDeLivros != NULL){
//          free(listaDeLivros); // quando em windows
          listaDeLivros = NULL;
        }
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