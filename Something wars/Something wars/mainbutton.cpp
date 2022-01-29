#include "mainbutton.hpp"
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<cstdlib>
#include<fstream>
#include"charactername.hpp"


using namespace sf;
using namespace std;

charactername Cname;

mainbutton::mainbutton(Font &ff)
{
    //moupos = Mouse::getPosition();



    Tplay.loadFromFile("data/images/mainmenu/play.png");
    Splay.setTexture(Tplay);
    Splay.setPosition(577,192);

    Thow.loadFromFile("data/images/mainmenu/how.png");
    Show.setTexture(Thow);
    Show.setPosition(467,292);

    Tlead.loadFromFile("data/images/mainmenu/lead.png");
    Slead.setTexture(Tlead);
    Slead.setPosition(458,388);

    Tstory.loadFromFile("data/images/mainmenu/story.png");
    Sstory.setTexture(Tstory);
    //Sstory.setPosition(562,486);

    Tex.loadFromFile("data/images/mainmenu/ex.png");
    Sexit.setTexture(Tex);
	Sexit.setPosition(584, 486);
    //Sexit.setPosition(584,580);


    Tplay2.loadFromFile("data/images/mainmenu/play2.png");
    Thow2.loadFromFile("data/images/mainmenu/how2.png");
    Tlead2.loadFromFile("data/images/mainmenu/lead2.png");
    Tstory2.loadFromFile("data/images/mainmenu/story2.png");
    Tex2.loadFromFile("data/images/mainmenu/ex2.png");


    map1.loadFromFile("data/images/mainmenu/map1.png");
    map12.loadFromFile("data/images/mainmenu/map1P.png");
    map2.loadFromFile("data/images/mainmenu/map2.png");
    map22.loadFromFile("data/images/mainmenu/map2P.png");
    map3.loadFromFile("data/images/mainmenu/map3.png");
    map32.loadFromFile("data/images/mainmenu/map3P.png");
    map4.loadFromFile("data/images/mainmenu/map4.png");
    map42.loadFromFile("data/images/mainmenu/map4P.png");
    map5.loadFromFile("data/images/mainmenu/map5.png");
    map52.loadFromFile("data/images/mainmenu/map5P.png");

    Smap1.setTexture(map1);
    Smap2.setTexture(map2);
    Smap3.setTexture(map3);
    Smap4.setTexture(map4);
    Smap5.setTexture(map5);

    Smap1.setPosition(65,190);
    Smap2.setPosition(476,190);
    Smap3.setPosition(887,190);
    Smap4.setPosition(224,446);
    Smap5.setPosition(728,446);

	TexbgselectChar.loadFromFile("data/images/mainmenu/selectchar.png");
	SprbgselectChar.setTexture(TexbgselectChar);
	TSelectC1.loadFromFile("data/images/mainmenu/Char1.png");
	SelectC1.setTexture(TSelectC1);
	TSelectC2.loadFromFile("data/images/mainmenu/Char2.png");
	SelectC2.setTexture(TSelectC2);
	TSelectC3.loadFromFile("data/images/mainmenu/Char3.png");
	SelectC3.setTexture(TSelectC3);

	TSelectC1outline.loadFromFile("data/images/mainmenu/Char1outline.png");
	TSelectC2outline.loadFromFile("data/images/mainmenu/Char2outline.png");
	TSelectC3outline.loadFromFile("data/images/mainmenu/Char3outline.png");

	tttt.setFont(ff);
	tttt.setFillColor(Color::Yellow);
	tttt.setOutlineColor(Color::Blue);
	tttt.setCharacterSize(40);
	tttt.setOutlineThickness(5);
	tttt.setString("Start Game");
	tttt.setOrigin(tttt.getGlobalBounds().width / 2, tttt.getGlobalBounds().height / 2);

	Curser.setSize(Vector2f(5,22));
	Curser.setFillColor(Color::White);

	for (int i = 0; i < 6 ; i++) {
		numchar[i] = 0;

		nameC[i].setFont(ff);
		nameC[i].setFillColor(Color::White);
		nameC[i].setOutlineColor(Color::Black);
		nameC[i].setCharacterSize(18);
		nameC[i].setOutlineThickness(2);
		nameC[i].setString("(RandomCharecter)");
		nameC[i].setOrigin(i > 2 ? nameC[i].getGlobalBounds().width : 0,0);

		nameP[i].setFont(ff);
		nameP[i].setFillColor(Color::White);
		nameP[i].setOutlineColor(Color::Black);
		nameP[i].setCharacterSize(18);
		nameP[i].setOutlineThickness(2);
		nameP[i].setString(" ");
		nameP[i].setOrigin(i > 2 ? nameP[i].getGlobalBounds().width : 0, 0);
	}
	nameP[0].setString("Edit name Here!!");



	/***result**/

	Texwin.loadFromFile("data/images/mainmenu/youwin.png");
	Texlose.loadFromFile("data/images/mainmenu/youlose.png");
	ResutlBG.loadFromFile("data/images/mainmenu/result.png");
	Sprwin.setTexture(Texwin);
	Sprwin.setOrigin(Sprwin.getGlobalBounds().width/2,0);
	Sprlose.setTexture(Texlose);
	Sprlose.setOrigin(Sprlose.getGlobalBounds().width / 2, 0);
	SprResult.setTexture(ResutlBG);
	//SprResult.setPosition(500, 500);

	RecText.setSize(Vector2f(180,28));
	RecText.setFillColor(Color(100, 100, 100, 255));



	/**lead*/

	Texlead.loadFromFile("data/images/mainmenu/leaderboard.png");
	Sprlead.setTexture(Texlead);
	Texlead2.loadFromFile("data/images/mainmenu/leaderboard2.png");
	Sprlead2.setTexture(Texlead2);


	Textleader.setFont(ff);
	Textleader.setFillColor(Color::Black);
	Textleader.setOutlineColor(Color::White);
	Textleader.setOutlineThickness(5);
	Textleader.setCharacterSize(22);
	Textleader.setPosition(640, 190);

	/************how */

	Texhow.loadFromFile("data/images/mainmenu/how to play.png");
	Sprhow.setTexture(Texhow);

 }


mainbutton::~mainbutton()
{
}


void mainbutton::play(){

    if(moupos.x > Splay.getPosition().x && moupos.y > Splay.getPosition().y
    && moupos.x < Splay.getPosition().x+Splay.getLocalBounds().width &&
       moupos.y < Splay.getPosition().y+Splay.getLocalBounds().height){
    Splay.setTexture(Tplay2);
    }
	else if(moupos.x > Show.getPosition().x && moupos.y > Show.getPosition().y
    && moupos.x < Show.getPosition().x+Show.getLocalBounds().width &&
       moupos.y < Show.getPosition().y+Show.getLocalBounds().height){
    Show.setTexture(Thow2);
    }
	
	else if(moupos.x > Slead.getPosition().x && moupos.y > Slead.getPosition().y
    && moupos.x < Slead.getPosition().x+Slead.getLocalBounds().width &&
       moupos.y < Slead.getPosition().y+Slead.getLocalBounds().height){
    Slead.setTexture(Tlead2);
    }
	/*
	else if(moupos.x > Sstory.getPosition().x && moupos.y > Sstory.getPosition().y
    && moupos.x < Sstory.getPosition().x+Sstory.getLocalBounds().width &&
       moupos.y < Sstory.getPosition().y+Sstory.getLocalBounds().height){
    Sstory.setTexture(Tstory2);
    }
	*/
	else if(moupos.x > Sexit.getPosition().x && moupos.y > Sexit.getPosition().y
    && moupos.x < Sexit.getPosition().x+Sexit.getLocalBounds().width &&
       moupos.y < Sexit.getPosition().y+Sexit.getLocalBounds().height){
    Sexit.setTexture(Tex2);
    }else{

    Splay.setTexture(Tplay);
    Show.setTexture(Thow);
    Slead.setTexture(Tlead);
    Sstory.setTexture(Tstory);
    Sexit.setTexture(Tex);

    }


}

void mainbutton::playP(){

    if(moupos.x > Splay.getPosition().x && moupos.y > Splay.getPosition().y
    && moupos.x < Splay.getPosition().x+Splay.getLocalBounds().width &&
       moupos.y < Splay.getPosition().y+Splay.getLocalBounds().height){
    Splay.setTexture(Tplay);
    }

	else if(moupos.x > Show.getPosition().x && moupos.y > Show.getPosition().y
    && moupos.x < Show.getPosition().x+Show.getLocalBounds().width &&
       moupos.y < Show.getPosition().y+Show.getLocalBounds().height){
    Show.setTexture(Thow);
    }
	
	else if(moupos.x > Slead.getPosition().x && moupos.y > Slead.getPosition().y
    && moupos.x < Slead.getPosition().x+Slead.getLocalBounds().width &&
       moupos.y < Slead.getPosition().y+Slead.getLocalBounds().height){
    Slead.setTexture(Tlead);
    }
	/*
	else if(moupos.x > Sstory.getPosition().x && moupos.y > Sstory.getPosition().y
    && moupos.x < Sstory.getPosition().x+Sstory.getLocalBounds().width &&
       moupos.y < Sstory.getPosition().y+Sstory.getLocalBounds().height){
    Sstory.setTexture(Tstory);
    }
	*/
	else if(moupos.x > Sexit.getPosition().x && moupos.y > Sexit.getPosition().y
    && moupos.x < Sexit.getPosition().x+Sexit.getLocalBounds().width &&
       moupos.y < Sexit.getPosition().y+Sexit.getLocalBounds().height){
    Sexit.setTexture(Tex);
    }else{
    Splay.setTexture(Tplay);
    //Show.setTexture(Thow);
    Slead.setTexture(Tlead);
   // Sstory.setTexture(Tstory);
    Sexit.setTexture(Tex);
    }
}
int mainbutton::playR(Sound &soundButton){

    if(moupos.x > Splay.getPosition().x && moupos.y > Splay.getPosition().y
    && moupos.x < Splay.getPosition().x+Splay.getLocalBounds().width &&
       moupos.y < Splay.getPosition().y+Splay.getLocalBounds().height){
    return 1;

    }
	
	else if(moupos.x > Show.getPosition().x && moupos.y > Show.getPosition().y
    && moupos.x < Show.getPosition().x+Show.getLocalBounds().width &&
       moupos.y < Show.getPosition().y+Show.getLocalBounds().height){
    return 7;

    }
	
	else if(moupos.x > Slead.getPosition().x && moupos.y > Slead.getPosition().y
    && moupos.x < Slead.getPosition().x+Slead.getLocalBounds().width &&
       moupos.y < Slead.getPosition().y+Slead.getLocalBounds().height){
    return 6;

    }

	/*
	else if(moupos.x > Sstory.getPosition().x && moupos.y > Sstory.getPosition().y
    && moupos.x < Sstory.getPosition().x+Sstory.getLocalBounds().width &&
       moupos.y < Sstory.getPosition().y+Sstory.getLocalBounds().height){
    return 7;

    }
	*/

	else if(moupos.x > Sexit.getPosition().x && moupos.y > Sexit.getPosition().y
    && moupos.x < Sexit.getPosition().x+Sexit.getLocalBounds().width &&
       moupos.y < Sexit.getPosition().y+Sexit.getLocalBounds().height){
    return 99;
    }else{

        return 0;

    }

}

void mainbutton::drawplay(RenderWindow &window){
    moupos = Mouse::getPosition(window);



window.draw(Splay);
window.draw(Show);
window.draw(Slead);
//window.draw(Sstory);
window.draw(Sexit);
}


void mainbutton::drawselect(RenderWindow &window){

moupos = Mouse::getPosition(window);

window.draw(Smap1);
window.draw(Smap2);
window.draw(Smap3);
window.draw(Smap4);
window.draw(Smap5);

}

void mainbutton::playselect(){

if(moupos.x > Smap1.getPosition().x && moupos.y > Smap1.getPosition().y
   && moupos.x < Smap1.getPosition().x+Smap1.getLocalBounds().width && moupos.y < Smap1.getPosition().y+Smap1.getLocalBounds().height){
    Smap1.setTexture(map12);}
else if(moupos.x > Smap2.getPosition().x && moupos.y > Smap2.getPosition().y
   && moupos.x < Smap2.getPosition().x+Smap2.getLocalBounds().width && moupos.y < Smap2.getPosition().y+Smap2.getLocalBounds().height){
    Smap2.setTexture(map22);}
else if(moupos.x > Smap3.getPosition().x && moupos.y > Smap3.getPosition().y
   && moupos.x < Smap3.getPosition().x+Smap3.getLocalBounds().width && moupos.y < Smap3.getPosition().y+Smap3.getLocalBounds().height){
    Smap3.setTexture(map32);}
else if(moupos.x > Smap4.getPosition().x && moupos.y > Smap4.getPosition().y
   && moupos.x < Smap4.getPosition().x+Smap4.getLocalBounds().width && moupos.y < Smap4.getPosition().y+Smap4.getLocalBounds().height){
    Smap4.setTexture(map42);}
else if(moupos.x > Smap5.getPosition().x && moupos.y > Smap5.getPosition().y
   && moupos.x < Smap5.getPosition().x+Smap5.getLocalBounds().width && moupos.y < Smap5.getPosition().y+Smap5.getLocalBounds().height){
    Smap5.setTexture(map52);}
else{

    Smap1.setTexture(map1);
    Smap2.setTexture(map2);
    Smap3.setTexture(map3);
    Smap4.setTexture(map4);
    Smap5.setTexture(map5);

}

}

int mainbutton::playselectmap(Sound& soundButton){

if(moupos.x > Smap1.getPosition().x && moupos.y > Smap1.getPosition().y
   && moupos.x < Smap1.getPosition().x+Smap1.getLocalBounds().width && moupos.y < Smap1.getPosition().y+Smap1.getLocalBounds().height){
    return 1;

}
else if(moupos.x > Smap2.getPosition().x && moupos.y > Smap2.getPosition().y
   && moupos.x < Smap2.getPosition().x+Smap2.getLocalBounds().width && moupos.y < Smap2.getPosition().y+Smap2.getLocalBounds().height){
    return 2;

}
else if(moupos.x > Smap3.getPosition().x && moupos.y > Smap3.getPosition().y
   && moupos.x < Smap3.getPosition().x+Smap3.getLocalBounds().width && moupos.y < Smap3.getPosition().y+Smap3.getLocalBounds().height){
    return 3;

}
else if(moupos.x > Smap4.getPosition().x && moupos.y > Smap4.getPosition().y
   && moupos.x < Smap4.getPosition().x+Smap4.getLocalBounds().width && moupos.y < Smap4.getPosition().y+Smap4.getLocalBounds().height){
    return 4;

}
else if(moupos.x > Smap5.getPosition().x && moupos.y > Smap5.getPosition().y
   && moupos.x < Smap5.getPosition().x+Smap5.getLocalBounds().width && moupos.y < Smap5.getPosition().y+Smap5.getLocalBounds().height){
    return 5;

}
else{

    return 0;

}

}


void mainbutton::drawselectChar(RenderWindow& window,int &nummap, Sound& soundButton) {

moupos = Mouse::getPosition(window);
//cout << moupos.x << " " << moupos.y << endl;
RecText.setPosition(205,207);
window.draw(SprbgselectChar);
window.draw(RecText);

for (int i = 0; i < 6; i++) {
	nameC[i].setOrigin(i > 2 ? nameC[i].getGlobalBounds().width : 0, 0);
	nameP[i].setOrigin(i > 2 ? nameP[i].getGlobalBounds().width : 0, 0);
	nameC[i].setPosition(i > 2 ? 1087 : 209, i > 2 ? 169 * (i)-507 + 191 + 50 : 169 * (i)+191 + 50);
	nameP[i].setPosition(i > 2 ? 1087 : 209, i > 2 ? 169 * (i)-507 + 191+20 : 169 * (i)+191+20);
	window.draw(nameP[i]);
	window.draw(nameC[i]);
}

if (nameP[4].getString() == ' ' && nameP[1].getString() == ' ' && nameP[2].getString() == ' ' && nameP[3].getString() == ' ' && nameP[5].getString() == ' ') {
	for (int i = 1; i < 6; i++) {
				do {
					nameP[i].setString(Cname.callname(rand() % 100) + "(Bot)");
				} while (nameP[i-1].getString() == nameP[i].getString() || nameP[i - 2].getString() == nameP[i].getString() ||
					nameP[i - 3].getString() == nameP[i].getString() || nameP[i - 4].getString() == nameP[i].getString() ||
					nameP[i - 5].getString() == nameP[i].getString() || nameP[i - 6].getString() == nameP[i].getString()
					|| nameP[i - 7].getString() == nameP[i].getString());
		nameP[i].setOrigin(i > 2 ? nameP[i].getGlobalBounds().width : 0,0);
	}
}

if (moupos.x > RecText.getPosition().x && moupos.x < RecText.getPosition().x + RecText.getGlobalBounds().width &&
	moupos.y > RecText.getPosition().y && moupos.y < RecText.getPosition().y + RecText.getGlobalBounds().height && clickmouse) {
	Editname = true;
	if (!soundButton.getStatus()) {
		soundButton.play();
	}
}else if(clickmouse){
	Editname = false;
}
if (Editname) {
	Time = ClockTime.getElapsedTime().asSeconds();

	if (Time < 0.5) {
		Curser.setFillColor(Color(0, 0, 0, 255));
	}else if (Time > 0.5) {
		Curser.setFillColor(Color(0, 0, 0, 0));
		
	}
	if (Time > 1) {
		Time = ClockTime.restart().asSeconds();
	}
	

	Curser.setPosition(nameP[0].getPosition().x+ nameP[0].getGlobalBounds().width +2, nameP[0].getPosition().y-1);
	window.draw(Curser);

}
else if (!selectgamestart && !Editname) {
	Time = ClockTime.restart().asSeconds();

}


if (startgamemap.empty()) {
	if (nummap == 1) {
		startgamemap.push_back(Smap1);
		startgamemap.back().setTexture(map1);
	}
	else if (nummap == 2) {
		startgamemap.push_back(Smap2);
		startgamemap.back().setTexture(map2);
	}
	else if (nummap == 3) {
		startgamemap.push_back(Smap3);
		startgamemap.back().setTexture(map3);
	}
	else if (nummap == 4) {
		startgamemap.push_back(Smap4);
		startgamemap.back().setTexture(map4);
	}
	else if (nummap == 5) {
		startgamemap.push_back(Smap5);
		startgamemap.back().setTexture(map5);
	}
	startgamemap.back().setPosition(481,439);
	
	tttt.setPosition(startgamemap.back().getPosition().x+startgamemap.back().getGlobalBounds().width/2,
		startgamemap.back().getPosition().y+startgamemap.back().getGlobalBounds().height/2);
}else{
	tttt.setOutlineColor(Color::Blue);
	//startgamemap.back().setColor(Color(255, 255, 255, 255));
	startgamemap.back().setTexture(nummap==1? map1: nummap==2? map2: nummap==3? map3: nummap==4? map4: map5);
	if (moupos.x > startgamemap.back().getPosition().x && moupos.x < startgamemap.back().getPosition().x + startgamemap.back().getGlobalBounds().width &&
		moupos.y > startgamemap.back().getPosition().y && moupos.y < startgamemap.back().getPosition().y + startgamemap.back().getGlobalBounds().height
		&& !selectgamestart && !Editname) {

		tttt.setOutlineColor(Color::Red);
		//startgamemap.back().setColor(Color(200, 0, 0, 255));
		startgamemap.back().setTexture(nummap == 1 ? map12 : nummap == 2 ? map22 : nummap == 3 ? map32 : nummap == 4 ? map42 : map52);
		if (clickmouse) {
			selectgamestart = true;
			Time = ClockTime.restart().asSeconds();
			if (!soundButton.getStatus()) {
				soundButton.play();
			}
		}
	}
	window.draw(startgamemap.back());
	window.draw(tttt);
}



if (SelectChar.empty()) {
	SelectChar.push_back(SelectC1);
	SelectChar.back().setPosition(456,191);
	SelectChar.push_back(SelectC2);
	SelectChar.back().setPosition(588, 191);
	SelectChar.push_back(SelectC3);
	SelectChar.back().setPosition(720, 191);
}else{

/**************************select charector ********************************/
	SelectChar[0].setTexture(TSelectC1);
	SelectChar[1].setTexture(TSelectC2);
	SelectChar[2].setTexture(TSelectC3);
	if (moupos.y > 191 && moupos.y < 191+SelectC1.getGlobalBounds().height && !selectgamestart && !Editname) {
		if (moupos.x > SelectChar[0].getPosition().x && moupos.x < SelectChar[0].getPosition().x+SelectC1.getGlobalBounds().width) {
			SelectChar[0].setTexture(TSelectC1outline);
			if (clickmouse) {
				ShowSelectChar.clear();
				ShowSelectChar.push_back(SelectC1);
				ShowSelectChar.back().setPosition(65, 190);
				numchar[0] = 1;
				nameC[0].setString("Warrior");
				if (!soundButton.getStatus()) {
					soundButton.play();
				}

			}
		}
		if (moupos.x > SelectChar[1].getPosition().x && moupos.x < SelectChar[1].getPosition().x+SelectC1.getGlobalBounds().width) {
			SelectChar[1].setTexture(TSelectC2outline);
			if (clickmouse) {
				ShowSelectChar.clear();
				ShowSelectChar.push_back(SelectC2);
				ShowSelectChar.back().setPosition(65, 190);
				numchar[0] = 2;
				nameC[0].setString("Assassin");
				if (!soundButton.getStatus()) {
					soundButton.play();
				}
			}
		}
		if (moupos.x > SelectChar[2].getPosition().x && moupos.x < SelectChar[2].getPosition().x+SelectC1.getGlobalBounds().width) {
			SelectChar[2].setTexture(TSelectC3outline);
			if (clickmouse) {
				ShowSelectChar.clear();
				ShowSelectChar.push_back(SelectC3);
				ShowSelectChar.back().setPosition(65, 190);
				numchar[0] = 3;
				nameC[0].setString("Wizard");
				if (!soundButton.getStatus()) {
					soundButton.play();
				}
			}
		}
	}
window.draw(SelectChar[0]);
window.draw(SelectChar[1]);
window.draw(SelectChar[2]);
}

if(!ShowSelectChar.empty()) {
	for (int i = 0; i < ShowSelectChar.size(); i++) {
		window.draw(ShowSelectChar[i]);
	}
}

if (selectgamestart && !startgame) {
	Time = ClockTime.getElapsedTime().asSeconds();
	//cout << Time << endl;
	if (Time < 2) {
		for (int i = (numchar[0] == 0 ? 0 : 1); i < 6; i++) {
			ShowSelectChar.push_back(rand() % 3 + 1 == 1 ? SelectC1 : rand() % 3 + 1 == 2 ? SelectC2 : SelectC3);
			ShowSelectChar.back().setPosition(i > 2 ? 1119 : 65, i > 2 ? 169 * (i)-507 + 191 : 169 * (i)+191);
			nameC[i].setString(rand() % 3+1 == 1? "Warrior" : rand() % 3 + 1 == 2 ? "Assassin" : "Wizard");
		}
	}else{
		ShowSelectChar.clear();
		if (numchar[0] != 0){
			ShowSelectChar.push_back(numchar[0] == 1 ? SelectC1 : numchar[0] == 2 ? SelectC2 : SelectC3);
			ShowSelectChar.back().setPosition(65, 190);
		}
		for (int i = (numchar[0] == 0 ? 0 : 1); i < 6; i++) {
			numchar[i] = rand() % 3 + 1;
			ShowSelectChar.push_back(numchar[i] == 1 ? SelectC1 : numchar[i] == 2 ? SelectC2 : SelectC3);
			ShowSelectChar.back().setPosition(i > 2 ? 1119 : 65, i > 2 ? 169 * (i) - 507 + 191 : 169 * (i) + 191);
			startgame = true;
			Time = ClockTime.restart().asSeconds();
			nameC[i].setString(numchar[i] == 1 ? "Warrior" : numchar[i] == 2 ? "Assassin" : "Wizard");
		}
	}
}

if (startgame && !go) {
	Time = ClockTime.getElapsedTime().asSeconds();
	if (Time > 2) {
		go = true;
		Time = ClockTime.restart().asSeconds();
	}

}

}


void mainbutton::clearvalue() {

	for (int i = 0; i < 6; i++) {
		numchar[i] = 0;
		nameC[i].setString("(RandomCharecter)");
	}

	for (int i = 1; i < 6; i++) {
		nameP[i].setString(" ");
	}


	Time = ClockTime.restart().asSeconds();
	SelectChar.clear();
	ShowSelectChar.clear();
	startgamemap.clear();
	selectgamestart = false;
	startgame = false;
	go = false;
	Editname = false;
}

void mainbutton::drawQ(RenderWindow& window, bool Q, float xmove, float ymove) {

	if (Q) {
		for (int i = 0; i < 6; i++) {

			ShowSelectChar[i].setPosition(i > 2 ? 1119+xmove-100 : 65 + xmove + 100, i > 2 ? 169 * (i)-507 + 191+ymove : 169 * (i)+191+ymove);
			nameC[i].setPosition(i > 2 ? 1087 + xmove-100 : 209 + xmove + 100, i > 2 ? 169 * (i)-507 + 191 + 50 +ymove: 169 * (i)+191 + 50 + ymove);
			nameP[i].setPosition(i > 2 ? 1087 + xmove-100 : 209 + xmove + 100, i > 2 ? 169 * (i)-507 + 191 + 20 + ymove : 169 * (i)+191 + 20 + ymove);
			window.draw(nameP[i]);
			window.draw(nameC[i]);
			window.draw(ShowSelectChar[i]);
		}
	}

}

void mainbutton::drawresult(RenderWindow& window,bool &chk) {

	window.draw(SprResult);
	if (chk) {
		Sprwin.setPosition(640,19);
		window.draw(Sprwin);
	}
	else {
		Sprlose.setPosition(640, 19);
		window.draw(Sprlose);
	}
	
	for (int i = 0; i < 6; i++) {

		ShowSelectChar[i].setPosition(i > 2 ? 1119-100  : 65 + 100, i > 2 ? 169 * (i)-507 + 191  : 169 * (i)+191 );
		nameC[i].setPosition(i > 2 ? 1087-100  :209 + 100, i > 2 ? 169 * (i)-507 + 191 + 50  :i==0?  191+30 :169 * (i)+191 + 50 );
		nameP[i].setPosition(i > 2 ? 1087-100  : 209 + 100, i > 2 ? 169 * (i)-507 + 191 + 20  :i==0? 191 : 169 * (i)+191 + 20 );
		window.draw(nameP[i]);
		window.draw(nameC[i]);
		window.draw(ShowSelectChar[i]);
	}

}

String mainbutton::savename() {

	return nameP[0].getString()+(numchar[0]==1? "(Warrior)" : numchar[0] == 2 ? "(Assassin)" : "(Wizard)");

}

void mainbutton::Leaderborad(RenderWindow& window) {
	ifstream Readfile("data/output/score.txt");
	string line,textfile;
	while (getline(Readfile,line))
	{
		textfile += line+"\n";
	}
	
	Textleader.setString(textfile);
	Textleader.setOrigin(Textleader.getGlobalBounds().width/2,0);

	

	window.draw(Sprlead2);
	window.draw(Textleader);
	window.draw(Sprlead);
}


void mainbutton::howtoplay(RenderWindow& window) {


	window.draw(Sprhow);


}