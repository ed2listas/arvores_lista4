void insere_avl(arvore_avl *raiz, int valor);

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

void insere_avl(arvore_avl *raiz, int valor){
    arvore_avl *aux1 = NULL, *aux2 = NULL;

    if(!raiz){
        raiz = (arvore_avl*) malloc(sizeof(arvore_avl));

        if(!raiz){
            printf("Erro ao alocar =(\n");
            exit(1);
        }

        raiz->valor = valor;
        raiz->esquerda = NULL;
        raiz->direita = NULL;
        raiz->pai = NULL;

        raiz->fb = 0;
    }
    else{
        aux1 = raiz;
        aux2 = raiz;

        while(aux2){

            if(valor < aux2->valor){
                aux2 = aux2->esquerda;

                if(!aux2){
                    aux1->esquerda = (arvore_avl*) malloc(sizeof(arvore_avl));

                    if(!aux1->esquerda){
                        printf("Erro ao alocar =(\n");
                        exit(1);
                    }

                    aux2 = aux1->esquerda;

                    aux2->esquerda = NULL;
                    aux2->direita = NULL;
                    aux2->pai = aux1;
                    aux2->valor = valor;
                    break;
                }
                else{
                    aux1 = aux2;
                }
            }

            else{ //Para outro lado
                aux2 = aux2->direita;

                if(!aux2){
                    aux1->direita = (arvore_avl*) malloc(sizeof(arvore_avl));

                    if(!aux1->direita){
                        printf("Erro ao alocar =(\n");
                        exit(1);
                    }

                    aux2 = aux1->direita;

                    aux2->esquerda = NULL;
                    aux2->direita = NULL;
                    aux2->pai = aux1;
                    aux2->valor = valor;
                    break;
                }

                else{
                    aux1 = aux2;
                }
            }
        }
    }

    if(aux2){
        while(aux2){
            aux2->fb = altura(aux2->direita) - altura(aux2->esquerda);

            if(aux2->fb > 1 || aux2->fb < -1){
                aux2 = balancear(raiz, aux2);
            }

            aux2 = aux2->pai;
        }
    }
}
