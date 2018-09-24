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

 int altura(arvore_avl* aux){
     if(!aux){
         return 0;
     }

     int alturaesq = altura(aux->esq);
     int alturadir = altura(aux->dir);

     return (alturaesq > alturadir) ? alturaesq+ 1: alturadir + 1;
}

arvore_avl* rot_dir(arvore_avl* raiz, arvore_avl *aux){
    arvore_avl *esq = aux->esq;

    aux->esq = esq->dir;
    esq->dir = aux;

    if(aux->esq){
        aux->esq->pai = aux;
    }

    esq->pai = aux->pai;
    aux->pai = esq;

    if(aux == raiz){
        raiz = esq;
    }

    if(esq->pai){
        if(esq->valor < esq->pai->valor){
            esq->pai->esq = esq;
        }
        else{
            esq->pai->dir = esq;
        }
    }

    esq->fator_bal = altura(esq->dir) - altura(esq->esq);
    aux->fator_bal = altura(aux->dir) - altura(aux->esq);

    return esq;
}

arvore_avl* rot_esq(arvore_avl* raiz,arvore_avl *aux){
    arvore_avl *dir = aux->dir;

    aux->dir = dir->esq;
    dir->esq = aux;

    if(aux->dir){
        aux->dir->pai = aux;
    }

    dir->pai = aux->pai;
    aux->pai = dir;

    if(aux == raiz){
        raiz = dir;
    }

    if(dir->pai){
        if(dir->valor < dir->pai->valor){
            dir->pai->esq = dir;
        }
        else{
            dir->pai->dir = dir;
        }
    }

    dir->fator_bal = altura(dir->dir) - altura(dir->esq);
    aux->fator_bal = altura(aux->dir) - altura(aux->esq);
    return dir;
}
arvore_avl* balancear(arvore_avl* raiz, arvore_avl *aux){
    if(aux->fator_bal < -1){
        if(aux->esq->fator_bal > 0){
            aux->esq = rot_esq(raiz, aux->esq);
        }

        aux = rot_dir(raiz, aux);
    }

    else if(aux->fator_bal > 1){
        if(aux->dir->fator_bal < 0){
            aux->dir = rot_dir(raiz, aux->dir);
        }

        aux = rot_esq(raiz, aux);
    }

    return aux;
}
