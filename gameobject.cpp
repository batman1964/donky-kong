#pragma once

#include"gameobject.h"

// virtual functions 
void gameobject::move(vector<gameobject*>stuff) {}
void gameobject::draw() {}


//regular functions
int gameobject::getX() { return xPos; }
int gameobject::getY() { return yPos; }
int gameobject::getID() { return ID; }
