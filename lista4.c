//Alunos: xxxxxxxxxxxxxxxxxxxx                          xx/xxxxxxx
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

typedef struct TREE {
  int value;
  int color; // só usado se for arvore VP
  struct TREE *left;
  struct TREE *right;
}tree;

#include "funcoes/_todas.h"

int main() {
  char lixo;
  char caminho[] = "arquivo/arvore1.txt";
  int opcao,valor;
  int tipo; // tipo vermelho preto
  tree *arvore = NULL;
  tree *aux;

  // carrega arvore
  arvore = lerArvoreDoArquivo(arvore, caminho, &tipo);

  do {
    // mostra arvore
    mostraArvore(arvore, tipo);

    opcao = mostraMenu();
    //limparTela();
    switch(opcao)
    {
      case 1: // inseri valor
        leValor(&valor);
        limparTela();
        arvore = insereValor(arvore, valor, tipo);
        // apos inserir, fazer balanceamento e outras coisas
        break;
      case 2: // remover valor
        leValor(&valor);
        limparTela();
        arvore = removeValue(arvore, valor, tipo);
        // apos remover, fazer balanceamento e outras coisas
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