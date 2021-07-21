// Limpa a tela
void limpa_tela() {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

// Limpa o buffer do teclado
void limpa_buffer() {
  int c;

  do { c = getchar(); }
  while (c != '\n' && c != EOF);
}

// Espera que o usuário pressione alguma tecla
void pausa() {
  limpa_buffer();
  printf("\nPressione qualquer tecla para continuar...");
  getchar();
}
