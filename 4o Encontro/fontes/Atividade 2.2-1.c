#include <stdlib.h>

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

int main() {
  struct Pilha meusLivros;
  criarPilha(&meusLivros, 5);
  empilhar(&meusLivros, 1111);
  
  return 0;
}