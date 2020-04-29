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

float CalcularMediaIdades(int ParamTamanhoIdade,int *ParamDadosIdade){
  float soma;
  int i;
  soma = 0;
  for(i=0;i<ParamTamanhoIdade;i++)
    soma += ParamDadosIdade[i];
  return soma / ParamTamanhoIdade;
}

int FECalculoDeEnderecos(int ParamIdadeABuscar, float ParamMedia){
  if(ParamIdadeABuscar < ParamMedia)
    return 0;
  else
    return 1;
}

int main() {
  int opcao;
  int idade;
  int i;
  int dadosIdade[20];
  int tamanhoIdade;
  int endereco;
  float media;
  int tamanhoColuna[2];
  int tabelaHash[10][2];
  int continuar;
  do{
    for(i=0;i<30;i++)
      printf("\n");
    printf("\t Fichamento de alunos - Com hash de 3 \n");
    printf("\t ==================================== \n");
    printf("\t MENU \n");
    printf("\t ---- \n");
    printf("\t 1-Carregar dados da idade e do nome dos alunos da turma \n");
    printf("\t 2-Calcular a média das idades \n");
    printf("\t 3-Obter endereço da tabela através da função de espalhamento na forma de Cálculo de Endereços \n");
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
        printf(" * \n Dados carregados. \n");
        printf(" * \n * \n * \n");
        break;
      case 2:
        media = CalcularMediaIdades(tamanhoIdade,dadosIdade);
        printf(" * \n Média: %.2f \n",media);
        printf(" * \n * \n * \n");
        break;
      case 3:
        printf(" * \n Informe a idade a Calcular: ");
        scanf("%d",&idade);
        media = CalcularMediaIdades(tamanhoIdade,dadosIdade);
        endereco = FECalculoDeEnderecos(idade,media);
        printf(" * \n Endereço Calculado: %d \n",endereco);
        printf(" * \n * \n * \n");
        break;
      case 4:
        tamanhoColuna[0] = tamanhoColuna[1] = 0;
        media = CalcularMediaIdades(tamanhoIdade,dadosIdade);
        for(i=0;i<tamanhoIdade;i++){
          endereco = FECalculoDeEnderecos(dadosIdade[i],media);
          tabelaHash[tamanhoColuna[endereco]][endereco] = dadosIdade[i];
          tamanhoColuna[endereco]++;
        }
        printf(" * \n Dados armazenados na Tabela de Espalhamento \n");
        printf(" * \n * \n * \n");
        break;
      case 5:
        printf("índice \t idades1 \t idades2 \n");
        printf("============================== \n");
        for(i=0;i<10;i++){
          printf("\t %d \t\t",i);
          if(i<tamanhoColuna[0])
            printf("%d \t\t\t",tabelaHash[i][0]);
          if(i<tamanhoColuna[1])
            printf("%d ",tabelaHash[i][1]);
          printf("\n");
        }
        printf(" * \n * \n * \n");
        break;
      case 6:
        printf(" * \n Informe a idade a Buscar: ");
        scanf("%d",&idade);
        media = CalcularMediaIdades(tamanhoIdade,dadosIdade);
        endereco = FECalculoDeEnderecos(idade,media);
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
    printf("*** Digite 0 + <ENTER> para continuar...");
    scanf("%d",&continuar);
  }while(opcao!=9);
  return 0;
}
