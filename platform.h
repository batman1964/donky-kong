#pragma once

#include<allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <vector>
#include"gameobject.h"
using namespace std;

class platform : public gameobject {
public:
	platform(int x, int y, ALLEGRO_BITMAP* img);
	void draw();
};
