#define ESPACO " "


void printaValor(int valor, int cor, int tipoDeArvore) {
  if(valor != 0) {
    if (tipoDeArvore == TIPO_VP) {
      if (cor == VERMELHO)
        background(RED);
      else
        background(BLACK);
      printf("%2d",valor);
      style(RESETALL);
    }
    else
      printf("%2d",valor);
  }
  else
    printf(ESPACO);
}

void mostraArvore(tree *arvore, int tipoDeArvore) {
    tree *aux = arvore;
    int altura = getHeight(arvore);
    int elementos = (pow(2,altura)) - 1;
    int ordem[elementos],cor[elementos],i = 0,atual = 0,numNivel ,cont,j,
    espacosParede = 0,espacosEntre = 3,contAux,aumentaEspaco;

    printf(" ========================================\n");
    printf(" = Arvore %s\n\n", (tipoDeArvore == TIPO_VP ? "vermelho/preto" : "AVL"));
    if (aux == NULL){
      printf("Nao ha arvore carregada\n");
      return;
    }//printf("Numero de elementos no maximo da arvore de altura %d = %d \n",altura, elementos);
    ordem[i] = aux->value;
    if(tipoDeArvore == TIPO_VP)
      cor[i] = aux->color;
    i++;

    while(i < elementos) {
        if(ordem[atual] == 0) {
          ordem[i] = 0;
          cor[i] = -1;
          i++;
        }
        else {
          aux = searchValue(arvore,ordem[atual]);// como estou reaproveitando a funcao searchValue q devolve o pai, devo encontrar o valor novamente
          if(aux->left != NULL){
            if(aux->left->value == ordem[atual])
              aux = aux->left;
          }
          if(aux->right != NULL){
            if(aux->right->value == ordem[atual])
              aux = aux->right;
          }
          if (aux->left != NULL) {
            ordem[i]= aux->left->value;
            if(tipoDeArvore == TIPO_VP)
              cor[i] = aux->left->color;
          }
          else {
            ordem[i] = 0;
            cor[i] = -1;
          }
          i++;
          if (aux->right != NULL) {
            ordem[i]= aux->right->value;
            if(tipoDeArvore == TIPO_VP)
              cor[i] = aux->right->color;
          }
          else {
            ordem[i] = 0;
            cor[i] = -1;
          }
          i++;
        }
        atual++;
    }

    atual = 1;
    i = 1;
    j = 1;
    numNivel = 2;
    aumentaEspaco = ((espacosEntre - 1) / 2) + 1;
    for(cont = 0; cont < (altura-1) ;cont++){
      espacosParede = espacosParede + aumentaEspaco;
      aumentaEspaco = 2*aumentaEspaco;
    }
    for(cont = 0; cont < (altura-1) ;cont++)
      espacosEntre = (2*espacosEntre) + 1;

    for(cont = 0;cont < espacosParede;cont++)
      printf(ESPACO);

    printaValor(ordem[0],cor[0],tipoDeArvore);
    printf("\n");
    aumentaEspaco = aumentaEspaco / 2;
    espacosParede = espacosParede - aumentaEspaco;
    aumentaEspaco = aumentaEspaco / 2;
    espacosEntre = espacosEntre - 1;
    espacosEntre = espacosEntre / 2;

    do {
      for(cont = 0;cont < espacosParede;cont++){
        printf(ESPACO);
      }
      for(cont = 0;cont < numNivel;cont++){
        if(j % 2 == 1){
          if(ordem[j] != 0)
            printf("/");
          else
            printf(ESPACO);
        }
        if(j % 2 == 0){
          if(ordem[j] != 0)
            printf("\\");
          else
            printf(ESPACO);
        }
        if(cont < numNivel-1){
          for(contAux = 0; contAux < espacosEntre ;contAux++){
            printf(ESPACO);
          }
        }
        j++;
      }
      printf("\n");
      for(cont = 0;cont < espacosParede;cont++){
        printf(ESPACO);
      }
      for(cont = 0;cont < numNivel;cont++){
        if((i % 2 == 1) || (i % 2 == 0)){
          printaValor(ordem[i], cor[i], tipoDeArvore);
        }
        if(cont < numNivel-1){
          for(contAux = 0; contAux < espacosEntre;contAux++)
            printf(ESPACO);
        }
        i++;
      }
      printf("\n");
      numNivel = 2*numNivel;
      espacosParede = espacosParede - aumentaEspaco;
      aumentaEspaco = aumentaEspaco / 2;
      espacosEntre = espacosEntre - 1;
      espacosEntre = espacosEntre / 2;

    }while(i < elementos);
}

/*
void arvoreParaVetor(tree *arvore, int *pos, int *v) {
  if(arvore) {
    arvoreParaVetor(arvore->left, pos, v);
    v[*pos] = arvore->value;
    *pos += 1;
    arvoreParaVetor(arvore->right, pos, v);
  }
}
*/
