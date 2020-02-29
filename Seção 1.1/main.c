#include <stdio.h>

// Criação ou definição da estrutura de uma lista
struct rota { 
    char parada[15];
    struct rota* prox; 
};

typedef struct rota Rota;

// Inicialização da lista
Rota* inicializar (void) {
    return NULL;
}

int main(void) {
  // Criação ou definição da estrutura de uma lista
  printf("Criando Lista de rotas... \n");
  Rota* listaDeRotas;
  printf("Lista de rotas criada com sucesso \n");
  
  // Inicialização da lista
  printf("Inicializando Lista de rotas... \n");
  listaDeRotas = inicializar();
  printf("Lista de rotas inicializada com sucesso \n");
  
  return 0;
}