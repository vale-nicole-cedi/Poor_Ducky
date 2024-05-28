#ifndef bolas_hpp
#define bolas_hpp
#include <SFML/Graphics.hpp>
using namespace sf;
class Bolas
{
    public:
Texture bola;
Sprite spriteBola;
Vector2f speed;
Bolas();
void update();
void drawTo(RenderWindow &window);
};
#endif
