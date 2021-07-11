#include <stdio.h>
#include <stdlib.h>

#include "utils.c"
#include "bd.c"

float total;

void altera() {
  limpa_tela();
  int id = le_id();
  
  float p;
  printf("Informe o novo preço: ");
  scanf("%f", &p);

  altera_preco(id, p);
  printf("Preço atualizado com sucesso!\n");
  pausa();
}

void _adiciona_pedido(float *p) {
  int id = le_id();

  int qtd;
  printf("Informe a quantidade: ");
  scanf("%d", &qtd);

  (*p) += qtd * preco(id);
  pausa();
}

void _encerra_pedido(float total_pedido) {
  limpa_tela();
  printf("Total do pedido: %.2f\n", total_pedido);
  total += total_pedido;

  pausa();
}

void pedido() {
  limpa_tela();
  float total_pedido = 0;

  for (int i = 5; i >= 1; i--) {
    while(1) {
      limpa_tela();
      printf("Total: %.2f. O que você deseja fazer?\n\n", total_pedido);
      printf("  (1) Adicionar um novo item ao pedido (%d itens restantes).\n", i);
      printf("  (2) Encerrar pedido.\n\n");
      
      int escolha;
      int invalida = 0;
      scanf("%d", &escolha);

      switch (escolha) {
        case 1:
          _adiciona_pedido(&total_pedido);
          break;

        case 2:
          _encerra_pedido(total_pedido);
          return;
          break;

        default:
          printf("Opção inválida!");
          invalida = 1;
          pausa();
      }

      if (!invalida) break;
    }
  }

  printf("Limite de itens atingido!\n");
  _encerra_pedido(total_pedido);
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
        pedido();
        break;
        
      case 4:
        limpa_tela();
        printf("Total vendido: %.2f\n", total);
        pausa();
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
