#ifndef __PANTANO_H__
#define __PANTANO_H__
#include "Fase.h"

namespace Fases{
    class Pantano: public Fase{
    public:
        Pantano();
        Pantano(Entidades::Jogador* jg,Gerenciadores::Gerenciador_Colisoes* gc);
        ~Pantano();

        void inserirPisos();

        void inserirPlataformas(int n);

        void inserirEspinhos(int n);

        void inserirNinhos(int n);
    };
}


#endif // __PANTANO_H__
