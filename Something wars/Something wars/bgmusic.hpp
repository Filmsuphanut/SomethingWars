#ifndef BGMUSIC_H
#define BGMUSIC_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

class bgmusic
{
    public:
        bgmusic();
        virtual ~bgmusic();
        void Playmusic(int numMu,bool startstop,int MVolume, bool loops);
        bool checkplaymusic(int numMu);

    protected:

    private:

        Music *Pmu;
        Music BGmainmenu;
        Music BG1,BG2,BG3,BG4,BGwin,BGlose;
};

#endif // BGMUSIC_H
