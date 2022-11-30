#include "Carta.hpp"
#include <iostream>
#include <string>

using namespace std;

Carta::Carta(int numeroPontosPadrao, int naipe){
	this->valorCarta = numeroPontosPadrao;
	this->_naipe = naipe;

}

int Carta::getPontos(){
	if(valorCarta<=10)
		return valorCarta;
	
	else if(valorCarta==14)
		return 11;
	
	else
		return 10;
}

void Carta::printCard(){

	string cardName = "";

	switch(valorCarta){
		case(J):
			cardName += "J";
			break;
		case(Q):
			cardName += "Q";
			break;	
		case(K):
			cardName += "K";
			break;
		case(A):
			cardName += "A";
			break;
		case(A_):
			cardName += "A";
			break;
		default:
			cardName += to_string(valorCarta);
			break;
	}
	
	cardName += " - ";
	
	switch(_naipe){
		case(COPAS):
			cardName+="Copas";
			break;
		case(ESPADAS):
			cardName+="Espadas";
			break;
		case(OUROS):
			cardName+="Ouros";
			break;
		case(PAUS):
			cardName+="Paus";
			break;
	}

	cout<< cardName << endl;
};
