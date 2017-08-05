#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	this->noise_source = ofRandom(10);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw() {
	this->cam.begin();

	float x, y, z;
	float len;
	float len_step = 100;
	int angle_step = 60;

	float tmp_noise_source = this->noise_source;
	float noise_step = 0.5;

	for (int angle = 0; angle < 360; angle += angle_step) {
		len = len_step;

		ofBeginShape();

		ofVertex(ofVec3f(0, 0, 0));

		x = len * cos(angle * DEG_TO_RAD);
		y = len * sin(angle * DEG_TO_RAD);
		z = 0;
		ofVertex(ofVec3f(x, y, z));

		x = len * cos((angle + angle_step) * DEG_TO_RAD);
		y = len * sin((angle + angle_step) * DEG_TO_RAD);
		z = 0;
		ofVertex(ofVec3f(x, y, z));

		ofColor c;
		c.setHsb(ofGetFrameNum() % 255, 255, 255);
		ofSetColor(c);

		ofEndShape(true);
	}

	int col_val = 1;
	for (; len < ofGetWidth(); len += len_step) {
		for (int angle = 0; angle < 360; angle += angle_step) {

			ofBeginShape();

			x = len * cos(angle * DEG_TO_RAD);
			y = len * sin(angle * DEG_TO_RAD);
			z = 0;
			ofVertex(ofVec3f(x, y, z));

			x = (len + len_step) * cos(angle * DEG_TO_RAD);
			y = (len + len_step) * sin(angle * DEG_TO_RAD);
			z = 0;
			ofVertex(ofVec3f(x, y, z));

			x = (len + len_step) * cos((angle + angle_step) * DEG_TO_RAD);
			y = (len + len_step) * sin((angle + angle_step) * DEG_TO_RAD);
			z = 0;
			ofVertex(ofVec3f(x, y, z));

			x = len * cos((angle + angle_step) * DEG_TO_RAD);
			y = len * sin((angle + angle_step) * DEG_TO_RAD);
			z = 0;
			ofVertex(ofVec3f(x, y, z));

			ofColor c;
			c.setHsb((ofGetFrameNum() + col_val) % 255, 255, 255);
			ofSetColor(c);
			col_val++;

			ofEndShape(true);
		}
	}
	

	this->noise_source += noise_step;
	
	this->cam.end();
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
