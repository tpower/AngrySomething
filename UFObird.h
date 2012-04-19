#ifndef UFOBIRD_H_INCLUDED
#define UFOBIRD_H_INCLUDED

#include "Projectile.h"

class UFObird : public Projectile
{
    private:
        const char* image2;
        SDL_Surface* Spaceship;
        bool UFOactive;
    public:
        UFObird(const char* file,const char* file2, int x, int y, int vx, int vy);
        ~UFObird();

        virtual void    run();
        virtual void    draw(SDL_Surface* s);
        Object*         handle(SDL_Event);

        static int      getNumBirds(){return numBirds;}
};

#endif // UFOBIRD_H_INCLUDED
