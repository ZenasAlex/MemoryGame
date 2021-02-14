#include "Player.h"
#include "ofUtils.h"

void Player::start(float x, float y, string numberPlayer){
	this->x = x;
	this->y = y;
	this->numberPlayer = numberPlayer;
	points = 0;
	font.load("ARDESTINE.ttf", 32);
}

void Player::draw(){
	font.drawString(numberPlayer + ofToString(points), x, y);
}
