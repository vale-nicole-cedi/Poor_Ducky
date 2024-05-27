#include "sandia.hpp"
#include <iostream>
using namespace std;
Sandia::Sandia()//tenemos que ponerle al constructor una posicion para mandarla desde el main y saber donde escribirlo.
{

 if(!this->sandia.loadFromFile("sandia_sinfondo.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->spriteSandia.setTexture(this->sandia);
    this->spriteSandia.setPosition(0,0);
}

void Sandia::drawTo(RenderWindow &window)
{
    window.draw(this->spriteSandia);
}