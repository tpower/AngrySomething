#include "StateEngine.h"

bool StateEngine::run(Room& room)
{
    static int currentLevel = 0;
    int state = 0;
    bool running = true;
    //Object* obj;

    for(int i = 0; i < room.getNumObjects() && !state; i++)
    {
        state = room.getObjectAt(i)->check();
        if(room.getObjectAt(i)->getState() == -1)
            room.remove(i--);
        else if(room.getObjectAt(i)->getState() == -4)
            state = -4;
    }

    //If the room is a level
    if(room.getRoomType() == 1)
    {
        if(Pig::getNumPigs() <= 0)
        {
            //Win Condition
            state = -2;
        }

        if(Projectile::getNumBirds() <= 0 && Sling::getProjectileCount() <= 0)
        {
            //Lose Condition
            state = -4;
        }
    }
    //If the room ends with a cutscene
    else if(room.getRoomType() == 3)
    {
        if(Projectile::getNumBirds() <= 0 && Sling::getProjectileCount() <=0)
        {
            state = 1001;
        }
    }

    if(state == -2)
            currentLevel++;
    static bool paused = false;
    switch(state)
    {
        //Pause/Unpause the game
        case -6:
            static bool paused = false;
            if(paused)
            {
                running = room.unpause();
                paused = false;
            }
            else
            {
                running = room.pause();
                paused = true;
            }
            break;
        //Reset the level
        case -5:
            if(!room.load(decideLevel(currentLevel).c_str()))
                running = room.load("TitleScreen.gel");
            paused = false;
            break;
        //TitleScreen
        case -4:
            running = room.load("TitleScreen.gel");
            paused = false;
            break;
        //Level Select
        case -3:
            running = room.load("LevelSelect.gel");
            paused = false;
            break;
        //You beat the previous level, move to the Level Select screen
        case -2:
            //if(!room.load(decideLevel(currentLevel).c_str()))
                running = room.load("LevelSelect.gel");
            paused = false;
            break;
        // You Lose. Exit the program
        case -1:
            running = false;
            paused = false;
            break;
        // Load whichever level you like
        case 1:
            running = room.load("Cordona.gel");
            currentLevel = 1;
            paused = false;
            break;
        case 11:
            running = room.load("Cordona1.gel");
            currentLevel = 11;
            paused = false;
            break;
        case 12:
            running = room.load("Cordona2.gel");
            currentLevel = 12;
            paused = false;
            break;
        case 13:
            running = room.load("Cordona3.gel");
            currentLevel = 13;
            paused = false;
            break;
        case 2:
            running = room.load("Apathos.gel");
            currentLevel = 2;
            paused = false;
            break;
        case 21:
            running = room.load("Apathos1.gel");
            currentLevel = 21;
            paused = false;
            break;
        case 22:
            running = room.load("Apathos2.gel");
            currentLevel = 22;
            paused = false;
            break;
        case 23:
            running = room.load("Apathos3.gel");
            currentLevel = 23;
            paused = false;
            break;
        case 3:
            running = room.load("Paxtonia.gel");
            currentLevel = 3;
            paused = false;
            break;
        case 31:
            running = room.load("Paxtonia1.gel");
            currentLevel = 31;
            paused = false;
            break;
        case 32:
            running = room.load("Paxtonia2.gel");
            currentLevel = 32;
            paused = false;
            break;
        case 33:
            running = room.load("Paxtonia3.gel");
            currentLevel = 33;
            paused = false;
            break;
        case 4:
            running = room.load("Knoxen.gel");
            currentLevel = 4;
            paused = false;
            break;
        case 41:
            running = room.load("Knoxen1.gel");
            currentLevel = 41;
            paused = false;
            break;
        case 42:
            running = room.load("Knoxen2.gel");
            currentLevel = 42;
            paused = false;
            break;
        case 43:
            running = room.load("Knoxen3.gel");
            currentLevel = 43;
            paused = false;
            break;
        case 5:
            running = room.load("Nilbog.gel");
            currentLevel = 5;
            paused = false;
            break;
        case 51:
            running = room.load("Nilbog1.gel");
            currentLevel = 51;
            paused = false;
            break;
        case 52:
            running = room.load("Nilbog2.gel");
            currentLevel = 52;
            paused = false;
            break;
        case 53:
            running = room.load("Nilbog3.gel");
            currentLevel = 53;
            paused = false;
            break;
        case 6:
            running = room.load("Ziggurat.gel");
            currentLevel = 6;
            paused = false;
            break;
        case 61:
            running = room.load("Ziggurat1.gel");
            currentLevel = 61;
            paused = false;
            break;
        case 1001:
            running = room.load("IntroCutscene.gel");
            currentLevel = 1001;
            paused = false;
            break;
    }

    return running;
}

string StateEngine::decideLevel(int i)
{
    /*
    char buffer[1];
    string s = "Level";
    //s += sprintf(buffer,"%d",i);
    itoa(i, buffer, 10);
    s += buffer;
    s += ".gel";
    */
    string s;
    switch(i)
    {
        case 1:
            s = "Cordona.gel";
            break;
        case 11:
            s = "Cordona1.gel";
            break;
        case 12:
            s = "Cordona2.gel";
            break;
        case 13:
            s = "Cordona3.gel";
            break;
        case 2:
            s = "Apathos.gel";
            break;
        case 21:
            s = "Apathos1.gel";
            break;
        case 22:
            s = "Apathos2.gel";
            break;
        case 23:
            s = "Apathos3.gel";
            break;
        case 3:
            s = "Paxtonia.gel";
            break;
        case 31:
            s = "Paxtonia1.gel";
            break;
        case 32:
            s = "Paxtonia2.gel";
            break;
        case 33:
            s = "Paxtonia3.gel";
            break;
        case 4:
            s = "Knoxen.gel";
            break;
        case 41:
            s = "Knoxen1.gel";
            break;
        case 42:
            s = "Knoxen2.gel";
            break;
        case 43:
            s = "Knoxen3.gel";
            break;
        case 5:
            s = "Nilbog.gel";
            break;
        case 51:
            s = "Nilbog1.gel";
            break;
        case 52:
            s = "Nilbog2.gel";
            break;
        case 53:
            s = "Nilbog3.gel";
            break;
        case 6:
            s = "Ziggurat.gel";
            break;
        case 61:
            s = "Ziggurat1.gel";
            break;
        case 1001:
            s = "IntroCutscene.gel";
            break;
    }
    return s;
}
