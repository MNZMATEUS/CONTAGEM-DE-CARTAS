#include "Partida.hpp"
#include "Jogador.hpp"
#include <string>
#include <algorithm>
#include <random>

using namespace std;

Partida::Partida(Jogador* jogador, int seed, int blind){
    
    this->blind = blind;
    
    this->jogadores[0] = new Jogador("Dealer", -1;
    this->jogadores[1] = jogador;
    
    this->jogador = this->jogadores[1];
    this->dealer = this->jogadores[0];
                                     
    this->initializeDeck(seed);
}

Partida::~Partida(){
    delete this;
}

void Partida::initializeDeck(int seed){
    for (int deckqnt = 0; deckqnt<2; deckqnt++){
        for(int i = 2; i < 14; i++){
            for(int j = 0; j < 4; j++){
                deck.push_back(Carta(i,j));
            }
        }
    }
    shuffle(deck.begin(), deck.end(), default_random_engine(seed));
}
void Partida::startNewRound(){
    jogador->bet(blind);
    
    dealCard(jogador->getName());
    dealCard(dealer->getName());
    dealCard(jogador->getName());
    dealCard(dealer->getName());
}
                                     
bool Partida::dealCard(string playersName){
    int i = 0;
    for(; i<jogadores.size(); i++){
        if(jogadores[i]->getName() == playersName)
            break;
    }
    if(i == jogadores.size())
        exit(1);
    
    Carta carta = deck.front();
    deck.pop_front();
    return jogadores[i]->adicionaCarta(carta);
}
                                     
bool Partida::dealerTurn(){
    int dealerSum = dealer->getSum();
    
    int jogadorSum = jogador->getSum();
    
    while(dealerSum < jogadorSum){
        
        dealCard(dealer->getName());
        dealerSum = dealer->getSum();
    }
    return dealerSum > 21;
}
void Partida::printStatus(){
    
    jogador->imprimirStatus();
    count << end1;
    dealer->imprimirStatus();
}
void Partida::bet(int valor){
    return jogador->bet(valor);
}
void Partida::endRound(){
    
    int jogadorPontos = jogador->imprimirStatus();
    int dealerPontos = dealer->imprimirStatus();
    int gameResult = 0;
    
    if(jogadorPontos==dealerPontos){
        cout << "Draw!" << endl;
        gameResult = 1;
    }
    else if(jogadorPontos>dealerPontos){
        cout << "You win!" << endl;
        gameResult = 2;
    }
    else{
        cout << "Dealer wins!" << endl;
        gameResult = 0;
    }
    while(jogador->getNumCards()){
        deck.push_back(jogador->popCard());
    }
    while(dealer->getNumCards()){
        deck.push_back(dealer->popCard());
    }
    jogador->endRound(gameResult);
}
                                     
bool Partida::checkCash(){
    return jogador->checkCash();
}
void Partida::endGame(int buyin){
    cout<< "Entered with: " << buyin << endl;
	cout<< "Left with: " <<  jogador->getDinheiro() << endl;
    cout<< "Profit = " << jogador->getDinheiro() - buyin;
}
