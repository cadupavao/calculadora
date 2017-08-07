/***************************************************************************************************************************************************************************************************************************
Alunos: Carlos Eduardo Pavão Aureliano & Pedro Bortolin
Matrículas: 2017.1.08.017 & 2017.1.08.031
Professor(es): Bressan & Andressa
***************************************************************************************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Criação de types */

typedef struct {

  char sobrenome[15];
  char nome[20];
  int celular[12];
  int CPF[12];
  int numero_da_conta[6];
  int saldo_da_conta_corrente[12];
  int saldo_da_aplicacao_CDB[12];
  int saldo_na_aplicacao_poupanca[12];

} cliente;

typedef struct {

  int numero_da_conta[6];
  int valor_da_movimentacao[12];
  int movimentacao[1];
  char descricao[30];
  char data[10];


} movimentacao;

/* Fim Criação de types */

/* Menu De Opçoes */
int menu(){

  int escolha;

  printf("\n*********** MENU DE OPCOES ***********\n");
  printf("\n* 1 - Inserir cliente:               *\n");
  printf("\n* 2 - Alterar cliente:               *\n");
  printf("\n* 3 - Deletar cliente:               *\n");
  printf("\n* 4 - Buscar cliente:                *\n");
  printf("\n* 5 - Inserir movimentacao:          *\n");
  printf("\n* 6 - Buscar saldos de um cliente:   *\n");
  printf("\n* 7 - Sair                           *\n");
  printf("\n* Escolha uma das opcoes acima:      *\n");
  printf("\n**************************************\n");
  fflush(stdout);
  scanf("%d", &escolha);

  return escolha;

}
/* Fim Do Menu */

/* Funçoes Do Menu */

int comparacao( const char *a, const char *b){
  int r = strcasecmp(a, b);
  if (r) return r;
  return -strcmp(a, b);
}

void ordem_alfabetica(cliente* clientes, int n){
  int i;
  cliente aux;
  for (i = 0; i<n-1; i++){
    if (comparacao(clientes[i+1].sobrenome, clientes[i].sobrenome) < 0){
      aux = clientes[i];
      clientes[i] = clientes[i+1];
      clientes[i+1] = aux;
      i = 0;
    }
  }
}

void salvarCliente(cliente* clientes, int n){

  FILE *arquivos;
  ordem_alfabetica(clientes, n);
  arquivos = fopen("cliente.txt", "w+");
  fprintf(arquivos, "%d", n);
  fprintf(arquivos, "\n");

  int i;

  for (i = 0; i < n; i++){

    fprintf(arquivos, "%s ", clientes[i].sobrenome);
    fprintf(arquivos, "%s ", clientes[i].nome);
    fprintf(arquivos, "%s ", clientes[i].celular);
    fprintf(arquivos, "%s ", clientes[i].CPF);
    fprintf(arquivos, "%s ", clientes[i].numero_da_conta);
    fprintf(arquivos, "%s ", clientes[i].saldo_da_conta_corrente);
    fprintf(arquivos, "%s ", clientes[i].saldo_da_aplicacao_CDB);
    fprintf(arquivos, "%s ", clientes[i].saldo_na_aplicacao_poupanca);
    fprintf(arquivos, "\n");

  }

  fclose(arquivos);

}

void salvarMovimentacao(movimentacao* movimentacoes, int n){

  FILE *arquivos;
  arquivos = fopen("movimentacao.txt", "w+");
  fprintf(arquivos, "%d", n);
  fprintf(arquivos, "\n");

  int i;

  for (i = 0; i < n; i++){

    fprintf(arquivos, "%d", movimentacoes[i].numero_da_conta);
    fprintf(arquivos, "%d", movimentacoes[i].valor_da_movimentacao);
    fprintf(arquivos, "%d", movimentacoes[i].movimentacao);
    fprintf(arquivos, "%s", movimentacoes[i].descricao);
    fprintf(arquivos, "%s", movimentacoes[i].data);

  }

  fclose(arquivos);

}

void inserirCliente(cliente* clientes, int n){
  cliente cliente;

  printf("\nDigite o sobrenome: \n");
  scanf("%s", &cliente.sobrenome);

  printf("\nDigite o nome:\n");
  scanf("%s", &cliente.nome);

  printf("\nDigite o número do celular:\n");
  scanf("%s", &cliente.celular);

  printf("\nDigite o número de CPF:\n");
  scanf("%s", &cliente.CPF);

  printf("\nDigite o Numero da conta:\n");
  scanf("%s", &cliente.numero_da_conta);

  printf("\nDigite o saldo da conta corrente:\n");
  scanf("%s", &cliente.saldo_da_conta_corrente);

  printf("\nDigite o saldo na aplicação CDB:\n");
  scanf("%s", &cliente.saldo_da_aplicacao_CDB);

  printf("\nDigite o saldo na aplicação poupança:\n");
  scanf("%s", &cliente.saldo_na_aplicacao_poupanca);

  clientes[n] = cliente;
  salvarCliente(clientes, n+1);

}


void alterarCliente(cliente* clientes, int n){

  int i, nenc = 0, exis = 0, ndc, j, ncliente, opcao, opcoes;
  printf("digite o numero da conta do cliente:\n");
  scanf("%d\n", &ndc);

  for(i=0; i < ncliente; i++){
    if(clientes[i].numero_da_conta == ndc){
      exis = 1;

      printf("Cliente %s encontrado com sucesso!\n", clientes[i].sobrenome);

      printf(" O que deseja alterar?\n");
      printf("1 - Sobrenome:\n");
      printf("2 - Nome:\n");
      printf("3 - Celular:\n");
      printf("4 - Numero da conta:\n");
      printf("5 - CPF:\n");
      printf("6 - Saldo da conta corrente:\n");
      printf("7 - Saldo na aplicação CDB:\n");
      printf("8 - Saldo na aplicação poupança:\n");
      printf("Qual sua escolha?\n");
      scanf("%d\n", &opcao);

      while (opcao > 8 || opcao < 1){

        printf("Opção inválida, escolha outra\n");
        scanf("%d\n", &opcoes);

      }

      switch (opcao){

        case 1:
          printf("Digite o sobrenome:\n");
          scanf("%s\n", &clientes[i].sobrenome);
          break;

        case 2:
          printf("Digite o nome:\n");
          scanf("%s\n", &clientes[i].nome);
          break;

        case 3:
          printf("Digite o celular:\n");
          scanf("%d\n", &clientes[i].celular);
          break;

        case 4:
          printf("Digite o CPF:\n");
          scanf("%d\n", &clientes[i].CPF);
          break;

        case 5:
          printf("Digite o numero da conta:\n");
          scanf("%d\n", &clientes[i].numero_da_conta);
          break;

        case 6:
          printf("Digite o saldo da conta corrente:\n");
          scanf("%d\n", &clientes[i].saldo_da_conta_corrente);
          break;

        case 7:
          printf("Digite o saldo da aplicação CDB:\n");
          scanf("%d\n", &clientes[i].saldo_da_aplicacao_CDB);
          break;

        case 8:
          printf("Digite o saldo da aplicação poupança:\n");
          scanf("%d\n", &clientes[i].saldo_na_aplicacao_poupanca);
          break;

      }

      salvarCliente(clientes, n);

      }
      ncliente--;
      i--;
    }
    if (exis == 0){
      printf("Cliente não encontrado!\n");
    }

}


void deletarCliente(cliente* clientes, movimentacao* movimentacoes, int ncliente, int nmovimentacao){
   int i, rem = 0, exis = 0, ndc, j;
   printf("digite o numero da conta do cliente:\n");
   scanf("%d\n", &ndc);

   for(i=0; i < ncliente; i++){
     if(clientes[i].numero_da_conta == ndc){
       exis = 1;

       printf("Cliente %s removido com sucesso!\n", clientes[i].sobrenome);
       for(j=i; j <= ncliente; j++){
         clientes[j] = clientes[j+1];
       }
       ncliente--;
       i--;
     }
   }
   if(exis == 0){
     printf("Cliente não encontrado!\n");
   }
   for(i = 0; i < nmovimentacao; i++){
     if(movimentacoes[i].numero_da_conta == ndc){
       rem++;
       printf("Movimentaçoes do cliente %s removidas\n", &clientes[i].sobrenome);
       for(j = i; j < nmovimentacao; j++){
         movimentacoes[j] = movimentacoes[j+1];
       }
       nmovimentacao--;
       i--;
     }
   }
   if(rem==0){
     printf("Nenhuma movimentação encontrada.\n");
   }
   salvarCliente(clientes,ncliente);
   salvarMovimentacao(movimentacoes,nmovimentacao);
}

void buscarCliente(){

}

void inserirMovimentacao(){

}

void buscarSaldos(){

}
/* Fim Função Do Menu */

/* Função Principal */
int main(){
  int selecao, n_cliente, n_movimentacao, i;



  FILE *arquivo;
  arquivo = fopen ("cliente.txt","r");
  fscanf(arquivo, "%d", &n_cliente);
  cliente clientes[200];

  FILE *arquivo_movimentacao;
  arquivo_movimentacao = fopen ("movimentacao.txt", "r");
  fscanf(arquivo_movimentacao, "%d", &n_movimentacao);
  movimentacao movimentacoes[200];

  for (i=0; i < n_cliente; i++){

    fscanf(arquivo, "%s %s %d %d %d %d %d %d %d",
          &clientes[i].sobrenome,
          &clientes[i].nome,
          &clientes[i].celular,
          &clientes[i].CPF,
          &clientes[i].numero_da_conta,
          &clientes[i].saldo_da_conta_corrente,
          &clientes[i].saldo_da_aplicacao_CDB,
          &clientes[i].saldo_na_aplicacao_poupanca);

  }

  for (i=0; i < n_movimentacao; i++){

    fscanf(arquivo_movimentacao, "%d %d %d %s %s",
          &movimentacoes[i].numero_da_conta,
          &movimentacoes[i].valor_da_movimentacao,
          &movimentacoes[i].movimentacao,
          &movimentacoes[i].data,
          &movimentacoes[i].descricao);

  }

  selecao = menu();

  while (selecao != 7) {
    switch(selecao){

      case 1:
          inserirCliente(clientes,n_cliente);
          break;

      case 2:
          alterarCliente(clientes,n_cliente);
          break;

      case 3:
          deletarCliente(clientes,movimentacoes,n_cliente,n_movimentacao);
          break;

      case 4:
          buscarCliente(clientes,n_cliente);
          break;

      case 5:
          inserirMovimentacao(movimentacoes,n_movimentacao);
          break;

      case 6:
          buscarSaldos(movimentacoes,n_movimentacao);
          break;

    }

    selecao = menu();

  }

  fclose(arquivo_movimentacao);
  fclose(arquivo);

  return 0;

}
/* Fim Função Principal */
