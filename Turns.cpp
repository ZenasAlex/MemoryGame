#include "Turns.h"

void Turns::start(float x, float y){
	this->x = x;
	this->y = y;
	font.load("ARDESTINE.ttf", 32);
	player1Turn = true;
}

void Turns::draw(){
	if (player1Turn) {
		playerTurn = "P1 turn";
		font.drawString(playerTurn, x, y);
	}
	else {
		playerTurn = "P2 turn";
		font.drawString(playerTurn, x, y);
	}
}

void Turns::changeTurn(){
	player1Turn = !player1Turn;
}
