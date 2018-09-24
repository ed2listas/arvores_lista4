/*tree *rodaDir(tree *arvore,tree *pai,tree *arvoreReal) {
  tree *aux = arvore->right;
  if (pai != NULL) {
    if (pai->left == arvore)
      pai->left = aux;
    else
      pai->right = aux;
    arvore->right = aux->left;
    aux->left = arvore;
  }
  else {
    arvore->right = aux->left;
    aux->left = arvore;
    arvoreReal = aux;
  }
  return arvoreReal;
}
tree *rodaEsq(tree *arvore,tree *pai,tree *arvoreReal) {
  tree *aux = arvore->left;
  if (pai != NULL) {
    if (pai->left == arvore)
      pai->left = aux;
    else
      pai->right = aux;
    arvore->left = aux->right;
    aux->right = arvore;
  }
  else {
    arvore->left = aux->right;
    aux->right = arvore;
    arvoreReal = aux;
  }
  return arvoreReal;
}

tree *rotaciona(tree *arvore,tree *pai,tree *arvoreReal) {
  if (arvore != NULL) {
    if (!verificaBalanceada(arvore)) {
      arvoreReal = rotaciona(arvore->left,arvore,arvoreReal);
      if (verificaBalanceada(arvore))
        return arvoreReal;
      arvoreReal = rotaciona(arvore->right,arvore,arvoreReal);
      if (verificaBalanceada(arvore))
        return arvoreReal;

      if (getHeight(arvore->left) > getHeight(arvore->right))
        arvoreReal = rodaEsq(arvore,pai,arvoreReal);
      else
        arvoreReal = rodaDir(arvore,pai,arvoreReal);
    }
  }
  return arvoreReal;
}
tree *balanceTree(tree *arvore) {
   if (arvore == NULL) {
     printf("arvore esta vazia\n");
     return arvore;
   }
   if(!verificaBalanceada(arvore)) {
     do {
       arvore = rotaciona(arvore,NULL,arvore);
     } while(!verificaBalanceada(arvore));
   } else {
     printf("arvore esta balanceada\n");
   }
   return arvore;
 }*/


arvore_avl* rot_direita(arvore_avl *raiz, arvore_avl *aux){
    arvore_avl *esq = aux->esquerda;

    aux->esquerda = esq->direita;
    esq->direita = aux;

    if(aux->esquerda){
        aux->esquerda->pai = aux;
    }

    esq->pai = aux->pai;
    aux->pai = esq;

    if(aux == raiz){
        raiz = esq;
    }

    if(esq->pai){
        if(esq->valor < esq->pai->valor){
            esq->pai->esquerda = esq;
        }
        else{
            esq->pai->direita = esq;
        }
    }

    esq->fb = altura(esq->direita) - altura(esq->esquerda);
    aux->fb = altura(aux->direita) - altura(aux->esquerda);

    return esq;
}

arvore_avl* rot_esquerda(arvore_avl *raiz, arvore_avl *aux){
    arvore_avl *dir = aux->direita;

    aux->direita = dir->esquerda;
    dir->esquerda = aux;

    if(aux->direita){
        aux->direita->pai = aux;
    }

    dir->pai = aux->pai;
    aux->pai = dir;

    if(aux == raiz){
        raiz = dir;
    }

    if(dir->pai){
        if(dir->valor < dir->pai->valor){
            dir->pai->esquerda = dir;
        }
        else{
            dir->pai->direita = dir;
        }
    }

    dir->fb = altura(dir->direita) - altura(dir->esquerda);
    aux->fb = altura(aux->direita) - altura(aux->esquerda);
    return dir;
}

arvore_avl* balancear(arvore_avl *raiz, arvore_avl *aux){
    if(aux->fb < -1){
        if(aux->esquerda->fb > 0){
            aux->esquerda = rot_esquerda(raiz, aux->esquerda);
        }

        aux = rot_direita(raiz, aux);
    }

    else if(aux->fb > 1){
        if(aux->direita->fb < 0){
            aux->direita = rot_direita(raiz, aux->direita);
        }

        aux = rot_esquerda(raiz, aux);
    }

    return aux;
}

int altura(arvore_avl* aux){
    if(!aux){
        return 0;
    }

    int alturaEsquerda = altura(aux->esquerda);
    int alturaDireita = altura(aux->direita);

    return (alturaEsquerda > alturaDireita) ? alturaEsquerda+ 1: alturaDireita + 1;
}
