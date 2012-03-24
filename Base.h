/*******************************************************************************
 Filename:                  Base.h
 Classname:                 Base

 Description:               This file declares the Base class. The Base class
                            serves as the template for all classes.
 ******************************************************************************/

#ifndef AngrySomething_Base_h
#define AngrySomething_Base_h

struct GameState
{
    int roomNum;
    int eleState;
};

enum type
{
    BASE        = 0,
    GAME        = 1,
    VIEW        = 2,
    ROOM        = 3,
    OBJECT      = 4
};

class Base
{
    private:
        static int  idGen;
        int         id;
        int         type;

    protected:
        GameState   state;

    public:
        Base();
        Base(int);
        Base(const Base&);
        ~Base();
    
        Base        operator=(const Base& other);

        void        setState(GameState s);

        int         getID() const;
        int         getType() const;
        GameState   getState() const;
};

#endif
