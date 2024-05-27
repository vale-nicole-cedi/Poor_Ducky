#include <SFML/Graphics.hpp>
#include "pato.hpp"
#include "bases.hpp"
#include "sandia.hpp"
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
    bool vivo;
    Texture fondo;
    Bases base1(Vector2f(100,310));
    Bases base2(Vector2f(452,310));
    Bases base3(Vector2f(802,310));
    Bases base4(Vector2f(284,205));
    Bases base5(Vector2f(618,205));
    Bases base6(Vector2f(100,100));
    Bases base7(Vector2f(452,100));
    Bases base8(Vector2f(802,100));
    vector<Bases>bases;
    bases.push_back(base1);
    bases.push_back(base2);
    bases.push_back(base3);
    bases.push_back(base4);
    bases.push_back(base5);
    bases.push_back(base6);
    bases.push_back(base7);
    bases.push_back(base8);
    Sandia sandia;
    
    if (!fondo.loadFromFile("fondo.jpg"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    Sprite fondoS;
    fondoS.setTexture(fondo);
    // shape.setFillColor(Color::Green);

    while (window.isOpen())
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
        if (Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::W) )
        {
            if (papu.pato.getPosition().y >= 415 || papu.pisando)
            {
                papu.click();
            }
        }
        window.clear(Color(51, 51, 51));
        papu.brincar();
        papu.estaEnBase();
        window.draw(fondoS);
        for(int i=0;i<bases.size();i++)
        {
            window.draw(bases[i].spriteBase);
        }
        window.draw(sandia.spriteSandia);
        window.draw(papu.pato);
        window.display();
    }
    return 0;
}