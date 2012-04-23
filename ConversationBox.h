#ifndef CONVERSATIONBOX_H_INCLUDED
#define CONVERSATIONBOX_H_INCLUDED

#include "DrawableObject.h"
#include "MechanicsObject.h"

#include <string>

using namespace std;

class ConversationBox : public DrawableObject, public MechanicsObject
{
    private:
        string conv;
        int index, startTime, dispTime;
        char person;
    public:
        ConversationBox(int x, int y, string c);

        Object*         process();
        void            draw(SDL_Surface* s);
        void            pause();
        void            unpause();
};

#endif // CONVERSATIONBOX_H_INCLUDED
