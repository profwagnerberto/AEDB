#include <stdio.h>
#include <string.h>

int main(void) {
  int opcao;
  char titulo[20];
  char primLetra;
  do{
    printf("\t MENU \n");
    printf("\t ---- \n");
    printf("\t 1 - Remover um livro da prateleira \n");
    printf("\t 9 - Encerrar \n");
    printf("\t ---- \n");
    printf("\t Informe a opção desejada: ");
    fflush(stdin);
    scanf("%d",&opcao);

    switch(opcao){
      case 1:
        printf("Qual o Título do livro \n");
        fflush(stdin);
        scanf("%s",titulo);
        toupper(titulo);
        printf("%s \n",titulo);
        primLetra = titulo[0];
        primLetra = toupper(primLetra);
        printf("%c \n",primLetra);

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