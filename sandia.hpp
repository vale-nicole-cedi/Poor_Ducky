#ifndef sandia_hpp
#define sandia_hpp
#include <SFML/Graphics.hpp>
using namespace sf;
class Sandia
{
    public:
Texture sandia;
Sprite spriteSandia;
Sandia();
void drawTo(RenderWindow &window);
};
#endif
