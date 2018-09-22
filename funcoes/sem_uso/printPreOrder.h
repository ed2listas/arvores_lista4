void printPreOrder(tree *arvore)
{
  if(arvore == NULL)
    ;
  else
  {
    printf("%d\n",arvore->value);
    printPreOrder(arvore->left);
    printPreOrder(arvore->right);
  }
}
