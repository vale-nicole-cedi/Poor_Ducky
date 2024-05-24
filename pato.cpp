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
 //   this->speed = Vector2f(0.f,-10.f);
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
    if(this->pato.getPosition().x >100)
    {

this->pato.move(-10.f,0.f);
    }
    else{
        this->pato.move(0.f,0.f);
    }
}
void Pato::moverseDer()
{
    if (this->pato.getPosition().x<=902)
    {

this->pato.move(10.f,0.f);
    }
    else{
        this->pato.move(0.f,0.f);
    }
}
void Pato::brincar()
{
               this->speed.y += this->acc.y;
        
         this->pato.move(this->speed);
        if (this->pato.getPosition().y >373)//rebota abajo
        {
            this->speed.y = 0;
            this->acc.y=0;
            this->pato.move(0.f,0.f);
            return ;
        }
        if(this->pato.getPosition().y<=0)
        {
           // this->pato.move(0.f,40.f);
            this->speed.y=0;
        }

    }
void Pato::click()
{
        this->speed = {0.f, -40.f};
        this->acc.y = 5.f;
}