#include "pato.hpp"
#include <iostream>
#include <sstream>

using namespace std;
using namespace sf; 


Pato::Pato()
{

    if (!this->texture.loadFromFile("pato_pequeno.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->pato.setTexture(this->texture);
    this->pato.setPosition(451, 415);
    this->pisando = 1;
    this->derecha = 1;
    this->pts = 0;
    //   this->speed = Vector2f(0.f,-10.f);
}

void Pato::sumarPts()
{
    this->pts += 1;
    cout << pts << endl;
}
void Pato::drawTo(RenderWindow &window)
{
    window.draw(this->pato);
}
void Pato::moverseIzq()
{
    if (this->pato.getPosition().x > 50)
    {

        this->pato.move(-10.f, 0.f);
    }
    else
    {
        this->pato.move(0.f, 0.f);
    }
}
void Pato::moverseDer()
{
    if (this->pato.getPosition().x <= 952)
    {

        this->pato.move(10.f, 0.f);
    }
    else
    {
        this->pato.move(0.f, 0.f);
    }
}
void Pato::brincar()
{
    this->speed.y += this->acc.y;
    this->pato.move(this->speed);
    if (this->pisando) // rebota abajo
    {
        this->speed.y = 0;
        this->acc.y = 0;
    }
    else
    {
        this->acc.y = 1.f;
    }
    if (this->pato.getPosition().y <= 0)
    {
        // this->pato.move(0.f,40.f);
        this->speed.y = 0;
    }
}
void Pato::click()
{
    this->speed = {0.f, -17.f};
    this->acc.y = 1.f;
    this->pato.move(this->speed);
    //  this->pisando = 0;
}
bool Pato::estaEnBase(Bases base)
{
    // Vector2f pos = this->pato.getPosition();
    // Vector2f size = this->pato.getLocalBounds().getSize();
    if (this->pato.getGlobalBounds().intersects(base.spriteBase.getGlobalBounds()))
    {
        if (this->pato.getPosition().y/* + this->pato.getLocalBounds().getSize().y*/ <= base.spriteBase.getPosition().y)
        {
            this->acc.y = 0;
            this->pisando = 1;
            this->speed.y = 0;
            //    cout<<pisando<<endl;
        }
        else
        {
           this->acc.y = 1;
           this->speed.y = 1;
            this->pisando = 0;
        }
    }
    else
    {
        this->pisando = 0;
        // cout<<this->pisando<<endl;
    }
    if ((this->pato.getPosition().y >= 401))
    {
        this->pisando = 1;
        // cout<<pisando<<endl;
    }
    // cout<<this->pisando<<endl;
    // if (this->pato.getPosition().y >= 401)
    // {
    //     this->pisando = 1;
    // }
    return this->pisando;
}