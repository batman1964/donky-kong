#pragma once
#include "barrel.h"
#include "global.h"
#include<iostream>
using namespace std;

//constructor
barrel::barrel(int x, int y, ALLEGRO_BITMAP* img) {
	xPos = x;
	yPos = y;
	dir = RIGHT;
	isonground = false;
	angle = 0;
	pic = img;
	ID = BARREL;
}

//draw function
void barrel::draw() {
	al_draw_rotated_bitmap(pic, 20, 20, xPos, yPos, (angle * 3.14) / 180, NULL);//this funtion SPINS an image based on the angle of the parameter

}
 

void barrel::move(vector<gameobject*>stuff) {
	
	cout << "direction is " << dir << endl;

	//spinning stuff
	if (dir == RIGHT)
		angle += 5;
	else 
		angle -= 5;
	if (angle > 360 || angle < -360)
		angle = 0;

	vector <gameobject*>::iterator iter;//makes the iterator so we can walk

	int x;
	int y;
	isonground - false;

	for (iter = stuff.begin(); iter != stuff.end(); iter++) { //walk through all the items in out gameobject 
		if ((*iter)->getID() == PLATFORM) {//only worry about colliding with platform
			x = (*iter) -> getX();
			y = (*iter)-> getY();
			if ((xPos + BARREL_SIZE > x) &&
				(xPos < x + PLATFORM_WIDTH) &&
				(yPos + BARREL_SIZE > y) &&
				(yPos < y + PLATFORM_HEIGHT))
				isonground = true;
		}
	}
	//if in free fall ,move down
	if (isonground == false)
		yPos += 2;
	else
		yPos += 1;

	// if barrel hiy left wall, turm right
	if (xPos < 0 && yPos < SCREEN_H - 100)
		dir = RIGHT;

	// if barrel hiy right wall, turm left
	if (xPos + 10 > SCREEN_W)
		dir = LEFT;

	//if dir is left, move left
	if (dir == LEFT)
		xPos -= 4;

	//if dir is left, move left
	if (dir == RIGHT)
		xPos += 4;

	// if you fall off the screen, the rest of your position to a random spot above the game screen
	if (yPos > SCREEN_H) {
		yPos = rand() % 500 - 1000;
		xPos = rand() % 500 - 1000;

	}
}
