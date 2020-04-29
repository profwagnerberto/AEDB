#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct pilha {
  int topo;
  int capacidade;
  int* proxElem;
};

typedef struct pilha Pilha;

Pilha *A,*B,*C;

Pilha* inicializar(Pilha *p, int c){
  p = (Pilha*) malloc (sizeof(Pilha));
  p -> proxElem = (int*) malloc (c * sizeof(int));
  p -> topo = -1;
  p -> capacidade = c;
  return p;
}

void empilhar(Pilha *p, int v){
  p -> topo++;
  p -> proxElem [p -> topo] =  v;
}

int desempilhar(Pilha *p){
  int aux = p -> proxElem [p -> topo];
  p -> topo--;
  return aux;
}

int estahVazia(Pilha *p){
  if(p -> topo == -1)
    return 1;
  else
    return 0;
}

void imprimir (Pilha *p) {
  Pilha *aux;
  int disco;
  int i;
  aux = inicializar(aux, 10);

  while(!estahVazia(p)){
    disco = desempilhar(p);
    empilhar(aux,disco);
    printf(" %d \n", disco);
  }
    
  while(!estahVazia(aux))
    empilhar(p,desempilhar(aux));
}

void imprimirTorres(Pilha *tA,Pilha *tB,Pilha *tC){
  int i;
  int continuar;
  for(i=1;i<=15;i++)
    printf("\n");
  imprimir(tA);
  printf("=== \n");
  printf(" A  \n\n");
  imprimir(tB);
  printf("=== \n");
  printf(" B  \n\n");
  imprimir(tC);
  printf("=== \n");
  printf(" C  \n\n");
  printf("Digite 0 p/ continuar... ");
  scanf("%d",&continuar);
}

void limpar(Pilha *p){
  while(!estahVazia(p))
    desempilhar(p);
}

void limparTorres(Pilha *tA,Pilha *tB,Pilha *tC){
  limpar(tA);
  limpar(tB);
  limpar(tC);
}

void carregamentoInicial(Pilha *tA,Pilha *tB,Pilha *tC){
  empilhar(tA,0);
  empilhar(tA,1);
  empilhar(tA,1);
  empilhar(tA,2);
  empilhar(tA,5);
  empilhar(tA,3);
  empilhar(tA,8);
}

//Só carregar
void teste1(){
  limparTorres(A,B,C);

  carregamentoInicial(A,B,C);

  imprimirTorres(A,B,C);
}

//Com apenas 6 PUT ordenar na seq de fibonacci
void teste2(){
  limparTorres(A,B,C);

  carregamentoInicial(A,B,C);

  empilhar(B,desempilhar(A));
  empilhar(C,desempilhar(A));
  empilhar(B,desempilhar(A));
  empilhar(A,desempilhar(C));
  empilhar(A,desempilhar(B));
  empilhar(A,desempilhar(B));

  imprimirTorres(A,B,C);
}

void PUT(int disco, int torre){
  int aux;
  aux = desempilhar(A);
  if(aux != disco){
    empilhar(A,aux);
    aux = desempilhar(B);
    if(aux != disco){
      empilhar(B,aux);
      aux = desempilhar(C);
      if(aux != disco)
        empilhar(C,aux);
    }
  }

  empilhar(torre == 1 ? A:
            torre == 2 ? B:
            torre == 3 ? C:NULL,
            disco);
}

//PUT(8,03) 3,02 5,03 3,01 5,01 8,01
void teste3(){
  limparTorres(A,B,C);

  carregamentoInicial(A,B,C);

  PUT(8,3);
  PUT(3,2);
  PUT(5,3);
  PUT(3,1);
  PUT(5,1);
  PUT(8,1);

  imprimirTorres(A,B,C);
}

//PUT(8,02) 3,02 5,02 3,01 5,01 8,01
void teste4(){
  limparTorres(A,B,C);

  carregamentoInicial(A,B,C);

  PUT(8,2);
  PUT(3,3);
  PUT(5,2);
  PUT(3,1);
  PUT(5,1);
  PUT(8,1);

  imprimirTorres(A,B,C);
}

int main(void) {
  A = inicializar(A, 10);
  B = inicializar(B, 10);
  C = inicializar(C, 10);
 
  teste1();

  teste2();

//  teste3();

//  teste4();

  return 0;
}