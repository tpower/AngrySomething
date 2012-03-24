/*******************************************************************************
 Filename:                  Object.h
 Classname:                 Object

 Description:               This file declares the Object class. The Object
                            class holds the components that define the objects
                            in the game.
 ******************************************************************************/

#ifndef AngrySomething_Object_h
#define AngrySomething_Object_h

#include <SDL/SDL.h>
#include <string>
#include <fstream>

#include "Base.h"

using namespace std;

struct vect
{
    int x, y;
};

class Object : public Base
{
    private:
        SDL_Rect    pos;        //bounding box
        vect        vel;        //velocity vector
        vect        acc;        //acceleration vector
        SDL_Rect    frame;      //current frame within sprite sheet
        string      filePath;   //file for sprite sheet
        SDL_Surface *image;     //sprite sheet
        
    
    public:
        Object();
        Object(const Object&);
        ~Object();

        Object      operator=(const Object& other);

        bool        load(fstream& file);
        bool        save(fstream& file);
        GameState   update();
};

#endif
