tree *freeArvore(tree *arvore){
  if(arvore !=NULL){
    freeArvore(arvore->left);
    freeArvore(arvore->right);
    free(arvore);
  }
  return NULL;
}
