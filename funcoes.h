#include <stdio.h> 
#include <string.h>
#include "cores.h"
#include <stdlib.h>



#define INSERIR 1
#define MOSTRAR 2
#define REMOVER 3
#define FIM 4
#define QTCONTATOS 3

struct cadastro{
  int telefone;
  char nome[15];
  char descricao[50];

};

struct cadastro contato[QTCONTATOS];


// funcao para inserir INFO

int inserirInfo( int linha){
  if ( linha < QTCONTATOS ){
    printf(MAG"\n Digite o nome:");
    scanf("%s", contato[linha].nome); 
    printf("\n Digite a descricao do contato:");
    scanf(" %s", &contato[linha].descricao); 
    printf("\n Digite seu telefone:");
    scanf(" %d", &contato[linha].telefone ); 
    system("clear");
    printf(GRN"\nContato salvo com sucesso!!\n");
   
    return 0;
  } else {
    printf(RED"Problemas na abertura dos contatos!\n");
    return -1;
  }
}


// funcao para mostrar informações
 int mostrarInfo (int linha) {
   system("clear");
  for (int i =0; i < linha; i++){
    printf(GRN"Numero: %d\n", contato[i].telefone);
    printf("Nome: %s\n", contato[i].nome);
    printf("Descrição do contato: %s\n", contato[i].descricao);
  }

  return 0;
}

// mostrar todos os contatos
int mostraTudo(int linha){
  int i;

  for ( i =0; i < linha; i++){
    mostrarInfo( i );
    printf(MAG"\n");
  }
  return 0;
}

int menu(){
  int op;
  printf(MAG"--------------------------");
  printf("\n  Lista Telefônica \n");
   printf("--------------------------");
  printf("\n 1 - Inserir");
  printf("\n 2 - Mostrar");
  printf("\n 3 - Remover");
  printf("\n 4 - Fim");
  printf("\n Digite sua opção:");
  scanf("%d", &op);
  return op;
}

// remover contato,a partir do telefone dele
int remover(int linha){
  
  int remover, i;

  if ( linha > 0){
      
      mostrarInfo(linha);
      printf(MAG"\n O número que você deseja apagar:");
      scanf("%d", &remover);

    
      for ( i = 0; i< linha ; i++ ){
        if( remover == contato[i].telefone){
          
          contato[i] = contato[i+1];

          printf(GRN"\nNúmero deletado com sucesso da lista\n");
        }
      }
      return 0;
    } else {
      system("clear");
      printf(RED"\n Tabela vazia,escolha outra opção!\n");
      return -1;
    }
  }
