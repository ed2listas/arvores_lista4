
tree * removeValue(tree * arvore, int valor, int tipoDeArvore) {
  tree *aux = arvore;
  tree *ant;
  tree *folha,*antFolha;
  int temp;

  if (arvore == NULL) {
    printf("arvore esta vazia!\n");
    pausar();
    return arvore;
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

  // caso o No tiver filho a esq
  if (aux->left != NULL && aux->right == NULL) {
    if (ant->value > valor)
      ant->left = aux->left;
    else
      ant->right = aux->left;
    free(aux);
  }
  // caso o No tiver filho a dir
  if (aux->left == NULL && aux->right != NULL) {
    if (ant->value > valor)
      ant->left = aux->right;
    else
      ant->right = aux->right;
    free(aux);
  }
  if (aux->left != NULL && aux->right != NULL) {
    folha = aux->right;
    antFolha = aux;
    while (folha->left != NULL) {
      antFolha = folha;
      folha = folha->left;
    }
    temp = folha->value;
    arvore = removeValue(arvore, folha->value, tipoDeArvore);
    aux->value = temp;
  }
  return arvore;
}

arvore_avl* men_dir(arvore_avl *arvore){
    while(arvore->esq){
        arvore = arvore->esq;
    }
    return arvore;
}

void remover_avl(arvore_avl *raiz, arvore_avl *aux){
    arvore_avl *aux2, *salva = aux->pai;
    if(aux != raiz){
        if(!aux->esq && !aux->dir){
            if(aux->valor < aux->pai->valor){
                aux->pai->esq = NULL;
            }
            else{
                aux->pai->dir = NULL;
            }
            free(aux);
        }
        else if(!aux->dir){
            if(aux->valor < aux->pai->valor){
                aux->pai->esq = aux->esq;
            }
            else{
                aux->pai->dir = aux->esq;
            }
            aux->esq->pai = aux->pai;
            free(aux);
        }
        else if(!aux->esq){
            if(aux->valor < aux->pai->valor){
                aux->pai->esq = aux->dir;
            }
            else{
                aux->pai->dir = aux->dir;
            }
            aux->dir->pai = aux->pai;
            free(aux);
        }
        else{
            aux2 = men_dir(aux->dir);
            aux->valor = aux2->valor;

            remover_avl(raiz, aux2);
        }
    }
    else{
        if(!aux->esq && !aux->dir){
            free(aux);
            raiz = NULL;
        }
        else if(!aux->dir){
            aux->esq->pai = NULL;
            raiz = aux->esq;
            free(aux);
        }
        else if(!aux->esq){
            aux->dir->pai = NULL;
            raiz = aux->dir;
            free(aux);
        }
        else{
            aux2 = men_dir(aux->dir);
            aux->valor = aux2->valor;

            remover_avl(raiz,aux2);
        }
    }
    if(salva){
        while(salva){
            salva->fator_bal = altura(salva->dir) - altura(salva->esq);

            if(salva->fator_bal > 1 || salva->fator_bal < -1){
                salva = balancear(raiz, salva);
            }

            salva = salva->pai;
        }
    }
}

void remove_chamada(arvore_avl *raiz, int valor){
    arvore_avl *aux;
    arvore_avl *aux2;

    aux2 = raiz;

    while(aux2 && aux2->valor != valor){
        if(valor < aux->valor){
            aux2 = aux2->esq;
        }
        else{
            aux2 = aux2->dir;
        }
    }

    if(aux){
        remover_avl(raiz,aux);
    }

    else{
        printf("Nao existe!\n");
    }
}
