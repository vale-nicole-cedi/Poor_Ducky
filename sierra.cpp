#include "sierra.hpp"
#include <iostream>
using namespace std;
Sierra::Sierra()
{
    if(!this->sierra.loadFromFile("sierra_sinfondo.gif"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->spriteSierra.setTexture(this->sierra);
    this->speed.x=8;
    this->speed.y=0;
    this->spriteSierra.setPosition(Vector2f(1300.f,1000.f));
}
void Sierra::drawTo(RenderWindow &window)
{
    window.draw(this->spriteSierra);
}
void Sierra::update()
{
 if (this->spriteSierra.getPosition().x + this->spriteSierra.getLocalBounds().getSize().x > 1000 || this->spriteSierra.getPosition().x < 0)
    {
        this->speed.x *= -1;
    }
    this->spriteSierra.move(this->speed);
}