#include "funcoes.h"
#include cores.h
#include stdlib.h


int main(void){
  int linha, opcao;

  linha=0;
//Ficar repetindo o switch
  do{
    opcao=menu();
    switch ( opcao ){
      
      case INSERIR :
        if ( inserirInfo(linha) >= 0 ){
          linha++;
        }
        break;
      
      case MOSTRAR :
        
        mostrarInfo(linha);
        break;
      
      
      case REMOVER :
        if ( remover(linha) >=0 ){
          linha--;
          if ( linha <0 ){
            linha=0;
          }
        }
        break;
      
      case FIM :
        break;
      
      default:
        system("clear");
        printf(RED"\nOpção Inválida\n");
        break;
    }
    } while( opcao != FIM );

  return 0;
}