#ifndef ALGORITHMBOT_H
#define ALGORITHMBOT_H


class algorithmbot
{
    public:

        algorithmbot(int selectchar);
        virtual ~algorithmbot();


        void updateData(int Endgame,int Vside,float enemy0xpos,float enemy0ypos
        ,float enemy1xpos,float enemy1ypos,float enemy2xpos,float enemy2ypos,bool Viscollide,bool Vstunned
        ,float Vxpos,float Vypos,double Vcd1,double Vcd2,bool right,double Vcreepxpos,double Venemycreepxpos
        ,float VenemyHP,float VenemyHP1,float VenemyHP2,float VmyHP,double &debugTime);



        int switchA();
        int switchD();
        int switchW();
        bool switchJ();
        bool switchK();
        bool switchL();
        int sideL;

    protected:

    private:

        float RplayerWidth;
        float Disatt;


        int Char;
        float enemyXpos[3];
        float enemyYpos[3];
        float enemyHP[3];
        float myHP;
        bool iscollide=false;
        bool stunned=false;

        //logic

        float xpos,ypos,creepxpos,enemycreepxpos;
        bool isRight;
        float cd1,cd2,cd3;
        bool leftwalk=false;
        bool rightwalk=false;
        bool jump=false;
        bool useskillJ=false;
        bool useskillK=false;
        bool useskillL=false;


        bool thinkleftwalk();
        bool thinkrightwalk();
        bool thinkjump();
        bool thinkuseJ();
        bool thinkuseK();
        bool thinkuseL();

        int checkenemyinyourarea();
        int checkenemyinbackyourarea();
        int checkenemyattackinyourarea();


        int checkmycreep();
        int checkenemycreep();
        float tt;


};


#endif // ALGORITHMBOT_H
