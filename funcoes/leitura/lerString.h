#ifndef LER_STRING
#define LER_STRING

#include <stdio.h>

// objetivo:    Ler entrada de caracteres do teclado, e armazenar na string
// parametros:  vetor de caracteres e tamanho desse vetor

void lerString(char *string, int nroLetras) {
  int i = 0;
  char lixo;
  scanf("%c", string);
  if (*string != '\n')
    while ( ((string[++i] = getc(stdin) ) != '\n') && (i < nroLetras-1)) {}
  if(i == nroLetras-1) while ((lixo = getc(stdin) ) != '\n') {}
  string[i] = '\0';
}

#endif // LER_STRING
