#include <stdlib.h>
#include <stdio.h>

struct Pilha{
  int posicaoTopo;
  int capacidade;
  int *proximoElemento;
};

void criarPilha(struct Pilha *endPilha, int capacidadeDesejada) {
  endPilha -> posicaoTopo = -1;
  endPilha -> capacidade = capacidadeDesejada;
  endPilha -> proximoElemento = malloc (capacidadeDesejada * sizeof(int));
}

void empilhar(struct Pilha *endPilha, int ISBNdesejado) {
  endPilha -> posicaoTopo++;
  endPilha -> proximoElemento [endPilha -> posicaoTopo] = ISBNdesejado;
}

int estahCheia (struct Pilha *endPilha) {
  if (endPilha -> posicaoTopo == endPilha -> capacidade)
    return 1;
  else
    return 0;
}

int desempilhar (struct Pilha *endPilha) {
  int valorАSerDesempilhado = endPilha -> proximoElemento [endPilha -> posicaoTopo];
  endPilha -> posicaoTopo--;
  return valorАSerDesempilhado;
}

int estahVazia(struct Pilha *endPilha ) {
  if( endPilha -> posicaoTopo == -1) 
    return 1;
  else
    return 0;
}

int main() {
  struct Pilha meusLivros;
  int ISBNdoLivro;
  criarPilha(&meusLivros, 5);
  if(estahCheia(&meusLivros)==1)
    printf("Nao cabem mais livros");
  else
    empilhar (&meusLivros, 1111);  
  if(estahVazia(&meusLivros)==1)
    printf("Nao tem mais livros");
  else{
    ISBNdoLivro = desempilhar (&meusLivros);
    printf("ISBN do livro desempilhado: %d\n", ISBNdoLivro);
  }

  return 0;
}