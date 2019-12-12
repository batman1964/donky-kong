#pragma once
#include<allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include"gameobject.h"
#include"global.h"

class player : public gameobject {
private:
	double xVel;
	double yVel;
	bool CanJump;
public:
	player();
	void move(vector<gameobject*>stuff);
	void moveLeft();
	void moveRight();
	void Jump();
	void draw();
	int VerticalCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2, int ydir);
};

