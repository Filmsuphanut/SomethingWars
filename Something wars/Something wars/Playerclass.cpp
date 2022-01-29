#include "Playerclass.hpp"
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "gamemap.hpp"
#include <iostream>
#include<ctime>
#include <sstream>
#include <string>
#include <iomanip>
gamemap mapping;



using namespace sf;
using namespace std;



Playerclass::Playerclass(int selectchar)
{

        //srand(time(NULL));
        //isstart = false;
        Char = selectchar;
        x = 0;
        y = 0;
        frame  = 0;
        isRight = true;
        Pcamera.setSize(1280,720);
        Pcamera.setViewport(FloatRect(0.f,0.f,1.f,1.f));
        Pcamera.setCenter(640,360);

        ff2.loadFromFile("data/font/segoeprb.ttf");
        playername.setFont(ff2);
        playername.setCharacterSize(20);
        playername.setOutlineThickness(2);
        playername.setOutlineColor(Color::Black);
        Printlevel.setFont(ff2);
        Printlevel.setCharacterSize(20);
        Printlevel.setOutlineThickness(2);
        Printlevel.setOutlineColor(Color::Black);


        callOBJ();

        maxHP = Char==1? 130:Char==2? 80:Char==3? 100:0;

        HP = maxHP;

        Hpbar.setSize(Vector2f(100,10));
        Hpbar.setFillColor(Color(0,255,0,200));
        strokeHp.setSize(Vector2f(100,10));
        strokeHp.setFillColor(Color(192,192,192,200));
        strokeHp.setOutlineColor(Color::Black);
        strokeHp.setOutlineThickness(1);

        immortality = false;
        stunned = false;
        cout<<y<<endl;
}




Playerclass::~Playerclass(){


}

    /*******************************************************************/

    void Playerclass::callOBJ(){

    /*********************************** load char 1********************************/
    if(Char == 1){

        Tchar1.loadFromFile("data/images/char/char1+.png");
        Splayer.setTexture(Tchar1,true);
        Tchar1.setSmooth(true);
        spriteRect = IntRect((Splayer.getGlobalBounds().width/10),(Splayer.getGlobalBounds().height/9+0.5),
                            (Splayer.getGlobalBounds().width/10),(Splayer.getGlobalBounds().height/9)+0.5);
        //Splayer.setTextureRect(IntRect(0,0,1280,1107));
        //Splayer.setScale(2,2);
        wBox1 = 45*1.5;
        hBox1 = 67*1.5;
        dwBox1 = 12*1.5;
        dhBox1 = 56*1.5;

        hit.setSize(Vector2f(100+wBox1,100));
        hit2.setSize(Vector2f(130+wBox1,45));
        hit3.setSize(Vector2f(150,150));

        hit.setFillColor(Color::Red);
        hit2.setFillColor(Color::Green);
        hit3.setFillColor(Color::Blue);

        soundBAtt1.loadFromFile("data/sound/att/C1att1.wav");
        soundAtt1.setBuffer(soundBAtt1);
        soundAtt1.setVolume(70);
        soundBAtt2.loadFromFile("data/sound/att/C1att2.wav");
        soundAtt2.setBuffer(soundBAtt2);
        soundAtt2.setVolume(70);
        soundBAtt3.loadFromFile("data/sound/att/C1att3.wav");
        soundAtt3.setBuffer(soundBAtt3);
        soundAtt3.setVolume(70);

    /*********************************** load char 2********************************/
    }else if(Char == 2){

        Tchar2.loadFromFile("data/images/char/char2+.png");
        Tc2at3.loadFromFile("data/images/char/char2a3.png");
        Splayer.setTexture(Tchar2,true);
        Tchar1.setSmooth(true);
        spriteRect = IntRect((Splayer.getGlobalBounds().width/13),(Splayer.getGlobalBounds().height/9),
                            (Splayer.getGlobalBounds().width/13),(Splayer.getGlobalBounds().height/9));
        //Splayer.setTextureRect(IntRect(0,0,1280,1107));
        //Splayer.setScale(2,2);

        wBox1 = 47;
        hBox1 = 108;
        dwBox1 = 101;
        dhBox1 = 42;

        hit.setSize(Vector2f(127+wBox1,53));
        hit2.setSize(Vector2f(wBox1+50,hBox1));
        hit3.setSize(Vector2f(800,400));
        //hit3.setFillColor(Color::Red);
        hit.setFillColor(Color::Red);
        hit2.setFillColor(Color::Green);
        hit3.setFillColor(Color::Blue);

        Tc2at3.setSmooth(true);
        Sc2at3.setTexture(Tc2at3);
        Sc2at3.setTextureRect(IntRect(0,0,Sc2at3.getGlobalBounds().width/15,Sc2at3.getGlobalBounds().height));

        soundBAtt1.loadFromFile("data/sound/att/C2att1.wav");
        soundAtt1.setBuffer(soundBAtt1);
        soundAtt1.setVolume(75);
        soundBAtt2.loadFromFile("data/sound/att/C2att2.wav");
        soundAtt2.setBuffer(soundBAtt2);
        soundAtt2.setVolume(75);
        soundBAtt3.loadFromFile("data/sound/att/C2att3.wav");
        soundAtt3.setBuffer(soundBAtt3);
        soundAtt3.setVolume(70);

    /*********************************** load char 3********************************/
    }else if(Char == 3){

        Tchar3.loadFromFile("data/images/char/char3+.png");
        Tball.loadFromFile("data/images/char/char3normala.png");
        Tc3at2.loadFromFile("data/images/char/char3a2.png");
        //Tc3at2.setSmooth(true);
        Tc3at3.loadFromFile("data/images/char/char3a3.png");
        Tc3at3.setSmooth(true);

        ball.setTexture(Tball);
        ball.setTextureRect(IntRect(0,0,ball.getGlobalBounds().width,ball.getGlobalBounds().height));
        c3at2.setTexture(Tc3at2);
        c3at2.setTextureRect(IntRect(0,0,c3at2.getGlobalBounds().width,c3at2.getGlobalBounds().height));
        //c3at2.setScale(2,6);
        c3at3.setTexture(Tc3at3);
        c3at3.setTextureRect(IntRect(0,0,c3at3.getGlobalBounds().width/5,c3at3.getGlobalBounds().height/4));

        Splayer.setTexture(Tchar3,true);
                Tchar1.setSmooth(true);
        spriteRect = IntRect((Splayer.getGlobalBounds().width/10),(Splayer.getGlobalBounds().height/9),
                            (Splayer.getGlobalBounds().width/10),(Splayer.getGlobalBounds().height/9));
        //Splayer.setTextureRect(IntRect(0,0,1280,1107));
        //Splayer.setScale(2,2);
        wBox1 = 27*1.5;
        hBox1 = 75*1.5;
        dwBox1 = 8*1.5;
        dhBox1 = 31*1.5;

        hit.setSize(Vector2f(ball.getGlobalBounds().width,ball.getGlobalBounds().height));
        hit2.setSize(Vector2f(c3at2.getGlobalBounds().width+wBox1,c3at2.getGlobalBounds().height));
        hit3.setSize(Vector2f(271,500));

        hit.setFillColor(Color::Red);
        hit2.setFillColor(Color::Green);
        hit3.setFillColor(Color::Blue);

        soundBAtt1.loadFromFile("data/sound/att/C3att1.wav");
        soundAtt1.setBuffer(soundBAtt1);
        soundAtt1.setVolume(55);
        soundBAtt2.loadFromFile("data/sound/att/C3att2.wav");
        soundAtt2.setBuffer(soundBAtt2);
        soundAtt2.setVolume(70);
        soundBAtt3.loadFromFile("data/sound/att/C3att3.wav");
        soundAtt3.setBuffer(soundBAtt3);
        soundAtt3.setVolume(65);


        //ball.setRadius(5);
        //ball.setFillColor(Color::Red);

    }

    Rplayer.setSize(Vector2f(wBox1,hBox1));



    }


    /*********************************** select map ********************************/
    void Playerclass::Select(float xpos,float ypos,int *nummap,int side,String nameofplayer)
    {

        spawnpointX = xpos;
        spawnpointY = ypos;
        mapping.mapselect(nummap);
        Rplayer.setPosition(spawnpointX,spawnpointY);
        sideL = side;
        TimeDead = 0;
        stuntime = 0;
        stunned = false;
        Hpbar.setFillColor(Color(sideL? 0:255,sideL? 255:0,0,200));

        playername.setString(nameofplayer);
        playername.setOrigin(playername.getGlobalBounds().width/2,0);
        playername.setFillColor(side==1?  (Color::Green):(Color::Red));
        Printlevel.setFillColor(side==1?  (Color::Green):(Color::Red));
        Level = 1;
        Exp = 0;
        Killcount = 0;
        Deathcount = 0;
    }


    /*********************************** update  ********************************/

    void Playerclass::update(double *debugTime,RenderWindow &window,bool A,bool D,bool W,bool J,bool K,bool L){

/**************** EXP AND DAMAGESKILL *********************/

    if(Exp > 15+10*(Level/2) && Level < 15){
        Exp = 0;
        Level++;
        if(HP>0){HP += maxHP*10/100;}
    }
    if(HP > maxHP){
        HP=maxHP;
    }


    //cout<<Exp<<endl;
        stringstream sslevel;
        sslevel<<Level;
    //    cout<<sslevel.str();
        Printlevel.setString("level : "+sslevel.str());
        Printlevel.setOrigin(Printlevel.getGlobalBounds().width/2,0);



/******************************** T Dead ***********************/


    if(TimeDead > 0){

        TimeDead = TimeDead - *debugTime;
        if(TimeDead < 0){
            /***************************** Spawn ******************/
            frame = 0;
            attframe = 0;
            HP = maxHP;
            xposdead=0;
            yposdead=0;
            framed=0;
            yxx = 0;
            chk=false;
            stunned = false;
            immortality = false;
            normalattack = false;
            attackT1 = false;
            attackT2 = false;
            cd1 = 0;
            cd2 = 0;
            Rplayer.setPosition(spawnpointX,spawnpointY);
            /********************************************************/

        }



    }

    if(cd1 > 0){
        cd1 = cd1 - *debugTime;
        if(cd1 < 0){
            cd1 = 0;
        //HP = 0;
        //stunned = immortality? false:true;/****************************************** stuuned immor **************/
        //cd2 = *debugTime+4.0 - *debugTime;
        }
    }
    if(cd2 > 0){
        cd2 = cd2 - *debugTime;
        if(cd2 < 0){
            cd2 = 0;
        //stunned = false;
        }
    }


    if(stuntime > 0){
        stunned = true;
        stuntime = stuntime - *debugTime;
        if(stuntime < 0){
            stuntime = 0;
        stunned = false;
        }
    }

       // cout<<onground<<" "<<y<<" "<<cd1<<" "<<cd2<<" "<<P1.size();
       // cout<<balls.size()<<" "<<hitbox.size()<<endl;
//cout<<immortality<<" "<<stunned<<" "<<TimeDead<<" "<<cd1<<endl;
/************************************************* control **********************************************/

if(HP>0){



if(!attackT1 && !attackT2 && !normalattack && !stunned){
            if(A)
            {
                //isRight =false;
                x = -250-(5*Level);
            }

            if(D)
            {
                //isRight = true;
               x = 250+(5*Level);
            }

            if(W && !isjumping && onground){
                 onground = false;
                 isjumping=true;
                 y = -950;
            }
}

//cout <<Splayer.getPosition().x+x*(*debugTime)<<"   "<<endl;

if(Char == 1 && !stunned){

Damagenormalatt = 4+0.5*(Level-1);
DamageS1 = 70+5*(Level-2);
DamageS2 = 40+5*(Level-4);
maxHP = 130 + 4 * (Level - 1);//+2*(Killcount);

if(Level == 15){
    HP += (4*maxHP/100)*(*debugTime);
}

        if(J && !isjumping && !K && !L && !attackT1 && !attackT2 && !normalattack){
            normalattack = true;

        }else if(normalattack){
            skillanimationP11(*debugTime);
           // soundAtt1.play();
        }
        //cout<<cd1<<endl;
        //if(K && !attackT1 && !attackT2  && !isjumping && cd1 <= 0 && !J && !L && !normalattack){ //&& cd{
        if(K && !attackT1 && !attackT2 && !isjumping && cd1 <= 0  && !J && !L && !normalattack && Level >= 2){
            attackT1 = true;
            cd1 = *debugTime+2.0 - *debugTime;
            //cout<<K<<endl;
        }else if(attackT1 && cd1 > 0){ //&& cd{
            skillanimationP21(*debugTime);
           //soundAtt2.play();

        }

        if(L && !attackT2 && !attackT1 && cd2 <= 0  && onground && !J && !K && !normalattack && Level >=4){
            attackT2 = true;
            onground = false;
            isjumping = true;
            immortality = true;
            y = -800 ;
            cd2 = *debugTime+8.0 - *debugTime;
        }else if(attackT2 && cd2 > 0){
            skillanimationP31(*debugTime);
           // soundAtt3.play();
        }

}else if(Char == 2 && !stunned){

Damagenormalatt = 6 + 0.5 * (Level - 1);//+0.25*(Killcount);
DamageS1 = 2.5+1*(Level-2);
DamageS2 = 10+5*(Level-4);
maxHP = 80+4*(Level-1);

        if(J  && !isjumping && !K && !L && !attackT1 && !attackT2 && !normalattack){
            normalattack = true;
        }else if(normalattack){
            skillanimationP12(*debugTime);
            //soundAtt1.play();
        }

        if(K && !attackT1 && !attackT2  && !isjumping && cd1 <= 0 && !J && !L && !normalattack && Level >= 2){ //&& cd{
            attackT1 = true;
            immortality = true;
            cd1 = *debugTime+6.0 - *debugTime;

        }else if(attackT1 && cd1 > 0){ //&& cd{
            skillanimationP22(*debugTime);
           // soundAtt2.play();
        }

        if(L && !attackT2 && !attackT1 && cd2 <= 0  && onground && !J && !K && !normalattack && Level >= 4) {// &&cd{

            immortality = true;
            attackT2 = true;
            cd2 = *debugTime+13.0 - *debugTime;
            //x = 0;
            //y = 0;
        }else if(attackT2 && cd2 > 0){ // &&cd{
            skillanimationP32(*debugTime,window);
           // soundAtt3.play();

        }

}else if(Char == 3 && !stunned){

Damagenormalatt = 6+0.5*(Level-1);
DamageS1 = 30 + 5 * (Level - 2);//+1.5*(Killcount);
DamageS2 = 30+5*(Level-4);
maxHP = 100+4*(Level-1);

        if(J && !isjumping && !K && !L && !attackT1 && !attackT2 && !normalattack){
            normalattack = true;
        }else if(normalattack){
			//soundAtt1.play();
            skillanimationP13(*debugTime,window);
        }

        if(K && !attackT1 && !attackT2  && !isjumping && cd1 <= 0 && !J && !L && !normalattack && Level >= 2 ){ //&& cd{
            attackT1 = true;
        cd1 = *debugTime+6.0 - *debugTime;
        }else if(attackT1 && cd1 > 0){ //&& cd{
            skillanimationP23(*debugTime,window);
           // soundAtt2.play();
        }

        if(L && !attackT2 && !attackT1 && cd2 <= 0  && onground && !J && !K && !normalattack && Level >= 4) {// &&cd{
            attackT2 = true;

        //cd2 = *debugTime+(30.0 -(Level==3? 20:0))- *debugTime;
			cd2 = *debugTime + (30.0) - *debugTime;
        }else if(attackT2 && cd2 > 0){ // &&cd{
            skillanimationP33(*debugTime,window);
            
        }
}


xposdead = Rplayer.getPosition().x;
framed = 0;
}else{

immortality = true;

if(!balls.empty() || !c3att2.empty() || !c3att3.empty()
   || !c2att3.empty() || !hitbox.empty() || !hitbox2.empty() || !hitbox3.empty()){
balls.clear();
c3att2.clear();
c3att3.clear();
c2att3.clear();
hitbox.clear();
hitbox2.clear();
hitbox3.clear();
}
    if(!chk){
        TimeDead = *debugTime+3+Level - *debugTime;
    }



    if(A){
    Rplayer.move(-500*(*debugTime),0);
    }
    if(D){
    Rplayer.move(500*(*debugTime),0);
    }

    if(Rplayer.getPosition().x < 640 - Rplayer.getGlobalBounds().width/2 ){

        Rplayer.setPosition(640 - Rplayer.getGlobalBounds().width/2,Rplayer.getPosition().y);

    }else if(Rplayer.getPosition().x > 3200){

        Rplayer.setPosition(3200,Rplayer.getPosition().y);
    }


    if(Rplayer.getPosition().y < 938){
    Rplayer.move(0,500*(*debugTime));
    //Rplayer.setPosition(Rplayer.getPosition().x,936);
    }



Deadanimation(*debugTime,Rplayer.getPosition().y);
}
/***********************************************************************************************************/

if(!attackT1 && !attackT2 && !normalattack && HP > 0 && !stunned){

    attframe = 0;
    animate(&Splayer,&(*debugTime));

}

if(stunned && !immortality){

if(!balls.empty() || !c3att2.empty() || !c3att3.empty()
   || !c2att3.empty() || !hitbox.empty() || !hitbox2.empty() || !hitbox3.empty()){
balls.clear();
c3att2.clear();
c3att3.clear();
c2att3.clear();
hitbox.clear();
hitbox2.clear();
hitbox3.clear();
}

    //stuntime = *debugTime+2.0 - *debugTime; /************************************************ stuntime ***************/
    normalattack = false;
    attackT1 = false;
    attackT2= false;
    attframe = 0;
    frame = 0;
    Stunnedanimation(*debugTime);
}

if(!chk){


        if(onground)
        {
            y=0;
            onground = false;
        }

        if(!onground)
        {
            y += 980*(*debugTime)*2;
        }

        if (topground){

        if(y < 0){y = 250;
        }
            y += Gravity*(*debugTime);
        }
        iscollide=false;
        Rplayer.setPosition(HP<=0? Rplayer.getPosition().x:(Rplayer.getPosition().x+x*(*debugTime)),(Rplayer.getPosition().y));
if(HP>0){collide(0);}
        onground = false;

        x = 0;

        Rplayer.setPosition(Rplayer.getPosition().x,(Rplayer.getPosition().y+(y*(*debugTime))));
        collide(1);
}

        Hpbar.setPosition(Rplayer.getPosition().x-strokeHp.getGlobalBounds().width/2+wBox1/2,Rplayer.getPosition().y-hBox1/3);
        strokeHp.setPosition(Hpbar.getPosition().x,Hpbar.getPosition().y);
        Hpbar.setSize(Vector2f((HP/maxHP)*100,10));

        /********************************* draw *****************************/
        if(isRight && HP > 0){Splayer.setPosition(Rplayer.getPosition().x-dwBox1,Rplayer.getPosition().y-dhBox1);}//Splayer.setTextureRect(IntRect(0,0,1280,1107)); }//Splayer.setScale(1.f,1.f);
        if(!isRight && HP > 0){Splayer.setPosition(Rplayer.getPosition().x-(Splayer.getGlobalBounds().width-(dwBox1+wBox1)),Rplayer.getPosition().y-dhBox1);}//Splayer.setTextureRect(IntRect(128*1+128,0,-128,1107)); }  //Splayer.setScale(-1.f,1.f);      //Splayer.setTexture(Tchar1,true);

/*
            for(size_t i = 0 ;i <hitbox3.size() ; i++){
            //att2[i].move((a2right[i])*1000*(*debugTime),0);
            window.draw(hitbox3[i]);
        }
            for(size_t i = 0 ;i <hitbox2.size() ; i++){
            //att2[i].move((a2right[i])*1000*(*debugTime),0);
            window.draw(hitbox2[i]);
        }
            for(size_t i = 0 ;i <hitbox.size() ; i++){
            //att2[i].move((a2right[i])*1000*(*debugTime),0);
            window.draw(hitbox[i]);
        }

*/
        //window.draw(Rplayer);
        window.draw(Splayer);
        window.draw(Printlevel);
        window.draw(playername);

       if(!immortality){
        window.draw(strokeHp);
        window.draw(Hpbar);
       }

       if(HP > 0){
        playername.setPosition(Rplayer.getPosition().x+wBox1/2,Rplayer.getPosition().y-hBox1/3-50);
        Printlevel.setPosition(Rplayer.getPosition().x+wBox1/2,Rplayer.getPosition().y-hBox1/3-30);

       }


        Listener::setPosition(Rplayer.getPosition().x,0,Rplayer.getPosition().y);
        //Listener::setDirection(1.f, 0.f, 0.f);
        //Listener::setUpVector(1.f, 1.f, 0.f);
        //Listener::setGlobalVolume(1);
        //window.draw(Rplayer);

    }

    /***************************************** collide ******************************************/

    void Playerclass::collide(int chk){

    for(int dy=Rplayer.getPosition().y/72 ; dy < (Rplayer.getPosition().y+Rplayer.getGlobalBounds().height)/72 ;dy++){
    for(int dx=Rplayer.getPosition().x/128 ; dx < (Rplayer.getPosition().x+Rplayer.getGlobalBounds().width)/128 ;dx++){

        if(mapping.bm[dy][dx] == 1 || mapping.bm[dy][dx] == 9 || mapping.bm[dy][dx] == 3
           || mapping.bm[dy][dx] == 6){//[dy][dx]

                    if(!(Rplayer.getPosition().x + (Rplayer.getLocalBounds().width) > dx*72
                    && Rplayer.getPosition().x < dx*72
                    && Rplayer.getPosition().y + (Rplayer.getLocalBounds().height) > dy*128
                    && Rplayer.getPosition().y < dy*128)){

                        if(x > 0 && chk == 0){
                        Rplayer.setPosition(Vector2f(dx*128-Rplayer.getLocalBounds().width,Rplayer.getPosition().y));
                        if(mapping.bm[dy][dx] == 3){iscollide = true;}

                        }
                        if(x < 0 && chk == 0){
                        Rplayer.setPosition(Vector2f(dx*128+128,Rplayer.getPosition().y));
                        if(mapping.bm[dy][dx] == 3){iscollide = true;}

                        }
                        if(y > 0 && chk == 1){
                        Rplayer.setPosition(Vector2f(Rplayer.getPosition().x,dy*72-Rplayer.getLocalBounds().height));
                        isjumping = false;
                        onground = true;
                        topground = false;

                        }

                        if(y < 0 && chk == 1){
                        //y=0;
                        topground = true;
                        Rplayer.setPosition(Vector2f(Rplayer.getPosition().x,dy*72+72));

                        }
                      //  if(y==0 || x!=0){
                           // onground = false;
                       // }

                    }



                }

        if(mapping.bm[dy][dx] == 2){

                    if(!(Rplayer.getPosition().y - (Rplayer.getLocalBounds().height) > (dy*128))){

                if(y > 0 && chk == 1){
                    Rplayer.setPosition(Vector2f(Rplayer.getPosition().x,dy*72-Rplayer.getLocalBounds().height));
                    isjumping = false;
                    onground = true;
                    topground = false;
                }
            }
        }

/******************************************************* slope ******************************/


        if(mapping.bm[dy][dx] == 5){//[dy][dx]

                    if(!(Rplayer.getPosition().y + (Rplayer.getLocalBounds().height) > dy*128
                    && Rplayer.getPosition().y < dy*128)){

                    for(float slope = (Rplayer.getPosition().x+Rplayer.getLocalBounds().width)/128-dx;
                    slope <= (Rplayer.getPosition().x+2*Rplayer.getLocalBounds().width)/128-dx
                    ;slope++){

                   // cout<<slope<<endl;


                        if(y > 0 && chk == 1){
                        Rplayer.setPosition(Vector2f(Rplayer.getPosition().x,
                        ((dy+1)*72-slope*72-Rplayer.getLocalBounds().height)
                        ));
                        isjumping = false;
                        onground = true;
                        topground = false;
                        }

                    }
                }
            }

        if(mapping.bm[dy][dx] == 4){//[dy][dx]
                    if(!(Rplayer.getPosition().y + (Rplayer.getLocalBounds().height) > dy*128
                    && Rplayer.getPosition().y < dy*128)){

                    for(float slope = (Rplayer.getPosition().x)/128-dx;
                    slope <= (Rplayer.getPosition().x+Rplayer.getLocalBounds().width)/128-dx
                    ;slope++){

                   //cout<<slope<<endl;

                        if(y > 0 && chk == 1){
                        Rplayer.setPosition(Vector2f(Rplayer.getPosition().x,
                        ((slope<0? dy*72:dy*72+slope*72)-Rplayer.getLocalBounds().height)

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

/*********************************************** view point *********************************/

void Playerclass::camera(RenderWindow &window)
{

    Pcamera.setCenter(camX(Rplayer.getPosition().x+(Rplayer.getLocalBounds().width/2))
                      ,camY(Rplayer.getPosition().y+(Rplayer.getLocalBounds().height/2)));

    window.setView(Pcamera);


}

void Playerclass::Endcamera(RenderWindow& window, int Endgame) {
	if (Endgame == 2) {
		Pcamera.setCenter(640,720);
	}
	else if (Endgame == 1) {
		Pcamera.setCenter(3200,720);
	}
	

	window.setView(Pcamera);
}


    float Playerclass::camX(float cx){

        if(cx < 640){
            return 640;
        }else if (cx > 3200){
            return 3200;
        }else{
            return cx;
        }
    }

    float Playerclass::camY(float cy){

        if(cy > 720){
            return 720;
        }else{
            return cy;
        }

    }

    /****************************************************** animate *****************************************/

    void Playerclass::animate(Sprite *SprP,double *debugTime){

    /*************** ide ***/

    if(x == 0 && onground){

        frame = (frame+2*(*debugTime)) ;
/*
        if(h == 1){

        }else{
        frame = 0;
        h= rand()%20;
        }
        */
        if(frame >= (Char==1? 5:Char==2? 4:7))
        {
            frame = 0;
            h= rand()%1500;
        }

        if(isRight)(*SprP).setTextureRect(IntRect(spriteRect.left*(int)frame,spriteRect.top*0,spriteRect.width,spriteRect.height));
        if(!isRight)(*SprP).setTextureRect(IntRect(spriteRect.left*(int)frame+spriteRect.width,spriteRect.top*0,-spriteRect.width,spriteRect.height));

    }

    /************ jumpdown ***********/

    if(y > 0 && !onground){
        frame = (frame + 2*(*debugTime)) ;
        if(frame >= (Char==1? 3:2)){
            frame = 0;
            h=1;
        }

        if(isRight){(*SprP).setTextureRect(IntRect(spriteRect.left*(int)frame,spriteRect.top*3,spriteRect.width,spriteRect.height));}
        if(!isRight){(*SprP).setTextureRect(IntRect(spriteRect.left*(int)frame+spriteRect.width,spriteRect.top*3,-spriteRect.width,spriteRect.height));}

    }

    /************** right ************/

    if (x > 0 && onground){
        isRight = true;

        frame = (frame + 15*(*debugTime)) ;

        if(frame >= (Char==1? 5:7)){
            frame = 0;
        }
        (*SprP).setTextureRect(IntRect(spriteRect.left*(int)frame,spriteRect.top,spriteRect.width,spriteRect.height));
    }

    /***************** left **************/

    if(x < 0 && onground){
        isRight = false;
        frame = (frame + 15*(*debugTime)) ;
        if(frame >= (Char==1? 5:7)){
            frame = 0;
        }
        (*SprP).setTextureRect(IntRect(spriteRect.left*(int)frame+spriteRect.width,spriteRect.top,-spriteRect.width,spriteRect.height));
    }

    /******************* jump up ***********/

    if(y < 0 && !onground && isjumping){

        frame = (frame+5*(*debugTime));
        if(frame >= (Char==1? 3:2)){
            frame = 0;
        }

        if(isRight){(*SprP).setTextureRect(IntRect(spriteRect.left*(int)frame,spriteRect.top*2,spriteRect.width,spriteRect.height));}
        if(!isRight){(*SprP).setTextureRect(IntRect(spriteRect.left*(int)frame+spriteRect.width,spriteRect.top*2,-spriteRect.width,spriteRect.height));}
    }



}

/********************************************************* skill P 1 ****************************************/

void Playerclass::skillanimationP11(double &debugTime){


        if(attframe >= 9.9){
            normalattack = false;
            attframe = 0;
            frame = 0;
            attack = false;

        }

            //attframe = (attframe + 25*(debugTime)) ;
        if(attframe >= 0 && attframe < 2){
            attframe = (attframe + 15*(debugTime)) ;
            //x = isRight? 200:-200;
			
        }else if(attframe >= 2 && attframe < 5){

            if(hitbox.empty() && !attack){
                hitbox.push_back(hit);
                hitbox.back().setScale(1*(isRight)-1*(!isRight),1);
                hitbox.back().setPosition(Rplayer.getPosition().x+Rplayer.getGlobalBounds().width*(!isRight)//-hit.getGlobalBounds().width*(!isRight)
                                          ,Rplayer.getPosition().y-30);
                attack = true;

            }
        attframe = (attframe + 15*(debugTime)) ;
            x = 0;

        }else if(attframe >= 5 && attframe < 7){
            hitbox.clear();
            attframe = (attframe + 15*(debugTime));
            attack = false;
            x = 0;

        }else if(attframe >= 7 && attframe < 8){

            if(hitbox.empty() && !attack){
                hitbox.push_back(hit);
                hitbox.back().setScale(1*(isRight)-1*(!isRight),1);
                hitbox.back().setPosition(Rplayer.getPosition().x+Rplayer.getGlobalBounds().width*(!isRight)//-hit.getGlobalBounds().width*(!isRight)
                                          ,Rplayer.getPosition().y-30);
                attack = true;
            }

        attframe = (attframe + 5*(debugTime)) ;
            x = 0;

        }else if(attframe >= 8){
            hitbox.clear();
            attframe = (attframe + 15*(debugTime)) ;
            x = 0;
        }


        if(isRight)Splayer.setTextureRect(IntRect(spriteRect.left*(int)attframe,spriteRect.top*4,spriteRect.width,spriteRect.height));
        if(!isRight)Splayer.setTextureRect(IntRect(spriteRect.left*(int)attframe+spriteRect.width,spriteRect.top*4,-spriteRect.width,spriteRect.height));
}



void Playerclass::skillanimationP21(double &debugTime){
        x = 0;
        attframe = (attframe + 20*(debugTime)) ;
        if(attframe >= 10){
            attackT1 = false;
            attframe = 0;

            //cd = isOn
        }

        if(attframe >= 3 && attframe < 5){

            if(hitbox2.empty()){
                hitbox2.push_back(hit2);
                hitbox2.back().setScale(1*(isRight)-1*(!isRight),1);
                hitbox2.back().setPosition(Rplayer.getPosition().x+Rplayer.getGlobalBounds().width*(!isRight)//-hit.getGlobalBounds().width*(!isRight)
                                          ,Rplayer.getPosition().y+25);
            }

        }else if(attframe >= 5){
            hitbox2.clear();
        }

        if(isRight)Splayer.setTextureRect(IntRect(spriteRect.left*(int)attframe,spriteRect.top*5,spriteRect.width,spriteRect.height));
        if(!isRight)Splayer.setTextureRect(IntRect(spriteRect.left*(int)attframe+spriteRect.width,spriteRect.top*5,-spriteRect.width,spriteRect.height));

}

void Playerclass::skillanimationP31(double &debugTime){


	if (!soundAtt3.getStatus()) {
		soundAtt3.play();
	}

        x = isRight? 500:-500;
        attframe = (attframe + 20*(debugTime));
        if(attframe >= 8){
            attframe = 3;

            //cd = isOn
        }

		if (attframe >= 0 && attframe < 0.3) {
			
		}

        if(attframe >=3){

            if(hitbox3.empty()){
                hitbox3.push_back(hit3);
            }

            hitbox3.back().setPosition(Rplayer.getPosition().x-(hit3.getGlobalBounds().width-Rplayer.getGlobalBounds().width)*(!isRight)
                                        ,Rplayer.getPosition().y-hit3.getGlobalBounds().height/3);
        }

        if(onground){
            attackT2 = false;
            immortality = false;
            hitbox3.clear();
			soundAtt3.stop();
        }

            if(isRight)Splayer.setTextureRect(IntRect(spriteRect.left*(int)attframe,spriteRect.top*6,spriteRect.width,spriteRect.height));
            if(!isRight)Splayer.setTextureRect(IntRect(spriteRect.left*(int)attframe+spriteRect.width,spriteRect.top*6,-spriteRect.width,spriteRect.height));

}

/****************************************************** skill P2 *********************************/

void Playerclass::skillanimationP12(double &debugTime){

        if(attframe > 12){
            attframe = 0;
             normalattack = false;
             attack = false;
        }

        if(attframe >= 0 && attframe < 3){
            attframe = (attframe + 25*(debugTime)) ;
            //x = isRight? 200:-200;
        }else if(attframe >= 3 && attframe < 8){
            attframe = (attframe + 30*(debugTime)) ;
            x = 0;

            if(hitbox.empty() && !attack){

                hitbox.push_back(hit);
                hitbox.back().setScale(1*(isRight)-1*(!isRight),1);
                hitbox.back().setPosition(Rplayer.getPosition().x+Rplayer.getGlobalBounds().width*(!isRight)//-hit.getGlobalBounds().width*(!isRight)
                                          ,Rplayer.getPosition().y+10);
            attack = true;
            }

        }else if(attframe >= 8){
            attframe = (attframe + 15*(debugTime)) ;
            hitbox.clear();
            x = 0;
        }
            if(isRight)Splayer.setTextureRect(IntRect(spriteRect.left*(int)attframe,spriteRect.top*4,spriteRect.width,spriteRect.height));
            if(!isRight)Splayer.setTextureRect(IntRect(spriteRect.left*(int)attframe+spriteRect.width,spriteRect.top*4,-spriteRect.width,spriteRect.height));
}

void Playerclass::skillanimationP22(double &debugTime){
        x = isRight? 450:-450;
        attframe = (attframe + 5*(debugTime)) ;

        if(hitbox2.empty()){
            hitbox2.push_back(hit2);
        }

        if(attframe >= 2){
            attackT1 = false;
            immortality = false;
            hitbox2.clear();
        }

        if(!hitbox2.empty()){hitbox2.back().setPosition(Rplayer.getPosition().x+(10-Rplayer.getGlobalBounds().width)*(isRight)-11*(!isRight),Rplayer.getPosition().y);}
        if(isRight)Splayer.setTextureRect(IntRect(spriteRect.left*(int)attframe,spriteRect.top*5,spriteRect.width,spriteRect.height));
        if(!isRight)Splayer.setTextureRect(IntRect(spriteRect.left*(int)attframe+spriteRect.width,spriteRect.top*5,-spriteRect.width,spriteRect.height));
}

void Playerclass::skillanimationP32(double &debugTime,RenderWindow &window){
        //cout<<c2att3.size()<<endl;
        x = 0;
        y = 0;
        if(hitbox3.empty() && c2att3.empty()){
        frame = 0;
        hitbox3.push_back(hit3);

        c2att3.push_back(Sc2at3);
		if (!soundAtt3.getStatus()) {
			soundAtt3.play();
		}


       // c2att3.back().setPosition(Rplayer.getPosition().x,Rplayer.getPosition().y);
        hitbox3.back().setPosition(Rplayer.getPosition().x+Rplayer.getGlobalBounds().width/2-hit3.getGlobalBounds().width/2
                                   ,Rplayer.getPosition().y+Rplayer.getGlobalBounds().height-hit3.getGlobalBounds().height);
        c2att3.back().setScale(5.5,5.5);
        c2att3.back().setPosition(hitbox3.back().getPosition().x-(c2att3.back().getGlobalBounds().width/2-hit3.getGlobalBounds().width/2)
                                   ,hitbox3.back().getPosition().y-(c2att3.back().getGlobalBounds().height/2-hit3.getGlobalBounds().height/2)+hitbox3.back().getGlobalBounds().height/2);

        }

        frame = (frame + (frame<5? 25:30)*(debugTime));
        if(frame > 15){
            frame = 5;
        }

        attframe = (attframe + 5*(debugTime));

        if(attframe > 10){
            attframe = 0;
            c2att3.clear();
            hitbox3.clear();
            immortality = false;
            attackT2 = false;

        }

        if(!c2att3.empty()){
            c2att3.back().setColor(Color(255,255,255,attframe>9? (attframe>9.9? 0:((9.9-attframe))*235):235));
            c2att3.back().setTextureRect(IntRect((Sc2at3.getGlobalBounds().width)*(int)frame,0,Sc2at3.getGlobalBounds().width
                                                 ,Sc2at3.getGlobalBounds().height));

            window.draw(c2att3.back());
        }

        if(attframe < 8){
         Splayer.setTextureRect(IntRect(spriteRect.left*99,0,spriteRect.width,spriteRect.height));
        }

}


/****************************************************** skill P3 *********************************/


void Playerclass::skillanimationP13(double &debugTime,RenderWindow &window){
        x = 0;

		if (!soundAtt1.getStatus()) {
			soundAtt1.play();
		}

        if(attframe >= 9.9){
           attframe = 0;
           normalattack = false;
           balls.clear();
           hitbox.clear();
           attack = false;
		  
        }

		if (attframe >= 0 && attframe < 0.2) {
			soundAtt1.play();
		}

        if(attframe >= 0 && attframe < 5){

            attframe = (attframe + 25*(debugTime)) ;

        }else if(attframe >= 5 && attframe < 6){
            attframe = (attframe + 5*(debugTime)) ;

            //some bullet vector
            //if(attframe > 5.1 && attframe < 5.3){
            if(hitbox.empty() && balls.empty() && !attack){

            balls.push_back(ball);
            hitbox.push_back(hit);
            //if(isRight){
            balls.back().setPosition(Rplayer.getPosition().x+(Rplayer.getGlobalBounds().width+25)*(isRight)-25*(!isRight),Rplayer.getPosition().y+Rplayer.getGlobalBounds().height/2-10);
            hitbox.back().setPosition(Rplayer.getPosition().x+(Rplayer.getGlobalBounds().width+25)*(isRight)-25*(!isRight),Rplayer.getPosition().y+Rplayer.getGlobalBounds().height/2-10);
                   // ballsright.push_back(1);}
            //if(!isRight){
                   // balls.back().setPosition(Rplayer.getPosition().x-ball.getGlobalBounds().width-25,Rplayer.getPosition().y+Rplayer.getGlobalBounds().height/2-10);
            balls.back().setScale(1-2*(!isRight),1);
            hitbox.back().setScale(1-2*(!isRight),1);
            //ballsright.push_back(-1);//}

            //attframe = 5.4;
            attack = true;
            }


        }else if(attframe >= 6){

            attframe = (attframe + 10*(debugTime)) ;

        }

        if(!hitbox.empty() && !balls.empty()){
            balls.back().move((1+(!isRight*(-2)))*800*(debugTime),0);
            hitbox.back().move((1+(!isRight*(-2)))*800*(debugTime),0);
            balls.back().setColor(Color(255,255,255,attframe>8.8? (attframe>9.85? 0:((10-attframe)/1.2)*255):255));

            window.draw(balls.back());

            if(abs(hitbox.back().getPosition().x-Rplayer.getPosition().x) > 1200){
                balls.clear();
                hitbox.clear();
				soundAtt1.stop();
            }

        }
           // if(abs(balls.back().getPosition().x-Rplayer.getPosition().x) > 1200){
           //     balls.clear();
           //     ballsright.clear();
           // }

            if(isRight)Splayer.setTextureRect(IntRect(spriteRect.left*(int)attframe,spriteRect.top*4,spriteRect.width,spriteRect.height));
            if(!isRight)Splayer.setTextureRect(IntRect(spriteRect.left*(int)attframe+spriteRect.width,spriteRect.top*4,-spriteRect.width,spriteRect.height));
}

void Playerclass::skillanimationP23(double &debugTime,RenderWindow &window){

	if (!soundAtt2.getStatus()) {
		soundAtt2.play();
	}
        x = 0;
        if(attframe >= 4){
           // attframe = 3;
            attackT1 = false;
        }

        if(attframe < 2){
          attframe = (attframe + 20*(debugTime)) ;
        }
        else if(attframe >= 2 && attframe < 3){
        attframe = (attframe + 2*(debugTime));


        if(c3att2.empty() && hitbox2.empty()){

            c3att2.push_back(c3at2);
            hitbox2.push_back(hit2);
            c3att2.back().setPosition(Rplayer.getPosition().x+Rplayer.getGlobalBounds().width*(!isRight)-10+20*(!isRight),Rplayer.getPosition().y-2*Rplayer.getGlobalBounds().height/4+5);
            hitbox2.back().setPosition(Rplayer.getPosition().x+Rplayer.getGlobalBounds().width*(!isRight)-10+20*(!isRight),Rplayer.getPosition().y-2*Rplayer.getGlobalBounds().height/4+5);;
            c3att2.back().setScale(-2+4*(isRight),6);
            hitbox2.back().setScale(-2+4*(isRight),6);
                   // c3att2.back().setPosition(Rplayer.getPosition().x+10,Rplayer.getPosition().y-2*Rplayer.getGlobalBounds().height/4+5);
                    //att2.back().setTextureRect(IntRect(ball.getGlobalBounds().width,0,-ball.getGlobalBounds().width,ball.getGlobalBounds().height));
        }else{

            c3att2.back().setColor(Color(255,255,255,attframe>2.65? (attframe>2.9? 0:(3-attframe)*255):255));
        }
        window.draw(c3att2.back());

        }else if(attframe >= 3){
            c3att2.clear();
            hitbox2.clear();
        attframe = (attframe + 50*(debugTime)) ;
        }



            if(isRight)Splayer.setTextureRect(IntRect(spriteRect.left*(int)attframe,spriteRect.top*5,spriteRect.width,spriteRect.height));
            if(!isRight)Splayer.setTextureRect(IntRect(spriteRect.left*(int)attframe+spriteRect.width,spriteRect.top*5,-spriteRect.width,spriteRect.height));




}

void Playerclass::skillanimationP33(double &debugTime,RenderWindow &window){

        x = 0;
		if (!soundAtt3.getStatus()) {
			soundAtt3.play();
		}

        if(attframe >= 4){
            //attframe = 3;
            //cd = isOn
            attackT2 = false;
            h = 0;
        }

        if(attframe < 2){
            frame = 0;
            attframe = (attframe + 20*(debugTime));

        if(attframe > 1.8 && attframe < 2){
            attframe = 2.0;
        }
        }else if(attframe >= 2 && attframe < 3){
            attframe = (attframe + 0.25*(debugTime));
            if(c3att3.empty() && hitbox3.empty()){

                    //some vector
                c3att3.push_back(c3at3);
                hitbox3.push_back(hit3);
                c3att3.back().setPosition(Rplayer.getPosition().x+Rplayer.getGlobalBounds().width-c3at3.getGlobalBounds().width/2,Rplayer.getPosition().y-c3at3.getGlobalBounds().height+Rplayer.getGlobalBounds().height+80);
                c3att3.back().setColor(Color(255,255,255,0));
            }

            frame = (frame + 100*(debugTime));
            h = (h + 60*(debugTime));
            if(frame > 19){
                frame = 0;
            }
            if(h > 4){
                h=0;
            }
            c3att3.back().move((isRight)*150*debugTime-(!isRight)*150*debugTime,0);
            c3att3.back().setTextureRect(IntRect(c3at3.getGlobalBounds().width*(int)h,(int)frame<4? c3at3.getGlobalBounds().height*0:(int)frame<9? c3at3.getGlobalBounds().height*1:(int)frame<14? c3at3.getGlobalBounds().height*2:frame<19? c3at3.getGlobalBounds().height*3:0
                                           ,c3at3.getGlobalBounds().width,c3at3.getGlobalBounds().height));
            hitbox3.back().setPosition(c3att3.back().getPosition().x+275,c3att3.back().getPosition().y+10);
            window.draw(c3att3.back());
            //c3att3.back().setColor(Color(255,255,255,attframe>2.89? (attframe>2.99? 0:((2.99-attframe)/0.1)*255):255));
            c3att3.back().setColor(Color(255,255,255,attframe>2.0? (attframe>2.15? (attframe>2.94? (attframe>2.99? 0:((2.99-attframe)/0.05)*255):255):255-(((2.15-attframe)/0.15)*255)):0));
        }else if(attframe >= 3){
            c3att3.clear();
            hitbox3.clear();
            attframe = (attframe + 25*(debugTime));
			soundAtt3.stop();
        }

        /****draw**/
 //       for(int i = 0 ; i<c3att3.size() ;i++){
//
  //          window.draw(c3att3[i]);
  //      }


            if(isRight)Splayer.setTextureRect(IntRect(spriteRect.left*(int)attframe,spriteRect.top*6,spriteRect.width,spriteRect.height));
            if(!isRight)Splayer.setTextureRect(IntRect(spriteRect.left*(int)attframe+spriteRect.width,spriteRect.top*6,-spriteRect.width,spriteRect.height));


}


/************************************************************** DEAD & stun **************************************/

void Playerclass::Deadanimation(double &debugTime,float ypos){

if(!chk){
    yxx = Rplayer.getPosition().y;
}

if(onground && !chk){
    Deathcount++;
    yxx = ypos;
    chk = true;
}

        if(isRight){Splayer.setPosition(xposdead-dwBox1,yxx-dhBox1+10);}//Splayer.setTextureRect(IntRect(0,0,1280,1107)); }//Splayer.setScale(1.f,1.f);
        if(!isRight){Splayer.setPosition(xposdead-(Splayer.getGlobalBounds().width-(dwBox1+wBox1)),yxx-dhBox1+10);}//Splayer.setTextureRect(IntRect(128*1+128,0,-128,1107)); }  //Splayer.setScale(-1.f,1.f);      //Splayer.setTexture(Tchar1,true);

        framed = (framed+(Char==1? 10:15)*(debugTime) );
        if(framed >= (Char==1? 6:4)){
            framed = Char==1? 5:3;
        }

        if(isRight){Splayer.setTextureRect(IntRect(spriteRect.left*(int)framed,spriteRect.top*8,spriteRect.width,spriteRect.height));}
        if(!isRight){Splayer.setTextureRect(IntRect(spriteRect.left*(int)framed+spriteRect.width,spriteRect.top*8,-spriteRect.width,spriteRect.height));}

}



void Playerclass::Stunnedanimation(double &debugTime){



    if(isRight){Splayer.setTextureRect(IntRect(0,spriteRect.top*7,spriteRect.width,spriteRect.height));}
    if(!isRight){Splayer.setTextureRect(IntRect(spriteRect.width,spriteRect.top*7,-spriteRect.width,spriteRect.height));}


}
