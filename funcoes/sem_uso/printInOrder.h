void printInOrder(tree *arvore)
{
  if(arvore == NULL)
    ;
  else
  {
    printInOrder(arvore->left);
    printf("%d\n", arvore->value);
    printInOrder(arvore->right);
  }
}
