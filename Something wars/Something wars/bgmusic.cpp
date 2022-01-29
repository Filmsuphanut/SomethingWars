#include "bgmusic.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace std;
using namespace sf;

bgmusic::bgmusic()
{
   BGmainmenu.openFromFile("data/sound/bg/MainmanuSong.wav");
   BG1.openFromFile("data/sound/bg/bg1.wav");
   BG2.openFromFile("data/sound/bg/bg2.wav");
   BG3.openFromFile("data/sound/bg/bg3.wav");
   BG4.openFromFile("data/sound/bg/bg4.wav");
   BGwin.openFromFile("data/sound/win.wav");
   BGlose.openFromFile("data/sound/lose.wav");
}

bgmusic::~bgmusic()
{
    //dtor
}

void bgmusic::Playmusic(int numMu,bool startstop,int MVolume,bool loops){

    if(numMu == 0){Pmu = &BGmainmenu;}
    if(numMu == 1){Pmu = &BG1;}
    if(numMu == 2){Pmu = &BG2;}
    if(numMu == 3){Pmu = &BG3;}
    if(numMu == 4){Pmu = &BG4;}
	if(numMu == 5) { Pmu = &BGwin; }
	if (numMu == 6) { Pmu = &BGlose; }
    (*Pmu).setVolume(MVolume);
	(*Pmu).setLoop(loops);
	

    if(startstop){
      (*Pmu).play();
	  cout << "asdadasd" << endl;
    }else{
       (*Pmu).stop();
    }



}

bool bgmusic::checkplaymusic(int numMu){

    if(numMu == 0){Pmu = &BGmainmenu;}
    if(numMu == 1){Pmu = &BG1;}
    if(numMu == 2){Pmu = &BG2;}
    if(numMu == 3){Pmu = &BG3;}
    if(numMu == 4){Pmu = &BG4;}
	if (numMu == 5) { Pmu = &BGwin; }
	if (numMu == 6) { Pmu = &BGlose; }
    if((*Pmu).getStatus()){
        return 1;
    }else{
        return 0;
    }

}
