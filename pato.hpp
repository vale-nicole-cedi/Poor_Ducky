#ifndef pato_hpp
#define pato_hpp
#include <SFML/Graphics.hpp>
using namespace sf;
class Pato
{
public:
Texture texture;
Sprite pato;
int speed;
int pts;
Pato();
int sumarPts();
void moverseIzq();
void moverseDer();
void brincar();
void drawTo(RenderWindow &window);
};

#endif