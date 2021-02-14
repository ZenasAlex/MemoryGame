#pragma once

#include "ofMain.h"
#include "Sprite.h"
#include "Card.h"
#include "Deck.h"
#include "ofxGui.h"
#include "Player.h"
#include "Turns.h"

class ofApp : public ofBaseApp{

	public:
		Deck deck;
		ofxPanel gui;
		ofxButton button;
		Card *selectedCard1;
		Card *selectedCard2;

		Player player1;
		Player player2;

		Turns turnsCounter;
		bool drawTurnsCounter;

		void buttonPressed();
		void setup();
		void update();
		void draw();

		void startGame();
		void validatePairs();
		void pointsCounter();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
