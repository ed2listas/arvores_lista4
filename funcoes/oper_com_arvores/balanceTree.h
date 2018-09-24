
tree* rot_right(tree* raiz, tree *no){
  tree *temp = no->left;
  no->left = temp->right; // no pega filho esq de temp
  if (temp->right) {
    temp->right->father = no;
  }

  temp->right = no;
  temp->father = no->father;
  if (no->father)
    no->father->left = temp;


  no->father = temp;
  /*if (no == NULL) {
    printf("NO nulo\n");
  } else {
    printf("NO nao nulo, no eh %d\n",no->value);
  }
  printf("peso esq: %d,  peso dir: %d\n",getHeight(no->left), getHeight(no->right));
  */
  //printf("valor: %d, esq e dir = %d, %d\n", no->value, no->left->value, no->right->value);
  //printf("valor esq: %d\n", no->left->value);
  no->fator_bal = getHeight(no->left) - getHeight(no->right);
  //printf("chegou no meio ********\n");
  temp->fator_bal = getHeight(temp->left) - getHeight(temp->right);
  //printf("chegou aqui tambem ********\n");
  return temp;
}

tree* rot_left(tree* raiz, tree *no){
  tree *temp = no->right;
  no->right = temp->left; // no pega filho esq de temp
  if (temp->left) {
    temp->left->father = no;
  }
  temp->left = no;
  temp->father = no->father;
  if (no->father)
    no->father->right = temp;


  no->father = temp;
  no->fator_bal = getHeight(no->left) - getHeight(no->right);
  temp->fator_bal = getHeight(temp->left) - getHeight(temp->right);

  return temp;
}

tree* balancear(tree* raiz, tree *aux){
  tree* esq = aux->left;
  tree * bug;
   if(aux->fator_bal > 1){
     if(esq->fator_bal < 0){
        //aux->left = rot_left(raiz, aux->left);

        /*bug = aux->left->left;
        printf("veja: %d\n", aux->left->father->value);
        printf("bug: %d ***\n", bug->value);
        printf("pai: %d ***\n", bug->father->value);
        printf("avo: %d ***\n", bug->father->father->value);*/
     }
     aux = rot_right(raiz, aux);
   }
   else if(aux->fator_bal < -1){
       if(aux->right->fator_bal > 0){
           //aux->right = rot_right(raiz, aux->right);
       }
       aux = rot_left(raiz, aux);
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
