#ifndef SHOWDAMAGECLASS_H
#define SHOWDAMAGECLASS_H
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class ShowDamageClass
{
    public:
        ShowDamageClass(Font &ff,int chk);
        virtual ~ShowDamageClass();
    int chkdamage;
    Text showDamage;
    void updateShowdamage(RenderWindow &window,double &debugTime);
    void InputTextDamage(int damage);

    float texttimestamp = 1;
    int maxtexttimestamp = 3;
    bool destroy = false;

    protected:

    private:
};

#endif // SHOWDAMAGECLASS_H
