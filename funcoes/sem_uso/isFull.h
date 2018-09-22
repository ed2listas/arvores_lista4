void isFull(tree *arvore){
  int altura = getHeight(arvore);
  int elementosMax = (pow(2,altura)) - 1;
  int elementos = 0;
  contaElementos(arvore,&elementos);
  if(elementos == elementosMax)
    printf("A arvore e cheia\n");
  else
    printf("A arvore nao e cheia\n");
}
