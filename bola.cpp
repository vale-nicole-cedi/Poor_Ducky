#include "bola.hpp"
#include <iostream>
using namespace std;
Bola::Bola()//tenemos que ponerle al constructor una posicion para mandarla desde el main y saber donde escribirlo.
{

 if(!this->bola.loadFromFile("sandia_sinfondo.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->spriteBola.setTexture(this->bola);
    this->spriteBola.setPosition(2000.f,2000.f);//random 
    this->speed=Vector2f(30,30);
}
void Bola::update()
{
     if (this->spriteBola.getPosition().x + this->spriteBola.getLocalBounds().getSize().x > 102 || this->spriteBola.getLocalBounds().getSize().x < 0)
    {
        this->speed.x *= -1;
    }
    if (this->spriteBola.getPosition().y + this->spriteBola.getLocalBounds().getSize().y > 450 || this->spriteBola.getPosition().y < 0)
    {
        this->speed.y *= -1;
    }
    this->spriteBola.move(this->speed);
}
void Bola::drawTo(RenderWindow &window)
{
    window.draw(this->spriteBola);
}