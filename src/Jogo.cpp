#include "../include/Jogo.h"


#include <iostream>
#define MAX 5
#define MIN 3
#define RANDOM (rand()%(MAX-MIN))+MIN

Jogo::Jogo():
gerenciador_grafico(Gerenciadores::Gerenciador_Grafico::getInstancia()),
//personagens(),
//gerenciador_colisoes(&personagens, &obstaculos),
jogador(sf::Vector2f(70, 70), sf::Vector2f(600, 100), sf::Vector2f(0.35, 0.35)),
jogador2(sf::Vector2f(70, 70), sf::Vector2f(600, 100), sf::Vector2f(0.35, 0.35)),
fase2(&jogador,&gerenciador_colisoes),
fase1(&jogador,&gerenciador_colisoes),
menu(static_cast <Fases::Fase*>(&fase1),static_cast <Fases::Fase*>(&fase2))
{
}

Jogo::~Jogo()
{
    //dtor
}

void Jogo::executar()
{
    menu.executar();

}
