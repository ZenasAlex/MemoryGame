#include "ofApp.h"

void ofApp::buttonPressed(){
	cout << "Se presiono el boton" << endl;
}

//--------------------------------------------------------------
void ofApp::setup(){
	deck.start(10, 10, 115, 150);
	gui.setup();
	gui.add(button.setup("Inicia"));
	button.addListener(this, &ofApp::startGame);
	selectedCard1 = NULL;
	selectedCard2 = NULL;
	player1.start(700, 50, "P1 points: ");
	player2.start(700, 90, "P2 points: ");
	drawTurnsCounter = false;
	turnsCounter.start(700, 200);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	deck.draw();
	gui.draw();
	player1.draw();
	player2.draw();
	
	if (drawTurnsCounter) {
		turnsCounter.draw();
	}
}

void ofApp::startGame(){
	deck.activeAllCards();
	deck.faceDownCards();
	deck.shuffle();
	player1.points = 0;
	player2.points = 0;
	turnsCounter.player1Turn = true;
	drawTurnsCounter = true;
}

void ofApp::validatePairs(){
	if (selectedCard1->imgName == selectedCard2->imgName) {
		selectedCard1->active = false;
		selectedCard2->active = false;
		pointsCounter();
	}
	else {
		selectedCard1->flip();
		selectedCard2->flip();
	}
	selectedCard1 = NULL;
	selectedCard2 = NULL;
	turnsCounter.changeTurn();
}

void ofApp::pointsCounter(){
	if (turnsCounter.player1Turn) {
		player1.points++;
		turnsCounter.changeTurn();
	}
	else {
		player2.points++;
		turnsCounter.changeTurn();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (button == OF_MOUSE_BUTTON_1) { //Presionaste boton izquierdo del mouse??
		if (selectedCard1 == NULL) { //No has sido seleccionada la primera carta??
			selectedCard1 = deck.getCard(x, y); //Seleccionas una carta
			if (selectedCard1 != NULL) { // Se selecciono una carta??
				selectedCard1->flip(); //Voltea la carta
			}
		}
		else if (selectedCard2 == NULL) { //No has seleccionado la segunda carta??
			selectedCard2 = deck.getCard(x, y); //Selecciona una carta
			if (selectedCard2 != NULL) { // Seleccionaste una carta??
				selectedCard2->flip(); //Voltea la carta
			}
		}
		else {
			validatePairs();
		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
