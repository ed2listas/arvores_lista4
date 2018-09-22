#ifndef PAUSAR
#define PAUSAR

#include <stdio.h>

void pausar() {
  int i = 0;
  char lixo;
  printf("\nPressione enter para continuar...\n");
  scanf("%c", &lixo);
  while (lixo != '\n') { lixo = getc(stdin); }
}

#endif // PAUSAR
