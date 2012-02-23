/*******************************************************************************
 Filename:                  Object.h
 Classname:                 Object
 
 Description:               This file declares the Object class. The Object
                            class holds the components that define the objects
                            in the game.
 
 Last Modified:            				02.04.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#ifndef AngrySomething_Object_h
#define AngrySomething_Object_h

#include "Base.h"
#include <SDL/SDL.h>

struct vector {
    double x;
    double y;
};

class Object : public Base
{
    private:
        SDL_Rect        loc;
        vector          vel;
        SDL_Rect        frame;
        SDL_Surface*    image;
        bool            needsUpdate;
    
    public:
        Object();
        Object(const Object&);
        ~Object();
    
        Object operator=(const Object& other);
     
        void setLoc(const SDL_Rect&);
        void setFrame(const SDL_Rect&);
        void setImage(const SDL_Surface&);
        void setNeedsUpdate(bool);
    
        SDL_Rect     getLoc() const;
        SDL_Rect     getFrame() const;
        SDL_Surface  getImage() const;
        bool                getNeedsUpdate();
        
        void update();
        void load();
        void save();
};

#endif
