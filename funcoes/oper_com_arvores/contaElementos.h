void contaElementos(tree *arvore,int *elementos)
{
  if(arvore != NULL) {
    *elementos = *elementos + 1;
    contaElementos(arvore->left,elementos);
    contaElementos(arvore->right,elementos);
  }
}
