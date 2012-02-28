/*******************************************************************************
 Filename:                  Base.h
 Classname:                 Base
 
 Description:               This file declares the Base class. The Base class
                            serves as the template for all classes. It will
                            handle the fundamental actions of classes, such
                            as Value Observing.
 
 Last Modified:            				02.28.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#ifndef AngrySomething_Base_h
#define AngrySomething_Base_h

#include <string>

using namespace std;

class Base
{
    private:
        static int  idGen;
        int         id;
        string      type;
        
    public:
        Base();
        Base(string);
        Base(const Base&);
        ~Base();
        Base operator=(const Base& other);
    
        int getID();
        string getType();
};

#endif
