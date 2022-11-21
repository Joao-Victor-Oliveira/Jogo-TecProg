#include "../../../include/Ente/Fases/Fase.h"

using namespace Fases;
#define MAX 6
#define MIN 4
#define RANDOM (rand()%(MAX-MIN))+MIN

Fase::Fase(Entidades::Jogador* jg,Gerenciadores::Gerenciador_Colisoes* gc){
    jogador1=jg;
    gerenciador_colisoes = gc;
}


Fase::Fase()
{
}

Fase::~Fase()
{
    jogador1=NULL;
    gerenciador_colisoes=NULL;
}

void Fase::executar()
{
    gerenciador_colisoes->setListaPersonagens(&personagens);
    gerenciador_colisoes->setListaObstaculos(&obstaculos);
    personagens.inserirEntidade(static_cast<Entidades::Entidade*>(jogador1));
    inserirPisos();
    inserirPlataformas(RANDOM);
    inserirEspinhos(RANDOM);
    inserirNinhos(RANDOM);
    gerenciador_grafico->limpaJanela();
    while (gerenciador_grafico->verificaJanelaAberta())
    {
        sf::Event evento;
        if (gerenciador_grafico->getWindow()->pollEvent(evento))
        {
            if (evento.type == sf::Event::Closed)
                gerenciador_grafico->fecharJanela();

        }
        gerenciador_grafico->limpaJanela();
        personagens.executarEntidades();
        obstaculos.executarEntidades();
        gerenciador_colisoes->executar();
        gerenciador_grafico->AttView(jogador1->getPosicao().x+150,jogador1->getPosicao().y-200);
        gerenciador_grafico->mostrarConteudo();
    }
}

void Fase::inserirPisos(){
}

void Fase::inserirPlataformas(int n){
}

void Fase::inserirEspinhos(int n){
}

void Fase::inserirNinhos(int n){
}

void Fase::inserirPi(int tam,int x,int y){
    obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Piso(tam,60,x,y)));
}

void Fase::inserirPla(int x,int y,int nivel){
    obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Plataforma(x,y-nivel*200,nivel)));
}

void Fase::inserirE(int x,int y){
    obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Espinhos(x,y)));
}

void Fase::inserirN(int x,int y){
    obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Ninho(x,y)));
}
