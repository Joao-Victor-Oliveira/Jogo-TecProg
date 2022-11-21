#include "../../../include/Ente/Fases/Pantano.h"

using namespace Fases;

        Pantano::Pantano(){}

        Pantano::Pantano(Entidades::Jogador* jg,Gerenciadores::Gerenciador_Colisoes* gc):
        Fase(jg,gc)
        {}

        Pantano::~Pantano(){}

        void Pantano::inserirPlataformas(int n){}

        void Pantano::inserirEspinhos(int n){}

        void Pantano::inserirNinhos(int n){}

        void Pantano::inserirPisos(){}
