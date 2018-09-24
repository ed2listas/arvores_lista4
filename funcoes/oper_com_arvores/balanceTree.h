/*int getHeight(tree* aux){
    if(!aux){
        return 0;
    }

    int getHeightleft = getHeight(aux->left);
    int getHeightright = getHeight(aux->right);

    return (getHeightleft > getHeightright) ? getHeightleft+ 1: getHeightright + 1;
}*/

// rot right

tree* rot_right(tree* raiz, tree *aux){
  tree *c = aux;
  tree *pai = c->father;
  tree *b = c->left;


  pai->left = b;
  c->left = b->right;
  b->right = c;

  b->father = pai;
  c->father = b;

  b->fator_bal = getHeight(aux->left) - getHeight(aux->right);
  c->fator_bal = getHeight(aux->left) - getHeight(aux->right);

  return b;
  /*
   tree *left = aux->left;

   aux->left = left->right;
   left->right = aux;

   if(aux->left){
       aux->left->father = aux;
   }

   left->father = aux->father;
   aux->father = left;

   if(aux == raiz){
       raiz = left;
   }

   if(left->father){
       if(left->value < left->father->value){
           left->father->left = left;
       }
       else{
           left->father->right = left;
       }
   }

   left->fator_bal = getHeight(left->left) - getHeight(left->right);
   aux->fator_bal = getHeight(aux->left) - getHeight(aux->right);

   return left;*/
}

tree* rot_left(tree* raiz,tree *aux){
   tree *right = aux->right;

   aux->right = right->left;
   right->left = aux;

   if(aux->right){
       aux->right->father = aux;
   }

   right->father = aux->father;
   aux->father = right;

   if(aux == raiz){
       raiz = right;
   }

   if(right->father){
       if(right->value < right->father->value){
           right->father->left = right;
       }
       else{
           right->father->right = right;
       }
   }

   right->fator_bal = getHeight(right->left) - getHeight(right->right);
   aux->fator_bal = getHeight(aux->left) - getHeight(aux->right);
   return right;
}
tree* balancear(tree* raiz, tree *aux){

   if(aux->fator_bal > 1){
       if(aux->left->fator_bal < 0){
           aux->left = rot_left(raiz, aux->left);
       }

       raiz = rot_right(raiz, aux);
   }

   else if(aux->fator_bal > 1){
       if(aux->right->fator_bal < 0){
           aux->right = rot_right(raiz, aux->right);
       }
       raiz = rot_left(raiz, aux);
   }

   return raiz;
}

/*tree *rodaright(tree *arvore,tree *father,tree *arvoreReal) {
  tree *aux = arvore->right;
  if (father != NULL) {
    if (father->left == arvore)
      father->left = aux;
    else
      father->right = aux;
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
tree *rodaleft(tree *arvore,tree *father,tree *arvoreReal) {
  tree *aux = arvore->left;
  if (father != NULL) {
    if (father->left == arvore)
      father->left = aux;
    else
      father->right = aux;
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

tree *rotaciona(tree *arvore,tree *father,tree *arvoreReal) {
  if (arvore != NULL) {
    if (!verificaBalanceada(arvore)) {
      arvoreReal = rotaciona(arvore->left,arvore,arvoreReal);
      if (verificaBalanceada(arvore))
        return arvoreReal;
      arvoreReal = rotaciona(arvore->right,arvore,arvoreReal);
      if (verificaBalanceada(arvore))
        return arvoreReal;

      if (getHeight(arvore->left) > getHeight(arvore->right))
        arvoreReal = rodaleft(arvore,father,arvoreReal);
      else
        arvoreReal = rodaright(arvore,father,arvoreReal);
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
 }
*/
