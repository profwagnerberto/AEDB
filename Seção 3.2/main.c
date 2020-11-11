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
int CarregarNomes(){
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
  return ++contaNome;
}

int FEDivisao(int ParamIdade){
  int restoDivisaoInteira;
  restoDivisaoInteira = ParamIdade % 3;
  return restoDivisaoInteira;
}

int main() {
  int opcao;
  int idade;
  int i;
  int dadosIdade[20];
  int tamanhoIdade;
  int tamanhoNome;
  int endereco;
  int tamanhoColuna[3];
  int tabelaHash[10][3];
  do{
    printf("\t MENU \n");
    printf("\t ---- \n");
    printf("\t 1-Carregar dados da idade e do nome dos alunos da turma \n");
    printf("\t 3-Obter endereço da tabela através da função de espalhamento na forma de Divisão \n");
    printf("\t 4-Armazenar dados da tabela de idade e nome na Tabela de Espalhamento \n");
    printf("\t 5-Imprimir tabela \n");
    printf("\t 6-Buscar na tabela\n");
    printf("\t 9-Encerrar \n");
    printf("\t ---- \n");
    printf("\t Informe a opção desejada: ");
    scanf("%d",&opcao);
    switch(opcao){
      case 1:
        tamanhoIdade = CarregarIdades(dadosIdade);
        tamanhoNome = CarregarNomes();
        printf(" * \n Dados carregados. \n");
        printf(" * \n * \n * \n");
        break;
      case 3:
        printf(" * \n Informe a idade a Calcular: ");
        scanf("%d",&idade);
        endereco = FEDivisao(idade);
        printf(" * \n Endereço Calculado: %d \n",endereco);
        printf(" * \n * \n * \n");
        break;
      case 4:
        for(i=0;i<tamanhoIdade;i++)
        tamanhoColuna[0] = tamanhoColuna[1] = tamanhoColuna[2] = 0;
        for(i=0;i<tamanhoIdade;i++){
          endereco = FEDivisao(dadosIdade[i]);
          tabelaHash[tamanhoColuna[endereco]][endereco] = dadosIdade[i];
          tamanhoColuna[endereco]++;
        }
        printf(" * \n Dados armazenados na Tabela de Espalhamento \n");
        printf(" * \n * \n * \n");
        break;
      case 5:
        printf("índice \t idades1 \t idades2 \t idades3 \n");
        printf("======================================== \n");
        for(i=0;i<10;i++){
          printf("\t %d \t\t",i);
          if(i<tamanhoColuna[0])
            printf("%d \t\t\t",tabelaHash[i][0]);
          if(i<tamanhoColuna[1])
            printf("%d \t\t\t",tabelaHash[i][1]);
          if(i<tamanhoColuna[2])
            printf("%d ",tabelaHash[i][2]);
          printf("\n");
        }
        printf(" * \n * \n * \n");
        break;
      case 6:
        printf(" * \n Informe a idade a Buscar: ");
        scanf("%d",&idade);
        endereco = FEDivisao(idade);
        i = 0;
        while(i<tamanhoColuna[endereco] && tabelaHash[i][endereco]!=idade)
          i++;
        if(tabelaHash[i][endereco]==idade)
          printf(" * \n A idade foi encontrada no vetor idades%d depois de %d iterações. \n",endereco+1,i+1);
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
  }while(opcao!=9);
  return 0;
}
