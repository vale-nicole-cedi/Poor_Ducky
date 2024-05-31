#include "canon.hpp"
#include <iostream>
using namespace std;
Canon::Canon()
{
    if(!this->canon.loadFromFile("canon.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->spriteCanon.setTexture(this->canon);
    this->spriteCanon.setPosition(950.f,rand()%400);//random 
    if(!this->bala.loadFromFile("ball.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->spriteBala.setTexture(this->bala);
    this->spriteBala.setScale(2.f,2.f);
    this->spriteBala.setPosition(this->spriteCanon.getPosition());
    this->speed=Vector2f(-20,0);
}
void Canon::update()
{
    this->spriteBala.move(this->speed);
    if (this->spriteBala.getPosition().x<-20)
    {
        this->spriteBala.setPosition(1010,this->spriteCanon.getPosition().y);
    }
}

void Canon::drawTo(RenderWindow &window)
{
    window.draw(this->spriteCanon);
}