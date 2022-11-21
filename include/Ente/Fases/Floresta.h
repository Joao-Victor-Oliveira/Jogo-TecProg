#ifndef __FLORESTA_H__
#define __FLORESTA_H__
#include "Fase.h"

namespace Fases{
    class Floresta: public Fase{
    private:
        const int tam=3000;
    public:
        Floresta();
        Floresta(Entidades::Jogador* jg,Gerenciadores::Gerenciador_Colisoes* gc);
        ~Floresta();

        void inserirPisos();

        void inserirPlataformas(int n);

        void inserirEspinhos(int n);

        void inserirNinhos(int n);
    };
}


#endif // __FLORESTA_H__
