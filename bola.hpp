#ifndef bola_hpp
#define bola_hpp
#include <SFML/Graphics.hpp>
using namespace sf;
class Bola
{
    public:
Texture bola;
Sprite spriteBola;
Vector2f speed;
Bola();
void update();
void drawTo(RenderWindow &window);
};
#endif
