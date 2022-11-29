#include <iostream>
#include <string>
#include "Partida.hpp"
#include "Jogador.hpp"

using namespace std;

void printSeparation(){
  cout << endl << endl;
  cout << "-----------------------------------" << endl;
  cout << "-----------------------------------" << endl;
  cout << endl << endl;
}

bool is_number(const string& s)
{
    return !s.empty() && find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !isdigit(c); }) == s.end();
}


int main(){
	
  string seed;
	
  string nome;
  string blind;
  string buyIn;	
	
  string bet;
  char resposta;
  string action;
  bool busted;
    
  printSeparation();
  
  do{
	  try{
		  cout << "Insert seed for test" << endl;
		  cin >> seed;
		  if(!is_number(seed))
			  throw invalid_argument("Seed is not number");
	  }
	  catch(invalid_argument& err){
		  cerr << "EXCEPTION: " << err.what() << endl << endl;
	  }
while(!is_number(seed));

cout << endl;
	  
cout << "Insert your name to start" << endl;
	cin >> nome;

	cout << endl;
	  
do{
		try{
			cout << "Insert blind" << endl;
			cin >> blind;
			if(!is_number(blind))
				throw invalid_argument("Blind is not number");	
		}
		catch(invalid_argument& err){
			cerr << "EXCEPTION: " << err.what() << endl << endl;
		}
	}while(!is_number(blind));

	cout << endl;
	  
do{
	try{
	  cout << "Insert buy-in" << endl;
  	  cin >> buyIn;
  	  if(!is_number(buyIn))
				throw invalid_argument("BuyIn is not number");
		}
		catch(invalid_argument& err){
			cerr<< "EXCEPTION: "<< err.what() << endl << endl;
		}
	}while(!is_number(buyIn));
	  
Jogador* jogador = new Jogador(nome, stoi(buyIn));
	  
	  
Partida *p = new Partida(jogador, stoi(seed), stoi(blind));
  
  do{
     p->startNewRound();
    
    do{
      busted = false;
      
      printSeparation();
      p->printStatus();
      printSeparation();
      
      do{
	      try{
		      cout << "Augment bet by? (Insert to zero to stand)" << endl;
        	      cin >> bet;
       		      if(!is_number(bet))
			      throw invalid_argument("Bet is not number");
	      }
	     catch(invalid_argument& err){
		cerr<< "EXCEPTION: "<< err.what() << endl << endl;
	     }	
      }while(!is_number(bet));
      
      p->bet(stoi(bet));
      
      cout << endl;
      
      do{
	      try{
		      cout << "Hit or Stand?" << endl;
        	      cin >> action;
        
        	      if(action != "Hit" && action!= "Stand")
            	      	throw("INVALID ACTION");
	 	}
	      
	      catch(invalid_argument& err){
		cerr<< "EXCEPTION: "<< err.what() << endl << endl;
	      }	            
      }while(action != "Hit" && action!= "Stand");
      
      if(action == "Hit")
        busted = p->dealCard(jogador->getName());
      
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
	try{
        cout << "Do you wish to play again?(y/n)" << endl;
        cin >> resposta;
        if(resposta!='y' && resposta!='n')
          throw<<"INVALID RESPONSE";
	}
	catch(invalid_argument& err){
		cerr<< "EXCEPTION: "<< err.what() << endl << endl;
	}
      while(resposta!='y' && resposta!='n');
      }
      else{
        cout<< "Game Over" << endl;
        break;
      }
    }while(resposta != 'n');
    
    printSeparation();

    p->endGame(buyin);

    printSeparation();

    return 0;
  }
