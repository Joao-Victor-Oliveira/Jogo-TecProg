#include "../../../include/Ente/Menus/Menu.h"

Menu::Menu(Fase* f1,Fase* f2):n(3){
    fase1= f1;
    fase2= f2;
    gerenciador_grafico->limpaJanela();
    if (!font.loadFromFile("arial.ttf")){
        printf("error abrindo fonte");}

    for(int i=0;i<3;i++){
        text[i].setFont(font);
        fases[i].setFont(font);}

    text[0].setString("Jogar");
    text[1].setString("Rank");
    text[2].setString("Sair");

    fases[0].setString("Voltar");
    fases[1].setString("Floresta");
    fases[2].setString("Pantano");

    for(int i=0;i<3;i++){
        text[i].setCharacterSize(24);
        text[i].setFillColor(sf::Color::White);
        text[i].setOutlineColor(sf::Color::Red);
        fases[i].setCharacterSize(24);
        fases[i].setFillColor(sf::Color::White);
        fases[i].setOutlineColor(sf::Color::Red);
    }

    text[0].setPosition(200.f,100.f);
    text[1].setPosition(200.f,300.f);
    text[2].setPosition(200.f,500.f);

    fases[0].setPosition(200.f,100.f);
    fases[1].setPosition(200.f,300.f);
    fases[2].setPosition(200.f,500.f);

}

Menu::~Menu(){
}

//=====================================================================================================//

#define INTERVALO 0.02
#define GROSSURA 2
//=====================================================================================================//

void Menu::executar(){
    n.reiniciar();
    sf::Clock relogio;
    text[n.getContador()].setOutlineThickness(GROSSURA);
    while(gerenciador_grafico->verificaJanelaAberta()){
        gerenciador_grafico->limpaJanela();
        sf::Event evento;
        if (gerenciador_grafico->getWindow()->pollEvent(evento))
        {
            if (evento.type == sf::Event::Closed)
                gerenciador_grafico->fecharJanela();

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            if(relogio.getElapsedTime().asSeconds()>INTERVALO){
                text[n.getContador()].setOutlineThickness(0);
                n--;
                text[n.getContador()].setOutlineThickness(GROSSURA);
            }
            relogio.restart();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            if(relogio.getElapsedTime().asSeconds()>INTERVALO){
                text[n.getContador()].setOutlineThickness(0);
                n++;
                text[n.getContador()].setOutlineThickness(GROSSURA);
            }
            relogio.restart();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            if(relogio.getElapsedTime().asSeconds()>INTERVALO){
                switch(n.getContador()){
                case 0:
                    MostraFases();
                    break;
                case 1:
                    printf("ranking");
                    break;
                case 2:
                    exit(0);
                    break;
                }
            }
            relogio.restart();
        }
        imprimir_se(0);
        gerenciador_grafico->mostrarConteudo();
    }
    return;
}

//=====================================================================================================//

void Menu::MostraFases(){
    n.reiniciar();
    sf::Clock relogio;
    fases[n.getContador()].setOutlineThickness(GROSSURA);

    gerenciador_grafico->limpaJanela();
    while(gerenciador_grafico->verificaJanelaAberta()){
        sf::Event evento;
        if (gerenciador_grafico->getWindow()->pollEvent(evento))
        {
            if (evento.type == sf::Event::Closed)
                gerenciador_grafico->fecharJanela();

        }
        gerenciador_grafico->limpaJanela();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            if(relogio.getElapsedTime().asSeconds()>INTERVALO){
                fases[n.getContador()].setOutlineThickness(0);
               n--;
                fases[n.getContador()].setOutlineThickness(GROSSURA);
            }
            relogio.restart();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            if(relogio.getElapsedTime().asSeconds()>INTERVALO){
                fases[n.getContador()].setOutlineThickness(0);
                n++;
                fases[n.getContador()].setOutlineThickness(GROSSURA);
            }
            relogio.restart();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            if(relogio.getElapsedTime().asSeconds()>INTERVALO){
                switch(n.getContador()){
                case 0:
                    executar();
                    break;
                case 1:
                    fase1->executar();
                    break;
                case 2:
                    fase2->executar();
                    break;
                }
                /*
                if(!n.getContador())
                    if(!n.getContador())
                        executar();
                return;*/
            }
            relogio.restart();
        }
        imprimir_se(1);
        gerenciador_grafico->mostrarConteudo();
    }
    return;
}

void Menu::imprimir_se(int tela){
   switch(tela){
        case 0:
            gerenciador_grafico->desenhaElemento(text,3);
            break;
        case 1:
            gerenciador_grafico->desenhaElemento(fases,3);
            break;
    }
    return;
}
