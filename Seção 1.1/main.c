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
  int opcao;
  do{
    printf("MENU \n");
    printf("---- \n");
    printf("1 - Criar lista pontos de parada \n");
    printf("2 - Inicializar lista \n");
    printf("9 - Encerrar \n");
    printf("---- \n");
    printf("*** Informe a opção desejada: ");
    fflush(stdin);
    scanf("%d",&opcao);

    switch(opcao){
      case 1:
        // Criação ou definição da estrutura de uma lista
        printf("Criando Lista de rotas... \n");
        Rota* listaDeRotas;
        printf("Lista de rotas criada com sucesso \n");
        printf(" * \n * \n * \n");
        break;
      case 2:
        // Inicialização da lista
        printf("Inicializando Lista de rotas... \n");
        listaDeRotas = inicializar();
        printf("Lista de rotas inicializada com sucesso \n");
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