#pragma once

#include<allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <vector>

using namespace std;

class gameobject {
private://only gameobjects objects can access this

protected://only child classes can access these
	int xPos;
	int yPos;
	int ID;
	bool isonground;
	ALLEGRO_BITMAP* pic;
public://all parts of your program can access this 
	//regular function
	int getX();
	int getY();
	int getID();

	//virtual functions
	virtual void move(vector<gameobject*>stuff);
	virtual void draw();
};
