tree * removeValue(tree * arvore, int valor) {

  tree *aux = arvore;
  tree *ant;
  tree *folha,*antFolha;
  int temp;

  if (arvore == NULL) {
    printf("arvore esta vazia!\n");
    pausar();
    return arvore;
  }
  if (arvore->left == NULL) {
    if (arvore->right == NULL) {
      free(arvore);
      return NULL;
    }
  }
  // primeiro procuramos o valor
  while(aux->value != valor){
    ant = aux;
    if(valor > aux->value)
      aux = aux->right;
    else
      aux = aux->left;
    if (aux == NULL) {
      printf("valor %d nao foi encontrado!\n\n", valor);
      printf("digite qualquer numero e aperte enter para continuar...\n");
      int pausa;
      scanf("%d", &pausa);
      return arvore;
    }
  }

  // caso o No nao tiver filho
  if ((aux->right == NULL) && (aux->left == NULL)) {
    if(valor > ant->value)
      ant->right = NULL;
    else
      ant->left = NULL;
    free(aux);
  }

  // caso o No tiver filho a esquerda
  if (aux->left != NULL && aux->right == NULL) {
    if (ant->value > valor)
      ant->left = aux->left;
    else
      ant->right = aux->left;
    free(aux);
  }
  // caso o No tiver filho a direita
  if (aux->left == NULL && aux->right != NULL) {
    if (ant->value > valor)
      ant->left = aux->right;
    else
      ant->right = aux->right;
    free(aux);
  }
  //caso o No tiver 2 filhos
  // if (aux->left != NULL && aux->right != NULL) {
  //   folha = aux->right;
  //   while (folha->left == NULL || folha->right == NULL) {
  //     folha = aux->left;
  //   }
  //   aux->value = folha->value;
  //   arvore = removeValue(arvore, folha->value);
  //   printf("removido do meio\n");
  //   pausar();
  // }
  if (aux->left != NULL && aux->right != NULL) {
    folha = aux->right;
    antFolha = aux;
    while (folha->left != NULL) {
      antFolha = folha;
      folha = folha->left;
    }
    temp = folha->value;
    arvore = removeValue(arvore, folha->value);
    aux->value = temp;
    //printf("removido do meio\n");
    //pausar();
  }
  return arvore;
}
