#include "bases.hpp"
#include <iostream>
using namespace std;
Bases::Bases()
{

 if(!this->base.loadFromFile("base_sinfondo.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->spriteBase.setTexture(this->base);
}