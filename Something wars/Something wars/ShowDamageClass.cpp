#include "ShowDamageClass.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <iomanip>
#include <sstream>

using namespace sf;
using namespace std;

ShowDamageClass::ShowDamageClass(Font &ff,int chk)
{
    chkdamage = chk;
    showDamage.setFont(ff);
    showDamage.setCharacterSize(35);
   // showDamage.setFillColor(Color::Red);
   showDamage.setFillColor(Color(255,chkdamage==1? 255:0,0));
   // showDamage.setOutlineColor(chkdamage==1? (Color::Yellow):(Color::Red));

    showDamage.setOutlineColor(chkdamage==1? (Color::Black):(Color::Black));
    showDamage.setOutlineThickness(0.5);
}

void ShowDamageClass::updateShowdamage(RenderWindow &window,double &debugTime){
    texttimestamp += texttimestamp*debugTime;

	cout << texttimestamp << endl;
    showDamage.move(0,-100*debugTime);

    if(texttimestamp >= 2){
        showDamage.setFillColor(Color(255,chkdamage==1? 255:0,0,((float)(maxtexttimestamp-texttimestamp)/1.2)*255));
    }
//    cout<<(maxtexttimestamp-texttimestamp)/1000)<<endl;
    if(texttimestamp > maxtexttimestamp){
        destroy = true;
    }

window.draw(showDamage);
}

void ShowDamageClass::InputTextDamage(int damage){
stringstream ss;
ss<<damage;
showDamage.setString((chkdamage==2? "-":"")+ss.str());

}



ShowDamageClass::~ShowDamageClass()
{
    //dtor
}
