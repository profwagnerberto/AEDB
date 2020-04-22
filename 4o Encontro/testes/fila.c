int main() {
  struct Fila senhas, auxiliar;
  int opcao, senha, carro;
  do{
    printf("Menu\n");
    printf("====\n");
    printf("1-Iniciar Impressora de senhas. \n");
    printf("2-Imprimir senha. \n");
    printf("3-Mostrar senha no painel. \n");
    printf("O-Encerrar. \n");
    printf("\n");
    printf("Digite o numero da opcao ==> ");
    scanf("%d",&opcao);
    if (opcao==1) {
      criarFila(&senhas, 3);
      printf("Impressora de senhas iniciada. \n");
    }else
    if (opcao==2) {
      printf("Informe o numero da senha impressa: ");
      scanf("%d", &senha);
      if (estahCheia(&senhas)==1)
        printf("Nao cabem mais senhas\n");
      else{
        enfileirar(&senhas, senha);
        printf("Senha colocada na fila para ser mostrada no painel. \n");
      }
    }else
    if (opcao==3){
      if(estahVazia(&senhas )==1)
        printf ("Nao tem mais senhas\n");
      else{
        senha=desenfileirar(&senhas);
        printf ("Senha no painel : %d.\n", senha);
      }
    }else
    if(opcao==0)
      printf("Encerrando o programa... \n");
  }while(opcao!=0);

  return 0;
}
