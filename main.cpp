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
    window.setFramerateLimit(10);
   // CircleShape shape(100.f);
                bool girar=1,girar2=0;
   Pato papu;
   bool vivo;
   Texture fondo;
   vector<Sprite>bases;
   if(!fondo.loadFromFile("fondo.jpg"))
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
        if (event.type == Event::MouseButtonPressed)
        {
            if(event.mouseButton.button==Mouse::Left)
            {
                girar2=1;
                papu.pato.setScale(-1,1); 
                if(girar)
                {
 papu.pato.move(100,0);
 girar=0;
 
                }
       // girar=1;
                papu.moverseIzq();
            }
            if(event.mouseButton.button==Mouse::Right)
            {papu.pato.setScale(1,1); 
            girar=1;
                 if(girar2)
                {
 papu.pato.move(-100,0);
 girar2=0;
                }
                papu.moverseDer();
            }
        }
        if(Keyboard::isKeyPressed(Keyboard::Space))
        {
            if(papu.pato.getPosition().y>50)
            {

            papu.click();
            }
        }
        window.clear(Color(51,51,51));
        papu.brincar();
        window.draw(fondoS);
        window.draw(papu.pato);
      //  window.draw(shape);
        window.display();
    }

    return 0;
}