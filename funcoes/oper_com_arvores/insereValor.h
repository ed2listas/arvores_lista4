
// caso for red black
tree* insereVP(tree *arvore, int valor){
  int tipoDeArvore = TIPO_VP;
  tree *novo = (tree*)malloc(sizeof(tree));
  tree *aux = arvore;
  tree *ant;
  novo->value = valor;
  if (tipoDeArvore == TIPO_VP) {
    novo->color = VERMELHO;
  }
  novo->left = NULL;
  novo->right = NULL;
  if(arvore == NULL) {
    arvore = novo;
    return novo;
  }
  else{
    while(aux != NULL) {
      ant = aux;
      if(valor > aux->value)
        aux = aux->right;
      else
        aux = aux->left;
    }
    if(valor > ant->value)
      ant->right = novo;
    else
      ant->left = novo;
  }
  return arvore;
}

//   ===============    avl ========================

tree* insereAVL(tree *arvore, int valor){
  tree *pai = NULL, *novoNo = NULL, *aux = arvore;
  int pausar;

  novoNo = (tree*) malloc(sizeof(tree));
  novoNo->value = valor;
  novoNo->left = NULL;
  novoNo->right = NULL;
  novoNo->father = NULL;
  novoNo->fator_bal = 0;

  if(!novoNo){
    printf("Nao foi possivel alocar\n");
    return arvore;
  }

  // caso raiz for nula
  if(arvore == NULL){
    return novoNo;
  }

  // caso raiz não for nula
  aux = arvore;
  pai = aux;
  while(aux){
    if(valor < aux->value){
      pai = aux;
      aux = aux->left;
    } else {
      pai = aux;
      aux = aux->right;
    }
  }
  novoNo->father = pai;
  if (valor < pai->value) {
    pai->left = novoNo;
  } else {
    pai->right = novoNo;
  }

  // balanceando seus ancestrais
  aux = novoNo->father;
  while(aux != NULL) {
    aux->fator_bal = getHeight(aux->left) - getHeight(aux->right);

    if(abs(aux->fator_bal) > 1){
        //printf("esse cara ta desbal  %d [%d]\n", aux->value, aux->fator_bal);
        aux = balancear(arvore,aux);
        aux->fator_bal = getHeight(aux->left) - getHeight(aux->right);

    }
    if (aux->father == NULL) {
      return aux;
    }
    aux = aux->father;
  }

  return aux;
}

// **********************************

tree *insereValor(tree *arvore, int valor, int tipo) {
  if (tipo == TIPO_VP) {
    arvore = insereVP(arvore, valor);
  } else {
    arvore = insereAVL(arvore, valor);
  }
  return arvore;
}
