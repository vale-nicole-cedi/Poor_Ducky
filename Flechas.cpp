#include "flechas.hpp"
#include <iostream>
using namespace std;


Flechas::Flechas()
    {

 if(!this->felcha.loadFromFile("flecha.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->spriteFlecha.setTexture(this->felcha);
    this->spriteFlecha.setPosition(1300,-10);//random 
}

void Flechas::update()
{
    this->spriteFlecha.move(Vector2f(0,8));
    if (this->spriteFlecha.getPosition().y>650)
    {
        this->spriteFlecha.setPosition(rand()%1000,-10);
    }
}   