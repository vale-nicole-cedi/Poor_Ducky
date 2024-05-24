#ifndef bases_hpp
#define bases_hpp
#include <SFML/Graphics.hpp>
using namespace sf;
class Bases
{
    public:
Texture base;
Sprite spriteBase;
Bases();
void drawTo(RenderWindow &window);
};
#endif
