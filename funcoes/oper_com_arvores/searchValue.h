tree *searchValue(tree *arvore,int valor){
  tree *aux = arvore,*ant = NULL;
  while(aux != NULL && aux->value != valor){
    ant = aux;
    if(valor > aux->value){
      aux = aux->right;
    }
    else if(valor < aux->value){
      aux = aux->left;
    }
  }
  if(ant == NULL)
    return aux;
  else if(aux->value == valor)
    return ant;
  else
    return NULL;
}
