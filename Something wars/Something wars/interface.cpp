#include "interface.hpp"
#include<SFML/Graphics.hpp>
#include<iostream>
#include<sstream>
#include <iomanip>
using namespace std;
using namespace sf;

interface::interface(int wChar)
{

    /******************************** interface ************************/
    Char = wChar;

    ff.loadFromFile("data/font/segoeprb.ttf");

    setText(Scd1,50);
    setText(Scd2,50);
    setText(Hitpoint,25);
    setText(Timedead,65);
    setText(TextKill,20);
    setText(TextDead,20);
    setText(TDFB1,25);
    setText(TDFB2,25);
    setText(TDEB1,25);
    setText(TDEB2,25);
    setText(TDEB3,25);
    setText(TextGametime,20);
	setText(QEB1, 18);
	setText(QEB2, 18);
	setText(QEB3, 18);
	setText(QFB1, 18);
	setText(QFB2, 18);
	setText(QP, 18);
	setText(TeamScore, 40);
	setText(score, 18);
	setText(backYes, 30);
	setText(backNo, 30);
	setText(backText,30);
	setText(TextDamage1, 10);
	setText(TextDamage2, 10);
	setText(TextDamage3, 10);

    Tinterface.loadFromFile("data/images/interface.png");
    Sinterface.setTexture(Tinterface);
    HPbar.setSize(Vector2f(419,37));
    HPbar.setFillColor(Color::Green);
    HPbarFB1.setSize(Vector2f(220,20));
    HPbarFB1.setFillColor(Color::Green);
    HPbarFB2.setSize(Vector2f(220,20));
    HPbarFB2.setFillColor(Color::Green);

switch(Char){
    case 1 :
        facep.loadFromFile("data/images/char/icon/C1.png");
        J.loadFromFile("data/images/char/icon/C1skill1.png");
        K.loadFromFile("data/images/char/icon/C1skill2.png");
        L.loadFromFile("data/images/char/icon/C1skill3.png");
        P.loadFromFile("data/images/char/icon/C1skillP.png");
		detailN.loadFromFile("data/images/char/icon/Detailskill1.png");
		detail2.loadFromFile("data/images/char/icon/DetailC1skill2.png");
		detail3.loadFromFile("data/images/char/icon/DetailC1skill3.png");
		detailP.loadFromFile("data/images/char/icon/DetailC1skillP.png");
    break;
    case 2 :
        facep.loadFromFile("data/images/char/icon/C2.png");
        J.loadFromFile("data/images/char/icon/C2skill1.png");
        K.loadFromFile("data/images/char/icon/C2skill2.png");
        L.loadFromFile("data/images/char/icon/C2skill3.png");
        P.loadFromFile("data/images/char/icon/C2skillP.png");
		detailN.loadFromFile("data/images/char/icon/Detailskill1.png");
		detail2.loadFromFile("data/images/char/icon/DetailC2skill2.png");
		detail3.loadFromFile("data/images/char/icon/DetailC2skill3.png");
		detailP.loadFromFile("data/images/char/icon/DetailC2skillP.png");
    break;
    case 3 :
        facep.loadFromFile("data/images/char/icon/C3.png");
        J.loadFromFile("data/images/char/icon/C3skill1.png");
        K.loadFromFile("data/images/char/icon/C3skill2.png");
        L.loadFromFile("data/images/char/icon/C3skill3.png");
        P.loadFromFile("data/images/char/icon/C3skillP.png");
		detailN.loadFromFile("data/images/char/icon/Detailskill1.png");
		detail2.loadFromFile("data/images/char/icon/DetailC3skill2.png");
		detail3.loadFromFile("data/images/char/icon/DetailC3skill3.png");
		detailP.loadFromFile("data/images/char/icon/DetailC3skillP.png");
    break;
}

    SJ.setTexture(J);
    SK.setTexture(K);
    SL.setTexture(L);
    SP.setTexture(P);
    Face.setTexture(facep);
	SdetailN.setTexture(detailN);
	Sdetail2.setTexture(detail2);
	Sdetail3.setTexture(detail3);
	SdetailP.setTexture(detailP);

	TexQpanel.loadFromFile("data/images/mainmenu/Qpanel.png");
	SprQpanel.setTexture(TexQpanel);
	SprQpanel.setColor(Color(255,255,255,150));


	/**************************************************/

	TexObjective.loadFromFile("data/images/map/objctive.png");
	SprObjctive.setTexture(TexObjective);

	Twin.loadFromFile("data/images/mainmenu/youwin.png");
	Tlose.loadFromFile("data/images/mainmenu/youlose.png");

	Sprlose.setTexture(Tlose);
	Sprlose.setOrigin(Sprlose.getGlobalBounds().width/2, Sprlose.getGlobalBounds().height / 2);
	Sprwin.setTexture(Twin);
	Sprwin.setOrigin(Sprwin.getGlobalBounds().width / 2, Sprwin.getGlobalBounds().height / 2);

	backYes.setString("Yes");
	backYes.setOrigin(backYes.getGlobalBounds().width / 2, 0);
	backNo.setString("No");
	backNo.setOrigin(backNo.getGlobalBounds().width / 2, 0);
	backBox.setSize(Vector2f(510,100));
	backBox.setFillColor(Color::Yellow);
	backBox.setOutlineColor(Color::Blue);
	backBox.setOutlineThickness(5);
	backBox.setOrigin(backBox.getGlobalBounds().width / 2, backBox.getGlobalBounds().height / 2);
	backText.setString("Do you want to surrender?");
	backText.setOrigin(backText.getGlobalBounds().width / 2, backText.getGlobalBounds().height);

	BuffDeath.loadFromFile("data/sound/death.wav");
	BuffRespawn.loadFromFile("data/sound/respawn.wav");
	soundDeath.setBuffer(BuffDeath);
	soundDeath.setVolume(100);
	soundRespawn.setBuffer(BuffRespawn);
	soundRespawn.setVolume(100);
}

interface::~interface()
{
    //dtor
}

void interface::setText(Text &tt,int ssize){
    tt.setFont(ff);
    tt.setCharacterSize(ssize);
    tt.setFillColor(Color::White);
    tt.setOutlineColor(Color::Black);
    tt.setOutlineThickness(2);
}

void interface::oneValue(int CharFbot1,int CharFbot2,int CharEbot1,int CharEbot2,int CharEbot3){

    CharFB1=CharFbot1;
    loadFileTexAndSetSpr(CharFB1,SprCharFB1,TexCharFB1);
    CharFB2=CharFbot2;
    loadFileTexAndSetSpr(CharFB2,SprCharFB2,TexCharFB2);
    CharEB1=CharEbot1;
    loadFileTexAndSetSpr(CharEB1,SprCharEB1,TexCharEB1);
    CharEB2=CharEbot2;
    loadFileTexAndSetSpr(CharEB2,SprCharEB2,TexCharEB2);
    CharEB3=CharEbot3;
    loadFileTexAndSetSpr(CharEB3,SprCharEB3,TexCharEB3);

}

void interface::loadFileTexAndSetSpr(int &VChar,Sprite &spr,Texture &tex){

switch(VChar){
    case 1 :
        tex.loadFromFile("data/images/char/icon/C1.png");
        spr.setTexture(tex);
        spr.setScale(0.491,0.491);
    break;
    case 2 :
        tex.loadFromFile("data/images/char/icon/C2.png");
        spr.setTexture(tex);
        spr.setScale(0.491,0.491);
    break;
    case 3 :
        tex.loadFromFile("data/images/char/icon/C3.png");
        spr.setTexture(tex);
        spr.setScale(0.491,0.491);
    break;
}

}



void interface::setting(float xmove,float ymove){

    Face.setPosition(26+xmove,28+ymove);
    SJ.setPosition(173+xmove,84+ymove);
    SK.setPosition(285+xmove,84+ymove);
    SL.setPosition(396+xmove,84+ymove);
    SP.setPosition(508+xmove,84+ymove);
    HPbar.setPosition(173+xmove,28+ymove);
    HPbarFB1.setPosition(93+xmove,185+ymove);
    HPbarFB2.setPosition(93+xmove,250+ymove);
    Hitpoint.setPosition(325+xmove,32+ymove);

    SprCharFB1.setPosition(26+xmove,185+ymove);
    SprCharFB2.setPosition(26+xmove,251+ymove);
    SprCharEB1.setPosition(1037+xmove,18+ymove);
    SprCharEB2.setPosition(1115+xmove,18+ymove);
    SprCharEB3.setPosition(1193+xmove,18+ymove);

	SdetailN.setPosition(173 + xmove, 84 + ymove);
	Sdetail2.setPosition(285 + xmove, 84 + ymove);
	Sdetail3.setPosition(396 + xmove, 84 + ymove);
	SdetailP.setPosition(508 + xmove, 84 + ymove);

	TextDamage1.setPosition(70+xmove+173,90+ymove+83);
	TextDamage2.setPosition((Char==1? 115:Char==2? 21 : 125) + xmove+285,(Char==2? 115:90)+ymove+84);
	TextDamage3.setPosition((Char == 1 ? 118 : Char == 2 ? 127 : 68) + xmove + 396, (Char == 2 ? 141 : Char==3? 115:91) + ymove+83);


	SprQpanel.setPosition(xmove,ymove);
	QP.setPosition(100+209+xmove, 241+30 + ymove);
	QFB1.setPosition(100+209 + xmove, 410+30 + ymove);
	QFB2.setPosition(100+209 + xmove, 579+30 + ymove);
	QEB1.setPosition(1087-100 + xmove, 241+30 + ymove);
	QEB2.setPosition(1087-100 + xmove, 410+30 + ymove);
	QEB3.setPosition(1087-100 + xmove, 579+30 + ymove);
	TeamScore.setPosition(640+xmove,191+ymove);

	SprObjctive.setPosition(xmove, ymove);

	backYes.setPosition(600+xmove,ymove+360);
	backNo.setPosition(680+xmove, ymove+360);
	backBox.setPosition(640 + xmove, 360 + ymove);
	backText.setPosition(640 + xmove, 350 + ymove);
}

void interface::drawinterface(RenderWindow &window,float xpos,float ypos, int damage1, int damage2, int damage3,bool normalatt,float cd1,float cd2,float HP,float maxhp,float TimeDead
                           ,float Damagenor,float Damages1,float Damages2,int Level,int kill,int death,double &gametime){

stringstream maxHit,hp,sscd1,sscd2,td,ssgtmin,ssgatsec,ssTkill,ssTdead,Damage1,Damage2,Damage3;
hp<< (HP<0? 0:(int)HP);
maxHit<<maxhp;
sscd1<<(int)cd1+1;
sscd2<<(int)cd2+1;
td<<(int)TimeDead+1;
ssgtmin<<((int)gametime)/60;
ssgatsec<<((int)gametime)%60;
ssTdead<<death;
ssTkill<<kill;
ClassLevel = Level;
Damage1 << damage1;
Damage2 << (int)(Char==1? damage2*0.07 : Char==3? damage2 * 0.3: damage2 * 1 );
Damage3 << (int)(Char==1? damage3*0.25 :Char==2? damage3*0.3 : damage3*0.08);

    setting(xpos,ypos);
    HPbar.setSize(Vector2f(419*(HP/maxhp),37));
    Hitpoint.setString(hp.str()+'/'+maxHit.str());
    Scd1.setString(sscd1.str());
    Scd2.setString(sscd2.str());
    Timedead.setString(td.str());
    Sinterface.setPosition(xpos,ypos);
    Scd1.setPosition(305+xpos,90+ypos);
    Scd2.setPosition((int)cd2/9==0? 420+xpos:400+xpos,90+ypos);
    Timedead.setPosition((int)TimeDead/9==0? 55+xpos:35+xpos,35+ypos);

    TextGametime.setString((((int)gametime/60)/10==0? "0":"")+ssgtmin.str()+" : "+(((int)gametime%60)/10==0? "0":"")+ssgatsec.str());
    TextGametime.setPosition(687+xpos,25+ypos);
    TextKill.setString("Kill : "+ssTkill.str());
    TextKill.setPosition(687+xpos,74+ypos);
    TextDead.setString("Death : "+ssTdead.str());
    TextDead.setPosition(687+xpos,122+ypos);

	TextDamage1.setString(Damage1.str());
	TextDamage2.setString(Damage2.str());
	TextDamage3.setString(Damage3.str());

    window.draw(Sinterface);
    window.draw(Face);
    window.draw(SJ);
    window.draw(SK);
    window.draw(SL);
    window.draw(SP);

    window.draw(TextGametime);
    window.draw(TextDead);
    window.draw(TextKill);

    if(cd2<=0 || Level >=4){
        SL.setColor(Color(255,255,255,255));
    }
      if(cd1<=0 || Level >= 2){
        SK.setColor(Color(255,255,255,255));
    }

    if(cd1>0){
        SK.setColor(Color(180,180,180,255));
        window.draw(Scd1);
    }

    if(cd2>0){
        SL.setColor(Color(180,180,180,255));
        window.draw(Scd2);
    }

    if(Level < 2){SK.setColor(Color(80,80,80,255));}
    if(Level < 4){SL.setColor(Color(80,80,80,255));}
	

    if(normalatt){
        SJ.setColor(Color(180,180,180,255));
    }else{
        SJ.setColor(Color(255,255,255,255));
    }

    if(HP>0){
        window.draw(HPbar);
        Face.setColor(Color(255,255,255,255));
		if (Level == 15) { SP.setColor(Color(255, 255, 255, 255)); }else if(Level < 15) { SP.setColor(Color(80, 80, 80, 255)); }
    }else{
        window.draw(Timedead);
        Face.setColor(Color(255,50,50,255));
        SK.setColor(Color(255,50,50,255));
        SL.setColor(Color(255,50,50,255));
        SJ.setColor(Color(255,50,50,255));
        SP.setColor(Color(255,50,50,255));
    }
        window.draw(Hitpoint);

		if (TimeDead <= 2 && TimeDead > 0) {
			if (!soundRespawn.getStatus()) {
				soundRespawn.play();
			}
		}

		if (!soundDeath.getStatus() && TimeDead >= (+2 + Level)) {
			soundDeath.play();
		}

		if (gametime < 5) {
			window.draw(SprObjctive);
		}

}



void interface::elsedatafloat(RenderWindow &window,float TimedeadFbot1,float TimedeadFbot2,float TimedeadEbot1
                           ,float TimedeadEbot2,float TimedeadEbot3
                           ,float HPFbot1,float maxHPFbot1,float HPFbot2,float maxHPFbot2,float xpos,float ypos){
	Vector2i mou = Mouse::getPosition(window);
    stringstream sstdfb1,sstdfb2,sstdeb1,sstdeb2,sstdeb3;
    sstdfb1<<(int)TimedeadFbot1+1;
    sstdfb2<<(int)TimedeadFbot2+1;
    sstdeb1<<(int)TimedeadEbot1+1;
    sstdeb2<<(int)TimedeadEbot2+1;
    sstdeb3<<(int)TimedeadEbot3+1;

    window.draw(SprCharFB1);
    window.draw(SprCharFB2);
    window.draw(SprCharEB1);
    window.draw(SprCharEB2);
    window.draw(SprCharEB3);
    TDFB1.setPosition((int)TimedeadFbot1/9==0? 43+xpos:35+xpos,195+ypos);
    TDFB2.setPosition((int)TimedeadFbot2/9==0? 43+xpos:35+xpos,260+ypos);
    TDEB1.setPosition((int)TimedeadEbot1/9==0? 1050+xpos:1045+xpos,26+ypos);
    TDEB2.setPosition((int)TimedeadEbot2/9==0? 1131+xpos:1126+xpos,26+ypos);
    TDEB3.setPosition((int)TimedeadEbot3/9==0? 1209+xpos:1204+xpos,26+ypos);

    if(TimedeadEbot1 <=0 || TimedeadEbot2 <=0 || TimedeadEbot3 <=0 || TimedeadFbot1 <=0 || TimedeadFbot2 <=0){
        SprCharEB1.setColor(Color(255,255,255,255));
        SprCharFB1.setColor(Color(255,255,255,255));
        SprCharEB2.setColor(Color(255,255,255,255));
        SprCharEB3.setColor(Color(255,255,255,255));
        SprCharFB2.setColor(Color(255,255,255,255));
    }

    if(TimedeadFbot1 > 0){
        TDFB1.setString(sstdfb1.str());
        window.draw(TDFB1);
        SprCharFB1.setColor(Color(255,50,50,255));
    }else{
        window.draw(HPbarFB1);
        HPbarFB1.setSize(Vector2f(220*(HPFbot1/maxHPFbot1),19));
    }
    if(TimedeadFbot2 > 0){
        TDFB2.setString(sstdfb2.str());
        window.draw(TDFB2);
        SprCharFB2.setColor(Color(255,50,50,255));
    }else{
        window.draw(HPbarFB2);
        HPbarFB2.setSize(Vector2f(220*(HPFbot2/maxHPFbot2),19));
    }
    if(TimedeadEbot1 > 0){
        TDEB1.setString(sstdeb1.str());
        window.draw(TDEB1);
         SprCharEB1.setColor(Color(255,50,50,255));
    }
    if(TimedeadEbot2 > 0){
        TDEB2.setString(sstdeb2.str());
        window.draw(TDEB2);
         SprCharEB2.setColor(Color(255,50,50,255));
    }
    if(TimedeadEbot3 > 0){
        TDEB3.setString(sstdeb3.str());
        window.draw(TDEB3);
         SprCharEB3.setColor(Color(255,50,50,255));
    }

	if (mou.x > SJ.getPosition().x - xpos && mou.x < (SJ.getPosition().x + SJ.getGlobalBounds().width) - xpos &&
		mou.y > SJ.getPosition().y - ypos && mou.y < (SJ.getPosition().y + SJ.getGlobalBounds().height) - ypos) {
		
		window.draw(SdetailN);
		window.draw(TextDamage1);
	}

	if (mou.x > SK.getPosition().x - xpos && mou.x < (SK.getPosition().x + SK.getGlobalBounds().width) - xpos &&
		mou.y > SK.getPosition().y - ypos && mou.y < (SK.getPosition().y + SK.getGlobalBounds().height) - ypos && ClassLevel>=2) {
		window.draw(Sdetail2);
		window.draw(TextDamage2);
	}

	if (mou.x > SL.getPosition().x - xpos && mou.x < (SL.getPosition().x + SL.getGlobalBounds().width) - xpos &&
		mou.y > SL.getPosition().y - ypos && mou.y < (SL.getPosition().y + SL.getGlobalBounds().height) - ypos && ClassLevel >= 4) {
		
		window.draw(Sdetail3);
		window.draw(TextDamage3);
	}

	if (mou.x > SP.getPosition().x - xpos && mou.x < (SP.getPosition().x + SP.getGlobalBounds().width) - xpos &&
		mou.y > SP.getPosition().y - ypos && mou.y < (SP.getPosition().y + SP.getGlobalBounds().height) - ypos && ClassLevel == 15) {

		window.draw(SdetailP);
	}



	if (Endgame == 1) {

		Sprwin.setPosition(640 + xpos, 360 + ypos);
		window.draw(Sprwin);

	}
	if (Endgame == 2) {
		Sprlose.setPosition(640 + xpos, 360 + ypos);
		window.draw(Sprlose);

	}

}

void interface::Qpanel(int killcountFB1, int deadcountFB1, int killcountFB2, int deadcountFB2,
	int killcountEB1, int deadcountEB1, int killcountEB2, int deadcountEB2,
	int killcountEB3, int deadcountEB3,int playerkillcount,int playerdeadcount,bool Q,RenderWindow &window){
	stringstream KFB1, DFB1, KFB2, DFB2, KEB1, DEB1, KEB2, DEB2, KEB3, DEB3,KP,DP,Teamleftsum,Teamrightsum,scoresum;
	KFB1 << killcountFB1;
	DFB1 << deadcountFB1;
	KFB2 << killcountFB2;
	DFB2 << deadcountFB2;
	KEB1 << killcountEB1;
	DEB1 << deadcountEB1;
	KEB2 << killcountEB2;
	DEB2 << deadcountEB2;
	KEB3 << killcountEB3;
	DEB3 << deadcountEB3;
	KP << playerkillcount;
	DP << playerdeadcount;
	Teamleftsum << (deadcountEB1 + deadcountEB2 + deadcountEB3);
	Teamrightsum << (deadcountFB1 + deadcountFB2 + playerdeadcount);
	scoresum << (200 * playerkillcount / (playerdeadcount + 1));

	QP.setString("Kill : "+KP.str()+" Dead : "+DP.str());
	QFB1.setString("Kill : " + KFB1.str() + " Dead : " + DFB1.str());
	QFB2.setString("Kill : " + KFB2.str() + " Dead : " + DFB2.str());

	QEB1.setString("Kill : " + KEB1.str() + " Dead : " + DEB1.str());
	QEB2.setString("Kill : " + KEB2.str() + " Dead : " + DEB2.str());
	QEB3.setString("Kill : " + KEB3.str() + " Dead : " + DEB3.str());
	QEB1.setOrigin(QEB1.getGlobalBounds().width,0);
	QEB2.setOrigin(QEB2.getGlobalBounds().width, 0);
	QEB3.setOrigin(QEB3.getGlobalBounds().width, 0);

	TeamScore.setString(Teamleftsum.str()+" : "+ Teamrightsum.str());
	TeamScore.setOrigin(TeamScore.getGlobalBounds().width/2, 0);
	score.setString("Score : "+ scoresum.str());

	if (Q) {
		window.draw(SprQpanel);
		window.draw(QP);
		window.draw(QFB1);
		window.draw(QFB2);
		window.draw(QEB1);
		window.draw(QEB2);
		window.draw(QEB3);
		window.draw(TeamScore);
	}


}

void interface::result(RenderWindow& window) {

	TeamScore.setPosition(640, 191);
	QP.setPosition(209 + 100, 241 + 10);
	score.setPosition(209 + 100, 241+40);
	QFB1.setPosition(209+100, 410+30);
	QFB2.setPosition(209+100, 579+30);
	QEB1.setPosition(1087-100, 241+30);
	QEB2.setPosition(1087-100, 410+30);
	QEB3.setPosition(1087-100, 579+30);

		window.draw(QP);
		window.draw(TeamScore);
		window.draw(score);
		window.draw(QFB1);
		window.draw(QFB2);
		window.draw(QEB1);
		window.draw(QEB2);
		window.draw(QEB3);

}

String interface::WriteKillDead() {

	return QP.getString();
	
}
String interface::WriteScore() {

	return score.getString();

}

void interface::EscTomenu(RenderWindow &window,float xpos,float ypos) {

 mouse = Mouse::getPosition(window);


	//cout << backYes.getPosition().y- ypos << " "<< backYes.getPosition().y + backYes.getGlobalBounds().height- ypos <<" "<<mouse.y<<endl;
	if (ESC) {

		if (mouse.x < backYes.getPosition().x + backYes.getGlobalBounds().width / 2-xpos && mouse.x > backYes.getPosition().x - backYes.getGlobalBounds().width / 2-xpos
			&& mouse.y < backYes.getPosition().y-ypos + backYes.getGlobalBounds().height && mouse.y > backYes.getPosition().y- ypos) {
			backYes.setFillColor(Color::Blue);


			if (clickmouse) {
				surrender = true;
				ESC = false;
			}

		}
		else {
			backYes.setFillColor(Color::White);
		}

		if (mouse.x < backNo.getPosition().x + backNo.getGlobalBounds().width / 2 - xpos && mouse.x > backNo.getPosition().x - backNo.getGlobalBounds().width / 2 - xpos
			&& mouse.y < backNo.getPosition().y - ypos + backNo.getGlobalBounds().height && mouse.y > backNo.getPosition().y - ypos) {
			backNo.setFillColor(Color::Blue);

			if (clickmouse) {
				ESC = false;
			}
		}
		else {
			backNo.setFillColor(Color::White);
		}


		window.draw(backBox);
		window.draw(backYes);
		window.draw(backNo);
		window.draw(backText);
	}
}
