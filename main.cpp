#include <SFML/Graphics.hpp>
#include "pato.hpp"
#include <iostream>
using namespace std;
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(1002, 600), "Poor Ducky :(");
    window.setFramerateLimit(10);
   // CircleShape shape(100.f);
   Pato papu;
   bool vivo;
   Texture fondo;
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
            {papu.pato.setScale(-1,1); 
            
                papu.moverseIzq();
            }
            if(event.mouseButton.button==Mouse::Right)
            {papu.pato.setScale(1,1); 
                papu.moverseDer();
            }
        }
        window.clear(Color(51,51,51));
        window.draw(fondoS);
        window.draw(papu.pato);
      //  window.draw(shape);
        window.display();
    }

    return 0;
}