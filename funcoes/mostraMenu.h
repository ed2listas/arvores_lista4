int mostraMenu(){
    int opcao;
    //printf("\n");
    printf(" ========================================\n");
    printf("|         >>>>>>>>> Menu <<<<<<<<<       |\n");
    printf("| 1 - Inserir valor                      |\n");
    printf("| 2 - Remover valor                      |\n");
    printf("| 3 - Carregar arvore de arquivo         |\n");
    printf("| 0 - Sair                               |\n");
    printf(" ========================================\n");
    printf("Sua opcao: ");
    scanf("%d",&opcao);
    return opcao;
}
