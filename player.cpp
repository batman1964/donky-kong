#pragma once
#include "player.h"
#include"global.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

player::player() {//constructor
	//player position
	xPos = 100;
	yPos = SCREEN_H - 50;

	//player velocity
	xVel = 0;
	yVel = 0;

	isonground = false;
	CanJump = false;
	ID = PLAYER;
}
void player::moveLeft() { xVel--; }
void player::moveRight() { xVel++; }
void player::Jump() {
	if (CanJump)
		yVel = -15;
}

void player::draw() {
	al_draw_filled_rectangle(xPos, yPos, xPos + 30, yPos + 30, al_map_rgb(50, 150, 10));
}

void player::move(vector<gameobject*>stuff) {
	//deal with platform collision 
	vector<gameobject*>::iterator iter;
	int x;
	int y;
	for (iter = stuff.begin(); iter != stuff.end(); iter++) {
		if ((*iter)->getID() == PLATFORM) {//only worry about colliosion with platform here!
			x = (*iter)->getX();
			y = (*iter)->getY();

			if (VerticalCollision(xPos, yPos, 32, 32, (*iter)->getX(), (*iter)->getY(), PLATFORM_WIDTH, PLATFORM_HEIGHT, yVel) == 2) {
				yVel = -1.0;
				isonground = true;
			}
			if (VerticalCollision(xPos, yPos, 32, 32, (*iter)->getX(), (*iter)->getY(), PLATFORM_WIDTH, PLATFORM_HEIGHT, yVel) == 1) {
				yVel = -0.0;
				isonground = true;
			}
		}
	}

	//update player position
	xPos += xVel;
	yPos += yVel;
	//friction
	xVel *= .7;
	//gravity
	if (isonground == false) {
		yVel += .4;//falling speed
		CanJump = false;//turn off flying
	}
	else {
		yVel = 0;// stop downword movement
		CanJump = true;
	}
	// checka if you're falling 
	if (yPos + 30 > SCREEN_H)
		isonground = true;
	else
		isonground = false;

	//set terminal velocity (dont fall too fast)
	if (yVel > 5)
		yVel = 5;
	//boundss checking 
	if (xPos < 0)
		xPos = 0;
	if (xPos + 32 > SCREEN_W)
		xPos = SCREEN_W - 32;
}
//collision function
int player::VerticalCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2, int ydir) {

	if ((ydir >= 0) &&
		(x1 + w1 > x2) &&
		(x1 < x2 + w2) &&
		(y1 + h1 + 4 > y2) &&
		(y1 < y2)) {
		//cout <<"adjuating up";
		return 2;
	}
	else if ((ydir > -0) &&
		(x1 + w1 > x2) &&
		(x1 < x2 + w2) &&
		(y1 + h1 + 5 > y2) &&
		(y1 < y2)) {
		//cout <<"stable ypos";
		return 1;
	}
	else
		return false;
}
