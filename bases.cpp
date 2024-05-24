#include "bases.hpp"
#include <iostream>
using namespace std;
Bases::Bases()//tenemos que ponerle al constructor una posicion para mandarla desde el main y saber donde escribirlo.
{

 if(!this->base.loadFromFile("base_sinfondo.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->spriteBase.setTexture(this->base);
}

void Bases::drawTo(RenderWindow &window)
{
    window.draw(this->spriteBase);
}