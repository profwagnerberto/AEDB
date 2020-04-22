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

float CalcularMediaIdades(int ParamTamanhoIdade,int *ParamDadosIdade){
  float soma;
  int i;
  soma = 0;
  for(i=0;i<ParamTamanhoIdade;i++)
    soma += ParamDadosIdade[i];
  return soma / ParamTamanhoIdade;
}

int FECalcularEndereco(int ParamIdadeABuscar, float ParamMedia){
  if(ParamIdadeABuscar < ParamMedia)
    return 1;
  else
    return 2;
}

int FEDividir(int ParamIdadeACalcular){
  int restoDivisaoInteira;
  restoDivisaoInteira = ParamIdadeACalcular % 3;
  restoDivisaoInteira++;
  return restoDivisaoInteira;
}

int main() {
  int opcao;
  int i;
  int dadosIdade[20];
  int tamanhoIdade;
  float media;
  int enderecoCalculado;
  int idades1[10],tamanhoIdades1;
  int idades2[10],tamanhoIdades2;
  int impressao;
  int busca,idadeABuscar;
  int calculo,idadeACalcular;
  int hashTable,idadeAArmazenar;
  do{
    printf("\t MENU \n");
    printf("\t ---- \n");
    printf("\t 1-Carregar a tabela com a idade e o nome dos alunos da turma \n");
    printf("\t 2-Imprimir tabelas \n");
    printf("\t 3-Buscar nas tabelas \n");
    printf("\t 4-Calcular a média aritmética simples das idades \n");
    printf("\t 5-Obter endereço da tabela a armazenar/buscar \n");
    printf("\t 6-Armazenar dados da tabela de idade e nome na Tabela de Espalhamento \n");
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
        printf("\t\t 1-... da tabela com a idade e o nome dos alunos \n");
        printf("\t\t 2-... da tabela com hash 2 \n");
        printf("\t\t 9-Voltar ao menu anterior \n");
        printf("\t\t Informe a impressão desejada: ");
        scanf("%d",&impressao);
        if(impressao==1){
          printf("Idade \t Nome \n=============== \n");
          for(i=0;i<tamanhoIdade;i++)
            printf("%2d \t\t %s \n",dadosIdade[i],dadosNome[i]);
        }else if(impressao==2){
          printf("idades1 \n=============== \n");
          for(i=0;i<tamanhoIdades1;i++)
            printf("%d \n",idades1[i]);
          printf(" * \n");
          printf("idades2 \n=============== \n");
          for(i=0;i<tamanhoIdades2;i++)
            printf("%d \n",idades2[i]);
        }else if(impressao==9)
          printf(" * \n Voltando... \n");
        else
          printf(" * \n Erro: Opção inválida. \n");
        printf(" * \n * \n * \n");
        break;
      case 3:
        printf("\t\t 1-... na tabela com a idade e o nome dos alunos \n");
        printf("\t\t 2-... na tabela com hash 2 \n");
        printf("\t\t 9-Voltar ao menu anterior \n");
        printf("\t\t Informe a busca desejada: ");
        scanf("%d",&busca);
        printf(" * \n Informe a idade a Buscar: ");
        scanf("%d",&idadeABuscar);
        if(busca==1){
          i = 0;
          while(i<tamanhoIdade && dadosIdade[i]!=idadeABuscar)
            i++;
          if(dadosIdade[i]==idadeABuscar)
            printf(" * \n A idade do(a) %s, foi encontrada depois de %d iterações. \n",dadosNome[i],i+1);
          else
            printf(" * \n Idade NÃO encontrada. \n");
        }else if(busca==2){
          media = CalcularMediaIdades(tamanhoIdade,dadosIdade);
          enderecoCalculado = FECalcularEndereco(idadeABuscar,media);
          if(enderecoCalculado==1){
            i = 0;
            while(i<tamanhoIdades1 && idades1[i]!=idadeABuscar)
              i++;
            if(idades1[i]==idadeABuscar)
              printf(" * \n A idade foi encontrada no vetor idades1 depois de %d iterações. \n",i+1);
            else
              printf(" * \n Idade NÃO encontrada. \n");
          }else if(enderecoCalculado==2){
            i = 0;
            while(i<tamanhoIdades2 && idades2[i]!=idadeABuscar)
              i++;
            if(idades2[i]==idadeABuscar)
              printf(" * \n A idade foi encontrada no vetor idades2 depois de %d iterações. \n",i+1);
            else
              printf(" * \n Idade NÃO encontrada. \n");
          }
        }else if(busca==9)
          printf(" * \n Voltando... \n");
        else
          printf(" * \n Erro: Opção inválida. \n");
        printf(" * \n * \n * \n");
        break;
      case 4:
        media = CalcularMediaIdades(tamanhoIdade,dadosIdade);
        printf(" * \n Média: %.2f \n",media);
        printf(" * \n * \n * \n");
        break;
      case 5:
        printf("\t\t 2-... na tabela com hash 2 (Forma da função de espalhamento: Cálculo de endereços) \n");
        printf("\t\t 3-... na tabela com hash 3 (Forma da função de espalhamento: Divisão) \n");
        printf("\t\t 9-Voltar ao menu anterior \n");
        printf("\t\t Informe a cálculo desejado: ");
        scanf("%d",&calculo);
        printf(" * \n Informe a idade a Calcular: ");
        scanf("%d",&idadeACalcular);
        if(calculo==2){
          media = CalcularMediaIdades(tamanhoIdade,dadosIdade);
          enderecoCalculado = FECalcularEndereco(idadeACalcular,media);
          printf(" * \n Endereço Calculado: %d (Armazenar ou buscar no vetor idades%d) \n",enderecoCalculado,enderecoCalculado);
        }else if(calculo==3){
          enderecoCalculado = FEDividir(idadeACalcular);
          printf(" * \n Endereço Calculado: %d (Armazenar ou buscar no vetor IDADES%d) \n",enderecoCalculado,enderecoCalculado);
        }else if(calculo==9)
          printf(" * \n Voltando... \n");
        else
          printf(" * \n Erro: Opção inválida. \n");
        printf(" * \n * \n * \n");
        break;
      case 6:
        printf("\t\t 2-... na tabela com hash 2 \n");
        printf("\t\t 3-... na tabela com hash 3 \n");
        printf("\t\t 9-Voltar ao menu anterior \n");
        printf("\t\t Informe a tabela de espalhamento desejada: ");
        scanf("%d",&hashTable);
        printf(" * \n Informe a idade a Armazenar: ");
        scanf("%d",&idadeAArmazenar);
        if(hashTable==2){
          enderecoCalculado = FEDividir(idadeAArmazenar);
          printf(" * \n Endereço Calculado: %d (Armazenar ou buscar no vetor idades%d) \n",enderecoCalculado,enderecoCalculado);
        }else if(hashTable==3){
          tamanhoIdades1 = tamanhoIdades2 = 0;
          for(i=0;i<tamanhoIdade;i++){
            enderecoCalculado = FEDividir(dadosIdade[i]);
            if(enderecoCalculado==1){
              idades1[tamanhoIdades1] = dadosIdade[i];
              tamanhoIdades1++;
            }else if(enderecoCalculado==2){
              idades2[tamanhoIdades2] = dadosIdade[i];
              tamanhoIdades2++;
            }
          }
        }else if(hashTable==9)
          printf(" * \n Voltando... \n");
        else
          printf(" * \n Erro: Opção inválida. \n");





        printf(" * \n Dados armazenados na Tabela de Espalhamento \n");
        printf(" * \n * \n * \n");
        break;
      case 8:
        printf(" * \n * \n * \n");
        break;
      case 9:
        printf(" * \n Encerrando... \n");
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
