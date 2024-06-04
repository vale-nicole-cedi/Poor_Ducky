#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "pato.hpp"
#include "bases.hpp"
#include "sandia.hpp"
#include "bolas.hpp"
#include "flechas.hpp"
#include "sierra.hpp"
#include "canon.hpp"
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(1002, 600), "Poor Ducky :(");
    window.setFramerateLimit(30);

    Clock clock;
    Time elapsed;
    Font font;
    if (!font.loadFromFile("arial.ttf")) 
    {
    cout << "Error al cargar la fuente" << std::endl;
        return 1;
    }
    Text text;

    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(Color::Black);

    // CircleShape shape(100.f);
    bool girar = 1, girar2 = 0;
    Pato papu;
    bool vivo = 1;
    Texture fondo;
    Bases base1(Vector2f(100, 320));
    Bases base2(Vector2f(452, 320));
    Bases base3(Vector2f(802, 320));
    Bases base4(Vector2f(284, 215));
    Bases base5(Vector2f(618, 215));
    Bases base6(Vector2f(100, 110));
    Bases base7(Vector2f(452, 110));
    Bases base8(Vector2f(802, 110));
    vector<Bases> bases;
    bases.push_back(base1);
    bases.push_back(base2);
    bases.push_back(base3);
    bases.push_back(base4);
    bases.push_back(base5);
    bases.push_back(base6);
    bases.push_back(base7);
    bases.push_back(base8);
    Sandia sandia;
    Bolas bola(Vector2f(6.f, 6.f));
    Bolas bola1(Vector2f(0.f, 6.f));
    Bolas bola2(Vector2f(6.f, 0.f));
    Flechas flecha;
    Flechas flecha1;
    Sierra sierra;
    Sierra sierra1;
    Canon canon;
    int c = 0;
    int bla = 0;
    int bla1 = 0;
    int bla2 = 0;
    int bla3 = 0;
    int bla4 = 0;
    int bla5 = 0;
    int bla6 = 0;
    int bla7 = 0;

    bool touching = 0;

    if (!fondo.loadFromFile("fondo.jpg"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    Sprite fondoS;
    fondoS.setTexture(fondo);
    // shape.setFillColor(Color::Green);
    SoundBuffer buffer;
    if (!buffer.loadFromFile("musica.wav"))
    {
        cout << "Error al cargar musica"<<endl;
    }
        Sound sound;
        sound.setBuffer(buffer);
        sound.play();
    while (window.isOpen())
    {
        if (vivo)
        {
            c++;
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
            }

            elapsed = clock.getElapsedTime();

            ostringstream ss;
            ss << elapsed.asSeconds() << "s";
            text.setString(ss.str());

            
            //  if (event.type == Event::KeyPressed)
            // {
            if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
            {
                papu.derecha = 0;
                girar2 = 1;
                papu.pato.setScale(-1, 1);
                if (girar)
                {
                    papu.pato.move(50, 0);
                    girar = 0;
                }
                // girar=1;
                papu.moverseIzq();
            }
            if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
            {
                papu.derecha = 1;
                papu.pato.setScale(1, 1);
                girar = 1;
                if (girar2)
                {
                    papu.pato.move(-50, 0);
                    girar2 = 0;
                }
                papu.moverseDer();
            }
            if (Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::W))
            {
                if (papu.pisando || touching)
                {
                    papu.click();
                }
            }
            touching = 0;
            for (int i = 0; i < bases.size(); i++)
            {
                if (papu.estaEnBase(bases[i]) == 1)
                {
                    touching = 1;
                    break;
                }
            }
            // }
            // if(touching)
            // {
            // papu.acc.y=0;
            // papu.speed.y=0;
            // }
            // else{
            //     papu.acc.y=1;
            //     papu.speed.y=1;
            // }
            if (!touching)
            {
                papu.acc.y = 1;
            }
            // cout<<touching<<endl;
            papu.brincar();

            if (sandia.spriteSandia.getGlobalBounds().intersects(papu.pato.getGlobalBounds()))
            {
                papu.sumarPts();
                sandia.cambioDeLugar();
            }
            /// Muertes
            // flechas
            if (flecha.spriteFlecha.getGlobalBounds().intersects(papu.pato.getGlobalBounds()))
            {
                cout << "moriste por flecha";
                vivo = 0;
            }
            if (c>910)
            {
            if (flecha1.spriteFlecha.getGlobalBounds().intersects(papu.pato.getGlobalBounds()))
            {
                vivo = 0;
                cout << "moriste por flecha1";
            }
            }
            // bolas
            if(c>110)
            {
            if (bola.spriteBola.getGlobalBounds().intersects(papu.pato.getGlobalBounds()))
            {
                vivo = 0;
                cout << "moriste por bola";
            }
            }
            if (c>310)
            {
            if (bola1.spriteBola.getGlobalBounds().intersects(papu.pato.getGlobalBounds()))
            {
                vivo = 0;
                cout << "moriste por bola1";
            }
            }
            if(c>710){
            if (bola2.spriteBola.getGlobalBounds().intersects(papu.pato.getGlobalBounds()))
            {
                vivo = 0;
                cout << "moriste por bola2";
            }
            }
            // sierras
            if(c>510)
            {
            if (sierra.spriteSierra.getGlobalBounds().intersects(papu.pato.getGlobalBounds()))
            {
                vivo = 0;
                cout << "moriste por sierra";
            }
            }
            if(c>1110)
            {

            if (sierra1.spriteSierra.getGlobalBounds().intersects(papu.pato.getGlobalBounds()))
            {
                vivo = 0;
                cout << "moriste por sierra1";
            }
            }
            if (canon.spriteBala.getGlobalBounds().intersects(papu.pato.getGlobalBounds()))
            {
                vivo=0;
                cout<<"moriste por canon"<<endl;
            }
            window.clear(Color(51, 51, 51));
            //  touching=0;
            // for (int i=0;i<bases.size();i++)
            // {
            //     if(papu.estaEnBase(bases[i])==1)
            //     {
            //         touching=1;
            //        break;
            //     }
            // }
            // if(!touching)
            // {
            //     papu.acc.y=1;
            // }
            // cout<<touching<<endl;
            // papu.brincar();
            window.draw(fondoS);
            for (int i = 0; i < bases.size(); i++)
            {
                window.draw(bases[i].spriteBase);
            }
            window.draw(sandia.spriteSandia);
            if (c > 100)
            {
                if (bla2 == 0)
                {
                    bola.spriteBola.setPosition(rand() % 952, rand() % 400);
                    bla2=1;
                }
                window.draw(bola.spriteBola);
                bola.update();
            }
            if (c > 300)
            {
                if (bla1 == 0)
                {
                    bola1.spriteBola.setPosition(rand() % 952, rand() % 400);
                    bla1 = 1;
                }
                window.draw(bola1.spriteBola);
                bola1.update();
            }
            if (c > 500)
            {
                if(bla3==0)
                {
                sierra.spriteSierra.setPosition(Vector2f(0.f, 411.f));
                bla3=1;
                }
                window.draw(sierra.spriteSierra);
                sierra.update();
            }
            if (c > 700)
            {
                if(bla4==0)
                {
                    bola2.spriteBola.setPosition(rand()%952,rand()%400);
                    bla4=1;
                }
                window.draw(bola2.spriteBola);
                bola2.update();
            }
            if (c > 900)
            {

                if (bla == 0)
                {
                    flecha1.spriteFlecha.setPosition(rand() % 952, -10);
                    bla = 1;
                }
                window.draw(flecha1.spriteFlecha);
                flecha1.update();
            }
            if (c > 1100)
            {
                if(bla5==0)
                {
                    sierra1.spriteSierra.setPosition(0.f,411.f);
                    bla5=1;
                }
                window.draw(sierra1.spriteSierra);
                sierra1.update();
            }
            if(bla6==0)
            {
                flecha.spriteFlecha.setPosition(rand() % 952, -10);
                bla6=1;
            }
            if (bla7=0)
            {
            canon.spriteCanon.setPosition(Vector2f(900,rand()%450));
            canon.spriteBala.setPosition(canon.spriteCanon.getPosition());
            bla7=1;
            }
            window.draw(canon.spriteBala);
            window.draw(canon.spriteCanon);
            canon.update();
            window.draw(flecha.spriteFlecha);
            flecha.update();
            window.draw(papu.pato);
            window.draw(text);
            window.display();
        }
        else
            return 0;
    }
    return 0;
}