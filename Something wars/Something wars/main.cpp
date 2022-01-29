#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "mainbutton.hpp"
#include "Playerclass.hpp"
#include "gamemap.hpp"
#include "creep.hpp"
#include "base.hpp"
#include "algorithmbot.hpp"
#include "interface.hpp"
#include "bgmusic.hpp"
#include "ShowDamageClass.hpp"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
using namespace sf;


int windowWidth = 1280;
int windowHeight = 720;



int main()
{

    //RenderWindow window(VideoMode(windowWidth, windowHeight), "Something wars",Style::Fullscreen);
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Something wars",Style::Close);
	window.setVerticalSyncEnabled(true);
	

	Image icon;
	icon.loadFromFile("data/images/mainmenu/Char1.png");

	window.setIcon(112, 112, icon.getPixelsPtr());
	//window.setSize(Vector2u(1360, 768));
    /****************************************** variable *********************************************/

    /***menu**/
    int stage;
    stage = 0; //1 =map , 2 =char, 3=play
    Texture Tmenu;
    Tmenu.loadFromFile("data/images/mainmenu/mainmenu.png");
    Sprite Smenu;
    Smenu.setTexture(Tmenu);
    Smenu.setPosition(0,0);
	Font ff;
	ff.loadFromFile("data/font/segoeprb.ttf");

    mainbutton mainmenu(ff); //class main menu


	/********************************BG********************/
    Texture bg1,bg2,bg3,bg4,bg5;
    bg1.loadFromFile("data/images/map/bg1.png");
	bg2.loadFromFile("data/images/map/bg2.png");
	bg3.loadFromFile("data/images/map/bg3.png");
	bg4.loadFromFile("data/images/map/bg4.png");
	bg5.loadFromFile("data/images/map/bg5.png");
    Sprite bgs1,bgs2,bgs3;
    bgs1.setTexture(bg1);
    bgs1.setPosition(0,0);
	bgs2.setTexture(bg2);
	bgs2.setPosition(0, 0);
	bgs3.setTexture(bg4);
	Clock BGclock;
	float TimeBG = 0;
	int screen = 1;
	/*****************************************************/

    Texture TselectC;
    TselectC.loadFromFile("data/images/mainmenu/loading.png");
    Sprite SselectC;
    SselectC.setTexture(TselectC);
    SselectC.setPosition(0,0);

    /***select map**/
    Texture selectmap;
    selectmap.loadFromFile("data/images/mainmenu/selectmap.png");
    Sprite SselectM;
    SselectM.setTexture(selectmap);
    SselectM.setPosition(0,0);

    interface gameinterface1(1);
    interface gameinterface2(2);
    interface gameinterface3(3);
    vector<interface> interfaceingame;

    Texture Tsdark;
    Tsdark.loadFromFile("data/images/char/dark.png");
    Sprite Sdark;
    Sdark.setTexture(Tsdark);
    Sdark.setColor(Color(255,255,255,180));
    //RectangleShape Sdark;
    //Sdark.setFillColor(Color(0,0,0,200));
    //Sdark.setSize(Vector2f(windowWidth,windowHeight));

    /**view**/

    View menuview;
    menuview.setSize(windowWidth,windowHeight);
    menuview.setCenter(640,360);


    /********************************************* map *************************************************/

    gamemap drawmap;
    int nummap;

    RectangleShape Rmap;
    Rmap.setSize(Vector2f(80,120));

    CircleShape snow;
    snow.setRadius(4);
    snow.setFillColor(Color::White);

	Text CyberSnow;
	CyberSnow.setFont(ff);
	CyberSnow.setFillColor(Color::Green);
	CyberSnow.setCharacterSize(20);
	CyberSnow.setString("1");

	vector<Text> CyberSnows;
    vector<CircleShape> snows;

    /***************************************** player variable ******************************************/
    Playerclass player1(1);
    Playerclass player2(2);
    Playerclass player3(3);

    algorithmbot BotChar1(1);
    algorithmbot BotChar2(2);
    algorithmbot BotChar3(3);

    /************************debug ***************/

    vector<Playerclass> playerIngame;
    vector<algorithmbot> Brainbot;

	/*
    playerIngame.push_back(player1);
    playerIngame.push_back(player2);
    playerIngame.push_back(player3);
	
    for(size_t i = 0 ; i < playerIngame.size() ; i++){
       playerIngame.pop_back();
    }
	*/
     /**************************************/

    int CurrentP;
    int NumbotL,NumbotR;
    //attack atkplayer;

    /***************************************** creep ******************************************/

    creep CreepR(false);
    creep CreepL(true);
    deque<creep> creepIngame;

    double VcreepxposL,VcreepxposR;

    /*********************************** Damage interface ***************************************/

 
    ShowDamageClass ShowHitByEdamage(ff,2);
    ShowDamageClass ShowHitByPdamage(ff,1);
    deque<ShowDamageClass>showDamageIngame;
    float damageDebugP[3]={0,0,0},damageDebugE[3]={0,0,0};
    deque<float> damageCreepDebug;


    /****************************** base **********************/

    base leftbase(0);
    base rightbase(1);

    /**************************** audio **********/

    bgmusic bbbggg;
    int CurrentMusic=0;
    int preCurrentMusic=0;
	
	SoundBuffer ButtonBuff,winBuff,loseBuff;
	Sound soundButton,soundwin,soundlose;
	ButtonBuff.loadFromFile("data/sound/button.wav");
	soundButton.setBuffer(ButtonBuff);


	 
    /******************************** interface ************************/

    Texture Tinterface;
    Tinterface.loadFromFile("data/images/interface.png");
    Sprite Sinterface;
    Sinterface.setTexture(Tinterface);
	String Display = "Edit name Here!!";
	bool winorlose=false;
	float EndgameTime = 0;

	Text SuphanutWandee;
	SuphanutWandee.setFillColor(Color::Yellow);
	SuphanutWandee.setFont(ff);
	SuphanutWandee.setCharacterSize(20);
	SuphanutWandee.setOutlineColor(Color::Blue);
	SuphanutWandee.setOutlineThickness(3);
	SuphanutWandee.setString("Suphanut Wandee 62010893");
	SuphanutWandee.setPosition(920,680);

    /********************************************* Time ***************************************************/

    Clock RealTime;
    Clock clockingame,creepTime;
	double	debugTime = 0 ;
	double	creeptime = 0;
	double	gametime = 0;
    window.setFramerateLimit(128);
    //window.
    //window.setVerticalSyncEnabled(true);

    srand(time(NULL));

    /************************************* start loop *******************************************/

    while (window.isOpen())
    {
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) {
				stage = 99;
			}
		}


		if (bbbggg.checkplaymusic(CurrentMusic) && CurrentMusic != 0) {
			bbbggg.Playmusic(CurrentMusic, false, 100, false);
			CurrentMusic = 0;
			//preCurrentMusic = CurrentMusic;
		}

		//bbbggg.Playmusic(CurrentMusic, true, 100, false);
		if (!bbbggg.checkplaymusic(0)) {		
			bbbggg.Playmusic(0, true, 100, true);
		}

		


    while(stage == 99){
        window.close();
        break;
        break;
    }

    while(stage == 0){
//cout<<" Brainbot = "<<Brainbot.size()<<" PlayerIngame = "<<playerIngame.size()<<endl;
/**************** clear vector ***********/

    if(!snows.empty() || !CyberSnows.empty() || !playerIngame.empty() || !creepIngame.empty() || !Brainbot.empty() || !interfaceingame.empty()
       || !showDamageIngame.empty()){

    snows.clear();
	CyberSnows.clear();
    playerIngame.clear();
    creepIngame.clear();
    Brainbot.clear();
    interfaceingame.clear();
    showDamageIngame.clear();
    damageCreepDebug.clear();
    }

/**************** event ***********/
        Event menu;
        while (window.pollEvent(menu))
        {
			
            if (menu.type == Event::Closed){
                stage = 99;
            }

            if(menu.type == Event::MouseMoved){

                mainmenu.play();
            }

            if(menu.type == Event::MouseButtonPressed){

				 mainmenu.playP();
            }

            if(menu.type == Event::MouseButtonReleased){
                stage = mainmenu.playR(soundButton);
				if (stage != 0) {
					if (!soundButton.getStatus()) {
						soundButton.play();
					}
				}

            }


        }


		TimeBG = BGclock.getElapsedTime().asSeconds();

		if (TimeBG > 0 && TimeBG < 3.5) {
			bgs1.setTexture(bg1);
			bgs2.setTexture(bg2);
		}else if(TimeBG > 3.5 && TimeBG <= 4) {
			bgs1.setColor(Color(255, 255, 255, (4.0 - TimeBG) * 510));
		}else if (TimeBG > 4 && TimeBG < 7.5) {
			bgs1.setColor(Color(255, 255, 255, 0));
			bgs1.setTexture(bg3);
		}else if (TimeBG >7.5 && TimeBG <= 8) {
			bgs1.setColor(Color(255, 255, 255, (TimeBG - 7.5) * 510));
		}else if (TimeBG > 8 && TimeBG < 11.5) {
			bgs1.setColor(Color(255, 255, 255, 255));
			bgs2.setTexture(bg4);
		}else if (TimeBG > 11.5 && TimeBG <= 12) {
			bgs1.setColor(Color(255, 255, 255, (12.0 - TimeBG) * 510));
		}else if (TimeBG > 12 && TimeBG < 15.5) {
			bgs1.setColor(Color(255, 255, 255, 0));
			bgs1.setTexture(bg5);
		}else if (TimeBG > 15.5 && TimeBG <= 16) {
			bgs1.setColor(Color(255, 255, 255, (TimeBG - 15.5) * 510));
		}else if (TimeBG > 16 && TimeBG < 19.5) {
			bgs1.setColor(Color(255, 255, 255, 255));
			bgs2.setTexture(bg1);
		}else if (TimeBG > 19.5 && TimeBG <= 20) {
			bgs1.setColor(Color(255, 255, 255, (20 - TimeBG) * 510));
		}else if (TimeBG > 20) {
			bgs1.setTexture(bg1);
			bgs2.setTexture(bg2);
			bgs2.setColor(Color(255, 255, 255, 255));
			bgs1.setColor(Color(255, 255, 255, 255));
			TimeBG = BGclock.restart().asSeconds();
		}

		window.clear(Color::Green);
        window.setView(menuview);
		window.draw(bgs2);
		window.draw(bgs1);
		mainmenu.drawplay(window);
        window.draw(Smenu);
		window.draw(SuphanutWandee);
		window.display();

    }

    while(stage == 1){

        cout<<Brainbot.size()<<" "<<playerIngame.size()<<endl;


    /********************* event *************/
        Event slm;
        while (window.pollEvent(slm))
        {

            if (slm.type == Event::Closed){

                stage = 99;
            }

            if(slm.type == Event::KeyPressed)
            {
                if(Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    stage = 0;

						if (!soundButton.getStatus()) {
							soundButton.play();
						}
					
                }
            }

            if(slm.type == Event::MouseMoved){
            mainmenu.playselect();

            }

            if(slm.type == Event::MouseButtonPressed){

				if (Mouse::getPosition(window).x > 14 && Mouse::getPosition(window).x < 128 &&
					Mouse::getPosition(window).y > 73 && Mouse::getPosition(window).y < 148) {
					stage = 0;

						if (!soundButton.getStatus()) {
							soundButton.play();
						}
					
				}

            nummap = mainmenu.playselectmap(soundButton);
			bgs3.setTexture(nummap==1? bg1:nummap==2? bg2: nummap==3? bg3:nummap==4? bg4:bg5);
                    if(nummap != 0)
                    {
                        drawmap.mapselect(&nummap);

                        leftbase.setBasePos(128,686);
                        rightbase.setBasePos(3400,686);

						
							if (!soundButton.getStatus()) {
								soundButton.play();
							}
						


                if(nummap == 3){
                    for(int i = 0 ; i < 512 ; i++){
                        snows.push_back(snow);
                        snows.back().setPosition(rand()%4000,rand()%2160-1080);

                    }
                }
				if (nummap == 5) {
					for (int i = 0; i < 200; i++) {
						CyberSnows.push_back(CyberSnow);
						CyberSnows.back().setPosition(rand() % 4000, rand() % 2160 - 1080);

					}
				}

                        stage = 112; mainmenu.clickmouse = false;
                    }
            }
        }


		TimeBG = BGclock.getElapsedTime().asSeconds();

		if (TimeBG > 0 && TimeBG < 3.5) {
			bgs1.setTexture(bg1);
			bgs2.setTexture(bg2);
		}
		else if (TimeBG > 3.5 && TimeBG <= 4) {
			bgs1.setColor(Color(255, 255, 255, (4.0 - TimeBG) * 510));
		}
		else if (TimeBG > 4 && TimeBG < 7.5) {
			bgs1.setColor(Color(255, 255, 255, 0));
			bgs1.setTexture(bg3);
		}
		else if (TimeBG > 7.5 && TimeBG <= 8) {
			bgs1.setColor(Color(255, 255, 255, (TimeBG - 7.5) * 510));
		}
		else if (TimeBG > 8 && TimeBG < 11.5) {
			bgs1.setColor(Color(255, 255, 255, 255));
			bgs2.setTexture(bg4);
		}
		else if (TimeBG > 11.5 && TimeBG <= 12) {
			bgs1.setColor(Color(255, 255, 255, (12.0 - TimeBG) * 510));
		}
		else if (TimeBG > 12 && TimeBG < 15.5) {
			bgs1.setColor(Color(255, 255, 255, 0));
			bgs1.setTexture(bg5);
		}
		else if (TimeBG > 15.5 && TimeBG <= 16) {
			bgs1.setColor(Color(255, 255, 255, (TimeBG - 15.5) * 510));
		}
		else if (TimeBG > 16 && TimeBG < 19.5) {
			bgs1.setColor(Color(255, 255, 255, 255));
			bgs2.setTexture(bg1);
		}
		else if (TimeBG > 19.5 && TimeBG <= 20) {
			bgs1.setColor(Color(255, 255, 255, (20 - TimeBG) * 510));
		}
		else if (TimeBG > 20) {
			bgs1.setTexture(bg1);
			bgs2.setTexture(bg2);
			bgs2.setColor(Color(255, 255, 255, 255));
			bgs1.setColor(Color(255, 255, 255, 255));
			TimeBG = BGclock.restart().asSeconds();
		}

        window.clear(Color::Cyan);
        window.draw(bgs2);
		window.draw(bgs1);
        mainmenu.drawselect(window);
        window.draw(SselectM);
        window.display();
		

    }


/******************************* select char **********************/

    while(stage == 112){

    //    cout<<Brainbot.size()<<" "<<playerIngame.size()<<endl;


    /********************* event *************/
        Event selectCharEvent;
        while (window.pollEvent(selectCharEvent))
        {
            if (selectCharEvent.type == Event::Closed){

                stage = 99;
            }

            if(selectCharEvent.type == Event::KeyPressed)
            {
                if( ((Keyboard::isKeyPressed(Keyboard::Escape)) && !mainmenu.startgame && !mainmenu.Editname )
					|| (selectCharEvent.type == Event::MouseButtonPressed &&
						Mouse::getPosition(window).x > 14 && Mouse::getPosition(window).x < 128 &&
						Mouse::getPosition(window).y > 73 && Mouse::getPosition(window).y < 148))
                {
                    stage = 0;
					mainmenu.clearvalue();
					
						if (!soundButton.getStatus()) {
							soundButton.play();
						}
					
                }
            }

            if(selectCharEvent.type == Event::MouseMoved){
				mainmenu.clickmouse = false;
            }

            if(selectCharEvent.type == Event::MouseButtonPressed){

				if (Mouse::getPosition(window).x > 14 && Mouse::getPosition(window).x < 128 &&
					Mouse::getPosition(window).y > 73 && Mouse::getPosition(window).y < 148) {
					stage = 0;
					mainmenu.clearvalue();
					
						if (!soundButton.getStatus()) {
							soundButton.play();
						}
					
				}


				mainmenu.clickmouse = true;
            }

			if (selectCharEvent.type == Event::MouseButtonReleased){
				mainmenu.clickmouse = false;
			}

			if (selectCharEvent.type == Event::TextEntered && mainmenu.Editname) {
				if (selectCharEvent.text.unicode >= 33 && selectCharEvent.text.unicode <= 126 && Display.getSize() <= 16) {
					Display += (char)selectCharEvent.text.unicode;
				}
				else if (selectCharEvent.text.unicode == 8 && !Display.isEmpty()) {
					
					Display = Display.substring(0, Display.getSize() - 1);
				}
				else if (selectCharEvent.text.unicode == 13 || selectCharEvent.text.unicode == 27) {
					mainmenu.Editname = false;
				}
				else if (selectCharEvent.text.unicode == 32) {
					Display += " ";
				}
				
				mainmenu.nameP[0].setString(Display);
	
			}


        }


		if (mainmenu.go) {
			stage = 2;
		}



		window.clear(Color::Cyan);
		window.draw(bgs3);
		mainmenu.drawselectChar(window, nummap, soundButton);

		window.display();
/*
        window.clear(Color::Cyan);
        window.draw(bgs);
        mainmenu.drawselect(window);
        window.draw(SselectM);
        window.display();
*/
    }


////////////////////////////////////////////////////////////////////////////////////////





    while(stage == 2){
        Event scr;
cout<<" Brainbot = "<<Brainbot.size()<<" PlayerIngame = "<<playerIngame.size()<<endl;

	while (window.pollEvent(scr)) {
	/*
	if (scr.type == Event::Closed) {

		stage = 99;
	}
	*/
	}
/****************************************************************************************************/
int randchar = 0;

	//playerIngame.clear();

	///bot1

	randchar = mainmenu.numchar[1];

	playerIngame.push_back(randchar == 1 ? player1 : randchar == 2 ? player2 : player3);
	Brainbot.push_back(randchar == 1 ? BotChar1 : randchar == 2 ? BotChar2 : BotChar3);
	playerIngame.back().Select(230, 600, &nummap, 1, mainmenu.nameP[1].getString());

	//bot2
	randchar = mainmenu.numchar[2];

	playerIngame.push_back(randchar == 1 ? player1 : randchar == 2 ? player2 : player3);
	Brainbot.push_back(randchar == 1 ? BotChar1 : randchar == 2 ? BotChar2 : BotChar3);
	playerIngame.back().Select(330, 600, &nummap, 1, mainmenu.nameP[2].getString());

	NumbotL = playerIngame.size();

	/*************/

	//bot3

	randchar = mainmenu.numchar[3];

	playerIngame.push_back(randchar == 1 ? player1 : randchar == 2 ? player2 : player3);
	Brainbot.push_back(randchar == 1 ? BotChar1 : randchar == 2 ? BotChar2 : BotChar3);
	playerIngame.back().Select(3600, 600, &nummap, 0, mainmenu.nameP[3].getString());
	playerIngame.back().isRight = false;
	

	//bot4
	randchar = mainmenu.numchar[4];

	playerIngame.push_back(randchar == 1 ? player1 : randchar == 2 ? player2 : player3);
	Brainbot.push_back(randchar == 1 ? BotChar1 : randchar == 2 ? BotChar2 : BotChar3);
	playerIngame.back().Select(3500, 600, &nummap, 0, mainmenu.nameP[4].getString());
	playerIngame.back().isRight = false;


	//bot5
	randchar = mainmenu.numchar[5];

	playerIngame.push_back(randchar == 1 ? player1 : randchar == 2 ? player2 : player3);
	Brainbot.push_back(randchar == 1 ? BotChar1 : randchar == 2 ? BotChar2 : BotChar3);
	playerIngame.back().Select(3200, 600, &nummap, 0, mainmenu.nameP[5].getString());
	playerIngame.back().isRight = false;
	NumbotR = playerIngame.size();

	/*************/

	//player
	randchar = mainmenu.numchar[0];

	playerIngame.push_back(randchar == 1 ? player1 : randchar == 2 ? player2 : player3);
	CurrentP = playerIngame.size() - 1;
	playerIngame[CurrentP].Select(130, 600, &nummap, 1, mainmenu.nameP[0].getString());
	interfaceingame.push_back(randchar == 1 ? gameinterface1 : randchar == 2 ? gameinterface2 : gameinterface3); //.push_back(gameinterface1);
	interfaceingame.back().oneValue(playerIngame[0].Char, playerIngame[1].Char
		, playerIngame[2].Char, playerIngame[3].Char, playerIngame[4].Char);
	// playerIngame.back().Select(130,600,&nummap);


	 //atkplayer.selectattack(1); /******************************************/
	stage = 3;
	creepTime.restart().asSeconds();
	RealTime.restart().asSeconds();
	clockingame.restart().asSeconds();

	//mainmenu.clearvalue();
	//gametime = RealTime.restart().asSeconds();

	//srand(time(NULL));



/****************************************************************************************************/
            
        
	CurrentMusic = 0;
    window.clear(Color::Cyan);

    window.draw(SselectC);

    window.display();

}

    /********************************** loop game **/

    /************** wait event **/

    while(stage == 3){
//cout<<" Brainbot = "<<Brainbot.size()<<" PlayerIngame = "<<playerIngame.size()<<endl;
        Event gs;
        while (window.pollEvent(gs)){


			if (gs.type == Event::KeyPressed)
			{
				if (gs.key.code == Keyboard::Escape)
				{
					interfaceingame.back().ESC = (interfaceingame.back().ESC+1)%2;
				}
			}

			if (gs.type == Event::MouseButtonPressed && interfaceingame.back().ESC) {
				interfaceingame.back().clickmouse = true;
			}

			if (gs.type == Event::MouseButtonReleased) {
				interfaceingame.back().clickmouse = false;
			}

			if (gs.type == Event::MouseMoved) {
				interfaceingame.back().clickmouse = false;
			}

			if (gs.type == Event::Closed) {

				stage = 99;

			}


        }
        /************** play music **********/

        if(bbbggg.checkplaymusic(0)){
			bbbggg.Playmusic(0, false, 40 ,false);
            //preCurrentMusic = CurrentMusic;
            //bbbggg.checkplaymusic(3);
        }


		if (!bbbggg.checkplaymusic(CurrentMusic)) {
			bbbggg.Playmusic(CurrentMusic, false, 40, false);
			//cout << "here";
			do {
				CurrentMusic = (rand() % 4) + 1;
			} while (CurrentMusic == preCurrentMusic);
			preCurrentMusic = CurrentMusic;
			bbbggg.Playmusic(CurrentMusic, true, 40, false);
		}

		
        //cout<<preCurrentMusic<<" "<<CurrentMusic<<endl;


		/*
            if(Keyboard::isKeyPressed(Keyboard::Escape) )
                {
                    leftbase.gameresert();
                    rightbase.gameresert();
                    stage = 0;
					mainmenu.clearvalue();

                }
			*/
			if (interfaceingame.back().surrender)
			{
				leftbase.HP = 0;
				interfaceingame.back().surrender = false;

			}


     //   cout<<playerIngame.size()<<endl;
/**************************************************** in game *******************************************************/

         //   cout<<CreepL[i][0].Splayer.getPosition().y<<" ";
         //cout<<readyL[i]<<" "<<readyR[i]<<" ";

            //cout<<creeptime[1]<<endl;
            //srand(time(NULL));
/****************** time **/
			debugTime = RealTime.restart().asSeconds();
            gametime = clockingame.getElapsedTime().asSeconds();
            //debugTime = RealTime.getElapsedTime().asSeconds();
           // cout<<debugTime<<endl;
            creeptime = creepTime.getElapsedTime().asSeconds();
//            creeptime[1] = creepTime.getElapsedTime().asSeconds();

/******************** end game **/
			if (interfaceingame.back().Endgame == 0) {
				EndgameTime = debugTime + 3.0 - debugTime;
			}
			else {
				EndgameTime = EndgameTime - debugTime;
			}


            if(leftbase.HP <= 0){ // lose endgame = 2
				interfaceingame.back().Endgame = 2;

				interfaceingame.back().Sprlose.setScale(1 + (4 - EndgameTime) / 2, 1 + (4 - EndgameTime) / 2);

				if (EndgameTime < 1) {
					interfaceingame.back().Sprlose.setColor(Color(255, 255, 255, (EndgameTime) * 255));
				}

				if (EndgameTime <= 0) {
					EndgameTime = 0;
					stage = 4;
					cout << "lose" << endl;
					leftbase.gameresert();
					rightbase.gameresert();
					creepTime.restart().asSeconds();
					winorlose = false;
				}

				if (bbbggg.checkplaymusic(CurrentMusic) && CurrentMusic !=6) {
					bbbggg.Playmusic(CurrentMusic, false, 40, false);
					CurrentMusic = 6;
				}
				if (!bbbggg.checkplaymusic(6)) {
					bbbggg.Playmusic(6, true, 100, false);
				}

					
				

            }else if(rightbase.HP <= 0){ // win endgame = 1
				interfaceingame.back().Endgame = 1;

				interfaceingame.back().Sprwin.setScale(1 + (4 - EndgameTime) / 2, 1 + (4 - EndgameTime) / 2);

				if (EndgameTime < 1) {
					interfaceingame.back().Sprwin.setColor(Color(255, 255, 255, (EndgameTime) * 255));
				}


				if (EndgameTime <= 0) {
					EndgameTime = 0;
					stage = 4;
					cout << "win" << endl;
					leftbase.gameresert();
					rightbase.gameresert();
					creepTime.restart().asSeconds();
					winorlose = true;
				}
				
				if (bbbggg.checkplaymusic(CurrentMusic) && CurrentMusic != 5) {
					bbbggg.Playmusic(CurrentMusic, false, 40, false);
					CurrentMusic = 5;

				}
				
				if (!bbbggg.checkplaymusic(5)) {
					bbbggg.Playmusic(5, true, 100, false);
				}
            }

/********************************** playeringameattack **************************/
/*
for(int i =0 ; i < 3 ;i++){
        damageDebugE[i]++;
        damageDebugP[i]++;

        if(damageDebugE[i] > 20000 || damageDebugP[i] > 20000)
        {
            damageDebugE[i]=0;
            damageDebugP[i]=0;
        }
}
*/
damageDebugP[0]++;
damageDebugP[1]++;
damageDebugP[2]++;
damageDebugE[0]++;
damageDebugE[1]++;
damageDebugE[2]++;

for(size_t i=0 ; i < playerIngame.size() ; i++){
    for(size_t j=0 ; j < playerIngame.size() ; j++){

    /*** normal att**/
        if(!playerIngame[i].hitbox.empty()){

            if(playerIngame[i].hitbox.back().getGlobalBounds().intersects(playerIngame[j].Rplayer.getGlobalBounds())
               && playerIngame[i].sideL != playerIngame[j].sideL){

                if(playerIngame[i].Char == 1 && !playerIngame[j].immortality){

					if (!playerIngame[i].soundAtt1.getStatus()) {
						playerIngame[i].soundAtt1.play();
					}
                    playerIngame[j].HP = playerIngame[j].HP-(playerIngame[i].Damagenormalatt);

                    if(j == CurrentP && damageDebugE[i-2] > 1/debugTime/16){

                        showDamageIngame.push_back(ShowHitByEdamage);
                        showDamageIngame.back().InputTextDamage((int)playerIngame[i].Damagenormalatt);
                        showDamageIngame.back().showDamage.setPosition(playerIngame[CurrentP].Rplayer.getPosition().x+(rand()%50-20)
                                                                   ,playerIngame[CurrentP].Rplayer.getPosition().y+playerIngame[CurrentP].Rplayer.getGlobalBounds().height/4);
                        damageDebugE[i-2] = 0;
                    }

                    if(i == CurrentP && damageDebugP[j-2] > 1/debugTime/16){
                        showDamageIngame.push_back(ShowHitByPdamage);
                        showDamageIngame.back().InputTextDamage((int)playerIngame[CurrentP].Damagenormalatt);
                        showDamageIngame.back().showDamage.setPosition
                        (playerIngame[j].Rplayer.getPosition().x+playerIngame[j].Rplayer.getGlobalBounds().width/2
                         ,playerIngame[j].Rplayer.getPosition().y+playerIngame[j].Rplayer.getGlobalBounds().height/4);

                         damageDebugP[j-2] = 0;
                    }

                    playerIngame[i].hitbox.clear();
                }

                if(playerIngame[i].Char == 2 && !playerIngame[j].immortality){
                    playerIngame[j].HP = playerIngame[j].HP-(playerIngame[i].Damagenormalatt);
					if (!playerIngame[i].soundAtt1.getStatus()) {
						playerIngame[i].soundAtt1.play();
					}

                    if(j == CurrentP && damageDebugE[i-2] > 1/debugTime/16){
                        showDamageIngame.push_back(ShowHitByEdamage);
                        showDamageIngame.back().InputTextDamage((int)playerIngame[i].Damagenormalatt);
                        showDamageIngame.back().showDamage.setPosition(playerIngame[CurrentP].Rplayer.getPosition().x+(rand()%50-20)
                                                                ,playerIngame[CurrentP].Rplayer.getPosition().y+playerIngame[CurrentP].Rplayer.getGlobalBounds().height/4);
                        damageDebugE[i-2] = 0;
                    }

                    if(i == CurrentP && damageDebugP[j-2] > 1/debugTime/16){
                        showDamageIngame.push_back(ShowHitByPdamage);
                        showDamageIngame.back().InputTextDamage((int)playerIngame[CurrentP].Damagenormalatt);
                        showDamageIngame.back().showDamage.setPosition
                        (playerIngame[j].Rplayer.getPosition().x+playerIngame[j].Rplayer.getGlobalBounds().width/2
                         ,playerIngame[j].Rplayer.getPosition().y+playerIngame[j].Rplayer.getGlobalBounds().height/4);
                         damageDebugP[j-2] = 0;
                    }

                    playerIngame[i].hitbox.clear();
                    if(playerIngame[i].Level == 15){playerIngame[i].HP += 20*playerIngame[i].Damagenormalatt/100;}
                }

                if(playerIngame[i].Char == 3 && !playerIngame[j].immortality){
                    playerIngame[j].HP = playerIngame[j].HP-(playerIngame[i].Damagenormalatt*(playerIngame[i].Level==15? 4*debugTime:1));



                    if(j == CurrentP  && damageDebugE[i-2] > 1/debugTime/16){
                        showDamageIngame.push_back(ShowHitByEdamage);
                        showDamageIngame.back().InputTextDamage((int)playerIngame[i].Damagenormalatt);
                        showDamageIngame.back().showDamage.setPosition(playerIngame[CurrentP].Rplayer.getPosition().x+(rand()%50-20)
                                                                   ,playerIngame[CurrentP].Rplayer.getPosition().y+playerIngame[CurrentP].Rplayer.getGlobalBounds().height/4);
                        damageDebugE[i-2] =0;
                    }

                    if(i == CurrentP  && damageDebugP[j-2] > 1/debugTime/16){
                        showDamageIngame.push_back(ShowHitByPdamage);
                        showDamageIngame.back().InputTextDamage((int)playerIngame[CurrentP].Damagenormalatt);
                        showDamageIngame.back().showDamage.setPosition
                        (playerIngame[j].Rplayer.getPosition().x+playerIngame[j].Rplayer.getGlobalBounds().width/2
                         ,playerIngame[j].Rplayer.getPosition().y+playerIngame[j].Rplayer.getGlobalBounds().height/4);
                         damageDebugP[j-2] = 0;
                    }


                   if(playerIngame[i].Level < 15){
                    playerIngame[i].hitbox.clear();
                    playerIngame[i].balls.clear();
                   }
                }
            }

/************************************************************** give exp ***********************************************/

    if(playerIngame[j].HP <= 0 && !playerIngame[j].immortality && playerIngame[j].Rplayer.getPosition().y < 935
       && playerIngame[i].sideL != playerIngame[j].sideL){
        //cout<<"player Death By skill3"<<endl;/////////////////////////////////// kill

        playerIngame[i].Killcount++;

        playerIngame[i].Exp += 4+(2*playerIngame[j].Level);

        if(playerIngame[i].sideL){
            //playerIngame[0].Exp += (playerIngame[0].HP>0? 1+(2*playerIngame[j].Level):0);
            //playerIngame[1].Exp += (playerIngame[1].HP>0? 1+(2*playerIngame[j].Level):0);
            //playerIngame[CurrentP].Exp += (playerIngame[CurrentP].HP>0? 1+(2*playerIngame[j].Level):0);
        }else{
            //playerIngame[2].Exp += (playerIngame[2].HP>0? 1+(2*playerIngame[j].Level):0);
            //playerIngame[3].Exp += (playerIngame[3].HP>0? 1+(2*playerIngame[j].Level):0);
            //playerIngame[4].Exp += (playerIngame[4].HP>0? 1+(2*playerIngame[j].Level):0);
        }


    }


}

    /**** skill 2 ***/

    if(!playerIngame[i].hitbox2.empty()){

            if(playerIngame[i].hitbox2.back().getGlobalBounds().intersects(playerIngame[j].Rplayer.getGlobalBounds())
            && playerIngame[i].sideL != playerIngame[j].sideL){

                if(playerIngame[i].Char == 1 && !playerIngame[j].immortality){
                    playerIngame[j].HP = playerIngame[j].HP-(playerIngame[i].DamageS1*debugTime);
					if (!playerIngame[i].soundAtt2.getStatus()) {
						playerIngame[i].soundAtt2.play();
					}
                    /**/
                    if(j == CurrentP && damageDebugE[i-2] > 1/debugTime/16){
                        showDamageIngame.push_back(ShowHitByEdamage);
                        showDamageIngame.back().InputTextDamage((int)playerIngame[i].DamageS1*0.07);
                        showDamageIngame.back().showDamage.setPosition(playerIngame[CurrentP].Rplayer.getPosition().x+(rand()%50-20)
                                                                   ,playerIngame[CurrentP].Rplayer.getPosition().y+playerIngame[CurrentP].Rplayer.getGlobalBounds().height/4);
                        damageDebugE[i-2] = 0;
                    }

                    if(i == CurrentP && damageDebugP[j-2] > 1/debugTime/16){
                        showDamageIngame.push_back(ShowHitByPdamage);
                        showDamageIngame.back().InputTextDamage((int)playerIngame[i].DamageS1*0.07);
                        showDamageIngame.back().showDamage.setPosition
                        (playerIngame[j].Rplayer.getPosition().x+playerIngame[j].Rplayer.getGlobalBounds().width/2
                         ,playerIngame[j].Rplayer.getPosition().y+playerIngame[j].Rplayer.getGlobalBounds().height/4);
                        damageDebugP[j-2] = 0;
                    }
                    /**/

                }

                if(playerIngame[i].Char == 2 && !playerIngame[j].immortality){
                    playerIngame[j].HP = playerIngame[j].HP-(playerIngame[i].DamageS1*debugTime);
                    playerIngame[j].stuntime = debugTime+0.5 - debugTime;
                    playerIngame[j].Rplayer.move(0,-450*debugTime);
					if (!playerIngame[i].soundAtt2.getStatus()) {
						playerIngame[i].soundAtt2.play();
					}

                    /**/
                    if(j == CurrentP && damageDebugE[i-2] > 1/debugTime/16){
                        showDamageIngame.push_back(ShowHitByEdamage);
                        showDamageIngame.back().InputTextDamage((int)playerIngame[i].DamageS1);
                        showDamageIngame.back().showDamage.setPosition(playerIngame[CurrentP].Rplayer.getPosition().x+(rand()%50-20)
                                                                   ,playerIngame[CurrentP].Rplayer.getPosition().y+playerIngame[CurrentP].Rplayer.getGlobalBounds().height/4);
                        damageDebugE[i-2] = 0;
                    }

                    if(i == CurrentP && damageDebugP[j-2] > 1/debugTime/16){
                        showDamageIngame.push_back(ShowHitByPdamage);
                        showDamageIngame.back().InputTextDamage((int)playerIngame[i].DamageS1);
                        showDamageIngame.back().showDamage.setPosition
                        (playerIngame[j].Rplayer.getPosition().x+playerIngame[j].Rplayer.getGlobalBounds().width/2
                         ,playerIngame[j].Rplayer.getPosition().y+playerIngame[j].Rplayer.getGlobalBounds().height/4);
                        damageDebugP[j-2] = 0;
                    }
                    /**/


                }

                if(playerIngame[i].Char == 3 && !playerIngame[j].immortality){
                    playerIngame[j].HP = playerIngame[j].HP-(playerIngame[i].DamageS1*debugTime);


                    /**/
                    if(j == CurrentP && damageDebugE[i-2] > 1/debugTime/8){
                        showDamageIngame.push_back(ShowHitByEdamage);
                        showDamageIngame.back().InputTextDamage((int)playerIngame[i].DamageS1*0.3);
                        showDamageIngame.back().showDamage.setPosition(playerIngame[CurrentP].Rplayer.getPosition().x+(rand()%50-20)
                                                                   ,playerIngame[CurrentP].Rplayer.getPosition().y+playerIngame[CurrentP].Rplayer.getGlobalBounds().height/4);
                        damageDebugE[i-2] = 0;
                    }

                    if(i == CurrentP && damageDebugP[j-2] > 1/debugTime/8){
                        showDamageIngame.push_back(ShowHitByPdamage);
                        showDamageIngame.back().InputTextDamage((int)playerIngame[i].DamageS1*0.3);
                        showDamageIngame.back().showDamage.setPosition
                        (playerIngame[j].Rplayer.getPosition().x+playerIngame[j].Rplayer.getGlobalBounds().width/2
                         ,playerIngame[j].Rplayer.getPosition().y+playerIngame[j].Rplayer.getGlobalBounds().height/4);
                        damageDebugP[j-2] = 0;
                    }
                    /**/



                }
            }

    if(playerIngame[j].HP <= 0 && !playerIngame[j].immortality && playerIngame[j].Rplayer.getPosition().y < 935
       && playerIngame[i].sideL != playerIngame[j].sideL){
        cout<<"player Death By skill3"<<endl;///////////////////////////////kkill

        playerIngame[i].Killcount++;
        playerIngame[i].Exp += 4+(2*playerIngame[j].Level);

        if(playerIngame[i].sideL){
            //playerIngame[0].Exp += (playerIngame[0].HP>0? 1+(2*playerIngame[j].Level):0);
            //playerIngame[1].Exp += (playerIngame[1].HP>0? 1+(2*playerIngame[j].Level):0);
            //playerIngame[CurrentP].Exp += (playerIngame[CurrentP].HP>0? 1+(2*playerIngame[j].Level):0);
        }else{
            //playerIngame[2].Exp += (playerIngame[2].HP>0? 1+(2*playerIngame[j].Level):0);
            //playerIngame[3].Exp += (playerIngame[3].HP>0? 1+(2*playerIngame[j].Level):0);
            //playerIngame[4].Exp += (playerIngame[4].HP>0? 1+(2*playerIngame[j].Level):0);
        }


    }

        }

    /**** skill 3 ***/

    if(!playerIngame[i].hitbox3.empty()){

            if(playerIngame[i].hitbox3.back().getGlobalBounds().intersects(playerIngame[j].Rplayer.getGlobalBounds())){

                if(playerIngame[i].Char == 1 && !playerIngame[j].immortality && playerIngame[i].sideL != playerIngame[j].sideL){
                    playerIngame[j].HP = playerIngame[j].HP-(playerIngame[i].DamageS2)*debugTime;

                    playerIngame[j].stuntime = debugTime+0.1 - debugTime;
                    playerIngame[j].Rplayer.move(0,-500*debugTime);
                   playerIngame[j].x = (playerIngame[i].isRight? 800:-800);
                   playerIngame[j].Rplayer.move(0,-1000*debugTime);


                    /**/
                    if(j == CurrentP && damageDebugE[i-2] > 1/debugTime/12){
                        showDamageIngame.push_back(ShowHitByEdamage);
                        showDamageIngame.back().InputTextDamage((int)playerIngame[i].DamageS2*0.25);
                        showDamageIngame.back().showDamage.setPosition(playerIngame[CurrentP].Rplayer.getPosition().x+(rand()%50-20)
                                                                   ,playerIngame[CurrentP].Rplayer.getPosition().y+playerIngame[CurrentP].Rplayer.getGlobalBounds().height/4);
                        damageDebugE[i-2] = 0;
                    }

                    if(i == CurrentP && damageDebugP[j-2] > 1/debugTime/12){
                        showDamageIngame.push_back(ShowHitByPdamage);
                        showDamageIngame.back().InputTextDamage((int)playerIngame[i].DamageS2*0.25);
                        showDamageIngame.back().showDamage.setPosition
                        (playerIngame[j].Rplayer.getPosition().x+playerIngame[j].Rplayer.getGlobalBounds().width/2
                         ,playerIngame[j].Rplayer.getPosition().y+playerIngame[j].Rplayer.getGlobalBounds().height/4);
                        damageDebugP[j-2] = 0;
                    }
                    /**/


                }

                if(playerIngame[i].Char == 2 && !playerIngame[j].immortality){
                    if(playerIngame[i].sideL != playerIngame[j].sideL){
						playerIngame[j].HP = playerIngame[j].HP-(playerIngame[i].DamageS2*debugTime);

					}
                   //playerIngame[j].stuntime = debugTime+0.5 - debugTime;


                    /**/
                    if(j == CurrentP && damageDebugE[i-2] > 1/debugTime/8 && playerIngame[i].sideL != playerIngame[j].sideL){
                        showDamageIngame.push_back(ShowHitByEdamage);
                        showDamageIngame.back().InputTextDamage((int)playerIngame[i].DamageS2*0.3);
                        showDamageIngame.back().showDamage.setPosition(playerIngame[CurrentP].Rplayer.getPosition().x+(rand()%50-20)
                                                                   ,playerIngame[CurrentP].Rplayer.getPosition().y+playerIngame[CurrentP].Rplayer.getGlobalBounds().height/4);
                        damageDebugE[i-2] = 0;
                    }

                    if(i == CurrentP && damageDebugP[j-2] > 1/debugTime/8 && playerIngame[i].sideL != playerIngame[j].sideL){
                        showDamageIngame.push_back(ShowHitByPdamage);
                        showDamageIngame.back().InputTextDamage((int)playerIngame[i].DamageS2*0.3);
                        showDamageIngame.back().showDamage.setPosition
                        (playerIngame[j].Rplayer.getPosition().x+playerIngame[j].Rplayer.getGlobalBounds().width/2
                         ,playerIngame[j].Rplayer.getPosition().y+playerIngame[j].Rplayer.getGlobalBounds().height/4);
                        damageDebugP[j-2] = 0;
                    }
                    /**/


                }

                if(playerIngame[i].Char == 3 && !playerIngame[j].immortality && playerIngame[i].sideL != playerIngame[j].sideL ){
                    playerIngame[j].HP = playerIngame[j].HP-(playerIngame[i].DamageS2*debugTime);
                    playerIngame[j].stuntime = debugTime+1 - debugTime;
                    playerIngame[j].Rplayer.move(0,-800*debugTime);
                    playerIngame[j].x = (playerIngame[i].isRight? 500:-500);


                    /**/
                    if(j == CurrentP && damageDebugE[i-2] > 1/debugTime/16){
                        showDamageIngame.push_back(ShowHitByEdamage);
                        showDamageIngame.back().InputTextDamage((int)playerIngame[i].DamageS2*0.08);
                        showDamageIngame.back().showDamage.setPosition(playerIngame[CurrentP].Rplayer.getPosition().x+(rand()%50-20)
                                                                   ,playerIngame[CurrentP].Rplayer.getPosition().y+playerIngame[CurrentP].Rplayer.getGlobalBounds().height/4);
                        damageDebugE[i-2] = 0;
                    }

                    if(i == CurrentP && damageDebugP[j-2] > 1/debugTime/16){
                        showDamageIngame.push_back(ShowHitByPdamage);
                        showDamageIngame.back().InputTextDamage((int)playerIngame[i].DamageS2*0.08);
                        showDamageIngame.back().showDamage.setPosition
                        (playerIngame[j].Rplayer.getPosition().x+playerIngame[j].Rplayer.getGlobalBounds().width/2
                         ,playerIngame[j].Rplayer.getPosition().y+playerIngame[j].Rplayer.getGlobalBounds().height/4);
                        damageDebugP[j-2] = 0;
                    }
                    /**/



                }

    if(playerIngame[j].HP <= 0 && !playerIngame[j].immortality && playerIngame[j].Rplayer.getPosition().y < 935
       && playerIngame[i].sideL != playerIngame[j].sideL){
        cout<<"player Death By skill3"<<endl;/////////////////////////////////// kill

        playerIngame[i].Killcount++;
        playerIngame[i].Exp += 4+(2*playerIngame[j].Level);

        if(playerIngame[i].sideL){
            //playerIngame[0].Exp += (playerIngame[0].HP>0? 1+(2*playerIngame[j].Level):0);
            //playerIngame[1].Exp += (playerIngame[1].HP>0? 1+(2*playerIngame[j].Level):0);
            //playerIngame[CurrentP].Exp += (playerIngame[CurrentP].HP>0? 1+(2*playerIngame[j].Level):0);
        }else{
            //playerIngame[2].Exp += (playerIngame[2].HP>0? 1+(2*playerIngame[j].Level):0);
            //playerIngame[3].Exp += (playerIngame[3].HP>0? 1+(2*playerIngame[j].Level):0);
            //playerIngame[4].Exp += (playerIngame[4].HP>0? 1+(2*playerIngame[j].Level):0);
        }



    }

            }

        }

/**************************************************** hit creep && exp by creep ****************/

 }



if(!creepIngame.empty()){

    for(size_t k=0 ; k < creepIngame.size() ; k++){
    damageCreepDebug[k]++;

    if(damageCreepDebug[k]>20000){
        damageCreepDebug[k]=0;
    }

    /*********/
    if(!playerIngame[i].hitbox.empty()){
        if(playerIngame[i].hitbox.back().getGlobalBounds().intersects(creepIngame[k].Splayer.getGlobalBounds())
            && playerIngame[i].sideL != creepIngame[k].isRight && creepIngame[k].HP > 0){

                if(playerIngame[i].Char == 1){
                    creepIngame[k].HP = creepIngame[k].HP-(playerIngame[i].Damagenormalatt);
                    playerIngame[i].hitbox.clear();
					if (!playerIngame[i].soundAtt1.getStatus()) {
						playerIngame[i].soundAtt1.play();
					}

                    if(i == CurrentP && damageCreepDebug[k] > 1/debugTime/16){
                        showDamageIngame.push_back(ShowHitByPdamage);
                        showDamageIngame.back().InputTextDamage((int)playerIngame[CurrentP].Damagenormalatt);
                        showDamageIngame.back().showDamage.setPosition
                        (creepIngame[k].Splayer.getPosition().x+creepIngame[k].Splayer.getGlobalBounds().width/2
                         ,creepIngame[k].Splayer.getPosition().y+creepIngame[k].Splayer.getGlobalBounds().height/4);

                         damageCreepDebug[k] = 0;
                    }

                }

                if(playerIngame[i].Char == 2){
                    creepIngame[k].HP = creepIngame[k].HP-(playerIngame[i].Damagenormalatt);
                    if(playerIngame[i].Level == 15){playerIngame[i].HP += 20*playerIngame[i].Damagenormalatt/100;}
                    playerIngame[i].hitbox.clear();

					if (!playerIngame[i].soundAtt1.getStatus()) {
						playerIngame[i].soundAtt1.play();
					}

                    if(i == CurrentP && damageCreepDebug[k] > 1/debugTime/16){
                        showDamageIngame.push_back(ShowHitByPdamage);
                        showDamageIngame.back().InputTextDamage((int)playerIngame[CurrentP].Damagenormalatt);
                        showDamageIngame.back().showDamage.setPosition
                        (creepIngame[k].Splayer.getPosition().x+creepIngame[k].Splayer.getGlobalBounds().width/2
                         ,creepIngame[k].Splayer.getPosition().y+creepIngame[k].Splayer.getGlobalBounds().height/4);

                         damageCreepDebug[k] = 0;
                    }

                }

                if(playerIngame[i].Char == 3){
                    creepIngame[k].HP = creepIngame[k].HP-(playerIngame[i].Damagenormalatt*(playerIngame[i].Level==15? 4*debugTime:1));
                   if(playerIngame[i].Level < 15){
                    playerIngame[i].hitbox.clear();
                    playerIngame[i].balls.clear();
                   }

                    if(i == CurrentP && damageCreepDebug[k] > 1/debugTime/16){
                        showDamageIngame.push_back(ShowHitByPdamage);
                        showDamageIngame.back().InputTextDamage((int)playerIngame[CurrentP].Damagenormalatt);
                        showDamageIngame.back().showDamage.setPosition
                        (creepIngame[k].Splayer.getPosition().x+creepIngame[k].Splayer.getGlobalBounds().width/2+rand()%50-20
                         ,creepIngame[k].Splayer.getPosition().y+creepIngame[k].Splayer.getGlobalBounds().height/4);

                         damageCreepDebug[k] = 0;
                    }

                }

    if(creepIngame[k].HP <= 0 && playerIngame[i].sideL != creepIngame[k].isRight){
       // cout<<"creep death by p"<<endl;/////////////////////////////////// kill

        playerIngame[i].Exp += 1+(0.5*(gametime/120));

		/*
        if(playerIngame[i].sideL){
            playerIngame[0].Exp += (playerIngame[0].HP>0? 1:0);
            playerIngame[1].Exp += (playerIngame[1].HP>0? 1:0);
            playerIngame[CurrentP].Exp += (playerIngame[CurrentP].HP>0? 1:0);
        }else{
            playerIngame[2].Exp += (playerIngame[2].HP>0? 1:0);
            playerIngame[3].Exp += (playerIngame[3].HP>0? 1:0);
            playerIngame[4].Exp += (playerIngame[4].HP>0? 1:0);
        }
		*/

    }


        }
    }
        /***********/

        if(!playerIngame[i].hitbox2.empty()){

        if(playerIngame[i].hitbox2.back().getGlobalBounds().intersects(creepIngame[k].Splayer.getGlobalBounds())
            && playerIngame[i].sideL != creepIngame[k].isRight && creepIngame[k].HP > 0){

                if(playerIngame[i].Char == 1){
                    creepIngame[k].HP = creepIngame[k].HP-(playerIngame[i].DamageS1*debugTime);
					if (!playerIngame[i].soundAtt2.getStatus()) {
						playerIngame[i].soundAtt2.play();
					}

                    if(i == CurrentP && damageCreepDebug[k] > 1/debugTime/4){
                        showDamageIngame.push_back(ShowHitByPdamage);
                        showDamageIngame.back().InputTextDamage((int)playerIngame[i].DamageS1*0.07);
                        showDamageIngame.back().showDamage.setPosition
                        (creepIngame[k].Splayer.getPosition().x+creepIngame[k].Splayer.getGlobalBounds().width/2+rand()%50-20
                         ,creepIngame[k].Splayer.getPosition().y+creepIngame[k].Splayer.getGlobalBounds().height/4);
                        damageCreepDebug[k] = 0;
                    }

                }

                if(playerIngame[i].Char == 2){
                    creepIngame[k].HP = creepIngame[k].HP-(playerIngame[i].DamageS1*debugTime);
                    creepIngame[k].Splayer.move(0,-450*debugTime);
					if (!playerIngame[i].soundAtt2.getStatus()) {
						playerIngame[i].soundAtt2.play();
					}

                    if(i == CurrentP && damageCreepDebug[k] > 1/debugTime/4){
                        showDamageIngame.push_back(ShowHitByPdamage);
                        showDamageIngame.back().InputTextDamage((int)playerIngame[i].DamageS1);
                        showDamageIngame.back().showDamage.setPosition
                        (creepIngame[k].Splayer.getPosition().x+creepIngame[k].Splayer.getGlobalBounds().width/2+rand()%50-20
                         ,creepIngame[k].Splayer.getPosition().y+creepIngame[k].Splayer.getGlobalBounds().height/4);
                        damageCreepDebug[k] = 0;
                    }

                }

                if(playerIngame[i].Char == 3){
                    creepIngame[k].HP = creepIngame[k].HP-(playerIngame[i].DamageS1*debugTime);

                    if(i == CurrentP && damageCreepDebug[k] > 1/debugTime/2){

                        showDamageIngame.push_back(ShowHitByPdamage);
                        showDamageIngame.back().InputTextDamage((int)playerIngame[i].DamageS1*0.3);
                        showDamageIngame.back().showDamage.setPosition
                        (creepIngame[k].Splayer.getPosition().x+creepIngame[k].Splayer.getGlobalBounds().width/2+rand()%50-20
                         ,creepIngame[k].Splayer.getPosition().y+creepIngame[k].Splayer.getGlobalBounds().height/4);
                        damageCreepDebug[k] = 0;
                    }


                }

    if(creepIngame[k].HP <= 0 && playerIngame[i].sideL != creepIngame[k].isRight){
       // cout<<"creep death by p"<<endl;/////////////////////////////////// kill

        playerIngame[i].Exp += 1+(0.5*(gametime/120));
		/*
        if(playerIngame[i].sideL){
            playerIngame[0].Exp += (playerIngame[0].HP>0? 1:0);
            playerIngame[1].Exp += (playerIngame[1].HP>0? 1:0);
            playerIngame[CurrentP].Exp += (playerIngame[CurrentP].HP>0? 2+(2*(gametime/60)):0);
        }else{
            playerIngame[2].Exp += (playerIngame[2].HP>0? 1:0);
            playerIngame[3].Exp += (playerIngame[3].HP>0? 1:0);
            playerIngame[4].Exp += (playerIngame[4].HP>0? 1:0);
        }

		*/
    }

    }
}
/***********/

    if(!playerIngame[i].hitbox3.empty()){

            if(playerIngame[i].hitbox3.back().getGlobalBounds().intersects(creepIngame[k].Splayer.getGlobalBounds())
               && creepIngame[k].HP > 0){

                if(playerIngame[i].Char == 1 && playerIngame[i].sideL != creepIngame[k].isRight){
                    creepIngame[k].HP = creepIngame[k].HP-(playerIngame[i].DamageS2)*debugTime;
                    creepIngame[k].Splayer.move(0,-500*debugTime);
                   creepIngame[k].x = (playerIngame[i].isRight? 800:-800);
                   creepIngame[k].Splayer.move(0,-1000*debugTime);

                    if(i == CurrentP && damageCreepDebug[k] > 1/debugTime/12){
                        showDamageIngame.push_back(ShowHitByPdamage);
                        showDamageIngame.back().InputTextDamage((int)playerIngame[i].DamageS2*0.25);
                        showDamageIngame.back().showDamage.setPosition
                        (creepIngame[k].Splayer.getPosition().x+creepIngame[k].Splayer.getGlobalBounds().width/2+rand()%50-20
                         ,creepIngame[k].Splayer.getPosition().y+creepIngame[k].Splayer.getGlobalBounds().height/4);
                        damageCreepDebug[k] = 0;
                    }

                }

                if(playerIngame[i].Char == 2){
                    if(playerIngame[i].sideL != creepIngame[k].isRight){ creepIngame[k].HP = creepIngame[k].HP-(playerIngame[i].DamageS2*debugTime);}


                    if(i == CurrentP && damageCreepDebug[k] > 1/debugTime/4 && playerIngame[CurrentP].sideL != creepIngame[k].isRight){
                        showDamageIngame.push_back(ShowHitByPdamage);
                        showDamageIngame.back().InputTextDamage((int)playerIngame[i].DamageS2*0.3);
                        showDamageIngame.back().showDamage.setPosition
                        (creepIngame[k].Splayer.getPosition().x+creepIngame[k].Splayer.getGlobalBounds().width/2+rand()%50-20
                         ,creepIngame[k].Splayer.getPosition().y+creepIngame[k].Splayer.getGlobalBounds().height/4);
                        damageCreepDebug[k] = 0;
                    }

                }

                if(playerIngame[i].Char == 3 && playerIngame[i].sideL != creepIngame[k].isRight){
                    creepIngame[k].HP = creepIngame[k].HP-(playerIngame[i].DamageS2*debugTime);
                    creepIngame[k].Splayer.move(0,-800*debugTime);
                    creepIngame[k].x = (playerIngame[i].isRight? 500:-500);



                    if(i == CurrentP && damageCreepDebug[k] > 1/debugTime/6){
                        showDamageIngame.push_back(ShowHitByPdamage);
                        showDamageIngame.back().InputTextDamage((int)playerIngame[i].DamageS2*0.08);
                        showDamageIngame.back().showDamage.setPosition
                        (creepIngame[k].Splayer.getPosition().x+creepIngame[k].Splayer.getGlobalBounds().width/2+rand()%50-20
                         ,creepIngame[k].Splayer.getPosition().y+creepIngame[k].Splayer.getGlobalBounds().height/4);
                        damageCreepDebug[k] = 0;
                    }

                }


    if(creepIngame[k].HP <= 0 && playerIngame[i].sideL != creepIngame[k].isRight){
       // cout<<"creep death by p"<<endl;/////////////////////////////////// kill
        playerIngame[i].Exp += 1+(0.5*(gametime/120));

		/*
        if(playerIngame[i].sideL){
            playerIngame[0].Exp += (playerIngame[0].HP>0? 1:0);
            playerIngame[1].Exp += (playerIngame[1].HP>0? 1:0);
            playerIngame[CurrentP].Exp += (playerIngame[CurrentP].HP>0? 1:0);
        }else{
            playerIngame[2].Exp += (playerIngame[2].HP>0? 1:0);
            playerIngame[3].Exp += (playerIngame[3].HP>0? 1:0);
            playerIngame[4].Exp += (playerIngame[4].HP>0? 1:0);
        }
		*/

    }



            }

        }


    }

}

}




/*************************************** Creep *************************************/

for(size_t i = 0 ; i< creepIngame.size() ; i++){

switch(creepIngame[i].isRight){

       case 1:
               if(creepIngame[i].Splayer.getGlobalBounds().intersects(rightbase.Spbase.getGlobalBounds()) &&
               creepIngame[i].Splayer.getPosition().y < 1080 && creepIngame[i].Splayer.getPosition().x > 3350
               && creepIngame[i].Splayer.getPosition().x < 3450 ){

                creepIngame[i].x = 0;
                if(creepIngame[i].attack){
                  rightbase.HP = rightbase.HP-0.25;
                }

            }else if(!creepIngame[i].iscollide){
                creepIngame[i].x=225;

            }else if(creepIngame[i].iscollide && !creepIngame[i].isjumping && creepIngame[i].onground){

                creepIngame[i].onground = false;
                creepIngame[i].isjumping=true;
                creepIngame[i].y = -800;

            }

            break;

        case 0:

            if(creepIngame[i].Splayer.getGlobalBounds().intersects(leftbase.Spbase.getGlobalBounds()) &&
               creepIngame[i].Splayer.getPosition().y < 1080 &&
               creepIngame[i].Splayer.getPosition().x > 290
               && creepIngame[i].Splayer.getPosition().x < 390 ){

                creepIngame[i].x = 0;
                if(creepIngame[i].attack){
                    leftbase.HP = leftbase.HP-0.25;
                }

            }else if(!creepIngame[i].iscollide){

                creepIngame[i].x= -225;

            }else if(creepIngame[i].iscollide && !creepIngame[i].isjumping && creepIngame[i].onground){

                creepIngame[i].onground = false;
                creepIngame[i].isjumping=true;
                creepIngame[i].y = -800;

            }
        break;
}


/******************/

for(size_t j = 0 ; j< creepIngame.size() ; j++){


        switch(creepIngame[i].isRight){

/*** L**/
            case 1 :
            if(creepIngame[i].Splayer.getGlobalBounds().intersects(creepIngame[j].Splayer.getGlobalBounds())
               && !creepIngame[j].isRight &&
               abs(creepIngame[i].Splayer.getPosition().x-creepIngame[j].Splayer.getPosition().x) < 40){ //rand()%35+15){
                creepIngame[i].x = 0;
                if(creepIngame[i].attack){
                    creepIngame[j].HP = creepIngame[j].HP-5;
                    creepIngame[i].attack = false;
                }

    if(creepIngame[j].HP <= 0 && creepIngame[i].isRight != creepIngame[j].isRight){

        playerIngame[0].Exp += (playerIngame[0].HP>0? 1:1);
        playerIngame[1].Exp += (playerIngame[1].HP>0? 1:1);
        playerIngame[CurrentP].Exp += (playerIngame[CurrentP].HP>0? 1:1);
}

}

/********** creep hit player R ***/

for(int k = NumbotL ; k < NumbotR ; k++ ){
            if(creepIngame[i].Splayer.getGlobalBounds().intersects(playerIngame[k].Rplayer.getGlobalBounds())
               && abs(creepIngame[i].Splayer.getPosition().x-playerIngame[k].Rplayer.getPosition().x) < 40 && !playerIngame[k].immortality){
                creepIngame[i].x = 0;
                if(creepIngame[i].attack){
                    playerIngame[k].HP = playerIngame[k].HP-3;
                    creepIngame[i].attack = false;
                }

                ///////////// ¤ÃÕºµÕ player R

    if(playerIngame[k].HP <= 0 && !playerIngame[k].immortality && playerIngame[k].Rplayer.getPosition().y < 935
       && creepIngame[i].isRight != playerIngame[k].sideL ){
        //cout<<"player Death By skill3"<<endl;/////////////////////////////////// kill

        playerIngame[0].Exp += (playerIngame[0].HP>0? 2:0);
        playerIngame[1].Exp += (playerIngame[1].HP>0? 2:0);
        playerIngame[CurrentP].Exp += (playerIngame[CurrentP].HP>0? 2:0);

    }



            }
}
            break;

/************************************************************************************************************/

/*** R**/

            case 0:
            if(creepIngame[i].Splayer.getGlobalBounds().intersects(creepIngame[j].Splayer.getGlobalBounds())
               && creepIngame[j].isRight &&
               abs(creepIngame[i].Splayer.getPosition().x-creepIngame[j].Splayer.getPosition().x) < 40){//rand()%35+15){
                creepIngame[i].x = 0;
                if(creepIngame[i].attack){
                    creepIngame[j].HP = creepIngame[j].HP-5;
                    creepIngame[i].attack = false;
                }
				
    if(creepIngame[j].HP <= 0 && creepIngame[i].isRight != creepIngame[j].isRight){

        playerIngame[2].Exp +=  (playerIngame[2].HP>0? 1:1);
        playerIngame[3].Exp +=  (playerIngame[3].HP>0? 1:1);
        playerIngame[4].Exp +=  (playerIngame[4].HP>0? 1:1);

}


            }


/********** creep hit player L ***/

for(int k = 0 ; k < 6 ; k++ ){

if(k==2){k = 5;}
            if(creepIngame[i].Splayer.getGlobalBounds().intersects(playerIngame[k].Rplayer.getGlobalBounds())
               && abs(creepIngame[i].Splayer.getPosition().x-playerIngame[k].Rplayer.getPosition().x) < 40  && !playerIngame[k].immortality){
                creepIngame[i].x = 0;
                if(creepIngame[i].attack){
                    playerIngame[k].HP = playerIngame[k].HP-3;
                    creepIngame[i].attack = false;

                    if(k == CurrentP){
                        showDamageIngame.push_back(ShowHitByEdamage);
                        showDamageIngame.back().InputTextDamage(3);
                        showDamageIngame.back().showDamage.setPosition(playerIngame[CurrentP].Rplayer.getPosition().x+(rand()%50-20)
                                                                   ,playerIngame[CurrentP].Rplayer.getPosition().y+playerIngame[CurrentP].Rplayer.getGlobalBounds().height/4);
                    }

                }

                /////////////// ¤ÃÕºµÕ player L
    if(playerIngame[k].HP <= 0 && !playerIngame[k].immortality && playerIngame[k].Rplayer.getPosition().y < 935
       && creepIngame[i].isRight != playerIngame[k].sideL ){
        //cout<<"player Death By skill3"<<endl;/////////////////////////////////// kill


        playerIngame[2].Exp += (playerIngame[2].HP>0? 2:0);
        playerIngame[3].Exp += (playerIngame[3].HP>0? 2:0);
        playerIngame[4].Exp += (playerIngame[4].HP>0? 2:0);

    }



            }

}
            break;
    }
}

    if(creepIngame.size() > 1 && creepIngame[i].HP <= 0){

        creepIngame.erase(creepIngame.begin()+i);
        damageCreepDebug.erase(damageCreepDebug.begin()+i);

    }

}

//cout<<creepIngame.size()<<" "<<creeptime<<endl;
//srand(time(NULL));

if(creeptime > 15){

for(int i = 0 ; i<5 ; i++){
    creepIngame.push_back(CreepL);
    creepIngame.back().Splayer.setPosition(200+(5*(rand()%10+1)*i),700);
    creepIngame.back().frame = rand()%8;
    creepIngame.back().h = rand()%10+i;
    damageCreepDebug.push_back(1);
//}

//srand(time(NULL)+651);
//for(int i = 0 ; i<5 ; i++){

    creepIngame.push_back(CreepR);
    creepIngame.back().Splayer.setPosition(3600-(5*(rand()%10+1)*i),700);
    creepIngame.back().frame = rand()%8;
    creepIngame.back().h = rand()%10+i;
    damageCreepDebug.push_back(1);

 }
    creeptime = creepTime.restart().asSeconds();

}

/****************************************************************/
double PrCpositionL = 0,PrCpositionR = 1280*3;
double MaxCpositionL = 0,MaxCpositionR = 1280*3;

    for(size_t i = 0 ; i< creepIngame.size() ; i++)
    {
        PrCpositionL = creepIngame[i].isRight? (creepIngame[i].HP>0? creepIngame[i].Splayer.getPosition().x:0) :0 ;
        MaxCpositionL = MaxCpositionL>PrCpositionL? MaxCpositionL:PrCpositionL ;

        PrCpositionR = !creepIngame[i].isRight? (creepIngame[i].HP>0? creepIngame[i].Splayer.getPosition().x:1280*3) :1280*3 ;
        MaxCpositionR = MaxCpositionR<PrCpositionR? MaxCpositionR:PrCpositionR ;
    }

VcreepxposL=MaxCpositionL;
VcreepxposR=MaxCpositionR;

/***************** control **/
if (!snows.empty()) {

	for (size_t i = 0; i < snows.size(); i++) {

		if (snows[i].getPosition().y > 932) {
			//srand(time(NULL));//rand()%4200-200
			snows[i].setPosition(rand() % 4200, rand() % 1080 - 1080);
		}

		snows[i].move(-10 * debugTime, 40 * debugTime);

	}
}
else if (!CyberSnows.empty()) {

	for (size_t i = 0; i < CyberSnows.size(); i++) {

			CyberSnows[i].setString(rand() % 300 == 1 ? "1" : rand() % 300 == 0 ? "0" : CyberSnows[i].getString());

		
		//CyberSnows[i].setString("1");
		if (CyberSnows[i].getPosition().y > 932) {
			//srand(time(NULL));//rand()%4200-200
			CyberSnows[i].setPosition(rand() % 4200, rand() % 1080 - 1080);
		}

		CyberSnows[i].move(-10 * debugTime, 40 * debugTime);

	}

}

            for(size_t i = 0 ; i< creepIngame.size() ; i++){creepIngame[i].update(&debugTime,nummap);}
            Rmap.setPosition(500,816);
            //Rmap.setSize(Vector2f(500,500));
            Rmap.setFillColor(Color::Green);


/******************* draw **/
            window.clear(Color::White);

/******************** camera ******/

			if (interfaceingame.back().Endgame == 0) {
				playerIngame[CurrentP].camera(window);
			}
			else if (interfaceingame.back().Endgame == 2) {
				playerIngame[CurrentP].Endcamera(window, 2);
			}
			else if (interfaceingame.back().Endgame == 1) {
				playerIngame[CurrentP].Endcamera(window, 1);
			}
             
			drawmap.drawbg(window
            , playerIngame[CurrentP].Rplayer.getPosition().x+( playerIngame[CurrentP].Rplayer.getLocalBounds().width/2)
            , playerIngame[CurrentP].Rplayer.getPosition().y+( playerIngame[CurrentP].Rplayer.getLocalBounds().height/2)
            ,&nummap, interfaceingame.back().Endgame);


/******************** map **/

            for(int i=0; i < 15 ; i++)
            {
                for(int j=0 ; j< 30 ; j++)
                {
                    if(drawmap.bm[i][j] == 0 || drawmap.bm[i][j] == 9)
                    {
                        continue;
                    }else{
                        drawmap.drawground(window,i,j,&nummap,drawmap.bm[i][j]);
                    }
                }
            }



/**************** draw player **/
           // window.draw(Rmap);
            leftbase.setBase(window);
            rightbase.setBase(window);

            for(size_t i = 0 ; i<creepIngame.size(); i++)
            {
               // window.draw(creepIngame[i].Splayer);
                creepIngame[i].drawCreep(window);
            }



/**************** update player *********/

    playerIngame[CurrentP].update(&debugTime,window,(Keyboard::isKeyPressed(Keyboard::A) && gametime > 4 && leftbase.HP > 0 && rightbase.HP > 0),Keyboard::isKeyPressed(Keyboard::D) && gametime > 4 && leftbase.HP > 0 && rightbase.HP > 0
        ,Keyboard::isKeyPressed(Keyboard::W) && gametime > 4 && leftbase.HP > 0 && rightbase.HP > 0,Keyboard::isKeyPressed(Keyboard::J) && gametime > 4 && leftbase.HP > 0 && rightbase.HP > 0,Keyboard::isKeyPressed(Keyboard::K) && leftbase.HP > 0 && rightbase.HP > 0
        ,Keyboard::isKeyPressed(Keyboard::L) && leftbase.HP > 0 && rightbase.HP > 0);

/*************** update bot ************/



//void Playerclass::update(debugTime,window,A,D,W,J,K,L)

/** L**/

for(int i = 0 ; i < NumbotL ; i++ ){


    Brainbot[i].updateData(interfaceingame.back().Endgame,0,
                           playerIngame[NumbotL].Rplayer.getPosition().x,playerIngame[NumbotL].Rplayer.getPosition().y,
                           playerIngame[NumbotL+1].Rplayer.getPosition().x,playerIngame[NumbotL+1].Rplayer.getPosition().y,
                           playerIngame[NumbotL+2].Rplayer.getPosition().x,playerIngame[NumbotL+2].Rplayer.getPosition().y,
                           playerIngame[i].iscollide,playerIngame[i].stunned
                           ,playerIngame[i].Rplayer.getPosition().x,playerIngame[i].Rplayer.getPosition().y,
                           playerIngame[i].cd1,playerIngame[i].cd2,playerIngame[i].isRight,VcreepxposL,VcreepxposR
                           ,playerIngame[NumbotL].HP,playerIngame[NumbotL+1].HP,playerIngame[NumbotL+2].HP
                           ,playerIngame[i].HP,debugTime);

     playerIngame[i].update(&debugTime,window
    ,Brainbot[i].switchA()
    ,Brainbot[i].switchD()
    ,Brainbot[i].switchW()
    ,Brainbot[i].switchJ()
    ,Brainbot[i].switchK()
    ,Brainbot[i].switchL());
   // playerIngame[i].Splayer.setColor(Color(255,0,0,200));
    playerIngame[i].Rplayer.setFillColor(Color(255,0,0,200));
//cout<<Brainbot[i].switchJ()<<endl;
}


/** R**/
for(int j = NumbotL ; j < NumbotR ; j++ ){



    Brainbot[j].updateData(interfaceingame.back().Endgame,1,
                           playerIngame[0].Rplayer.getPosition().x,playerIngame[0].Rplayer.getPosition().y,
                           playerIngame[1].Rplayer.getPosition().x,playerIngame[1].Rplayer.getPosition().y,
                           playerIngame[CurrentP].Rplayer.getPosition().x,playerIngame[CurrentP].Rplayer.getPosition().y,
                           playerIngame[j].iscollide,playerIngame[j].stunned
                           ,playerIngame[j].Rplayer.getPosition().x,playerIngame[j].Rplayer.getPosition().y,
                           playerIngame[j].cd1,playerIngame[j].cd2,playerIngame[j].isRight,VcreepxposR,VcreepxposL
                           ,playerIngame[0].HP,playerIngame[1].HP,playerIngame[CurrentP].HP
                           ,playerIngame[j].HP,debugTime);

     playerIngame[j].update(&debugTime,window
    ,Brainbot[j].switchA()
    ,Brainbot[j].switchD()
    ,Brainbot[j].switchW()
    ,Brainbot[j].switchJ()
    ,Brainbot[j].switchK()
    ,Brainbot[j].switchL());
   // playerIngame[j].Splayer.setColor(Color(0,0,255,200));
    playerIngame[j].Rplayer.setFillColor(Color(0,0,255,200));
}
//playerIngame[CurrentP].Splayer.setColor(Color(255,0,0,200));
    playerIngame[CurrentP].Rplayer.setFillColor(Color(255,0,0,200));
    //    cout<<" Brainbot = "<<Brainbot.size()<<" PlayerIngame = "<<playerIngame.size()<<endl;

/***************** effect ******************/


	if (!snows.empty()) {
		for (size_t i = 0; i < snows.size(); i++) {
			window.draw(snows[i]);
		}
	}
	if (!CyberSnows.empty()) {
		for (size_t i = 0; i < CyberSnows.size(); i++) {
			window.draw(CyberSnows[i]);
		}
	}
/******************** show draw damage *********/
    for(size_t i=0 ; i < showDamageIngame.size(); i++){

        showDamageIngame[i].updateShowdamage(window,debugTime);
        if(showDamageIngame[i].destroy){
            showDamageIngame.erase(showDamageIngame.begin()+i);
        }
    }

/******************* interface ****************/

        Sdark.setPosition(playerIngame[CurrentP].Pcamera.getCenter().x-windowWidth/2,playerIngame[CurrentP].Pcamera.getCenter().y-windowHeight/2);
        //Sdark.setPosition(Sinterface.getPosition().x,Sinterface.getPosition().y);
        //Sdark.setPosition(playerIngame[CurrentP].Rplayer.getPosition().x-Sdark.getGlobalBounds().width/2,playerIngame[CurrentP].Rplayer.getPosition().y-Sdark.getGlobalBounds().height/2);
        if(playerIngame[CurrentP].HP <= 0) {window.draw(Sdark);}
        interfaceingame.back().drawinterface(window,playerIngame[CurrentP].Pcamera.getCenter().x-windowWidth/2
        ,playerIngame[CurrentP].Pcamera.getCenter().y-windowHeight/2, playerIngame[CurrentP].Damagenormalatt, playerIngame[CurrentP].DamageS1, playerIngame[CurrentP].DamageS2
		,playerIngame[CurrentP].normalattack
        ,playerIngame[CurrentP].cd1,playerIngame[CurrentP].cd2,playerIngame[CurrentP].HP,playerIngame[CurrentP].maxHP,playerIngame[CurrentP].TimeDead
        ,playerIngame[CurrentP].Damagenormalatt,playerIngame[CurrentP].DamageS1,playerIngame[CurrentP].DamageS2
        ,playerIngame[CurrentP].Level,playerIngame[CurrentP].Killcount,playerIngame[CurrentP].Deathcount,gametime);
        interfaceingame.back().elsedatafloat(window,playerIngame[0].TimeDead
                                             ,playerIngame[1].TimeDead,playerIngame[2].TimeDead
                                             ,playerIngame[3].TimeDead,playerIngame[4].TimeDead
                                             ,playerIngame[0].HP,playerIngame[0].maxHP
                                             ,playerIngame[1].HP,playerIngame[1].maxHP
                                             ,playerIngame[CurrentP].Pcamera.getCenter().x-windowWidth/2
                                             ,playerIngame[CurrentP].Pcamera.getCenter().y-windowHeight/2);

       // gameinterface.drawinterface(window,(playerIngame[CurrentP].Pcamera.getCenter().x-windowWidth/2),playerIngame[CurrentP].Pcamera.getCenter().y-windowHeight/2);

       // window.draw(Sdark);

		interfaceingame.back().Qpanel(playerIngame[0].Killcount, playerIngame[0].Deathcount, playerIngame[1].Killcount, playerIngame[1].Deathcount
			, playerIngame[2].Killcount, playerIngame[2].Deathcount, playerIngame[3].Killcount, playerIngame[3].Deathcount,
			playerIngame[4].Killcount, playerIngame[4].Deathcount, playerIngame[CurrentP].Killcount, playerIngame[CurrentP].Deathcount
			, Keyboard::isKeyPressed(Keyboard::Q), window);

		mainmenu.drawQ(window, Keyboard::isKeyPressed(Keyboard::Q), playerIngame[CurrentP].Pcamera.getCenter().x - windowWidth / 2
			, playerIngame[CurrentP].Pcamera.getCenter().y - windowHeight / 2);

		interfaceingame.back().EscTomenu(window, playerIngame[CurrentP].Pcamera.getCenter().x - windowWidth / 2, playerIngame[CurrentP].Pcamera.getCenter().y - windowHeight / 2);
/************ display & frametime ****/

            window.display();
            

/************************************************* out game *********************************************/

    ///////////////// close game


}

        /********************************************** end game *****************************************/



/*************************************************** Result **********************************************/

while (stage == 4){
	Event Result;
		window.clear();
		window.setView(menuview);
		window.draw(bgs3);
		mainmenu.drawresult(window,winorlose);
		interfaceingame.back().result(window);
		window.display();


		while (window.pollEvent(Result)) {

			if (Result.type == Event::Closed) {

				stage = 99;

			}

			if (Result.type == Event::KeyPressed)
			{
				if (Keyboard::isKeyPressed(Keyboard::Escape))
				{
					stage = 5;
					if (!soundButton.getStatus()) {
						soundButton.play();
					}
				//	bbbggg.Playmusic(6, false, 100, true);
				//	bbbggg.Playmusic(5, false, 100, true);
					//mainmenu.clearvalue();
				}

			}

			if ((Result.type == Event::MouseButtonPressed && Mouse::getPosition(window).x > 14 && Mouse::getPosition(window).x < 128 &&
				Mouse::getPosition(window).y > 73 && Mouse::getPosition(window).y < 148)) {
				stage = 5;
				
					if (!soundButton.getStatus()) {
						soundButton.play();
					}
				
			//	bbbggg.Playmusic(6, false, 100, true);
			//	bbbggg.Playmusic(5, false, 100, true);
				//mainmenu.clearvalue();
			}


		}

}

while (stage == 5) {
	Event save;
	string line1,line2,line3;
	stringstream ss,ssgtmin,ssgatsec;
	ssgtmin << ((int)gametime) / 60;
	ssgatsec << ((int)gametime) % 60;
	ss << (((int)gametime / 60) / 10 == 0 ? "0" : "") + ssgtmin.str() + " : " + (((int)gametime % 60) / 10 == 0 ? "0" : "") + ssgatsec.str();
	time_t now;
	now = time(0);
	tm* ltm = localtime(&now);
	cout << (ltm->tm_mday) << (1 + ltm->tm_mon) << (1900 + ltm->tm_year) << endl;
	ofstream WriteFile("data/output/score.txt", ios::app);
	if (WriteFile) {

		line1 += mainmenu.savename() + "\n" + (winorlose? "Result : Win":"Result : lose") +"("+interfaceingame.back().TeamScore.getString()+")"
			+"\n"+"Total playing time "+ss.str();
		line2 += interfaceingame.back().WriteKillDead();
		line3 += interfaceingame.back().WriteScore();

		WriteFile << line1 <<endl;
		WriteFile << "Played on " << (ltm->tm_mday) <<"/"<< (1 + ltm->tm_mon) <<"/"<< (1900 + ltm->tm_year) << endl;
		WriteFile << line2 << endl;
		WriteFile << line3 << endl;
		WriteFile << endl;
	}

	WriteFile.close();

	stage = 0;
	mainmenu.clearvalue();
}

while (stage == 6) {
	Event Leaderbord;
	debugTime = RealTime.restart().asSeconds();


	while (window.pollEvent(Leaderbord)) {
		if (Leaderbord.type == Event::Closed) {
			stage = 99;
		}

		if (Leaderbord.type == Event::KeyPressed)
		{
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				stage = 0;
				mainmenu.Textleader.setPosition(640, 190);
				
					if (!soundButton.getStatus()) {
						soundButton.play();
					}
				
			}

		}

		if ((Leaderbord.type == Event::MouseButtonPressed && Mouse::getPosition(window).x > 14 && Mouse::getPosition(window).x < 128 &&
			Mouse::getPosition(window).y > 73 && Mouse::getPosition(window).y < 148)) {
			stage = 0;
			mainmenu.Textleader.setPosition(640, 190);
			
				if (!soundButton.getStatus()) {
					soundButton.play();
				}
			
		}

		if (Leaderbord.type == Event::MouseWheelScrolled) {
			
			if (mainmenu.Textleader.getPosition().y < 190 - (mainmenu.Textleader.getGlobalBounds().height - 296)) {
				mainmenu.Textleader.setPosition(mainmenu.Textleader.getPosition().x, 190 - (mainmenu.Textleader.getGlobalBounds().height - 296));
			}

			mainmenu.Textleader.move(0, 1200 * Leaderbord.mouseWheelScroll.delta * debugTime);
		}

	}
	cout << mainmenu.Textleader.getGlobalBounds().height << endl;
	window.clear();
	window.draw(bgs3);
	mainmenu.Leaderborad(window);
	window.display();


}

while (stage == 6) {
	Event Leaderbord;
	debugTime = RealTime.restart().asSeconds();


	while (window.pollEvent(Leaderbord)) {
		if (Leaderbord.type == Event::Closed) {
			stage = 99;
		}

		if (Leaderbord.type == Event::KeyPressed)
		{
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				stage = 0;
				mainmenu.Textleader.setPosition(640, 190);

				if (!soundButton.getStatus()) {
					soundButton.play();
				}

			}

		}

		if ((Leaderbord.type == Event::MouseButtonPressed && Mouse::getPosition(window).x > 14 && Mouse::getPosition(window).x < 128 &&
			Mouse::getPosition(window).y > 73 && Mouse::getPosition(window).y < 148)) {
			stage = 0;
			mainmenu.Textleader.setPosition(640, 190);

			if (!soundButton.getStatus()) {
				soundButton.play();
			}

		}

		if (Leaderbord.type == Event::MouseWheelScrolled) {

			if (mainmenu.Textleader.getPosition().y < 190 - (mainmenu.Textleader.getGlobalBounds().height - 296)) {
				mainmenu.Textleader.setPosition(mainmenu.Textleader.getPosition().x, 190 - (mainmenu.Textleader.getGlobalBounds().height - 296));
			}

			mainmenu.Textleader.move(0, 1200 * Leaderbord.mouseWheelScroll.delta * debugTime);
		}

	}
	cout << mainmenu.Textleader.getGlobalBounds().height << endl;
	window.clear();
	window.draw(bgs1);
	mainmenu.Leaderborad(window);
	window.display();


}


while (stage == 7) {
	Event how;



	while (window.pollEvent(how)) {
		if (how.type == Event::Closed) {
			stage = 99;
		}

		if (how.type == Event::KeyPressed)
		{
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				stage = 0;
				mainmenu.Textleader.setPosition(640, 190);

				if (!soundButton.getStatus()) {
					soundButton.play();
				}

			}

		}

		if ((how.type == Event::MouseButtonPressed && Mouse::getPosition(window).x > 14 && Mouse::getPosition(window).x < 128 &&
			Mouse::getPosition(window).y > 73 && Mouse::getPosition(window).y < 148)) {
			stage = 0;
			mainmenu.Textleader.setPosition(640, 190);

			if (!soundButton.getStatus()) {
				soundButton.play();
			}

		}

	}


	window.clear();
	window.draw(bgs3);
	mainmenu.howtoplay(window);
	window.display();


}















        window.clear();

        window.display();

        }

    return 0;
}
