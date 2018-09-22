#ifndef LIMPAR_TELA
#define LIMPAR_TELA
  #if defined(linux) || defined(LINUX) || defined(Linux) || defined(UNIX)
  //código específico para linux
  void limparTela() {
    system("clear");
  }
  #elif defined(WIN32) || defined(Win32) || defined(win32) || defined(WIN64) || defined(Win64) || defined(win64)
  //código específico para windows
  void limparTela() {
    system("cls");
  }
  #else
  //sistema operacional desconhecido
  void limparTela() {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
  }
  #endif
#endif // LIMPAR_TELA
