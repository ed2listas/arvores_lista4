
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
    tree *pai = NULL, *filho = NULL;
    tree *aux = NULL;
    int pausar;
    // caso for nula
    if(!arvore){
        arvore = (tree*) malloc(sizeof(tree));

        if(!arvore){
            printf("Nao foi possivel alocar\n");
            return arvore;
        }
        arvore->value = valor;
        arvore->left = NULL;
        arvore->right = NULL;
        arvore->father = NULL;
        arvore->fator_bal = 0;
        return arvore;
    }
    // caso raiz não for nula
    pai = arvore;
    filho = arvore;

    while(filho){
      if(valor < filho->value){
          filho = filho->left;
          if(!filho){
            pai->left = (tree*) malloc(sizeof(tree));

            if(!pai->left){
              printf("Erro ao alocar =(\n");
              exit(1);
            }

            filho = pai->left;

            filho->left = NULL;
            filho->right = NULL;
            filho->father = pai;
            filho->value = valor;
            break;
          }
          else{
              pai = filho;
          }
      }
      else{ //Para outro lado
        filho = filho->right;

        if(!filho){
          pai->right = (tree*) malloc(sizeof(tree));

          if(!pai->right){
              printf("Erro ao alocar =(\n");
              exit(1);
          }

          filho = pai->right;

          filho->left = NULL;
          filho->right = NULL;
          filho->father = pai;
          filho->value = valor;
          break;
        }
        else{
            pai = filho;
        }
      }
    }

    if(filho){
        aux = filho;
        while(aux){
            aux->fator_bal = getHeight(aux->left) - getHeight(aux->right);

            if(aux->fator_bal > 1 || aux->fator_bal < -1){
                arvore = balancear(arvore,aux); // aux = ...
            }
            aux = aux->father;
        }
        return arvore;
    }
}

// **********************************

tree *insereValor(tree *arvore, int valor, int tipo) {
  if (tipo == TIPO_VP) {
    arvore = insereVP(arvore, valor);
  }
  else {
    arvore = insereAVL(arvore, valor);
  }
  return arvore;
}
