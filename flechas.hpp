#ifndef flechas_hpp
#define sflechas_hpp
#include <SFML/Graphics.hpp>
using namespace sf;
class Flechas
{
    public:
Texture felcha;
Sprite spriteFlecha;
Flechas();
void update();
void drawTo(RenderWindow &window);
};
#endif
