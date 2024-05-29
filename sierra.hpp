#ifndef sierra_hpp
#define sierra_hpp
#include <SFML/Graphics.hpp>
using namespace sf;
class Sierra
{
    public:
Texture sierra;
Sprite spriteSierra;
Vector2f speed;
Sierra();
void update();
void drawTo(RenderWindow &window);
};
#endif
