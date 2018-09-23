tree* lerArvoreDoArquivo(tree *arvore,char *caminho, int *tipoDeArvore){
  //Declarações
  FILE *p_arq;
  int pause,valor,cor, aux, qualArq;
  //Instruções
  limparTela();
  printf("Qual arquivo quer carregar? \n\n");
  for(aux=1;aux<=5;aux++) printf("%d para 'arvore%d.txt'\n",aux,aux);
  printf("\nOpcao: ");
  do {
    scanf("%d", &qualArq);
  } while((qualArq < 0) || (qualArq > 5));
  limparTela();
  caminho[14] = '0' + qualArq;

  printf("Digite qual sera o tipo da arvore \n");
  printf("(%d para ", TIPO_VP);
  printComCor("verm", VERMELHO);
  printf("/");
  printComCor("preto", PRETO);
  printf(", %d para ", TIPO_AVL);
  printComCor("AVL", BRANCO);
  printf(")\n\n");


  do {
    scanf("%d", tipoDeArvore);
  } while((*tipoDeArvore != TIPO_VP) && (*tipoDeArvore != TIPO_AVL));
  limparTela();

  if ((p_arq=fopen(caminho,"r"))==NULL) {
      limparTela();
      printf("nao foi possivel encontrar a arvore\n\n\n\n");
      pausar();
      return NULL;
  }
  else {
    while((fscanf(p_arq,"%d", &valor)) != EOF) {
       arvore = insereValor(arvore, valor, *tipoDeArvore);
    }
    fclose(p_arq);
    return arvore;
  }
}
