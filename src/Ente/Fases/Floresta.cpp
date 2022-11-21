#include "../../../include/Ente/Fases/Floresta.h"

using namespace Fases;


Floresta::Floresta(){}

Floresta::Floresta(Entidades::Jogador* jg,Gerenciadores::Gerenciador_Colisoes* gc):
Fase(jg,gc)
{
}

Floresta::~Floresta(){}

void Floresta::inserirPisos(){
    inserirPi(tam,1500,TelaY-30);
    obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Obstaculo(60,1000,-30,500)));
    obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Obstaculo(60,1000,3030,500)));
}

void Floresta::inserirPlataformas(int n){
    int y=TelaY-280,k=0;
    int const espaco = tam/n;
    int x,largura_plataforma=200,x_ant=-300;
    for(int i=0;i<tam;i+=espaco){
        x = (rand()%(espaco-2*largura_plataforma)+largura_plataforma);
        if((x+espaco)-x_ant<=600){
            inserirPla(x+i,y,1);
            inserirN(x+i+55,y-258);
        }
        else
            inserirPla(x+i,y,0);
        x_ant=x;
    }
}

void Floresta::inserirEspinhos(int n){
    int y=TelaY-85;
    int const espaco = tam/n;
    int x,largura_Espinho=200;
    for(int i=0;i<tam;i+=espaco){
        x = (rand()%(espaco-largura_Espinho)+largura_Espinho);
        inserirE(x+i,y);
    }
}

void Floresta::inserirNinhos(int n){
    n-=2;

}

