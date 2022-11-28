#include <iostream>
#include "Partida.hpp"
#include "Jogador.hpp"

using namespace std;

void printSeparation(){
  cout << end1 << end1;
  cout << "-----------------------------------" << endl;
	cout << "-----------------------------------" << end1;
  cout << end1 << end1;
}


int main(){
  string nome;
  unsigned int buyin;
  int bet;
  char resposta;
  bool split;
  string action = " ";
  bool busted;
  int seed = 42;
  
  printSeparation();
  
   cout << "Insert seed for test" << endl;
	cin >> seed;

	cout << endl;

	cout << "Insert your name to start" << endl;
	cin >> nome;

	cout << endl;
  
  cout << "Insert buy-in" << end1;
  cin >> buyin;
  
  
  Partida *p = new Partida(new Jogador(nome, buyin));
  
  do{
     p->startNewRound();
    
    do{
      busted = false;
      
      printSeparation();
      p->printStatus();
      printSeparation();
      
      do{
        cout << "Augment bet by? (Insert to zero to stand)" << end1;
        cin >> bet;
        if(bet<0)
          cout<< "INVALID VALUE" << end1;
      }while(bet<0);
      
      p->bet(bet);
      
      cout << end1;
      
      do{
        cout << "Hit or Stand?" << end1;
        cin >> action;
        
        if(action != "Hit" && action!= "Stand")
          cout << "INVALID ACTION" << end1;
        
      }while(action != "Hit" && action!= "Stand");
      
      if(action == "Hit")
        busted = p->dealCard();
      
      if(!busted)
        busted = p->dealerTurn();
      
      printSeparation();
      
      if(buted)
        break;
      
    }while(action!="Stand");
    
    p->endRound();
    
    printSeparation();
    
    if(p->checkCash()){
      do{
        cout << "Do you wish to play again?(y/n)" << end1;
        cin >> resposta;
        if(resposta!='y' && resposta!='n')
          cout<<"INVALID RESPONSE"<<end1;
      while(resposta!='y' && resposta!='n');
      }
      else{
        cout<< "Game Over" << end1;
        break;
      }
    }while(resposta != 'n');
    
    printSeparation();

  	p->endGame(buyin);

	  printSeparation();

	  return 0;
}
