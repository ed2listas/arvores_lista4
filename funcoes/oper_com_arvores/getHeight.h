int getHeight(tree *arvore){
  if(arvore == NULL)
    return 0;

  int height_left = getHeight(arvore->left);
  int height_right = getHeight(arvore->right);

  if(height_left > height_right)
    return(height_left + 1);
  else
    return(height_right + 1);
}
