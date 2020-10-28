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

int main(void) {
  int opcao;
  char titulo[20];
  char primLetra, letraPilha;
  Pilha* livrosA;
  do{
    printf("\t MENU \n");
    printf("\t ---- \n");
    printf("\t 1 - Remover um livro da prateleira \n");
    printf("\t 2 - Colocar pilha de livros numa prateleira \n");
    printf("\t 9 - Encerrar \n");
    printf("\t ---- \n");
    printf("\t Informe a opção desejada: ");
    scanf("%d",&opcao);

    switch(opcao){
      case 1:
        printf("Qual o Título do livro? ");
        scanf("%s",titulo);
        primLetra = titulo[0];
        primLetra = toupper(primLetra);
        switch(primLetra){
          case 'A':
            if( !(livrosA->topo >= -1) )
              livrosA = inicializar(livrosA, 100);
            break;
        }
        printf(" * \n * \n * \n");
        break;
      case 2:
        printf("Qual a letra da pilha de livros? ");
        getchar();
        scanf("%c",&letraPilha);
        letraPilha = toupper(letraPilha);
        switch(letraPilha){
          case 'A':
            break;
        }
        printf(" * \n * \n * \n");
        break;
      case 9:
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