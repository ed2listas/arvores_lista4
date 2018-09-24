#define ESPACO " "

void debug(char *msg, int a, int x, int y) {
  static int linha = 1;
  gotoxy(1, 25+linha);
  printf("[%d] %s: %d", linha, msg, a);
  linha++;
  gotoxy(x, y);
}

void printaValor(int valor, int cor, int tipo, int fator) {
  if (tipo == TIPO_VP) {
    if (cor == VERMELHO)
      background(RED);
    else
      background(BLACK);
    printf("%d",valor);
    style(RESETALL);
  }
  else
    //printf("%d (%d)",valor,fator);
    printf("%d",valor);
}

void printaRecursivo(tree *no, int tipo, int sizeLine, int posX, int posY) {
  int pos = posX / 2, i;
  char pausa;
  gotoxy(posX, posY);
  //debug("linha", sizeLine, posX, posY);
  printaValor(no->value, no->color, tipo, no->fator_bal);
  //debug("tamanho linha", sizeLine, posX, posY);
  //debug("posX", posX, posX, posY);
  //scanf("%c", &pausa);
  if (no->left) {
    for (i = 1; i <= sizeLine; i++) {
      gotoxy(posX-i, posY+i);
      printf("/");
    }
    printaRecursivo(no->left, tipo, sizeLine/2, posX-sizeLine, posY+sizeLine+1);
  }

  if (no->right) {
    for (i = 1; i <= sizeLine; i++) {
      gotoxy(posX+i, posY+i);
      printf("\\");
    }
    printaRecursivo(no->right, tipo, sizeLine/2, posX+sizeLine, posY+sizeLine+1);
  }
}

void mostraArvore(tree *arvore, int tipo) {
  int h = getHeight(arvore)-1, pausa;
  int posX = 2*pow(2, h), posY = 5;

  printf(" ========================================\n");
  printf(" | Arvore %-30s|\n", (tipo == TIPO_VP ? "vermelho/preto" : "AVL"));
  printf(" ========================================\n");
  if (arvore != NULL){
    printaRecursivo(arvore, tipo, posX/2, posX, posY);
    gotoxy(1,posX+h+posY);
  } else {
    printf("Sem arvore carregada\n");
  }
}
