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

int main() {
  struct Pilha meusLivros;
  criarPilha(&meusLivros, 5);
  if(estahCheia(&meusLivros)==1)
    printf("Nao cabem mais livros");
  else
    empilhar (&meusLivros, 1111);  
  return 0;
}