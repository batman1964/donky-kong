#pragma once

#include<allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <vector>
#include"gameobject.h"
using namespace std;

class barrel :public gameobject {
private:
	int dir;
	int angle;
public:
	barrel(int x, int y, ALLEGRO_BITMAP* img);
	void draw();
	virtual void move(vector<gameobject*>stuff);

};
