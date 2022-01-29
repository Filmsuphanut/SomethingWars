#ifndef MAINBUTTON_H
#define MAINBUTTON_H
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<string>


using namespace sf;
using namespace std;

class mainbutton
{
    public:
        mainbutton(Font &ff);
        ~mainbutton();
        void drawplay(RenderWindow &window);
        void play();
        void playP();
        int playR(Sound& soundButton);

        void drawselect(RenderWindow &window);
        void playselect();
        int playselectmap(Sound& soundButton);

		void drawselectChar(RenderWindow& window, int& nummap, Sound& soundButton);
		bool clickmouse;
		int numchar[6];

		bool selectgamestart = false;
		bool startgame = false;
		bool go = false;
		
		void clearvalue();

		bool Editname=false;

		Text nameC[6];
		Text nameP[6];

		Clock ClockTime;
		float Time = 0;

		void drawresult(RenderWindow& window,bool &chk);
		void drawQ(RenderWindow& window, bool Q, float xmove, float ymove);
		String savename();
		Text Textleader;
		void Leaderborad(RenderWindow& window);
		void howtoplay(RenderWindow& window);

    protected:

    private:

	Vector2i moupos;
  
    Texture Tplay;
    Texture Thow;
    Texture Tlead;
    Texture Tstory;
    Texture Tex;
    Texture Tplay2;
    Texture Thow2;
    Texture Tlead2;
    Texture Tstory2;
    Texture Tex2;

    Sprite Splay;
    Sprite Show;
    Sprite Slead;
    Sprite Sstory;
    Sprite Sexit;


    Texture map1;
    Texture map2;
    Texture map3;
    Texture map4;
    Texture map5;
    Texture map12;
    Texture map22;
    Texture map32;
    Texture map42;
    Texture map52;

    Sprite Smap1;
    Sprite Smap2;
    Sprite Smap3;
    Sprite Smap4;
    Sprite Smap5;

	/*******************************************select char ******************/

	Texture TexbgselectChar;
	Sprite SprbgselectChar;

	Texture TSelectC1;
	Texture TSelectC2;
	Texture TSelectC3;
	Texture TSelectC1outline;
	Texture TSelectC2outline;
	Texture TSelectC3outline;
	Sprite SelectC1;
	Sprite SelectC2;
	Sprite SelectC3;

	vector<Sprite> SelectChar;
	vector<Sprite> ShowSelectChar;
	vector<Sprite> startgamemap;

	Text tttt;

	RectangleShape Curser;

	/**************************************Result*********************************/

	Texture ResutlBG;
	Texture Texwin, Texlose;
	Sprite Sprwin, Sprlose;
	Sprite SprResult;
	RectangleShape RecText;

	/***********************************Leaderborad****/
	Texture Texlead, Texlead2;
	Sprite Sprlead,Sprlead2;

	/**********************************howto*****/

	Texture Texhow;
	Sprite Sprhow;
};

#endif // MAINBUTTON_H
