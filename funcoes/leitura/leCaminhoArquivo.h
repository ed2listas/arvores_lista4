void leCaminhoArquivo(char *caminho){
  int pause;
  char nome[9];
  printf("Nome do arquivo: ");
  limpaBuffer();
  fgets(nome,5,stdin);
  tiraTerminador(nome);
  strcat(nome, ".txt");
  strcpy(caminho, "./BSTs/");
  strcat(caminho, nome);
}
