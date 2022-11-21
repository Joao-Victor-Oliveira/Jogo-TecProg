#ifndef __ESPINHOS_H__
#define __ESPINHOS_H__
#include "Obstaculo.h"

namespace Entidades{

class Espinhos:public Obstaculo{
    private:
        int dano;
    public:
        Espinhos(){};
        Espinhos(int Px,int Py);
        ~Espinhos();
};
}

#endif // __ESPINHOS_H__
