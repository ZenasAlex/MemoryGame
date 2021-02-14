#pragma once
#include <iostream>
#include "ofTrueTypeFont.h"

class Player {
public:
	float x;
	float y;
	int points;
	string numberPlayer;
	ofTrueTypeFont font;

	void start(float x, float y, string numberPlayer);
	void draw();
};
