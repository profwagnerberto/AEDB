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

int main() {
  struct Pilha meusLivros;
  criarPilha(&meusLivros, 5);

  return 0;
}