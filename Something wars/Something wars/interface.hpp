#ifndef INTERFACE_H
#define INTERFACE_H
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

using namespace sf;

class interface
{
    public:
        interface(int wChar);
        virtual ~interface();

        void drawinterface(RenderWindow &window,float xpos,float ypos,int damage1,int damage2,int damage3,bool normalatt,float cd1,float cd2,float HP,float maxhp,float TimeDead
                           ,float Damagenor,float Damages1,float Damages2,int Level,int kill,int death,double &gametime);
        void setting(float xmove,float ymove);

        void oneValue(int CharFbot1,int CharFbot2,int CharEbot1,int CharEbot2,int CharEbot3);
        Texture Tinterface;
        Sprite Sinterface;
        Texture J,K,L,P,facep,detailN,detail2,detail3,detailP;
        Sprite SJ,SK,SL,SP,Face, SdetailN, Sdetail2, Sdetail3, SdetailP;
        void elsedatafloat(RenderWindow &window,float TimedeadFbot1,float TimedeadFbot2,float TimedeadEbot1
                           ,float TimedeadEbot2,float TimedeadEbot3
                           ,float HPFbot1,float maxHPFbot1,float HPFbot2,float maxHPFbot2,float xpos,float ypos);
        void Qpanel(int killcountFB1,int deadcountFB1,int killcountFB2,int deadcountFB2,
                    int killcountEB1,int deadcountEB1,int killcountEB2,int deadcountEB2,
                    int killcountEB3,int deadcountEB3, int playerkillcount, int playerdeadcount,bool Q, RenderWindow& window);

		void result(RenderWindow& window);
		String WriteKillDead();
		String WriteScore();

		Text TeamScore;

		int Endgame=0;
		Sprite Sprwin, Sprlose;

		void EscTomenu(RenderWindow& window,float xpos,float ypos);
		bool ESC=false;
		bool clickmouse=false;
		bool surrender=false;

    protected:

    private:
        Font ff;
        Text Scd1,Scd2,Hitpoint,Timedead,TextKill,TextDead,TDFB1,TDFB2,TDEB1,TDEB2,TDEB3,TextGametime;
        Text QP,QFB1,QFB2,QEB1,QEB2,QEB3;
        int Char,CharFB1,CharFB2,CharEB1,CharEB2,CharEB3;
        RectangleShape HPbar,HPbarFB1,HPbarFB2;

		int ClassLevel;

        Texture TexCharFB1,TexCharFB2,TexCharEB1,TexCharEB2,TexCharEB3;
        Sprite SprCharFB1,SprCharFB2,SprCharEB1,SprCharEB2,SprCharEB3;

        void loadFileTexAndSetSpr(int &VChar,Sprite &spr,Texture &tex);
        void setText(Text &tt,int ssize);

		Texture TexQpanel;
		Sprite SprQpanel;
		Text score;

		Text TextDamage1, TextDamage2, TextDamage3;

		Texture TexObjective;
		Sprite SprObjctive;

		Texture Twin, Tlose;

		Text backYes,backNo,backText;
		RectangleShape backBox;
		Vector2i mouse;

		SoundBuffer BuffDeath, BuffRespawn;
		Sound soundDeath, soundRespawn;
};

#endif // INTERFACE_H
