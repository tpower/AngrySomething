#ifndef CLASSES_H
#define CLASSES_H

#include <fstream>
#include <string>

using namespace std;

class Base
{
    private:
    
    public:
    
}

class Game : public Base
{
	private:
		int currentRoom;
		Room current;

	public:
		Game();
		Game(Game&);
		~Game();

		// opens text file containing the rooms and then opens a room text file based
		// on which room has that corresponding line number
		void loadRoom(string, int);

		// called to begin the game
		void init();

		// progress through the game loop
		void run();

		// called to end the game
		void stop();
}

class Room : public Base
{
	private:
		Object* arr;
    
	public:
		Room();
		Room(Room&);
		~Room();

		// Load all of the objects from room file
		void loadObjects(string);

		// updates all of the objects
		void update();
}

class MainView : public Base
{
    private:
    
    public:
    
}

class Object : public Base
{
	private:
		Component *arr;
	public:
		Object();
		Object{Object&);
		~Object();

		// Loads all of the components from object
		void loadAllComponent(string);

		// updates all the components
		void update();
}

class Component : public Base
{
	public:
		// updates the specific components
		update();
}
    
class ControllerComp : public Component
{
    
}
    
class ModelComp : public Component
{
    
}

#endif