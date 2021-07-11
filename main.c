#include <stdio.h>
#include <stdlib.h>

#include "utils.c"
#include "bd.c"

int main() {
  inicializa_banco();

  while (1) {
    limpa_tela();
    printf("                              \n\
Menu                                      \n\
                                          \n\
  (1) Alterar o valor de um produto       \n\
  (2) Visualizar a lista de produtos      \n\
  (3) Fazer pedido                        \n\
  (4) Verificar o total vendido           \n\
  (5) Sair                                \n");
    
    int escolha;
    scanf("%i", &escolha);

    switch (escolha) {
      case 1:
        break;
        
      case 2:
        limpa_tela();
        mostra_produtos();
        pausa();
        break;
        
      case 3:
        break;
        
      case 4:
        break;
      
      case 5:
        limpa_tela();
        exit(0);
        
      default:
        limpa_tela();
        printf("Opção Inválida!\n");
        pausa();
    }
  }

  return 0;
}
