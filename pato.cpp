#include "pato.hpp"
#include <iostream>
using namespace std;
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
    //   this->speed = Vector2f(0.f,-10.f);
}

int Pato::sumarPts()
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
    this->pisando = 0;
}
void Pato::estaEnBase()
{
    if (derecha)
    {

        // base1
        if (this->pato.getPosition().x > 50 && this->pato.getPosition().x < 200 /*&& this->pato.getPosition().y <= 290*/)
        {
            if (this->speed.y > 1 && this->pato.getPosition().y >= 283)
            {
                this->pisando = 1;
                this->pato.setPosition(this->pato.getPosition().x, 290);
            }
            else
            {
                this->pisando = 0;
            }
        }
        // base2
        if (this->pato.getPosition().x > 402 && this->pato.getPosition().x < 552 /*&& this->pato.getPosition().y <= 290*/)
        {
            if (this->speed.y > 0 && this->pato.getPosition().y >= 283)
            {
                this->pisando = 1;
                this->pato.setPosition(this->pato.getPosition().x, 285);
            }
            else
            {
                this->pisando = 0;
            }
        }
        // base 3
        if (this->pato.getPosition().x > 752 && this->pato.getPosition().x < 902 /*&& this->pato.getPosition().y <= 290*/)
        {
            if (this->speed.y > 0 && this->pato.getPosition().y >= 283)
            {
                this->pisando = 1;
                this->pato.setPosition(this->pato.getPosition().x, 285);
            }
            else
            {
                this->pisando = 0;
            }
        }
        //base 4
         if (this->pato.getPosition().x > 234 && this->pato.getPosition().x < 378 && this->pato.getPosition().y <= 185)
        {
            if (this->speed.y > 0 && this->pato.getPosition().y >= 178)
            {
                this->pisando = 1;
                this->pato.setPosition(this->pato.getPosition().x, 180);
            }
            else
            {
                this->pisando = 0;
            }
        }
    }
    if (!this->derecha)
    {
    //Base1
    if (this->pato.getPosition().x > 100 && this->pato.getPosition().x < 250 /*&& this->pato.getPosition().y <= 290*/)
    {
        if (this->speed.y > 1 && this->pato.getPosition().y >= 283)
        {
            this->pisando = 1;
            this->pato.setPosition(this->pato.getPosition().x, 290);
        }
        else
        {
            this->pisando = 0;
        }
    }
    // base2
    if (this->pato.getPosition().x > 452 && this->pato.getPosition().x < 602 /*&& this->pato.getPosition().y <= 290*/)
    {
        if (this->speed.y > 0 && this->pato.getPosition().y >= 283)
        {
            this->pisando = 1;
            this->pato.setPosition(this->pato.getPosition().x, 285);
        }
        else
        {
            this->pisando = 0;
        }
    }
    // base 3
    if (this->pato.getPosition().x > 802 && this->pato.getPosition().x < 952 /*&& this->pato.getPosition().y <= 290*/)
    {
        if (this->speed.y > 0 && this->pato.getPosition().y >= 283)
        {
            this->pisando = 1;
            this->pato.setPosition(this->pato.getPosition().x, 285);
        }
        else
        {
            this->pisando = 0;
        }
    }
     //base 4
         if (this->pato.getPosition().x > 284 && this->pato.getPosition().x < 428 && this->pato.getPosition().y <= 185)
        {
            if (this->speed.y > 0 && this->pato.getPosition().y >= 178 )
            {
                this->pisando = 1;
                this->pato.setPosition(this->pato.getPosition().x, 180);
            }
            else
            {
                this->pisando = 0;
            }
        }
    }

    if (this->pato.getPosition().y >= 401)
    {
        this->pisando = 1;
    }
    // else
    // {
    //     this->pisando=0;
    // }
}