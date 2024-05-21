#include "pato.hpp"
#include <iostream>
using namespace std;
Pato::Pato()
{
    if(!this->texture.loadFromFile("pato_sinfondo.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->pato.setTexture(this->texture);
    this->pato.setPosition(451,370);


}

int Pato::sumarPts()
{
this->pts+=1;
}
void Pato::drawTo(RenderWindow &window)
{
 window.draw(this->pato);
}
void Pato::moverseIzq()
{
this->pato.move(-10.f,0.f);
//this->pato.move(100,0);
// this->pato.setScale(-1,1);    esto va en el main antes de mandar la funcion moverseIzq()
}
void Pato::moverseDer()
{
this->pato.move(10.f,0.f);
}
void Pato::brincar()
{

}