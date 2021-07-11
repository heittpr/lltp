#include <stdio.h>
#include <stdlib.h>

#include "utils.c"
#include "bd.c"

void altera() {
  limpa_tela();
  float p;
  int id;

  while (1) {
    printf("Informe o id do produto: ");
    scanf("%d", &id);

    if (verifica_produto(id)) break;
    else printf("Id inválido!\n");
  }

  printf("Informe o novo preço: ");
  scanf("%f", &p);

  altera_preco(id, p);
  printf("Preço atualizado com sucesso!\n");
  pausa();
}

int main() {
  inicializa_banco();

  while (1) {
    limpa_tela();
    printf("Menu                        \n\
                                        \n\
  (1) Alterar o valor de um produto     \n\
  (2) Visualizar a lista de produtos    \n\
  (3) Fazer pedido                      \n\
  (4) Verificar o total vendido         \n\
  (5) Sair                              \n\n");
    
    int escolha;
    scanf("%i", &escolha);

    switch (escolha) {
      case 1:
        altera();
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
