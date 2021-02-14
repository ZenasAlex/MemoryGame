#pragma once
#include <iostream>
#include "ofTrueTypeFont.h"
#include"Player.h"

class Turns {
public:
	float x;
	float y;
	string playerTurn;
	ofTrueTypeFont font;
	bool player1Turn;

	void start(float x, float y);
	void draw();
	void changeTurn();
};
