#ifndef CREEP_H
#define CREEP_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

class creep
{
    public:
        creep(bool side);
        virtual ~creep();
        float x;
        float y;
        bool isstart = false;
        bool onground = false;
        bool isjumping = true;
        bool iscollide = false;
        bool attack = false;

        bool isRight;
        Sprite Splayer;
        float frame;
        float Gravity = 980;
        bool topground = false;
        void update(double *debugTime,int &nummap);
        void drawCreep(RenderWindow &window);
        int h;

        float HP;
        float HPedit;
    Sound CreepAttack;
    protected:

    private:

    SoundBuffer CAttack;

    Sprite CreepDead;

    Texture Tchar1;
    IntRect spriteRect;

    RectangleShape Hpbar,strokeHp;

    void animate(Sprite *SprP,double *debugTime);
    void collide(int chk);



};

#endif // CREEP_H
