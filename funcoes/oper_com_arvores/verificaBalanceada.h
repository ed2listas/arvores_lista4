int verificaBalanceada(tree *arvore){
  if(arvore == NULL)
    return 1; // true
  else {
    if(abs(getHeight(arvore->left) - getHeight(arvore->right)) > 1){
      return 0; // false
    }
    verificaBalanceada(arvore->left);
    verificaBalanceada(arvore->right);
  }
}
