#ifndef PARTIDA
#define PARTIDA

#include <string>
#include <array>
#include <list>
#include <deque>
#include <iostream>
#include "Jogador.hpp"

using namespace std;

class Partida {
	
private:
	
	int baseBet = 100;
	array<Jogador*, 2> jogadores;
	Jogador* jogador;
	Jogador* dealer;
	deque<Carta> deck;

public:

	Partida(Jogador* jogador, int seed, int blind);
	~Partida();
	
	void startNewRound();
	bool dealCard(string playersName);
	void printStatus();
	void initializeDeck(int seed);
	void bet(int valor);
	void endRound();
	bool checkCash();
	bool dealerTurn();
	void endGame(int buyin);
};

#endif
