#include<SFML/Graphics.hpp>
#include<iostream>
#include<cmath>
#include "algorithmbot.hpp"
#include<cstdlib>

using namespace sf;
using namespace std;


algorithmbot::algorithmbot(int selectchar)
{
    Char = selectchar ;
    RplayerWidth = (Char==1? 67.5:Char==2? 47:40.5);
    Disatt = Char==1? 70:Char==2? 80:Char==3? 200:0;
	tt = 1;
}

algorithmbot::~algorithmbot()
{
    //dtor
}

void algorithmbot::updateData(int Endgame,int Vside,float enemy0xpos,float enemy0ypos
        ,float enemy1xpos,float enemy1ypos,float enemy2xpos,float enemy2ypos,bool Viscollide,bool Vstunned
        ,float Vxpos,float Vypos,double Vcd1,double Vcd2,bool right,double Vcreepxpos,double Venemycreepxpos
        ,float VenemyHP,float VenemyHP1,float VenemyHP2,float VmyHP,double &debugTime){
    xpos = Vxpos;
    ypos = Vypos;
    sideL = !Vside;
    isRight = right;
    cd1 = Vcd1;
    cd2 = Vcd2;
    creepxpos = Vcreepxpos;
    enemycreepxpos = Venemycreepxpos;
    //for(int i = 0 ; i<3 ; i++){
    enemyXpos[0] = enemy0xpos;
    enemyYpos[0] = enemy0ypos;
    enemyXpos[1] = enemy1xpos;
    enemyYpos[1] = enemy1ypos;
    enemyXpos[2] = enemy2xpos;
    enemyYpos[2] = enemy2ypos;
    myHP = VmyHP;

    enemyHP[0] = VenemyHP;
    enemyHP[1] = VenemyHP1;
    enemyHP[2] = VenemyHP2;
   // }

    //enemyXpos[1] = enemy1xpos;
//    enemyYpos[1] = enemy1ypos;
  //  enemyXpos[2] = enemy2xpos;
    //enemyYpos[2] = enemy2ypos;
    iscollide = Viscollide;
    stunned = Vstunned;

  // if(!sideL){ Brain();}
    //Brain();
   // if(Char == 1){cout<<checkenemyinyourarea()<<" "<<checkenemyattackinyourarea()<<endl;}
    tt = tt*debugTime+tt;
	//cout << tt << endl;

   if(tt >= 125 && Endgame == 0){
    leftwalk = thinkleftwalk();
    rightwalk = thinkrightwalk();
    jump = thinkjump();


    useskillJ = (rand()%3)==0? thinkuseJ():0;
    useskillK = (rand()%3)==1? thinkuseK():0;
    useskillL = (rand()%3)==2? thinkuseL():0;
    tt = 1500;
    //cout<<useskillJ<<" "<<useskillK<<" "<<useskillL<<endl;
   }
   else {
	   leftwalk = 0;
	   rightwalk =0;
	   jump = 0;


	   useskillJ = 0;
	   useskillK = 0;
	   useskillL = 0;
	   
   }
}

int algorithmbot::switchA(){

if(leftwalk){
    return 1;
}else{
    return 0;
}

}


int algorithmbot::switchD(){

if(rightwalk){
    return 1;
}else{
    return 0;
}

}


int algorithmbot::switchW(){

if(!stunned && jump){
    return 1;
}else{
    return 0;
}

}


bool algorithmbot::switchJ(){

if(!stunned && useskillJ){
    return 1;
}else{
    return 0;
}


}

bool algorithmbot::switchK(){

if(!stunned && useskillK){
    return 1;
}else{
    return 0;
}

}

bool algorithmbot::switchL(){

if(!stunned && useskillL){
    return 1;
}else{
    return 0;
}

}




bool algorithmbot::thinkleftwalk(){

if(checkenemyattackinyourarea() != 0){
    //return rand()%2;
    return 0;
}else if(checkenemyinyourarea() == 2 && checkenemyinbackyourarea() == 0){//
    return 1;

}else if(checkenemyinbackyourarea() == 1 && checkenemyinyourarea() == 0){// && checkenemyinyourarea() == 0 
    return 1;
/*
}else if(checkenemybackcreep() == 1 && creepxpos != 0 && creepxpos != 3840 && checkenemyinyourarea() != 1 && checkenemyinbackyourarea() != 2 ){
    return 1;
*/

}else if(checkenemyinyourarea() == 0 && checkmycreep() == -1 && (creepxpos != 0 && creepxpos != 3840) && checkenemyinbackyourarea() == 0){
    return 1;


}else if(checkmycreep() == 2  && checkenemyinbackyourarea() == 0 && checkenemyinyourarea() == 0){
    return 1;
}else if(checkenemycreep() == 2  && checkenemyinbackyourarea() == 0 && checkenemyinyourarea() == 0){
    return 0;

}else if(checkenemyinyourarea() == 0 && checkenemyinbackyourarea() == 0){
    if(!sideL && creepxpos == 3840 ){
        return 1;
    }else{
        return 0;
    }
/*
}else if(checkmycreep() == 22){
    return 1;
*/



}else if(creepxpos == 0 || creepxpos == 1280*3){
    return 0;


}else{
    return 0;
}


}
//มีบัคอยู่ 1 จุดน๊ะ แถวๆนี้แหละ

bool algorithmbot::thinkrightwalk(){


if(checkenemyattackinyourarea() != 0){
    //return rand()%2;
    return 0;
}else if(checkenemyinyourarea() == 1 ){
    return 1;

}else if(checkenemyinbackyourarea() == 2){
    return 1;
/*
}else if(checkenemybackcreep() == 2 &&  creepxpos != 0 && creepxpos != 3840 && checkenemyinyourarea() != 2 && checkenemyinbackyourarea() != 1 ){
    return 1;
   */

}else if(checkenemyinyourarea() == 0 && checkmycreep() == -2 && ( creepxpos != 0 && creepxpos != 3840) && checkenemyinbackyourarea() == 0){/**/
    return 1;



}else if(checkmycreep() == 1 && checkenemyinbackyourarea() == 0 && checkenemyinyourarea() == 0){
    return 1;
}else if(checkenemycreep() == 1 && checkenemyinbackyourarea() == 0 && checkenemyinyourarea() == 0){
    return 0;

}else if(checkenemyinyourarea() == 0 && checkenemyinbackyourarea() == 0){/***/

    if(sideL && creepxpos == 0 ){
        return 1;
    }else{
        return 0;
    }
/*
}else if(checkmycreep() == 11){
    return 1;
*/


}else if(creepxpos == 0 || creepxpos == 1280*3 ){
    return 0;

}else{
    return 0;
}

}


bool algorithmbot::thinkjump(){

if(iscollide){
    return 1;
}else{
    if(rand()%1000 == 0){
        return 1;
    }else{
        return 0;
    }

}

}

bool algorithmbot::thinkuseJ(){


if((checkenemyattackinyourarea() == 1)){
    return 1;
}else if( (checkenemyattackinyourarea() == 2)){
    return 1;
}

if((checkenemyattackinyourarea() == 0 && checkenemycreep() == 1 && checkenemyinyourarea() == 0)){
    return 1;
}else if( (checkenemyattackinyourarea() == 0 && checkenemycreep() == 2 && checkenemyinyourarea() == 0)){
    return 1;
}


if((checkenemycreep() == 0) && checkenemyattackinyourarea() == 0 ){
    return 0;
}

}

bool algorithmbot::thinkuseK(){


if((checkenemyattackinyourarea() == 1) && cd1 <= 0){
    return 1;
}else if( (checkenemyattackinyourarea() == 2)){
    return 1;
}

if((checkenemyattackinyourarea() == 0 && checkenemycreep() == 1 && checkenemyinyourarea() == 0)  && cd1 <= 0){
    return 1;
}else if( (checkenemyattackinyourarea() == 0 && checkenemycreep() == 2 && checkenemyinyourarea() == 0)){
    return 1;
}

if((checkenemycreep() == 0) && checkenemyattackinyourarea() == 0){
    return 0;
}


}

bool algorithmbot::thinkuseL(){

if((checkenemyattackinyourarea() == 1)  && cd2 <= 0){
    return 1;
}else if( (checkenemyattackinyourarea() == 2)  && cd2 <= 0){
    return 1;
}

if(checkenemyattackinyourarea() == 0){
    return 0;
}

}

int algorithmbot::checkenemyinyourarea(){

    if(isRight)
    {//เจอขวา
        if( ( enemyXpos[0]-(xpos) < 500 && enemyXpos[0]-(xpos) > 0 && enemyYpos[0] < 935 )
           || ( enemyXpos[1]-(xpos) < 500 && enemyXpos[1]-(xpos) > 0 && enemyYpos[1] < 935  )
           || ( enemyXpos[2]-(xpos) < 500 && enemyXpos[2]-(xpos) > 0 && enemyYpos[2] < 935  ) ){
            return 1;
        }else{//ไม่เจอ
            return 0;
        }
    }

    if(!isRight)
    {//เจอซ้าย
        if( (((xpos+RplayerWidth)-(enemyXpos[0]+RplayerWidth)) < 500 && ((xpos+RplayerWidth)-(enemyXpos[0]+RplayerWidth)) > 0 && enemyYpos[0] < 935 )
           || (((xpos+RplayerWidth)-(enemyXpos[1]+RplayerWidth)) < 500 && ((xpos+RplayerWidth)-(enemyXpos[1]+RplayerWidth)) > 0 && enemyYpos[1] < 935 )
           || (((xpos+RplayerWidth)-(enemyXpos[2]+RplayerWidth)) < 500 && ((xpos+RplayerWidth)-(enemyXpos[2]+RplayerWidth)) > 0 && enemyYpos[2] < 935 )  ){
            return 2;
        }else{//ไม่เจอ
            return 0;
        }
    }
}

int algorithmbot::checkenemyinbackyourarea(){

    if(isRight){//อยู่ด้านหลังตอนหันขวา
        if( (((xpos+RplayerWidth)-(enemyXpos[0]+RplayerWidth)) < 500 && ((xpos+RplayerWidth)-(enemyXpos[0]+RplayerWidth)) > 0 && enemyYpos[0] < 935 )
           || (((xpos+RplayerWidth)-(enemyXpos[1]+RplayerWidth)) < 500 && ((xpos+RplayerWidth)-(enemyXpos[1]+RplayerWidth)) > 0 && enemyYpos[1] < 935 )
           || (((xpos+RplayerWidth)-(enemyXpos[2]+RplayerWidth)) < 500 && ((xpos+RplayerWidth)-(enemyXpos[2]+RplayerWidth)) > 0 && enemyYpos[2] < 935 )  ){
            //if(sideL){cout<<"adssssssssssssssssssssssssssss"<<endl;}
            return 1;
        }else{//ไม่อยู่ด้านหลัง
            return 0;
        }
    }else if(!isRight){//อยู่ด้านหลังตอนหันซ้าย
        if( ( enemyXpos[0]-(xpos+RplayerWidth) < 500 && enemyXpos[0]-(xpos+RplayerWidth) > 0 && enemyYpos[0] < 935 )
           || ( enemyXpos[1]-(xpos+RplayerWidth) < 500 && enemyXpos[1]-(xpos+RplayerWidth) > 0 && enemyYpos[1] < 935 )
           || ( enemyXpos[2]-(xpos+RplayerWidth) < 500 && enemyXpos[2]-(xpos+RplayerWidth) > 0 && enemyYpos[2] < 935 ) ){

            return 2;
        }else{//ไม่อยู่ด้านหลัง
            return 0;
        }
    }
}

int algorithmbot::checkenemyattackinyourarea(){

    if(isRight)
    {//เจอขวา
        if( ( enemyXpos[0]-(xpos) < Disatt && enemyXpos[0]-(xpos) > 0 && enemyYpos[0] < 935 && abs(ypos-enemyYpos[0]) < 40)
           || ( enemyXpos[1]-(xpos) < Disatt && enemyXpos[1]-(xpos) > 0 && enemyYpos[1] < 935 && abs(ypos-enemyYpos[1]) < 40)
           || ( enemyXpos[2]-(xpos) < Disatt && enemyXpos[2]-(xpos) > 0 && enemyYpos[2] < 935 && abs(ypos-enemyYpos[2]) < 40) ){
            return 1;
        }else{//ไม่เจอ
            return 0;
        }
    }else if(!isRight)
    {//เจอซ้าย
        if( (((xpos+RplayerWidth)-(enemyXpos[0]+RplayerWidth/2)) < Disatt && ((xpos+RplayerWidth)-(enemyXpos[0]+RplayerWidth/2)) > 0 && enemyYpos[0] < 935 && abs(ypos-enemyYpos[0]) < 40)
           || (((xpos+RplayerWidth)-(enemyXpos[1]+RplayerWidth/2)) < Disatt && ((xpos+RplayerWidth)-(enemyXpos[1]+RplayerWidth/2)) > 0 && enemyYpos[1] < 935 && abs(ypos-enemyYpos[1]) < 40 )
           || (((xpos+RplayerWidth)-(enemyXpos[2]+RplayerWidth/2)) < Disatt && ((xpos+RplayerWidth)-(enemyXpos[2]+RplayerWidth/2)) > 0 && enemyYpos[2] < 935 && abs(ypos-enemyYpos[2]) < 40 )  ){
            return 2;
        }else{//ไม่เจอ
            return 0;
        }
    }

}


int algorithmbot::checkmycreep(){

    if(isRight){//เห็นครีบ
        if( (creepxpos-(xpos+RplayerWidth)) > -150 ){
            return 1;
        }else{//ไม่เห็น
            return -1;
        }
    }
    if(!isRight){
        if( xpos-(creepxpos+100) > -150){
            return 2;
        }else{
            return -2;
        }

    }

    if(sideL){
        if(creepxpos == 0){
            return 11;
        }
    }
    if(!sideL){
        if(creepxpos == 3840){
            return 22;
        }
    }

}


int algorithmbot::checkenemycreep(){

    if(isRight)
    {
        if( enemycreepxpos-(xpos+RplayerWidth) < (Char!=3? Disatt:100) && enemycreepxpos-(xpos+RplayerWidth) > 0 ){

            return 1;
        }else{
            return 0;
        }
    }



    if(!isRight)
    {
        if( xpos-(enemycreepxpos+RplayerWidth) < (Char!=3? Disatt:100) && xpos-(enemycreepxpos+RplayerWidth) > 0 ){
            return 2;
        }else{
            return 0;
        }
    }

}

