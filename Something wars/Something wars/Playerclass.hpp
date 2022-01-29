#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <deque>
#include <sstream>

using namespace std;
using namespace sf;

class Playerclass
{
    public:
        Playerclass(int selectchar);
        virtual ~Playerclass();
        float x;
        float y;
        bool onground = false;
        bool topground = false;
        bool isjumping = true;
        bool attack = false;
        bool isRight;
        Sprite Splayer;
        RectangleShape Rplayer;
        float frame;
        int Char;
        const float Gravity = 980; /***** debug vector**/
        void Select(float xpos,float ypos,int *nummap,int side,String nameofplayer);
        void update(double *debugTime,RenderWindow &window
                    ,bool A,bool D,bool W,bool J,bool K,bool L);

        Font ff2;
        Text playername;

        /***************** camera ****************/

        void camera(RenderWindow &window);
		void Endcamera(RenderWindow& window,int Endgame);
        float camX(float cx);
        float camY(float cy);

        /******************** attack ***********/

        float HP;
        float maxHP;

        double cd1 = 0;
        double cd2 = 0;
        vector<Sprite> balls;
        vector<Sprite> c3att2;
        vector<Sprite> c3att3;
        vector<Sprite> c2att3;
        vector<RectangleShape> hitbox,hitbox2,hitbox3;

        float Damagenormalatt,DamageS1,DamageS2;/***********************/

        int Killcount,Deathcount;

        Sprite c3at2;
        Sprite c3at3;

        bool normalattack = false;
        float attframe=0;
        bool immortality;
        bool stunned;
        double stuntime;
        float TimeDead;
        int sideL;

        /*** exp **/

        Text Printlevel;
        int Level=0;
        float Exp=0;

        /*** bot **/

        bool iscollide = false;

        /******* camera ******/

        View Pcamera;

        /********** Lisener *******/

		Sound soundAtt1, soundAtt2, soundAtt3;

    protected:

    private:


    void callOBJ();
    int h=0;
    Texture Tchar1;
    Texture Tchar2;
    Texture Tchar3;
    IntRect spriteRect;

    int wBox1,hBox1,dwBox1,dhBox1;

    // void skillanimationP _whatskill _whatplayer(double &debugTime);
    void skillanimationP11(double &debugTime);
    void skillanimationP21(double &debugTime);
    void skillanimationP31(double &debugTime);
    void skillanimationP12(double &debugTime);
    void skillanimationP22(double &debugTime);
    void skillanimationP32(double &debugTime,RenderWindow &window);
    void skillanimationP13(double &debugTime,RenderWindow &window);
    void skillanimationP23(double &debugTime,RenderWindow &window);
    void skillanimationP33(double &debugTime,RenderWindow &window);
    void Deadanimation(double &debugTime,float ypos);
    void Stunnedanimation(double &debugTime);

    bool attackT1 = false;
    bool attackT2 = false;

    Texture Tball;
    Texture Tc3at2;
    Texture Tc3at3;
    Texture Tc2at3;
    Sprite Sc2at3;

    RectangleShape hit,hit2,hit3;

    Sprite ball;
    RectangleShape Hpbar,strokeHp;

    void animate(Sprite *SprP,double *debugTime);
    void collide(int chk);

    float xposdead,yposdead,framed,spawnpointX,spawnpointY;
    float yxx = 0;
    bool chk=false;



    /**************/
    SoundBuffer soundBAtt1,soundBAtt2,soundBAtt3;





};

#endif // PLAYERCLASS_H
