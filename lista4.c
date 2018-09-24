//Alunos: Joberth Rogers Tavares Costa                  16/0128013
//        Marcelo Araujo dos Santos                     16/0035481

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PRETO 0
#define VERMELHO 1
#define BRANCO 2
#define TIPO_AVL 0
#define TIPO_VP 1

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))
/*#define moveUp() printf("\033[XA")
#define moveDown() printf("\033[XB")
#define moveRight() printf("\033[XC")
#define moveLeft() printf("\033[XD")
printf("\033[2J"); // Clear screen*/

typedef struct TREE {
  int value;
  int color;
  int fator_bal;
  struct TREE *father;
  struct TREE *left;
  struct TREE *right;
}tree;


#include "funcoes/_todas.h"

int main() {
  char lixo;
  char caminho[] = "arquivo/arvorex.txt";
  int opcao,valor;
  int tipo = TIPO_AVL;
  tree *arvore = NULL;
  tree *aux;
  limparTela();

  // carrega arvore
  //arvore = lerArvoreDoArquivo(arvore, caminho, &tipo);

  do {
    // mostra arvore
    mostraArvore(arvore, tipo);
    opcao = mostraMenu();
    //limparTela();
    switch(opcao) {
      case 1: // inseri valor
        leValor(&valor);
        limparTela();
        arvore = insereValor(arvore, valor, tipo);
        // apos inserir, fazer balanceamento e outras coisas
        break;
      case 2: // remover valor
        leValor(&valor);
        limparTela();
        arvore = removeValue(arvore, valor);
        break;
      case 3: // carregar arvore
        arvore = freeArvore(arvore);
        arvore = lerArvoreDoArquivo(arvore, caminho, &tipo);
        break;
      case 0: // sair
        arvore = freeArvore(arvore);
    }
  }while(opcao != 0);

  return 0;
}
