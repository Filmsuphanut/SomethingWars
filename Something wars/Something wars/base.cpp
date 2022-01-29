#include "base.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

base::base(int side)
{

sidec = side;

texbase.loadFromFile("data/images/map/base.png");
Spbase.setTexture(texbase);

boxbase = IntRect(Spbase.getGlobalBounds().width/5,0,
                    Spbase.getGlobalBounds().width/5,Spbase.getGlobalBounds().height);

if(side==0){Spbase.setTextureRect(IntRect(boxbase.left*0,boxbase.top,boxbase.width,boxbase.height));}
if(side==1){Spbase.setTextureRect(IntRect(boxbase.left*0+boxbase.width,boxbase.top,-boxbase.width,boxbase.height));}
Spbase.setScale(0.5f,0.5f);
Hpbar.setSize(Vector2f(320.f,30.f));
Hpbar.setFillColor(Color::Green);
stroke.setSize(Vector2f(320.f,30.f));
stroke.setFillColor(Color::Red);
stroke.setOutlineColor(Color::Black);
stroke.setOutlineThickness(5.0f);
HP = 100;
}

void base::gameresert(){

HP = 100;

}

base::~base()
{
    //dtor
}

void base::setBasePos(float xpos,float ypos){

Spbase.setPosition(xpos,ypos);
Hpbar.setPosition(xpos,ypos-45);
stroke.setPosition(xpos,ypos-45);


}


void base::setBase(RenderWindow &window){

	if (HP < 0) {
		HP = 0;
}

int frame = HP>75? 0:HP>50? 1:HP>25? 2:HP>0? 3:HP<=0? 4:3;

if(sidec==0){Spbase.setTextureRect(IntRect(boxbase.left*(frame),boxbase.top,boxbase.width,boxbase.height));}
if(sidec==1){Spbase.setTextureRect(IntRect(boxbase.left*(frame)+boxbase.width,boxbase.top,-boxbase.width,boxbase.height));}

Hpbar.setSize(Vector2f((HP*320)/100,30));
window.draw(Spbase);
window.draw(stroke);
window.draw(Hpbar);


}
