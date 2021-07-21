// Limpa a tela
void limpa_tela() {
  system("clear");
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

/*
  Conta o número de caracteres
  não-ASCII de uma string
*/
int nao_ascii(const char *str) {
  int tam = 0;

  while (*str != '\0') {
    if ((*str & 0xc0) == 0x80)
      tam++;
    
    str++;
  }

  return tam;
}

/*
  Imprime exatamente tam caracteres
  de uma string adicionando espaços ou
  ignorando caracteres se necessário,
  seguida de um espaço
*/
void imprime_tam(const char *str, int tam) {
  int k = tam + nao_ascii(str);
  printf("%*.*s ", -k, k, str);
}
