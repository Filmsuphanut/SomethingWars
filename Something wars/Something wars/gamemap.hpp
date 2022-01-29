#ifndef GAMEMAP_H
#define GAMEMAP_H
#include <SFML/Graphics.hpp>

using namespace sf;
class gamemap
{
    public:
        gamemap();
        virtual ~gamemap();
        int bm[15][30];
        void array2d(int copymap[][30]);
        void mapselect(int *nummap);
        void drawbg(RenderWindow &window,float xpos,float ypos,int *nummap,int &Endgame);
        void drawground(RenderWindow &window,int i,int j,int *nummap,int type);

    protected:

    private:

        Texture bg1;
        Texture ground1;
        Texture ground1left;
        Texture ground1right;
        Texture groundjump1;
        Texture dirt1;
        Texture dirtlow1;

        Texture bg2;
        Texture ground2;
        Texture ground2left;
        Texture ground2right;
        Texture groundjump2;
        Texture dirt2;
        Texture dirtlow2;

        Texture bg3;
        Texture ground3;
        Texture ground3left;
        Texture ground3right;
        Texture groundjump3;
        Texture dirt3;
        Texture dirtlow3;

        Texture bg4;
        Texture ground4;
        Texture ground4left;
        Texture ground4right;
        Texture groundjump4;
        Texture dirt4;
        Texture dirtlow4;

        Texture bg5;
        Texture ground5;
        Texture ground5left;
        Texture ground5right;
        Texture groundjump5;
        Texture dirt5;
        Texture dirtlow5;


        Sprite Sbg1;
        Sprite Sground;


        float camX(float xpos);
        float camY(float ypos);

};

#endif // GAMEMAP_H
