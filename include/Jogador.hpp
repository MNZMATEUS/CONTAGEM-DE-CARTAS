#ifndef JOGADOR
#define JOGADOR

#include <string>
#include <list>
#include "Carta.hpp"

using namespace std;

class Jogador {
private:
	string _nomeJogador;
	int dinheiro = 0;
	int currentBet = 0;
	list<Carta> _cartas;
	unsigned int numCards = 0;
	unsigned int sum = 0;

public:

	Jogador();
	Jogador(string nome, int buyin);
	bool adicionaCarta (Carta carta);
	int imprimirStatus();
	bool bet(int valor);
	void endRound(int gameResult);
	bool checkCash();
	int getSum();
	Carta popCard();
	int getNumCards();
	int getDinheiro();

};

#endif
