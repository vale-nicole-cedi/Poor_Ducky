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
    this->pato.setPosition(451,420);
    this->pato.setScale(.5,.5);


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
Vector2f acc,brinco;
acc=Vector2f(0.f,2.f);
brinco=Vector2f(0.f,200);
while()
}