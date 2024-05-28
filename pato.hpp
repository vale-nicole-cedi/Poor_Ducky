#ifndef pato_hpp
#define pato_hpp
#include <SFML/Graphics.hpp>
#include "bases.hpp"
using namespace sf;
class Pato
{
public:
Texture texture;
Sprite pato;
Vector2f speed, acc;
int pts;
bool pisando;
bool derecha;
Pato();
void sumarPts();
void moverseIzq();
void moverseDer();
void brincar();
void click();
bool estaEnBase(Bases base);
void drawTo(RenderWindow &window);
};

#endif