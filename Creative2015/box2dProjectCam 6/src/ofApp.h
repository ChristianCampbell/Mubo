#pragma once

#include "ofMain.h"
#include "Box2D.h"
#include "groundShape.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
        void b2DPlatform();
        void b2DCharacter();
        void platformVertices();
        void lavaShapes();
        void pickUpsInit();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void debugDraw();
    
        void getPlayer(int x, int y);
    
        void exit();
    
        b2World * mWorld;
        b2Body * mGroundBody;
        b2Body * mGroundBody2;
        b2Body * mGroundBody3;
        b2Body * mGroundBody4;
        b2Body * mGroundBody5;
        b2Body * mGroundBody6;
        b2Body * mGroundBody7;
        b2Body * mGroundBody8;
        b2Body * mGroundBody9;
        b2Body * mGroundBody10;
        b2Body * mGroundBody11;
        b2Body * mGroundBody12;
        b2Body * mGroundBody13;
        b2Body * mGroundBody14;
        b2Body * mGroundBody15;
        b2Body * mGroundBody16;
        b2Body * mGroundBody17;
        b2Body * mGroundBody18;
        b2Body * mGroundBody19;
        b2Body * mGroundBody20;
        b2Body * mGroundBody21;
        b2Body * mGroundBody22;
        b2Body * mGroundBody23;
        b2Body * mGroundBody24;
        b2Body * mGroundBody25;
    
        b2Body * mEdge1;
        b2Body * mEdge2;
    
        b2Body * mFalling;
    
        b2Body * mMouse;

    
        ofSoundPlayer soundBed, bass, chords, hatsClaps, kick, lava, grab;
    
        ofSoundPlayer music[12];
    
        ofSoundPlayer SFX[4];
    
        ofImage findBucket, background, bsmntBackGr, buildings, _platform1, _platform2, _platform3, _platform4, crt, spike, pill, ball, groundSpikes;
    
        ofImage pickUps[10];
    
        ofImage pickedUps[8];
    
        ofImage colBuilds[10];
    
        ofImage buckets[4];
    
        ofCamera cam;
    
        int  mScale = 17;
    
        bool lavaTouched = false;
        bool pickedUp[10];
        bool inBasement = false;
    
        //vector<groundShape> mBackbodies;
        //groundShape * platform1();
    
        int gameState = 0;
    
        int x = 0;
        int y = 0;
        int z = 1000;//575;
        int count;
    
        b2Vec2 vertices[150][4];
        b2Body * mGroundBodies[150];
        b2Vec2 bucketVecs[3];
    
        b2Vec2 lavaRecs[3][4];
        b2Vec2 lavaPoints[12];
    
        int a = 132;
        int b = -1;

        ofColor hover = (255,0,0,255);
        ofColor hoverNull= (255,255,0,255);
    
        //ofTrueTypeFont myFont;

        float cameraX = 0.0f;
        float scale = 30.0f;
    
        float pickUpRotation = 0;
    
        b2Vec2 pickUpPos[11];
        b2Vec2 pickedUpPos[11];
        int pickUpVars[11][7];
        float pickupVol[11];
    
    
        int pickUpBlueX = 163.0f;
        int pickUpBlueY = 0.0f;
        int pickedUpBlueX;
        int pickedUpBlueY;
        int pickUpBlueAlpha = 0;
        int pickedUpBlueAlpha = 0;
        int buildingsBlueAlpha = 0;
        int pDisplayBlue = 0;
        int alphaMulBlue = 0;
        int alphaAddBlue = 0;
        int pickUpCountBlue = 0;
        float pickUpBlueVol = 0;
    
        int pickUpGreenX = 179.5f;
        int pickUpGreenY = 24.50f;
        int pickedUpGreenX;
        int pickedUpGreenY;
        int pickUpGreenAlpha = 0;
        int pickedUpGreenAlpha = 0;
        int buildingsGreenAlpha = 0;
        int pDisplayGreen = 0;
        int alphaMulGreen = 0;
        int alphaAddGreen = 0;
        int pickUpCountGreen = 0;
        float pickUpGreenVol = 0;
    
        int pickUpOrangeX = 318.00;
        int pickUpOrangeY = 0.82;
        int pickedUpOrangeX;
        int pickedUpOrangeY;
        int pickUpOrangeAlpha = 0;
        int pickedUpOrangeAlpha = 0;
        int buildingsOrangeAlpha = 0;
        int pDisplayOrange = 0;
        int alphaMulOrange = 0;
        int alphaAddOrange = 0;
        int pickUpCountOrange = 0;
        float pickUpOrangeVol = 0;
    
        int pickUpPurpleX = 387.24;
        int pickUpPurpleY = 36.24;
        int pickedUpPurpleX;
        int pickedUpPurpleY;
        int pickUpPurpleAlpha = 0;
        int pickedUpPurpleAlpha = 0;
        int buildingsPurpleAlpha = 0;
        int pDisplayPurple = 0;
        int alphaMulPurple = 0;
        int alphaAddPurple = 0;
        int pickUpCountPurple = 0;
        float pickUpPurpleVol = 0;
    
        int pickUpSpikeX = 163.0f;
        int pickUpSpikeY = 54.0f;
        int pickUpSpikeAlpha = 0;
        int pickedUpSpikeAlpha = 0;
        int buildingsSpikeAlpha = 0;
        int pDisplaySpike = 0;
        int alphaMulSpike = 0;
        int alphaAddSpike = 0;
        int pickUpCountSpike = 0;
    
        int pickUpPillX = 152.0f;
        int pickUpPillY = 54.0f;
        int pickUpPillAlpha = 0;
        int pickedUpPillAlpha = 0;
        int buildingsPillAlpha = 0;
        int pDisplayPill = 0;
        int alphaMulPill = 0;
        int alphaAddPill = 0;
        int pickUpCountPill = 0;
    
        float lavaVol = 0;
    
        float h1 = 8.7;
        float h2 = 10.9;
        float h3 = 13.1;
        float h4 = 15.3;
    
        float w1 = 2.2;
};
