tree* insereValor(tree *arvore, int valor, int tipoDeArvore){
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
