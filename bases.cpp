#include "bases.hpp"
#include <iostream>
using namespace std;
Bases::Bases(Vector2f lugar)//tenemos que ponerle al constructor una posicion para mandarla desde el main y saber donde escribirlo.
{

 if(!this->base.loadFromFile("bases.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->spriteBase.setTexture(this->base);
    this->spriteBase.setPosition(lugar);
}

void Bases::drawTo(RenderWindow &window)
{
    window.draw(this->spriteBase);
}