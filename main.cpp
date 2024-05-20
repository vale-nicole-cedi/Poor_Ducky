#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(900, 600), "Poor Ducky :(");
   // CircleShape shape(100.f);

   // shape.setFillColor(Color::Green);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color(200,200,200));
      //  window.draw(shape);
        window.display();
    }

    return 0;
}