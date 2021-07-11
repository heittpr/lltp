#include <sqlite3.h>
sqlite3 *db;

/*
  Wrapper para a função sqlite3_exec 
  (sqlite.org/c3ref/exec.html)

  Executa uma query no banco e lida
  com os eventuais erros.
*/
void executa_sql(char *sql, int (*callback)(void*,int,char**,char**), void *arg) {
  char *err;  // mensagem de erro
  int cod;    // código de retorno

  cod = sqlite3_exec(db, sql, callback, arg, &err);

  if (cod != SQLITE_OK) {
    fprintf(stderr, "%s\n", err);

    sqlite3_free(err);
    sqlite3_close(db);

    exit(1);
  }
}

// Inicializa o banco de dados
void inicializa_banco() {
  sqlite3_open("bd.sqlite", &db);
  
  char *sql = "                           \
    CREATE TABLE IF NOT EXISTS Produto (  \
      Id INTEGER PRIMARY KEY,             \
      Nome TEXT NOT NULL,                 \
      Preco NUMERIC NOT NULL              \
    );                                    \
                                          \
    INSERT OR IGNORE INTO Produto         \
      (Id, Nome, Preco)                   \
    VALUES                                \
      (1, 'Arroz', 15.99),                \
      (2, 'Feijão', 4.5),                 \
      (3, 'Óleo', 7.99),                  \
      (4, 'Macarrão', 2.75),              \
      (5, 'Farinha de trigo', 4),         \
      (6, 'Leite', 3.2),                  \
      (7, 'Café', 10.5),                  \
      (8, 'Açúcar', 3.75),                \
      (9, 'Sal', 1.99),                   \
      (10, 'Sabonete', 0.99);             \
  ";

  executa_sql(sql, 0, 0);
}

int cabecalho;

// Callback para a função mostra produtos
int _mostra_produtos(void *ponteiro, int argc, char **argv, char **nomeColuna) {
  int tamanhoColuna[3] = {3, 18, 10};

  // Imprime o cabeçalho
  if (!cabecalho) {
    for (int i = 0; i < argc; i++)
      imprime_tam(nomeColuna[i], tamanhoColuna[i]);

    printf("\n\n");

    cabecalho = 1;
  }

  // Imprime a coluna
  for (int i = 0; i < argc; i++)
    imprime_tam(argv[i], tamanhoColuna[i]);

  printf("\n");
  return 0;
}

// Imprime os conteúdos da tabela Produto
void mostra_produtos() {
  cabecalho = 0;
  executa_sql("SELECT * FROM Produto", _mostra_produtos, 0);
}

// Callback para a função verifica_produto
int _verifica_produto(void *ponteiro, int argc, char **argv, char **nomeColuna) {
  int *ret = (int *)ponteiro;
  *ret = 1;
  
  return 0;
}

// Verifica se existe um produto com certo id
int verifica_produto(int id) {
  char sql[50];
  sprintf(sql, "SELECT Id FROM Produto WHERE Id = %d", id);

  int ret = 0;
  executa_sql(sql, _verifica_produto, &ret);
  return ret;
}

// Altera o preço de um produto
void altera_preco(int id, float p) {
  char sql[50];
  sprintf(sql, "UPDATE Produto SET Preco=%f WHERE Id=%d", p, id);

  executa_sql(sql, 0, 0);
}

// Callback para a função preco
int _preco(void *ponteiro, int argc, char **argv, char **nomeColuna) {
  // salva o resultado da query no endereço especificado
  float *ret = (float *)ponteiro;
  *ret = atof(argv[0]);
  
  return 0;
}

// Obtem o preço de um produto
float preco(int id) {
  char sql[50];
  sprintf(sql, "SELECT Preco FROM Produto WHERE Id=%d", id);
  
  float ret;
  executa_sql(sql, _preco, &ret);
  return ret;
}
