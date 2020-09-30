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

struct aluno { 
  int idade;
  char primeiroNome[15];
  struct aluno* prox; 
};

typedef struct aluno Aluno;

int FEDivisao(int ParamIdade,int ParamTamanhoTabela){
  int restoDivisaoInteira;
  restoDivisaoInteira = ParamIdade % ParamTamanhoTabela;
  return restoDivisaoInteira;
}

Aluno* inicializar (void) {
    return NULL;
}

Aluno* inserir (Aluno* l, Aluno v) {
  Aluno* novo = (Aluno*) malloc(sizeof(Aluno));
  novo -> idade = v.idade;
  strcpy(novo -> primeiroNome, v.primeiroNome);
  novo -> prox = l;
  return novo;
}

void imprimir (Aluno* l) {
  Aluno* p;
  for (p = l; p != NULL; p = p -> prox) {
    printf(" %d,%s -> ", p -> idade, p -> primeiroNome);
  }
  printf("NULL\n");
}

Aluno* buscar(Aluno* l, Aluno v){
  Aluno* p;
  for (p = l; p != NULL; p = p -> prox) {
    if ( p -> idade == v.idade )
      return p;
  }
  return NULL;
}

Aluno* remover (Aluno* l, Aluno v) {
  Aluno* anterior = NULL;
  Aluno* p = l;
  while (p != NULL && p -> idade != v.idade) {
    anterior = p;
    p = p -> prox;
  }
  if (p == NULL)
    return l;
  if (anterior == NULL) 
    l = p -> prox;
  else 
    anterior -> prox = p -> prox;
  return l;
}

int main() {
  int opcao;
  int dadosIdade[20];
  int tamanhoIdade;
  int tamanhoNome;
  Aluno umAluno;
  int endereco;
  int i;
  int tamanhoTabela = 3;
  Aluno* tabelaHash[tamanhoTabela];
  Aluno* alunoRetornado;
  do{
    printf("\t MENU \n");
    printf("\t ---- \n");
    printf("\t 1-Carregar dados da idade e do nome dos alunos da turma \n");
    printf("\t 3-Obter endereço da tabela através da função de espalhamento na forma de Divisão \n");
    printf("\t 4-Armazenar dados da tabela de idade e nome na Tabela de Espalhamento \n");
    printf("\t 5-Imprimir tabela \n");
    printf("\t 6-Buscar na tabela \n");
    printf("\t 7-Inserir um aluno na tabela \n");
    printf("\t 8-Remover um aluno da tabela \n");
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
        scanf("%d",&umAluno.idade);
        endereco = FEDivisao(umAluno.idade,tamanhoTabela);
        printf(" * \n Endereço Calculado: %d \n",endereco);
        printf(" * \n * \n * \n");
        break;
      case 4:
        for(i=0;i<tamanhoTabela;i++)
          tabelaHash[i] = inicializar();
        for(i=0;i<tamanhoIdade;i++){
          endereco = FEDivisao(dadosIdade[i],tamanhoTabela);
          umAluno.idade = dadosIdade[i];
          strcpy(umAluno.primeiroNome, dadosNome[i]);
          tabelaHash[endereco] = inserir(tabelaHash[endereco],umAluno);
        }
        printf(" * \n Dados armazenados na Tabela de Espalhamento \n");
        printf(" * \n * \n * \n");
        break;
      case 5:
        for(i=0;i<tamanhoTabela;i++){
          printf("idades%d \n",i+1);
          printf("======== \n");
          imprimir(tabelaHash[i]);
          printf("\n");
        }
        printf(" * \n * \n * \n");
        break;
      case 6:
        printf(" * \n Informe a idade a Buscar: ");
        scanf("%d",&umAluno.idade);
        endereco = FEDivisao(umAluno.idade,tamanhoTabela);
        alunoRetornado = buscar(tabelaHash[endereco],umAluno);
        if (alunoRetornado == NULL) {
          printf(" * \n Idade NÃO encontrada. \n");
        } else {
          printf(" * \n A idade do aluno %s foi encontrada no vetor idades%d. \n",alunoRetornado->primeiroNome,endereco+1);
        }
        printf(" * \n * \n * \n");
        break;
      case 7:
        printf(" * \n Informe a idade do aluno: ");
        scanf("%d",&umAluno.idade);
        endereco = FEDivisao(umAluno.idade,tamanhoTabela);
        tabelaHash[endereco] = inserir(tabelaHash[endereco],umAluno);
        printf(" * \n Aluno inserido na Tabela de Espalhamento idades%d \n",endereco);
        printf(" * \n * \n * \n");
        break;
      case 8:
        printf(" * \n Informe a idade do aluno: ");
        scanf("%d",&umAluno.idade);
        endereco = FEDivisao(umAluno.idade,tamanhoTabela);
        tabelaHash[endereco] = remover(tabelaHash[endereco],umAluno);
        printf(" * \n Aluno removido na Tabela de Espalhamento idades%d \n",endereco);
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
