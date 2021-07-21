typedef struct flor {
  char nome[11];
  char id;
  int qtd;
} flor;

flor estoque[5] = {
  { .nome="Rosa"      , .id='R' , .qtd=0 },
  { .nome="Margarida" , .id='M' , .qtd=0 },
  { .nome="Cravo"     , .id='C' , .qtd=0 },
  { .nome="Girassol"  , .id='G' , .qtd=0 },
  { .nome="Hortência" , .id='H' , .qtd=0 }
};

flor estoque_ordenado[5];

// função de comparação para o qsort
int cmp(const void *_a, const void *_b) {
  // transforma os ponteiros void em pointeiros flor
  flor *a = (flor *)_a;
  flor *b = (flor *)_b;

  return a->qtd > b->qtd;
}

// cria uma cópia ordenada do estoque em um endereço
void ordena(flor e[]) {
  memcpy(e, estoque, sizeof(estoque));
  qsort(e, 5, sizeof(flor), cmp);
}

void cadastra() {
  for (int i = 0; i < 5; i++) {
    flor *ptr = &estoque[i]; 
    limpa_buffer();
    
    while (1) {
      printf("Insira um valor para a flor %s (%c): ", ptr->nome, ptr->id);  
      
      if (scanf("%d", &ptr->qtd) == 1)
       break;
      else {
        printf("Valor inválido!\n");
        limpa_buffer();
      }  
    }
  }

  // atualiza o estoque ordenado
  ordena(estoque_ordenado);
}

void mostra_estoque() {
  for (int i = 0; i < 5; i++)
    printf("%s: %d unidades\n", estoque[i].nome, estoque[i].qtd);
}

void menos_pra_mais() {
  for (int i = 0; i < 5; i++)
    printf("%s: %d unidades\n", estoque_ordenado[i].nome, estoque_ordenado[i].qtd);
}

void mais_pra_menos() {
  for (int i = 4; i >= 0; i--)
    printf("%s: %d unidades\n", estoque_ordenado[i].nome, estoque_ordenado[i].qtd);
}
