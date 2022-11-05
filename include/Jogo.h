#ifndef JOGO_H
#define JOGO_H

#include "SFML/Graphics.hpp"

#include "Ente/Entidades/Personagens/Jogador.h"
#include "Ente/Entidades/Personagens/Inimigo.h"

#include "Gerenciadores/Gerenciador_Grafico.h"
class Jogo
{
    private:
        Entidades::Jogador jogador1;
        Entidades::Inimigo inimigo1;

        sf::RenderWindow window;
        Gerenciadores::Gerenciador_Grafico* gerenciador_grafico;
    public:
        Jogo();
        virtual ~Jogo();

        void executar();
};

#endif // JOGO_H
