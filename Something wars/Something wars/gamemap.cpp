#include "gamemap.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;


gamemap::gamemap()
{
    /***load tex**/
        bg1.loadFromFile("data/images/map/bg1.png");
        ground1.loadFromFile("data/images/map/ground1.png");
        ground1right.loadFromFile("data/images/map/ground1right.png");
        ground1left.loadFromFile("data/images/map/ground1left.png");
        groundjump1.loadFromFile("data/images/map/groundjump1.png");
        dirt1.loadFromFile("data/images/map/dirt1.png");
        dirtlow1.loadFromFile("data/images/map/dirtlow1.png");

        bg2.loadFromFile("data/images/map/bg2.png");
        ground2.loadFromFile("data/images/map/ground2.png");
        ground2right.loadFromFile("data/images/map/ground2right.png");
        ground2left.loadFromFile("data/images/map/ground2left.png");
        groundjump2.loadFromFile("data/images/map/groundjump2.png");
        dirt2.loadFromFile("data/images/map/dirt2.png");
        dirtlow2.loadFromFile("data/images/map/dirtlow2.png");

        bg3.loadFromFile("data/images/map/bg3.png");
        ground3.loadFromFile("data/images/map/ground3.png");
        ground3right.loadFromFile("data/images/map/ground3right.png");
        ground3left.loadFromFile("data/images/map/ground3left.png");
        groundjump3.loadFromFile("data/images/map/groundjump3.png");
        dirt3.loadFromFile("data/images/map/dirt3.png");
        dirtlow3.loadFromFile("data/images/map/dirtlow3.png");

        bg4.loadFromFile("data/images/map/bg4.png");
        ground4.loadFromFile("data/images/map/ground4.png");
        ground4right.loadFromFile("data/images/map/ground4right.png");
        ground4left.loadFromFile("data/images/map/ground4left.png");
        groundjump4.loadFromFile("data/images/map/groundjump4.png");
        dirt4.loadFromFile("data/images/map/dirt4.png");
        dirtlow4.loadFromFile("data/images/map/dirtlow4.png");

        bg5.loadFromFile("data/images/map/bg5.png");
        ground5.loadFromFile("data/images/map/ground5.png");
        ground5right.loadFromFile("data/images/map/ground5right.png");
        ground5left.loadFromFile("data/images/map/ground5left.png");
        groundjump5.loadFromFile("data/images/map/groundjump5.png");
        dirt5.loadFromFile("data/images/map/dirt5.png");
        dirtlow5.loadFromFile("data/images/map/dirtlow5.png");
//     Sbg1.setPosition(0,0);

}

gamemap::~gamemap(){}

void gamemap::array2d(int copymap[][30]){

    for(int i=0 ; i < 15 ; i++)
    {
        for(int j=0 ; j < 30 ; j++)
        {
            bm[i][j]=copymap[i][j];
        }

    }
}

//map 0=blank,1=glass,2=glassjump,3=dirt,4=glassright,5=glassleft,9=block


void gamemap::mapselect(int *nummap){

    if(*nummap == 1){
        int Cbm[15][30] =
        {
            9,9,9,0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,0,0,0,0,0,0,9,
            9,0,0,0,0,0,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,0,0,0,0,0,9,
            5,3,3,3,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,4,
            3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
        };
        array2d(Cbm);
    }

    if(*nummap == 2){
        int Cbm[15][30] =
        {
            9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,6,0,0,0,9,
            9,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,
            3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
        };
        array2d(Cbm);
    }

    if(*nummap == 3){
        int Cbm[15][30] =
        {
            9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,5,1,1,1,1,1,1,4,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,5,1,1,3,3,3,1,1,1,4,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,5,1,1,3,3,3,3,3,3,1,1,4,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,5,1,1,3,3,3,3,3,3,3,3,1,1,4,0,0,0,0,0,0,0,9,
            5,1,1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1,1,1,4,
            3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
        };
        array2d(Cbm);
    }

    if(*nummap == 4){
        int Cbm[15][30] =
        {
            9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,9,
            9,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,3,1,1,1,3,0,0,0,0,0,0,0,0,3,1,1,1,3,0,0,0,0,0,9,
            9,0,0,0,0,3,3,1,1,1,3,3,0,0,0,0,0,0,3,3,1,1,1,3,3,0,0,0,0,9,
            5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,
            3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
        };
        array2d(Cbm);
    }
    if(*nummap == 5){
        int Cbm[15][30] =
        {
            9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,6,0,0,0,9,
            9,0,0,0,0,0,6,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,6,0,0,0,0,0,0,6,0,0,0,0,0,0,6,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
            5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,
            3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
        };
        array2d(Cbm);
    }


}

 void gamemap::drawbg(RenderWindow &window,float xpos,float ypos,int *nummap,int &Endgame){

if(*nummap == 1){
        Sbg1.setTexture(bg1);
}
if(*nummap == 2){
        Sbg1.setTexture(bg2);
}
if(*nummap == 3){
        Sbg1.setTexture(bg3);
}
if(*nummap == 4){
        Sbg1.setTexture(bg4);
}
if(*nummap == 5){
        Sbg1.setTexture(bg5);
}
if (Endgame == 0) {
	Sbg1.setPosition(camX(xpos / 2 - Sbg1.getLocalBounds().width / 8), camY(ypos / 3 - Sbg1.getLocalBounds().height / 2) + (*nummap == 5 ? 150 : 60));
}
if (Endgame == 1) {
	Sbg1.setPosition(1280, -496 + (*nummap == 5 ? 150 : 60));
}else if (Endgame == 2) {
	Sbg1.setPosition(0, -496 + (*nummap == 5 ? 150 : 60));
}
        window.draw(Sbg1);
 }


float gamemap::camX(float xpos){
    if(xpos < 0){
        return 0;
    }else if (xpos > 1280){
        return 1280;
    }else{
        return xpos;
    }
 }

 float gamemap::camY(float ypos){
    if(ypos > -496){
        return -496;
    }else{
        return ypos;
    }
}


 void gamemap::drawground(RenderWindow &window,int i,int j,int *nummap,int type){


if(*nummap == 1){
    if(type == 1) Sground.setTexture(ground1);
    if(type == 2) Sground.setTexture(groundjump1);
    if(type == 3) Sground.setTexture(dirt1);
    if(type == 4) Sground.setTexture(ground1right);
    if(type == 5) Sground.setTexture(ground1left);
    if(type == 6) Sground.setTexture(dirtlow1);
}

if(*nummap == 2){
    if(type == 1) Sground.setTexture(ground2);
    if(type == 2) Sground.setTexture(groundjump2);
    if(type == 3) Sground.setTexture(dirt2);
    if(type == 4) Sground.setTexture(ground2right);
    if(type == 5) Sground.setTexture(ground2left);
    if(type == 6) Sground.setTexture(dirtlow2);
}

if(*nummap == 3){
    if(type == 1) Sground.setTexture(ground3);
    if(type == 2) Sground.setTexture(groundjump3);
    if(type == 3) Sground.setTexture(dirt3);
    if(type == 4) Sground.setTexture(ground3right);
    if(type == 5) Sground.setTexture(ground3left);
    if(type == 6) Sground.setTexture(dirtlow3);
}
if(*nummap == 4){
    if(type == 1) Sground.setTexture(ground4);
    if(type == 2) Sground.setTexture(groundjump4);
    if(type == 3) Sground.setTexture(dirt4);
    if(type == 4) Sground.setTexture(ground4right);
    if(type == 5) Sground.setTexture(ground4left);
    if(type == 6) Sground.setTexture(dirtlow4);
}
if(*nummap == 5){
    if(type == 1) Sground.setTexture(ground5);
    if(type == 2) Sground.setTexture(groundjump5);
    if(type == 3) Sground.setTexture(dirt5);
    if(type == 4) Sground.setTexture(ground5right);
    if(type == 5) Sground.setTexture(ground5left);
    if(type == 6) Sground.setTexture(dirtlow5);
}

Sground.setPosition(128*j,72*i);
window.draw(Sground);

 }


