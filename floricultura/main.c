#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.c"
#include "estoque.c"

int main() {
  // copia os valores do estoque para o estoque ordenado
  memcpy(estoque_ordenado, estoque, sizeof(estoque));

  while (1) {
    limpa_tela();
    printf("Menu                        \n\n\
  (1) Cadastrar flores                    \n\
  (2) Mostrar estoque                     \n\
  (3) Mostrar estoque (menos pra mais)    \n\
  (4) Mostrar estoque (mais pra menos)    \n\
  (5) Sair                              \n\n");

    int escolha;
    scanf("%d", &escolha);

    switch (escolha) {
      case 1:
        limpa_tela();
        cadastra();
        pausa();
        break;

      case 2:
        limpa_tela();
        mostra_estoque();
        pausa();
        break;

      case 3:
        limpa_tela();
        menos_pra_mais();
        pausa();
        break;

      case 4:
        limpa_tela();
        mais_pra_menos();
        pausa();
        break;

      case 5:
        limpa_tela();
        exit(0);
        break;
      
      default:
        limpa_tela();
        printf("Opção Inválida!\n");
        pausa();
    }
  }

  return 0;
}
