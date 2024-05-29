#include <SFML/Graphics.hpp>
#include "pato.hpp"
#include "bases.hpp"
#include "sandia.hpp"
#include "bolas.hpp"
#include "flechas.hpp"
#include <iostream>
#include <vector>
using namespace std;
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(1002, 600), "Poor Ducky :(");
    window.setFramerateLimit(30);
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
    Bolas bola;
    Flechas flecha;

    if (!fondo.loadFromFile("fondo.jpg"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    Sprite fondoS;
    fondoS.setTexture(fondo);
    // shape.setFillColor(Color::Green);

    while (window.isOpen())
    {
        if (vivo)
        {

            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
            }
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
            // }
            if (Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::W))
            {
                if (papu.pisando)
                {
                    papu.click();
                }
            }
            if (sandia.spriteSandia.getGlobalBounds().intersects(papu.pato.getGlobalBounds()))
            {
                papu.sumarPts();
                sandia.cambioDeLugar();
            }
            if (flecha.spriteFlecha.getGlobalBounds().intersects(papu.pato.getGlobalBounds()))
            {
                vivo = 0;
            }
            if (bola.spriteBola.getGlobalBounds().intersects(papu.pato.getGlobalBounds()))
            {
                vivo=0;
            }
            window.clear(Color(51, 51, 51));
            bool touching=0;
            for (int i=0;i<bases.size();i++)
            {
                if(papu.estaEnBase(bases[i])==1)
                {
                    touching=1;
                   // break;
                }
            }
            if(!touching)
            {
                papu.acc.y=1;
            }
            papu.brincar();
            window.draw(fondoS);
            for (int i = 0; i < bases.size(); i++)
            {
                window.draw(bases[i].spriteBase);
            }
            window.draw(sandia.spriteSandia);
            window.draw(bola.spriteBola);
            window.draw(flecha.spriteFlecha);
            flecha.update();
            bola.update();
            window.draw(papu.pato);
            window.display();
        }
        else return 0;
    }
    return 0;
}