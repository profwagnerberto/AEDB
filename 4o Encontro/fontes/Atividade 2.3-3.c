#include <stdlib.h>
#include <stdio.h>

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

int estahCheia(struct Fila *endFila) {
  if (endFila -> posicaoFinal == endFila -> capacidade - 1)
    return 1;
  else
    return 0;
}

int desenfileirar(struct Fila *endFila) {
  int valorАSerDesenfileirado;
  valorАSerDesenfileirado = endFila -> dados [endFila -> posicaoInicial];
  endFila -> posicaoInicial++;
  return valorАSerDesenfileirado;
}

int main() {
  struct Fila senhas;
  int senha;
  criarFila(&senhas,3);
  if(estahCheia(&senhas)==1)
    printf("Nao cabem mais senhas\n");
  else{
    enfileirar(&senhas, 111);
    printf("Senha colocada na fila para ser mostrada no painel. \n");
  }
  senha=desenfileirar(&senhas);

  return 0;
}
