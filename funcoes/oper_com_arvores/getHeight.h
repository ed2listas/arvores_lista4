/*int getHeight(tree *arvore){
  if(arvore == NULL) {
    return 0;
  }
  printf("valor q chegou: %d\n", arvore->value);
  int height_left = getHeight(arvore->left);
  int height_right = getHeight(arvore->right);

  if(height_left > height_right)
    return(height_left + 1);
  else
    return(height_right + 1);
}*/

int getHeight(tree* aux){
    static int ciclos = 0;
    if(!aux){
        return 0;
    }
    //printf("[%d] valor q chegou: %d\n",++ciclos, aux->value);
    /*if (ciclos == 50) {
      exit(1);
    }*/
    int alturaesq = getHeight(aux->left);
    int alturadir = getHeight(aux->right);

    return (alturaesq > alturadir) ? alturaesq+ 1: alturadir + 1;
}
