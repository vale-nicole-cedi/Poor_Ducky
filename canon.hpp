#ifndef canon_hpp
#define canon_hpp
#include <SFML/Graphics.hpp>
using namespace sf;
class Canon
{
    public:
Texture canon;
Sprite spriteCanon;
Texture bala;
Sprite spriteBala;
Vector2f speed;
Canon();
void update();
void drawTo(RenderWindow &window);
};
#endif
