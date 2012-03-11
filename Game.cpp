/*******************************************************************************
 Filename:                  Game.cpp
 Classname:                 Game
 
 Description:               This file defines the Game class. This class will
                            be the controller for the game. It is in charge of
                            running the game loop and handling communication
                            between the Room and the View
 
 Last Modified:            				02.28.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#include "Game.h"

/*******************************************************************************
 Name:              Game
 Description:       Default constructor for Game class
 ******************************************************************************/
Game::Game() : Base(GAME)
{
    room = new Room;
    view = new View;
}

/*******************************************************************************
 Name:              Game
 Description:       Copy constructor for Game class
 
 Input:
    other           Game object to be copied
 ******************************************************************************/
Game::Game(const Game& other) : Base(GAME)
{
    running = other.running;
    *room = *(other.room);
    *view = *(other.view);
}

/*******************************************************************************
 Name:              ~Game
 Description:       Destructor for Game class
 ******************************************************************************/
Game::~Game()
{
    if(room) delete room;
    if(view) delete view;
    
    SDL_Quit();
}

/*******************************************************************************
 Name:              operator=
 Description:       Overloaded assignment operator for Game class
 
 Input:
    other           const Game&
 ******************************************************************************/
Game Game::operator=(const Game& other)
{
    if(&other != this)
    {
        running = other.running;
        *room = *(other.room);
        *view = *(other.view);
    }
    
    return *this;
}

/*******************************************************************************
 ACCESSORS
 Name:              getRoom, getView, getRunning
 ******************************************************************************/
Room* Game::getRoom()
{
    return room;
}

View* Game::getView()
{
    return view;
}

bool Game::getRunning()
{
    return running;
}

/*******************************************************************************
 Name:              init
 Description:       This method handles any initialization involved before the
                    run loop begins
 Input:
    roomNum         int representing roomNumber to load
 
 Output:
    returns         boolean value representing if the game initialized correctly
 ******************************************************************************/
void Game::init(int roomNum)
{
    //open game file
    fstream file("GameFile.gel", ios::in | ios::binary);
    int numRooms, roomLoc;
    
    if(!file)
    {
        running = false;
        return;
    }
    
    //Read number of rooms and check validity of room request
    file.read(reinterpret_cast<char*>(numRooms), sizeof(numRooms));
    if(roomNum >= numRooms)
    {
        running = false;
        return;
    }
    
    //Move cursor to location of requested room
    file.seekg((sizeof(int) * roomNum), ios::cur);
    file.read(reinterpret_cast<char*>(roomLoc), sizeof(roomLoc));
    file.seekg(roomLoc, ios::beg);
    
    //load room
    running = room->load(file);
}

/*******************************************************************************
 Name:              save
 Description:       This method saves the current state of the game
 
 Output:
    returns         bool representing the success of the save
 ******************************************************************************/
bool Game::save()
{
    //open save file
    fstream file("SavedGame.gel", ios::out | ios::binary);
    
    //save room
    return room->save(file);
}

/*******************************************************************************
 Name:              run
 Description:       This method starts the game and controls the game loop
 
 Output:
    returns         int value representing the exit state of the game
 ******************************************************************************/
int Game::run()
{
    while(running)
    {
        room->update();
        view->update();
    }
    
    return 0;
}

