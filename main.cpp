#include <SFML/Graphics.hpp>
#include "pato.hpp"
#include "bases.hpp"
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
    Bases base1(Vector2f());
    vector<Sprite> bases;
    bases.pushback()
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
                    papu.pato.move(100, 0);
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
                    papu.pato.move(-100, 0);
                    girar2 = 0;
                }
                papu.moverseDer();
            }
       // }
        if (Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::W) )
        {
            if (papu.pato.getPosition().y >= 370)
            {
                papu.click();
            }
        }
        window.clear(Color(51, 51, 51));
        papu.brincar();
        window.draw(fondoS);
        window.draw(papu.pato);
        window.draw(base1.spriteBase);
        //  window.draw(shape);
        window.display();
    }

    return 0;
}