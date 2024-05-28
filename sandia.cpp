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
    this->spriteSandia.setPosition(rand()%952,rand()%400);//random 
}

void Sandia::drawTo(RenderWindow &window)
{
    window.draw(this->spriteSandia);
}
void Sandia::cambioDeLugar()
{
    this->spriteSandia.setPosition(rand()%952,rand()%400);
}