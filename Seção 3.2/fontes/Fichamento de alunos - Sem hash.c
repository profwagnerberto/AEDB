#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CarregarIdades(int *paramDadosIdade){
  FILE *fl;
  int caracter;
  int tamanho = 1000;
  char temp[tamanho];
  int contaCarac;
  int contaIdade;
  fl = fopen("dadosIdade.txt", "r");
  contaCarac=0;
  strcpy(temp,"");
  contaIdade=0;
  while((caracter = fgetc(fl)) != EOF){
    if(caracter!=','){
      temp[contaCarac]=caracter;
      contaCarac++;
    }else{
      paramDadosIdade[contaIdade]=atoi(temp);
      contaCarac=0;
      strcpy(temp,"");
      contaIdade++;
    }
  }        
  paramDadosIdade[contaIdade]=atoi(temp);
  fclose(fl);
  return ++contaIdade;
}

char dadosNome[30][20];
void CarregarNomes(){
  FILE *fl;
  int caracter;
  int tamanho = 1000;
  char temp[tamanho];
  int contaCarac;
  int contaNome;
  fl = fopen("dadosNome.txt", "r");
  contaCarac=0;
  temp[0]='\0';
  contaNome=0;
  while((caracter = fgetc(fl)) != EOF){
    if(caracter!=','){
      temp[contaCarac]=caracter;
      contaCarac++;
    }else{
      temp[contaCarac]='\0';
      strcpy(dadosNome[contaNome],temp);
      contaCarac=0;
      temp[0]='\0';
      contaNome++;
    }
  }        
  temp[contaCarac]='\0';
  strcpy(dadosNome[contaNome],temp);
  fclose(fl);
}

int main() {
  int opcao;
  int idadeABuscar;
  int i;
  int dadosIdade[20];
  int tamanhoIdade;
  int impressao;
  int continuar;
  do{
    for(i=0;i<30;i++)
      printf("\n");
    printf("\t Fichamento de alunos - Sem hash \n");
    printf("\t =============================== \n");
    printf("\t MENU \n");
    printf("\t ---- \n");
    printf("\t 1-Armazenar dados da idade e do nome dos alunos da turma numa tabela Sem Hash\n");
    printf("\t 2-Imprimir tabela \n");
    printf("\t 3-Buscar na tabela \n");
    printf("\t 9-Encerrar \n");
    printf("\t ---- \n");
    printf("\t Informe a opção desejada: ");
    scanf("%d",&opcao);
    switch(opcao){
      case 1:
        tamanhoIdade = CarregarIdades(dadosIdade);
        CarregarNomes();
        printf(" * \n Dados carregados. \n");
        printf(" * \n * \n * \n");
        break;
      case 2:
        printf("Idade \t Nome \n=============== \n");
        for(i=0;i<tamanhoIdade;i++)
          printf("%2d \t\t %s \n",dadosIdade[i],dadosNome[i]);
        printf(" * \n * \n * \n");
        break;
      case 3:
        printf(" * \n Informe a idade a Buscar: ");
        scanf("%d",&idadeABuscar);
        i = 0;
        while(i<tamanhoIdade && dadosIdade[i]!=idadeABuscar)
          i++;
        if(dadosIdade[i]==idadeABuscar)
          printf(" * \n A idade do(a) %s, foi encontrada depois de %d iterações. \n",dadosNome[i],i+1);
        else
          printf(" * \n Idade NÃO encontrada. \n");
        printf(" * \n * \n * \n");
        break;
      case 9:
        printf("Encerrando... \n");
        printf(" * \n * \n * \n");
        break;
      default:
        printf(" * \n Erro: Opção inválida. \n");
        printf(" * \n * \n * \n");
        break;
    }
    printf("*** Digite 0 + <ENTER> para continuar...");
    scanf("%d",&continuar);
  }while(opcao!=9);
  return 0;
}
