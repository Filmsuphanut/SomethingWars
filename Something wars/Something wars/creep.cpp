#include "creep.hpp"
#include<SFML/Graphics.hpp>
#include "gamemap.hpp"
#include <iostream>
#include<ctime>

gamemap creepmap;

using namespace sf;
using namespace std;

creep::creep(bool side)
{
        //srand(time(NULL)+5687);
        isstart = false;
        x = (side==1? 0.1:-0.1);
        y = 0;
        frame  = 0;
        isRight = side;
        //isRight = true;

        Tchar1.loadFromFile("data/images/char/creep.png");

        Splayer.setPosition(0,72);

        HPedit = 80;
         HP = HPedit;
        Hpbar.setSize(Vector2f(100,10));
        if(side)Hpbar.setFillColor(Color(0,255,0,200));
        if(!side)Hpbar.setFillColor(Color(255,0,0,200));
        strokeHp.setSize(Vector2f(100,10));
       // strokeHp.setFillColor(Color(255,0,0,95));
        strokeHp.setFillColor(Color(192,192,192,95));
        strokeHp.setOutlineColor(Color::Black);
        strokeHp.setOutlineThickness(1);

        CAttack.loadFromFile("data/sound/creepattack.wav");
        CreepAttack.setBuffer(CAttack);
        CreepAttack.setVolume(15);
        CreepAttack.setRelativeToListener(true);
        //CreepAttack.setMinDistance(5.f);
        //CreepAttack.setAttenuation(10.f);

        Splayer.setTexture(Tchar1,true);
        CreepDead.setTexture(Tchar1,true);
        spriteRect = IntRect((Splayer.getGlobalBounds().width/10),(Splayer.getGlobalBounds().height/10),
                             (Splayer.getGlobalBounds().width/10),(Splayer.getGlobalBounds().height/10));
        Splayer.setTextureRect(spriteRect);
        CreepDead.setTextureRect(spriteRect);


}

creep::~creep()
{
    //dtor
}






    void creep::update(double *debugTime,int &nummap){
        //Splayer.setScale(2,2);
    //    if(isstart){
        creepmap.mapselect(&nummap);
        animate(&Splayer,&*debugTime);

        if(HP > 0){
        if(!onground)
        {
            iscollide = false;
            y += Gravity*(*debugTime)*2;
        }
        else
        {
            y=0;

        }



        if (topground){
        if(y < 0){y = 250;
        }
            y += Gravity*(*debugTime);

        }


        CreepDead.setPosition((Splayer.getPosition().x+x*(*debugTime)),(Splayer.getPosition().y+(y*(*debugTime))));

        Splayer.setPosition((Splayer.getPosition().x+x*(*debugTime)),Splayer.getPosition().y);
        collide(0);
        onground = false;

        Splayer.setPosition(Splayer.getPosition().x,(Splayer.getPosition().y+(y*(*debugTime))));
        collide(1);


        Hpbar.setPosition(Splayer.getPosition().x,Splayer.getPosition().y-2*h);
        strokeHp.setPosition(Splayer.getPosition().x,Splayer.getPosition().y-2*h);
        Hpbar.setSize(Vector2f((HP/HPedit)*100,10));

        }else{

        animate(&CreepDead,&*debugTime);
        Splayer.setPosition(0,0);
        HP=0;

        Hpbar.setPosition(0,0);
        strokeHp.setPosition(0,0);
        Hpbar.setSize(Vector2f((HP/HPedit)*100,10));
        }



    }

    void creep::collide(int chk){

    for(int dy=Splayer.getPosition().y/72 ; dy < (Splayer.getPosition().y+Splayer.getGlobalBounds().height)/72 ;dy++){
    for(int dx=Splayer.getPosition().x/128 ; dx < (Splayer.getPosition().x+Splayer.getGlobalBounds().width)/128 ;dx++){

        if(creepmap.bm[dy][dx] == 1 || creepmap.bm[dy][dx] == 9 || creepmap.bm[dy][dx] == 3){//[dy][dx]

                    if(!(Splayer.getPosition().x + (Splayer.getLocalBounds().width) > dx*72
                    && Splayer.getPosition().x < dx*72
                    && Splayer.getPosition().y + (Splayer.getLocalBounds().height) > dy*128
                    && Splayer.getPosition().y < dy*128)){



                        if(x > 0 && chk == 0){
                        Splayer.setPosition(Vector2f(dx*128-Splayer.getLocalBounds().width,Splayer.getPosition().y));
                        if(creepmap.bm[dy][dx] == 3){iscollide = true;}

                        }
                        if(x < 0 && chk == 0){
                        Splayer.setPosition(Vector2f(dx*128+128,Splayer.getPosition().y));
                        if(creepmap.bm[dy][dx] == 3){iscollide = true;}
                        }
                        if(y > 0 && chk == 1){
                        Splayer.setPosition(Vector2f(Splayer.getPosition().x,dy*72-Splayer.getLocalBounds().height));
                        isjumping = false;
                        onground = true;
                        topground = false;
                        }

                        if(y < 0 && chk == 1){
                        y=0;
                        topground = true;
                        Splayer.setPosition(Vector2f(Splayer.getPosition().x,dy*72+72));

                        }

                    }else{

                    iscollide = false;

                    }

                }

        if(creepmap.bm[dy][dx] == 2){

                    if(!(Splayer.getPosition().y - (Splayer.getLocalBounds().height) > (dy*128))){

                if(y > 0 && chk == 1){
                    Splayer.setPosition(Vector2f(Splayer.getPosition().x,dy*72-Splayer.getLocalBounds().height));
                    isjumping = false;
                    onground = true;
                    topground = false;
                }
            }
        }



/******************************************************* slope ******************************/


        if(creepmap.bm[dy][dx] == 5){//[dy][dx]

                    if(!(Splayer.getPosition().y + (Splayer.getLocalBounds().height) > dy*128
                    && Splayer.getPosition().y < dy*128)){

                    for(float slope = (Splayer.getPosition().x+Splayer.getLocalBounds().width)/128-dx;
                    slope <= (Splayer.getPosition().x+2*Splayer.getLocalBounds().width)/128-dx
                    ;slope++){

                   // cout<<slope<<endl;

                        if(y > 0 && chk == 1){
                        Splayer.setPosition(Vector2f(Splayer.getPosition().x,
                        (((dy+1)*72-slope*72)-Splayer.getLocalBounds().height)
                        ));
                        isjumping = false;
                        onground = true;
                        topground = false;
                        }

                    }
                }
            }

        if(creepmap.bm[dy][dx] == 4){//[dy][dx]
                    if(!(Splayer.getPosition().y + (Splayer.getLocalBounds().height) > dy*128
                    && Splayer.getPosition().y < dy*128)){

                    for(float slope = (Splayer.getPosition().x)/128-dx;
                    slope <= (Splayer.getPosition().x+Splayer.getLocalBounds().width)/128-dx
                    ;slope++){

                   //cout<<slope<<endl;

                        if(y > 0 && chk == 1){
                        Splayer.setPosition(Vector2f(Splayer.getPosition().x,
                        ((slope<0? dy*72:dy*72+slope*72)-Splayer.getLocalBounds().height)

                        ));
                        isjumping = false;
                        onground = true;
                        topground = false;
                        }
                    }
                }
            }

/************************************************************************************/

        }

        }
}


void creep::drawCreep(RenderWindow &window){

    if(HP > 0){
        window.draw(Splayer);
        window.draw(strokeHp);
        window.draw(Hpbar);
        //Hpbar.setPosition(Splayer.getPosition().x,Splayer.getPosition().y-5*i);
        //strokeHp.setPosition(Splayer.getPosition().x,Splayer.getPosition().y-5*i);
        Hpbar.setSize(Vector2f((HP/100)*100,10));
    }else if(HP <= 0){
        //Hpbar.setPosition(0,0);
       // strokeHp.setPosition(0,0);
        window.draw(CreepDead);
    }

}


    void creep::animate(Sprite *SprP,double *debugTime){

    if(HP <= 0){
        attack = false;

if(isRight){

        if(frame > 7.99){
            frame = 8;
        }

        if((int)frame != 8){
        frame = frame + 5*(*debugTime);
        }

        (*SprP).setTextureRect(IntRect(spriteRect.left*(int)frame,200,spriteRect.width,spriteRect.height));


}else{

        if(frame > 7.99){
            frame = 8;
        }

        if((int)frame != 8){
        frame = frame + 5*(*debugTime);
        }

        (*SprP).setTextureRect(IntRect(spriteRect.left*(int)frame+spriteRect.width,200,-spriteRect.width,spriteRect.height));

}

    }else{


   if(x == 0)
    {
        frame = frame + 10*(*debugTime) ;
        if(frame > 10)
        {
            frame = 0;
        }
        if((int)frame == 1 && x==0){
        frame=2;
        attack = true;

        CreepAttack.play();
        //CreepAttack.setVolume(1000/(300+2*(max((int)abs(Listener::getPosition().x-Splayer.getPosition().x),300))-20));
       // CreepAttack.setPosition(Splayer.getPosition().x,0,Splayer.getPosition().y);
        //CreepAttack.setMinDistance(Splayer.getPosition().x);


        //CreepAttack.setAttenuation(41);


        }else if((int)frame != 1 && x==0){
        attack = false;
        }

        if(isRight)(*SprP).setTextureRect(IntRect(spriteRect.left*(int)frame,0,spriteRect.width,spriteRect.height));
        if(!isRight)(*SprP).setTextureRect(IntRect(spriteRect.left*(int)frame+spriteRect.width,0,-spriteRect.width,spriteRect.height));

    }

    if (x > 0){
        attack = false;
        isRight = true;

        frame = frame + 10*(*debugTime);

        if(frame > 8){
            frame = 0;
        }
        (*SprP).setTextureRect(IntRect(spriteRect.left*(int)frame,spriteRect.top,spriteRect.width,spriteRect.height));

    }
    if(x < 0){
        attack = false;
        isRight = false;
        frame = frame + 10*(*debugTime) ;
        if(frame > 8){
            frame = 0;
        }
        (*SprP).setTextureRect(IntRect(spriteRect.left*(int)frame+spriteRect.width,spriteRect.top,-spriteRect.width,spriteRect.height));
    }


    }

}


