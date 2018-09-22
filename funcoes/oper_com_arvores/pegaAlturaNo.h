int pegaAlturaNo(tree *arvore,int valor){
  tree *aux = arvore;
  int altura = 1;
  while(aux != NULL && aux->value != valor){
    if(valor > aux->value){
      aux = aux->right;
    }
    else if(valor < aux->value){
      aux = aux->left;
    }
    altura++;
  }
  return altura;
}
