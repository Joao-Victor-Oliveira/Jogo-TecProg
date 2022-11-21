#include "../../../../include/Ente/Entidades/Obstaculos/Plataforma.h"

using namespace Entidades;

Plataforma::Plataforma(int Px,int Py,int nvl):Obstaculo(150,30,Px,Py)
{
    nivel = nvl;
    corpo.setFillColor(sf::Color::White);
    setTextura("imagens/Obstaculos/Plataforma.png");
}


Plataforma::~Plataforma()
{}
