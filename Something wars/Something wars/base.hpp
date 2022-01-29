#ifndef BASE_H
#define BASE_H
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class base
{
    public:
        base(int side);
        virtual ~base();
        Sprite Spbase;
        void setBase(RenderWindow &window);
        void setBasePos(float xpos,float ypos);
        RectangleShape Hpbar;
        double HP;
        void gameresert();

    protected:

    private:

        int sidec;
        Texture texbase;
        RectangleShape stroke;
        IntRect boxbase;

};

#endif // BASE_H
