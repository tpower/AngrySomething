/*******************************************************************************
 Filename:                  GrphComp.h
 Classname:                 GrphComp
 
 Description:               This file declares the GrphComp class.
 
 Last Modified:            				03.09.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#ifndef AngrySomething_GrphComp_h
#define AngrySomething_GrphComp_h

#include "Component.h"
#include <SDL/SDL.h>
#include <fstream>

class GrphComp : public Component
{
private:
    SDL_Surface *image;     //sprite sheet
    SDL_Rect    frame;      //current frame within sprite sheet
    char        *filePath;  //file for sprite sheet
    
public:
    GrphComp();
    GrphComp(const GrphComp&);
    ~GrphComp();
    
    GrphComp operator=(const GrphComp& other);
    
    SDL_Surface*    getImage();
    SDL_Rect        getFrame();
    
    virtual bool    load(fstream& file);
    virtual bool    save(fstream& file);
    virtual int     update();
};

#endif
