#include <stdlib.h>

struct Fila{
  int posicaoInicial;
  int posicaoFinal;
  int capacidade;
  int *dados;
};

void criarFila(struct Fila *endFila, int capacidadeDesejada) {
  endFila -> posicaoInicial = 0;
  endFila -> posicaoFinal = -1;
  endFila -> capacidade = capacidadeDesejada;
  endFila -> dados = malloc (capacidadeDesejada * sizeof(int));
}

void enfileirar(struct Fila *endFila, int senhaDesejada) {
  endFila -> posicaoFinal++;
  endFila -> dados[endFila -> posicaoFinal] = senhaDesejada;
}

int main() {
  struct Fila senhas;
  criarFila(&senhas,3);
  enfileirar(&senhas, 111);

  return 0;
}
