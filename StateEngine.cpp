#include "StateEngine.h"

bool StateEngine::run(Room& room)
{
    static int currentLevel = 0;
    int state = 0;
    bool running = true;
    Object* obj;

    for(int i = 0; i < room.getNumObjects() && !state; i++)
    {
        state = room.getObjectAt(i)->check();
        if(room.getObjectAt(i)->getState() == -1)
            room.remove(i--);
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
            state = -1;
        }
    }

    if(state == -2)
            currentLevel++;
    switch(state)
    {
        //Reset the level
        case -5:
            if(!room.load(decideLevel(currentLevel).c_str()))
                running = room.load("TitleScreen.gel");
            break;
        //TitleScreen
        case -4:
            running = room.load("TitleScreen.gel");
            break;
        //Level Select
        case -3:
            running = room.load("LevelSelect.gel");
            break;
        //You beat the previous level, move to the next level
        case -2:
            if(!room.load(decideLevel(currentLevel).c_str()))
                running = room.load("TitleScreen.gel");
            break;
        // You Lose. Exit the program
        case -1:
            running = false;
            break;
        // Load whichever level you like
        case 1:
            running = room.load("Level1.gel");
            currentLevel = 1;
            break;
        case 2:
            running = room.load("Level2.gel");
            currentLevel = 2;
            break;
        case 3:
            running = room.load("Level3.gel");
            currentLevel = 3;
            break;
    }

    return running;
}

string StateEngine::decideLevel(int i)
{
    char buffer[1];
    string s = "Level";
    //s += sprintf(buffer,"%d",i);
    itoa(i, buffer, 10);
    s += buffer;
    s += ".gel";
    return s;
}
