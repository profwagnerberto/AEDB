int main() {
  struct Pilha meusLivros;
  int opcao, ISBNdoLivro;
  do{
    printf("Menu\n");
    printf("====\n");
    printf("1-Limpar mesa para empilhar livros. \n");
    printf("2-Colocar livro na pilha. \n");
    printf("3-Tirar livro da pilha. \n");
    printf("O-Encerrar. \n");
    printf("\n");
    printf("Digite o numero da opcao ==> ");
    scanf("%d",&opcao);
    if (opcao==1) {
      criarPilha(&meusLivros, 5);
      printf("Mesa limpa. \n");
    }else
    if (opcao==2) {
      printf("Informe o ISBN do livro a ser colocado na pilha: ");
      scanf("%d", &ISBNdoLivro);
      if (estahCheia(&meusLivros)==1)
        printf("Nao cabem mais livros\n");
      else{
        empilhar(&meusLivros, ISBNdoLivro);
        printf("Livro colocado na pilha. \n");
      }
    }else
    if (opcao==3){
      if(estahVazia(&meusLivros)==1)
        printf ("Nao tem mais livros\n");
      else{
        ISBNdoLivro=desempilhar(&meusLivros);
        printf ("ISBN do livro: %d.\n", ISBNdoLivro);
      }
    }else
    if(opcao==0)
      printf("Encerrando o programa... \n");
  }while(opcao!=0);

  return 0;
}