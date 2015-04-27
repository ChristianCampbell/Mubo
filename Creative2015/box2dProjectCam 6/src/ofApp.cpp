#include "ofApp.h"



//--------------------------------------------------------------

void ofApp::setup(){
    
    
    mWorld = new b2World(b2Vec2(0.0f, -25.0f), true);
    mScale = 17;
    
    ofSetFrameRate(60);
    
    cam.enableOrtho();
    //cam.setGlobalPosition(ofVec3f (0,0,1000));
    //cam.lookAt(ofVec3f (0,0,0));
    
    count = 4;
    
    //myFont.loadFont("fonts/arial.ttf", 20);
    
    background.load("images/Sky-01.png");
    bsmntBackGr.load("images/cavesky_3.png");
    buildings.load("images/buildings.png");
    _platform1.load("images/top left.png");
    _platform2.load("images/top right.png");
    _platform3.load("images/bottom left.png");
    _platform4.load("images/bottom right.png");
    crt.load("images/crt.png");
    spike.load("images/grey baddy spike.png");
    pill.load("images/pill.png");
    ball.load("images/BALL1-01.png");
    groundSpikes.load("images/spikes.png");
    findBucket.load("images/find the bucket-01.png");
    
    pickUps[0].load("images/blue pickup.png");
    pickUps[1].load("images/green pickup.png");
    pickUps[2].load("images/orange pickup.png");
    pickUps[3].load("images/purple pickup.png");
    pickUps[4].load("images/cave pickup 1-01.png");
    pickUps[5].load("images/cave pickup 2-01.png");
    pickUps[6].load("images/cave pickup 3-01.png");
    pickUps[7].load("images/cave pickup 4-01.png");
    pickUps[8].load("images/bucket.png");
    pickUps[9].load("images/grey pickup.png");
    
    music[0].loadSound("sounds/Chords.mp3");
    music[1].loadSound("sounds/kick.mp3");
    music[2].loadSound("sounds/bass.mp3");
    music[3].loadSound("sounds/hats and claps.mp3");
    music[4].loadSound("sounds/cavebacking.mp3");
    music[5].loadSound("sounds/cavesynth.mp3");
    music[6].loadSound("sounds/bass.mp3");
    music[7].loadSound("sounds/cavebreak.mp3");
    music[8].loadSound("sounds/pad.mp3");
    music[9].loadSound("sounds/cavepop.mp3");
    music[10].loadSound("sounds/bucket squelch.mp3");
    music[11].loadSound("sounds/lava.mp3");
    music[12].loadSound("sounds/hats and claps.mp3");

    
    pickedUps[0].load("images/blue ball picked up-01.png");
    pickedUps[1].load("images/green ball picked up-01.png");
    pickedUps[2].load("images/orange ball picked up-01.png");
    pickedUps[3].load("images/PURPLE ball picked up-01.png");
    pickedUps[4].load("images/cave pickedup 1-01.png");
    pickedUps[5].load("images/cave pickedup 2-01.png");
    pickedUps[6].load("images/cave pickedup 3-01.png");
    pickedUps[7].load("images/cave pickedup 4-01.png");
    
    colBuilds[0].load("images/Buildings Blue-01.png");
    colBuilds[1].load("images/Buildings Green-01.png");
    colBuilds[2].load("images/Buildings Orange-01.png");
    colBuilds[3].load("images/Buildings Purple-01.png");
    colBuilds[4].load("images/caveoverlay1_4.png");
    colBuilds[5].load("images/caveoverlay2_4.png");
    colBuilds[6].load("images/caveoverlay3_4.png");
    colBuilds[7].load("images/caveoverlay4_4.png");
    colBuilds[8].load("images/BUILDINGS EVIL-01.png");
    colBuilds[9].load("images/caveoverlayred.png");
    
    grab.loadSound("sounds/ball grab.mp3");
    
    soundBed.loadSound("sounds/background.mp3");

    lava.loadSound("sounds/spike.mp3");
    
    lava.setVolume(0.0f);
    grab.setVolume(1.0f);
    music[9].setVolume(0.0);
    music[8].setVolume(0.0);
    
    
    soundBed.setLoop(true);
    lava.setLoop(true);
    grab.setVolume(false);
    music[9].setLoop(true);
    music[8].setLoop(true);
    
    soundBed.play();
    lava.play();
    music[9].play();
    music[8].play();
    
    for (int i = 0; i < 8; i++){
        music[i].setVolume(0.0f);
        music[i].setLoop(true);
        music[i].play();
    }

    b2DCharacter();
    b2DPlatform();
    
    pickUpsInit();
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    

}

void ofApp::b2DPlatform(){

    b2BodyDef groundBodyDefs[134];
    b2PolygonShape platforms[134];
    
    platformVertices();
    lavaShapes();
    
    for (int i = 0; i < 134; i++){
        
        groundBodyDefs[i].position.Set(0.0f, 0.0f);
        groundBodyDefs[i].type = b2_staticBody;
        mGroundBodies[i] = mWorld->CreateBody(&groundBodyDefs[i]);
        
    }
    
    for (int i = 0; i < 134; i++){
        
        platforms[i].Set(vertices[i], count);
        mGroundBodies[i]->CreateFixture(&platforms[i], 22.0f);
        
    }

}

void ofApp:: pickUpsInit(){
    
    //0 = Blue
    //1 = Green
    //2 = Orange
    //3 = Purple
    //4 = Purple (BASEMENT)
    //5 = Burnt Orange (BASEMENT)
    //6 = Beige (BASEMENT)
    //7 = Orange (BASEMENT)
    
    
    //Initialising all other variables
    for (int a = 0; a < 9; a ++) {
        pickupVol[a] = 0.0f;
        pickedUp[a] = false;
        for (int b = 0; b < 7; b ++) {
            pickUpVars[a][b] = 0;
        }
    }
    
    //Spike
    
    //pickUpPos[8].Set(163.0f, 54.0f);
    //pickedUpPos[8].Set(pickedUpOrangeX + 2.00f * mScale, pickedUpBlueY);
    
    //Bucket
    
    //pickUpPos[8].Set(387.24f, 36.25f);
    //pickedUpPos[8].Set(pickedUpPos[1].y * mScale + 10, pickedUpPos[0].y);

    
}

void ofApp:: platformVertices(){
    
    vertices[0][0].Set(-33.5, -14.75);
    vertices[0][1].Set(-33.5, -20);
    vertices[0][2].Set(313.48, -20);
    vertices[0][3].Set(313.48, -14.75);
    
    vertices[1][0].Set(16.5, -10.9);
    vertices[1][1].Set(16.5, -14.75);
    vertices[1][2].Set(21.1, -14.75);
    vertices[1][3].Set(21.1, -10.9);
    
    vertices[2][0].Set(104.3, -10.9);
    vertices[2][1].Set(104.3, -14.75);
    vertices[2][2].Set(159, -14.75);
    vertices[2][3].Set(159, -10.9);
    
    vertices[3][0].Set(167, -10.9);
    vertices[3][1].Set(167, -14.75);
    vertices[3][2].Set(192.6, -14.75);
    vertices[3][3].Set(192.6, -10.9);
    
    vertices[4][0].Set(204.6, -10.9);
    vertices[4][1].Set(204.6, -14.75);
    vertices[4][2].Set(221.7, -14.75);
    vertices[4][3].Set(221.7, -10.9);
    
    vertices[5][0].Set(112.75,-7.0);
    vertices[5][1].Set(112.75,-10.9);
    vertices[5][2].Set(125.6, -10.9);
    vertices[5][3].Set(125.6, -7);
    
    vertices[6][0].Set(129.4,-7);
    vertices[6][1].Set(129.4, -10.9);
    vertices[6][2].Set(142.4, -10.9);
    vertices[6][3].Set(142.4, -7);
    
    vertices[7][0].Set(146, -7);
    vertices[7][1].Set(146, -10.9);
    vertices[7][2].Set(154.9, -10.9);
    vertices[7][3].Set(154.9, -7);
    
    vertices[8][0].Set(171.1, -7);
    vertices[8][1].Set(171.1, -10.9);
    vertices[8][2].Set(179.9, -10.9);
    vertices[8][3].Set(179.9, -7);
    
    vertices[9][0].Set(183.6, -7);
    vertices[9][1].Set(183.6, -10.9);
    vertices[9][2].Set(188.3, -10.9);
    vertices[9][3].Set(188.3, -7);
    
    vertices[10][0].Set(208.7, -7);
    vertices[10][1].Set(208.7, -10.9);
    vertices[10][2].Set(217.5, -10.9);
    vertices[10][3].Set(217.5, -7);
    
    vertices[11][0].Set(137.7, -3.1);
    vertices[11][1].Set(137.7, -7);
    vertices[11][2].Set(142.4, -7);
    vertices[11][3].Set(142.4, -3.1);
    
    vertices[12][0].Set(122.94,4.12);
    vertices[12][1].Set(122.94,1.53);
    vertices[12][2].Set(136.00,1.59);
    vertices[12][3].Set(136.00,4.12);
    
    vertices[13][0].Set(142.71,7.59);
    vertices[13][1].Set(142.71,5.00);
    vertices[13][2].Set(155.71,5.18);
    vertices[13][3].Set(155.71,7.59);
    
    vertices[14][0].Set(162.12,12.65);
    vertices[14][1].Set(162.18,8.18);
    vertices[14][2].Set(187.71,8.18);
    vertices[14][3].Set(187.71,12.71);
    
    vertices[15][0].Set(170.35,16.59);
    vertices[15][1].Set(170.35,12.59);
    vertices[15][2].Set(175.12,12.65);
    vertices[15][3].Set(175.12,16.59);
    
    vertices[16][0].Set(182.94,16.53);
    vertices[16][1].Set(182.88,12.65);
    vertices[16][2].Set(200.18,12.76);
    vertices[16][3].Set(200.18,16.59);
    
    vertices[17][0].Set(195.53,20.53);
    vertices[17][1].Set(195.59,16.47);
    vertices[17][2].Set(208.59,16.65);
    vertices[17][3].Set(208.53,20.47);
    
    vertices[18][0].Set(199.76,24.35);
    vertices[18][1].Set(199.71,20.41);
    vertices[18][2].Set(208.53,20.65);
    vertices[18][3].Set(208.53,24.35);
    
    vertices[19][0].Set(203.82,28.24);
    vertices[19][1].Set(203.76,24.35);
    vertices[19][2].Set(208.53,24.41);
    vertices[19][3].Set(208.53,28.24);
    
    vertices[20][0].Set(342.00,21.65);
    vertices[20][1].Set(342.06,19.18);
    vertices[20][2].Set(350.18,19.18);
    vertices[20][3].Set(350.18,21.71);
    
    vertices[21][0].Set(356.12,24.94);
    vertices[21][1].Set(356.06,22.41);
    vertices[21][2].Set(364.29,22.41);
    vertices[21][3].Set(364.29,24.82);
    
    vertices[22][0].Set(357.35,6.82);
    vertices[22][1].Set(357.29,4.24);
    vertices[22][2].Set(365.59,4.29);
    vertices[22][3].Set(365.53,6.76);
    
    vertices[23][0].Set(399.29,0.71 -(0.65));
    vertices[23][1].Set(399.24,-1.82 -(0.65));
    vertices[23][2].Set(412.12,-1.71 -(0.65));
    vertices[23][3].Set(412.06,0.76 -(0.65));
    
    vertices[24][0].Set(413.24,-7.06);
    vertices[24][1].Set(413.24,-10.76);
    vertices[24][2].Set(417.88,-10.94);
    vertices[24][3].Set(417.94,-7.00);
    
    vertices[25][0].Set(246.2, -10.85);
    vertices[25][1].Set(246.2, -14.8);
    vertices[25][2].Set(250.8, -14.8);
    vertices[25][3].Set(250.8, -10.85);
    
    vertices[26][0].Set(254.6, -10.82);
    vertices[26][1].Set(254.6, -14.8);
    vertices[26][2].Set(309.3, -14.8);
    vertices[26][3].Set(309.3, -10.82);
    
    vertices[27][0].Set(262.9, -6.9);
    vertices[27][1].Set(262.9, -10.82);
    vertices[27][2].Set(275.9, -10.82);
    vertices[27][3].Set(275.9, -6.9);
    
    vertices[28][0].Set(279.6, -6.9);
    vertices[28][1].Set(279.6, -10.82);
    vertices[28][2].Set(292.6, -10.82);
    vertices[28][3].Set(292.6, -6.9);
    
    vertices[29][0].Set(287.9, -3.05);
    vertices[29][1].Set(287.9, -7);
    vertices[29][2].Set(292.6, -7);
    vertices[29][3].Set(292.6, -3.05);
    
    vertices[30][0].Set(296.3, -6.9);
    vertices[30][1].Set(296.3, -10.82);
    vertices[30][2].Set(305.1, -10.82);
    vertices[30][3].Set(305.1, -6.9);
    
    vertices[31][0].Set(321.47,-14.76);
    vertices[31][1].Set(321.59,-19.24);
    vertices[31][2].Set(438.76,-18.82);
    vertices[31][3].Set(447.29,-14.76);
    
    vertices[32][0].Set(329.82,-10.79);
    vertices[32][1].Set(329.76,-14.76);
    vertices[32][2].Set(401.24,-14.76);
    vertices[32][3].Set(401.18,-10.79);
    
    vertices[33][0].Set(333.94,-7.00);
    vertices[33][1].Set(333.94,-10.79);
    vertices[33][2].Set(346.88,-10.79);
    vertices[33][3].Set(346.88,-7);
    
    vertices[34][0].Set(354.82,-6.9);
    vertices[34][1].Set(354.82,-10.88);
    vertices[34][2].Set(367.82,-10.88);
    vertices[34][3].Set(367.82,-6.9);
    
    vertices[35][0].Set(371.53,-6.9);
    vertices[35][1].Set(371.47,-10.82);
    vertices[35][2].Set(384.53,-10.82);
    vertices[35][3].Set(384.53,-6.9);
    
    vertices[36][0].Set(388.24,-6.9);
    vertices[36][1].Set(388.24,-10.82);
    vertices[36][2].Set(397.06,-10.82);
    vertices[36][3].Set(397.06,-6.9);
    
    vertices[37][0].Set(338.12,-3.06);
    vertices[37][1].Set(338.12,-7.00);
    vertices[37][2].Set(346.88,-7.00);
    vertices[37][3].Set(346.88,-3.06);
    
    vertices[38][0].Set(409.18,-10.82);
    vertices[38][1].Set(409.18,-14.71);
    vertices[38][2].Set(413.71,-14.71);
    vertices[38][3].Set(413.71,-10.82);
    
    vertices[39][0].Set(417.47,-11.00);
    vertices[39][1].Set(417.47,-14.71);
    vertices[39][2].Set(422.18,-14.71);
    vertices[39][3].Set(422.18,-11.00);
    
    vertices[40][0].Set(425.8,-10.82);
    vertices[40][1].Set(425.8,-14.65);
    vertices[40][2].Set(443.00,-14.65);
    vertices[40][3].Set(443.00,-10.82);
    
    vertices[41][0].Set(379.94,-3.06);
    vertices[41][1].Set(379.94,-6.9);
    vertices[41][2].Set(384.53,-6.9);
    vertices[41][3].Set(384.53,-3.06);
    
    vertices[42][0].Set(434.24,-6.94);
    vertices[42][1].Set(434.24,-10.82);
    vertices[42][2].Set(438.88,-10.82);
    vertices[42][3].Set(438.88,-6.94);
    
    vertices[43][0].Set(332.82,11.29);
    vertices[43][1].Set(332.76,8.71);
    vertices[43][2].Set(341.82,8.76);
    vertices[43][3].Set(341.82,11.41);
    
    vertices[44][0].Set(332.82,15.35);
    vertices[44][1].Set(332.82,11.18);
    vertices[44][2].Set(337.47,11.41);
    vertices[44][3].Set(337.41,15.35);
    
    vertices[45][0].Set(345.65,10.41);
    vertices[45][1].Set(345.71,7.94);
    vertices[45][2].Set(353.88,7.88);
    vertices[45][3].Set(353.82,10.41);
    
    vertices[46][0].Set(369.00,3.59);
    vertices[46][1].Set(369.06,1.00);
    vertices[46][2].Set(377.24,1.06);
    vertices[46][3].Set(377.24,3.53);
    
    vertices[47][0].Set(305.00,-20.12);
    vertices[47][1].Set(304.65,-31.00);
    vertices[47][2].Set(313.65,-30.88);
    vertices[47][3].Set(313.47,-20.12);
    
    vertices[48][0].Set(321.59,-19.35);
    vertices[48][1].Set(321.59,-23.12);
    vertices[48][2].Set(325.59,-23.18);
    vertices[48][3].Set(325.71,-19.35);
    
    vertices[49][0].Set(325.53,-23.12);
    vertices[49][1].Set(325.53,-27.00);
    vertices[49][2].Set(329.71,-27.06);
    vertices[49][3].Set(329.94,-23.00);
    
    vertices[50][0].Set(329.65,-27.00);
    vertices[50][1].Set(329.76,-42.00);
    vertices[50][2].Set(335.35,-41.94);
    vertices[50][3].Set(335.12,-26.71);
    
    vertices[51][0].Set(329.76,-41.94);
    vertices[51][1].Set(325.53,-41.94);
    vertices[51][2].Set(325.53,-45.94);
    vertices[51][3].Set(330.00,-46.06);
    
    vertices[52][0].Set(419.76,0.82 -(0.65));
    vertices[52][1].Set(419.76,-1.65 -(0.65));
    vertices[52][2].Set(424.18,-1.65 -(0.65));
    vertices[52][3].Set(424.12,0.88 -(0.65));
    
    vertices[53][0].Set(427.88,3.12);
    vertices[53][1].Set(427.94,0.53);
    vertices[53][2].Set(432.29,0.59);
    vertices[53][3].Set(432.29,3.12);
    
    vertices[54][0].Set(438.24,5.35);
    vertices[54][1].Set(438.24,0.94);
    vertices[54][2].Set(463.82,1.00);
    vertices[54][3].Set(463.76,5.35);
    
    vertices[55][0].Set(446.65,9.24);
    vertices[55][1].Set(446.59,5.29);
    vertices[55][2].Set(451.29,5.35);
    vertices[55][3].Set(451.29,9.24);
    
    vertices[56][0].Set(459.18,9.24);
    vertices[56][1].Set(459.06,5.41);
    vertices[56][2].Set(476.24,5.47);
    vertices[56][3].Set(476.24,9.29);
    
    vertices[57][0].Set(471.71,13.12);
    vertices[57][1].Set(471.71,9.29);
    vertices[57][2].Set(484.47,9.41);
    vertices[57][3].Set(484.47,13.18);
    
    vertices[58][0].Set(475.88,17.00);
    vertices[58][1].Set(475.88,13.12);
    vertices[58][2].Set(484.47,13.06);
    vertices[58][3].Set(484.53,17.00);
    
    vertices[59][0].Set(480.06,20.88);
    vertices[59][1].Set(480.06,17.06);
    vertices[59][2].Set(484.53,17.06);
    vertices[59][3].Set(484.41,21.00);
    
    vertices[60][0].Set(455.12,-14.59);
    vertices[60][1].Set(455.12,-18.88);
    vertices[60][2].Set(501.24,-18.88);
    vertices[60][3].Set(501.24,-14.47);
    
    vertices[61][0].Set(459.29,-10.71);
    vertices[61][1].Set(459.29,-14.59);
    vertices[61][2].Set(501.29,-14.47);
    vertices[61][3].Set(501.29,-10.71);
    
    vertices[62][0].Set(488.53,1.00);
    vertices[62][1].Set(488.53,-10.76);
    vertices[62][2].Set(501.24,-11.00);
    vertices[62][3].Set(501.18,1.00);
    
    vertices[63][0].Set(321.59,-45.82);
    vertices[63][1].Set(317.29,-49.82);
    vertices[63][2].Set(325.71,-50.00);
    vertices[63][3].Set(325.53,-45.88);
    
    vertices[64][0].Set(304.65,-49.82);
    vertices[64][1].Set(304.65,-53.76);
    vertices[64][2].Set(317.29,-53.76);
    vertices[64][3].Set(317.29,-49.82);
    
    vertices[65][0].Set(304.59,-53.71);
    vertices[65][1].Set(296.59,-53.76);
    vertices[65][2].Set(292.18,-57.59);
    vertices[65][3].Set(304.59,-57.65);
    
    vertices[66][0].Set(288.35,-57.53);
    vertices[66][1].Set(288.29,-60.29);
    vertices[66][2].Set(292.41,-60.24);
    vertices[66][3].Set(292.24,-57.53);
    
    vertices[67][0].Set(283.88,-57.76);
    vertices[67][1].Set(283.88,-60.71);
    vertices[67][2].Set(288.41,-60.71);
    vertices[67][3].Set(288.41,-53.88);
    
    vertices[68][0].Set(430.59,-19.00);
    vertices[68][1].Set(430.59,-20.29);
    vertices[68][2].Set(439.00,-20.18);
    vertices[68][3].Set(438.94,-18.88);
    
    vertices[69][0].Set(283.76,-62.00);
    vertices[69][1].Set(283.82,-65.88);
    vertices[69][2].Set(287.94,-65.94);
    vertices[69][3].Set(287.94,-61.88);
    
    vertices[70][0].Set(287.88,-65.82);
    vertices[70][1].Set(287.88,-69.71);
    vertices[70][2].Set(300.94,-69.76);
    vertices[70][3].Set(300.82,-65.35);
    
    vertices[71][0].Set(300.94,-66.24);
    vertices[71][1].Set(304.88,-69.76);
    vertices[71][2].Set(304.88,-62.94);
    vertices[71][3].Set(300.53,-62.71);
    
    vertices[72][0].Set(304.76,-65.35);
    vertices[72][1].Set(304.76,-69.76);
    vertices[72][2].Set(309.12,-69.82);
    vertices[72][3].Set(313.76,-65.82);
    
    vertices[73][0].Set(313.47,-61.53);
    vertices[73][1].Set(313.82,-65.88);
    vertices[73][2].Set(350.53,-65.94);
    vertices[73][3].Set(350.41,-61.35);
    
    vertices[74][0].Set(350.59,-65.88);
    vertices[74][1].Set(350.59,-73.12);
    vertices[74][2].Set(354.94,-73.18);
    vertices[74][3].Set(354.82,-65.82);
    
    vertices[75][0].Set(267.47,-50.41);
    vertices[75][1].Set(262.71,-50.53);
    vertices[75][2].Set(262.94,-58.12);
    vertices[75][3].Set(267.53,-58.06);
    
    vertices[76][0].Set(263.29,-58.12);
    vertices[76][1].Set(259.41,-58.12);
    vertices[76][2].Set(259.24,-61.65);
    vertices[76][3].Set(263.35,-61.41);
    
    vertices[77][0].Set(263.35,-61.41);
    vertices[77][1].Set(263.18,-65.24);
    vertices[77][2].Set(271.65,-65.35);
    vertices[77][3].Set(271.71,-61.41);
    
    vertices[78][0].Set(275.88,-65.29);
    vertices[78][1].Set(271.65,-65.29);
    vertices[78][2].Set(271.53,-69.41);
    vertices[78][3].Set(275.88,-69.18);
    
    vertices[79][0].Set(275.88,-69.18);
    vertices[79][1].Set(275.82,-73.24);
    vertices[79][2].Set(280.06,-73.18);
    vertices[79][3].Set(280.06,-69.18);
    
    vertices[80][0].Set(280.00,-73.18);
    vertices[80][1].Set(280.06,-76.94);
    vertices[80][2].Set(284.29,-77.00);
    vertices[80][3].Set(284.29,-73.18);
    
    vertices[81][0].Set(284.29,-76.94);
    vertices[81][1].Set(284.18,-80.82);
    vertices[81][2].Set(309.29,-80.94);
    vertices[81][3].Set(309.35,-77.06);
    
    vertices[82][0].Set(309.29,-80.88);
    vertices[82][1].Set(309.29,-85.12);
    vertices[82][2].Set(313.53,-84.82);
    vertices[82][3].Set(313.53,-80.88);
    
    vertices[83][0].Set(313.53,-84.82);
    vertices[83][1].Set(313.24,-89.00);
    vertices[83][2].Set(317.59,-88.71);
    vertices[83][3].Set(317.65,-84.82);
    
    vertices[84][0].Set(317.65,-88.71);
    vertices[84][1].Set(317.59,-91.71);
    vertices[84][2].Set(354.82,-91.65);
    vertices[84][3].Set(354.76,-88.82);
    
    vertices[85][0].Set(354.76,-84.71);
    vertices[85][1].Set(354.76,-88.71);
    vertices[85][2].Set(363.35,-88.82);
    vertices[85][3].Set(363.12,-84.82);
    
    vertices[86][0].Set(350.53,-73.18);
    vertices[86][1].Set(342.35,-73.12);
    vertices[86][2].Set(338.12,-77.06);
    vertices[86][3].Set(350.82,-77.24);
    
    vertices[87][0].Set(317.18,-77.00);
    vertices[87][1].Set(326.24,-81.47);
    vertices[87][2].Set(351.12,-81.47);
    vertices[87][3].Set(351.06,-77.00);
    
    vertices[88][0].Set(350.94,-74.18);
    vertices[88][1].Set(351.12,-77.41);
    vertices[88][2].Set(363.41,-69.76);
    vertices[88][3].Set(358.53,-69.76);
    
    vertices[89][0].Set(305.00,-31.18);
    vertices[89][1].Set(309.24,-34.94);
    vertices[89][2].Set(309.24,-31.18);
    vertices[89][3].Set(308.82,-31.06);
    
    vertices[90][0].Set(367.24,-80.88);
    vertices[90][1].Set(363.18,-80.88);
    vertices[90][2].Set(363.12,-84.88);
    vertices[90][3].Set(367.71,-85.06);
    
    vertices[91][0].Set(367.29,-77.06);
    vertices[91][1].Set(367.35,-80.94);
    vertices[91][2].Set(413.24,-80.47);
    vertices[91][3].Set(413.29,-77.06);
    
    vertices[92][0].Set(413.35,-73.06);
    vertices[92][1].Set(413.35,-77.00);
    vertices[92][2].Set(420.18,-76.35);
    vertices[92][3].Set(421.65,-73.12);
    
    vertices[93][0].Set(421.71,-69.24);
    vertices[93][1].Set(421.71,-73.12);
    vertices[93][2].Set(426.18,-73.24);
    vertices[93][3].Set(425.82,-69.29);
    
    vertices[94][0].Set(425.82,-65.29);
    vertices[94][1].Set(425.82,-69.24);
    vertices[94][2].Set(430.18,-69.47);
    vertices[94][3].Set(430.00,-65.29);
    
    vertices[95][0].Set(430.00,-61.41);
    vertices[95][1].Set(430.00,-65.29);
    vertices[95][2].Set(434.29,-65.41);
    vertices[95][3].Set(434.12,-61.47);
    
    vertices[96][0].Set(445.82,-42.88);
    vertices[96][1].Set(434.24,-61.53);
    vertices[96][2].Set(437.94,-61.53);
    vertices[96][3].Set(446.76,-42.24);
    
    vertices[97][0].Set(283.82,-34.94);
    vertices[97][1].Set(283.82,-38.59);
    vertices[97][2].Set(288.24,-42.47);
    vertices[97][3].Set(288.35,-34.94);
    
    vertices[98][0].Set(421.94,-46.41);
    vertices[98][1].Set(430.18,-50.24);
    vertices[98][2].Set(445.82,-42.88);
    vertices[98][3].Set(444.18,-41.12);
    
    vertices[99][0].Set(276.00,-42.29);
    vertices[99][1].Set(273.53,-40.12);
    vertices[99][2].Set(262.71,-50.71);
    vertices[99][3].Set(267.47,-50.47);
    
    vertices[100][0].Set(363.71,-62.12);
    vertices[100][1].Set(363.76,-69.76);
    vertices[100][2].Set(392.94,-69.71);
    vertices[100][3].Set(393.00,-61.82);
    
    vertices[101][0].Set(392.94,-57.47);
    vertices[101][1].Set(392.94,-61.76);
    vertices[101][2].Set(413.76,-61.71);
    vertices[101][3].Set(424.35,-57.65);
    
    vertices[102][0].Set(413.76,-53.71);
    vertices[102][1].Set(413.65,-57.53);
    vertices[102][2].Set(417.94,-57.59);
    vertices[102][3].Set(417.94,-53.76);
    
    vertices[103][0].Set(405.53,-49.82);
    vertices[103][1].Set(405.41,-53.76);
    vertices[103][2].Set(413.82,-53.82);
    vertices[103][3].Set(413.76,-49.94);
    
    vertices[104][0].Set(401.24,-45.94);
    vertices[104][1].Set(401.12,-49.88);
    vertices[104][2].Set(405.41,-49.76);
    vertices[104][3].Set(405.41,-45.94);
    
    vertices[105][0].Set(409.12,-41.94);
    vertices[105][1].Set(421.88,-46.35);
    vertices[105][2].Set(422.47,-43.00);
    vertices[105][3].Set(421.65,-42.12);
    
    vertices[106][0].Set(400.76,-35.06);
    vertices[106][1].Set(401.29,-38.88);
    vertices[106][2].Set(405.41,-34.76);
    vertices[106][3].Set(402.59,-33.76);
    
    vertices[107][0].Set(397.35,-38.71);
    vertices[107][1].Set(396.76,-45.94);
    vertices[107][2].Set(401.24,-45.94);
    vertices[107][3].Set(401.24,-38.71);
    
    vertices[108][0].Set(421.71,-38.06);
    vertices[108][1].Set(421.59,-42.06);
    vertices[108][2].Set(430.06,-42.06);
    vertices[108][3].Set(429.94,-38.12);
    
    vertices[109][0].Set(430.00,-34.18);
    vertices[109][1].Set(430.00,-38.06);
    vertices[109][2].Set(434.29,-38.41);
    vertices[109][3].Set(434.18,-34.18);
    
    vertices[110][0].Set(434.24,-30.29);
    vertices[110][1].Set(434.18,-34.24);
    vertices[110][2].Set(438.53,-33.94);
    vertices[110][3].Set(438.41,-30.29);
    
    vertices[111][0].Set(418.00,-27.00);
    vertices[111][1].Set(404.88,-26.88);
    vertices[111][2].Set(405.41,-34.82);
    vertices[111][3].Set(418.00,-34.65);
    
    vertices[112][0].Set(417.82,-22.88);
    vertices[112][1].Set(418.00,-27.00);
    vertices[112][2].Set(430.53,-20.29);
    vertices[112][3].Set(430.53,-19.41);
    
    vertices[113][0].Set(438.41,-26.47);
    vertices[113][1].Set(438.41,-30.35);
    vertices[113][2].Set(446.82,-30.82);
    vertices[113][3].Set(446.71,-26.47);
    
    vertices[114][0].Set(446.71,-22.53);
    vertices[114][1].Set(446.71,-26.41);
    vertices[114][2].Set(451.12,-26.71);
    vertices[114][3].Set(450.88,-22.47);
    
    vertices[115][0].Set(450.94,-18.12);
    vertices[115][1].Set(450.88,-22.59);
    vertices[115][2].Set(455.41,-22.82);
    vertices[115][3].Set(455.06,-18.12);
    
    vertices[116][0].Set(461.35,22.29);
    vertices[116][1].Set(461.35,19.82);
    vertices[116][2].Set(469.41,19.82);
    vertices[116][3].Set(469.41,22.41);
    
    vertices[117][0].Set(447.06,22.35);
    vertices[117][1].Set(447.06,19.82);
    vertices[117][2].Set(455.35,19.82);
    vertices[117][3].Set(455.29,22.35);
    
    vertices[118][0].Set(432.88,22.00);
    vertices[118][1].Set(432.82,19.47);
    vertices[118][2].Set(441.06,19.47);
    vertices[118][3].Set(441.06,22.00);
    
    vertices[119][0].Set(417.06,22.18);
    vertices[119][1].Set(417.06,19.76);
    vertices[119][2].Set(426.12,19.71);
    vertices[119][3].Set(426.06,22.35);
    
    vertices[120][0].Set(417.06,26.35);
    vertices[120][1].Set(417.12,22.18);
    vertices[120][2].Set(421.71,22.35);
    vertices[120][3].Set(421.71,26.35);
    
    vertices[121][0].Set(399.24,27.29);
    vertices[121][1].Set(399.24,24.76);
    vertices[121][2].Set(412.18,24.71);
    vertices[121][3].Set(412.12,27.24);
    
    vertices[122][0].Set(389.41,27.24);
    vertices[122][1].Set(389.41,23.24);
    vertices[122][2].Set(394.24,23.00);
    vertices[122][3].Set(394.18,27.24);
    
    vertices[123][0].Set(381.06,27.29);
    vertices[123][1].Set(381.06,23.29);
    vertices[123][2].Set(385.82,23.29);
    vertices[123][3].Set(385.82,27.24);
    
    vertices[124][0].Set(368.71,27.12);
    vertices[124][1].Set(368.71,24.65);
    vertices[124][2].Set(376.88,24.59);
    vertices[124][3].Set(376.88,27.12);
    
    vertices[125][0].Set(381.00,23.24);
    vertices[125][1].Set(381.00,20.82);
    vertices[125][2].Set(394.12,20.71);
    vertices[125][3].Set(394.18,23.12);
    
    vertices[126][0].Set(325.53,-42.00);
    vertices[126][1].Set(325.47,-46.00);
    vertices[126][2].Set(329.94,-46.06);
    vertices[126][3].Set(329.76,-42.06);
    
    vertices[127][0].Set(296.53,-53.82);
    vertices[127][1].Set(292.24,-57.65);
    vertices[127][2].Set(304.59,-57.71);
    vertices[127][3].Set(304.59,-53.82);
    
    vertices[128][0].Set(283.88,-57.71);
    vertices[128][1].Set(283.88,-60.65);
    vertices[128][2].Set(288.35,-60.53);
    vertices[128][3].Set(288.29,-53.82);
    
    vertices[129][0].Set(277.53,-57.59);
    vertices[129][1].Set(283.76,-62.06);
    vertices[129][2].Set(283.94,-60.82);
    vertices[129][3].Set(283.88,-57.65);
    
    vertices[130][0].Set(271.71,-65.41);
    vertices[130][1].Set(271.59,-69.35);
    vertices[130][2].Set(275.88,-69.29);
    vertices[130][3].Set(275.88,-65.35);
    
    vertices[131][0].Set(342.41,-73.12);
    vertices[131][1].Set(338.18,-77.06);
    vertices[131][2].Set(350.65,-77.00);
    vertices[131][3].Set(350.53,-73.18);
    
    vertices[132][0].Set(363.12,-80.94);
    vertices[132][1].Set(363.12,-84.94);
    vertices[132][2].Set(367.65,-84.82);
    vertices[132][3].Set(367.29,-80.88);
    
    //LEFT EDGE
    vertices[133][0].Set(-37.35,18.24);
    vertices[133][1].Set(-35.59,-15.06);
    vertices[133][2].Set(-33.53,-15.06);
    vertices[133][3].Set(-33.00,18.35);
    
    //RIGHT EDGE
    vertices[134][0].Set(501.24,39.24);
    vertices[134][1].Set(501.24,0.94);
    vertices[134][2].Set(503.59,0.94);
    vertices[134][3].Set(503.59,30.35);
    
}

void ofApp:: lavaShapes(){
 
    //LAVA POINTS
     
     lavaPoints[0].Set(vertices[6][1].x - 0.70, vertices[6][1].y);
     lavaPoints[1].Set(vertices[7][1].x - 0.70, vertices[7][1].y);
     lavaPoints[2].Set(vertices[9][1].x - 0.70, vertices[9][1].y);
     lavaPoints[3].Set(vertices[16][1].x - 4.88, vertices[16][1].y);
     lavaPoints[4].Set(vertices[28][1].x - 0.70, vertices[28][1].y);
     lavaPoints[5].Set(vertices[34][1].x - 5.05, vertices[34][1].y);
     lavaPoints[6].Set(vertices[36][1].x - 0.70, vertices[36][1].y);
     lavaPoints[7].Set(vertices[122][1].x - 0.70, vertices[122][1].y);
     lavaPoints[8].Set(vertices[56][1].x - 5.05, vertices[56][1].y);
     lavaPoints[9].Set(vertices[64][1].x - 0.70, vertices[64][1].y);
     lavaPoints[10].Set(vertices[126][1].x - 0.70, vertices[126][1].y);
     lavaPoints[11].Set(vertices[132][1].x - 0.70, vertices[132][1].y);
     
     //LAVA RECTANGLES
     
     lavaRecs[0][0].Set(vertices[16][1].x - 4.70, vertices[16][1].y + 2.35);
     lavaRecs[0][1].Set(vertices[16][1].x - 4.70, vertices[16][1].y);
     lavaRecs[0][2].Set(vertices[16][1].x, vertices[16][1].y);
     lavaRecs[0][3].Set(vertices[16][1].x, vertices[16][1].y + 2.35);
     
     lavaRecs[1][0].Set(vertices[34][1].x - 4.70, vertices[34][1].y + 2.35);
     lavaRecs[1][1].Set(vertices[34][1].x - 4.70, vertices[34][1].y);
     lavaRecs[1][2].Set(vertices[34][1].x, vertices[34][1].y);
     lavaRecs[1][3].Set(vertices[34][1].x, vertices[34][1].y + 2.35);
     
     lavaRecs[2][0].Set(vertices[56][1].x - 4.70, vertices[56][1].y + 2.35);
     lavaRecs[2][1].Set(vertices[56][1].x - 4.70, vertices[56][1].y);
     lavaRecs[2][2].Set(vertices[56][1].x, vertices[56][1].y);
     lavaRecs[2][3].Set(vertices[56][1].x, vertices[56][1].y + 2.35);
    
}


void ofApp:: b2DCharacter(){
    
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(1, 1);
    bodyDef.fixedRotation = false;
    mFalling = mWorld->CreateBody(&bodyDef);
    
    b2CircleShape circleShape;
    circleShape.m_p.Set(-0.0f, 0.0f); //position, relative to body position
    circleShape.m_radius = 1.0f; //radius
    
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 0.0001f;
    fixtureDef.friction = 10.0f;
    fixtureDef.restitution = 0.2f;
    
    mFalling->SetFixedRotation(false);
    mFalling->SetAngularVelocity(0);
    
    mFalling->CreateFixture(&fixtureDef);
    
}

//--------------------------------------------------------------

void ofApp::update(){
    
    float timeStep = 1.0f / 60.0f;
    int velocityIterations = 6;
    int positionIterations = 2;
    
    
    mWorld->Step(timeStep, velocityIterations, positionIterations);
    
    ofVec3f ballPos1(mFalling->GetPosition().x, mFalling->GetPosition().y, 1500);
    
    float tempY = cam.getPosition().y;
    
    if(mFalling->GetPosition().y < - 18.59 && mFalling->GetPosition().y > -39.00 && mFalling->GetPosition().x > 282.00 && mFalling->GetPosition().x < 340.00 && cam.getPosition().y != mFalling->GetPosition().y){
        if(cam.getPosition().y > mFalling->GetPosition().y){
            
            cam.setGlobalPosition(ofVec3f(mFalling->GetPosition().x * mScale, tempY -= 2 * mScale, 1500));
            cam.lookAt(ofVec3f(mFalling->GetPosition().x * mScale, tempY -= 2 * mScale, 0));
            
        }
    }
    
    
    
    //Left, Right, Top, Bottom
    if (mFalling->GetPosition().x > 0 && mFalling->GetPosition().x < (ofGetWindowWidth()*7)/mScale){
        if(mFalling->GetPosition().y > - 75.0f && mFalling->GetPosition().y < 42.0f){
    
            cam.setGlobalPosition(ofVec3f(mFalling->GetPosition().x * mScale, mFalling->GetPosition().y * mScale, 1500));
            cam.lookAt(ofVec3f(mFalling->GetPosition().x * mScale, mFalling->GetPosition().y * mScale, 0));
            
        }
        // Basement
        else {
            
            cam.setGlobalPosition(ofVec3f(mFalling->GetPosition().x * mScale, -75.0f * mScale, 1500));
            cam.lookAt(ofVec3f(mFalling->GetPosition().x * mScale, -75.0f * mScale, 0));
            
        }
    }
    
    if (mFalling->GetPosition().x > 0 && mFalling->GetPosition().x < (ofGetWindowWidth()*7)/mScale){
        if(mFalling->GetPosition().y > - 18.59 && mFalling->GetPosition().y < 0){
            
            cam.setGlobalPosition(ofVec3f(mFalling->GetPosition().x * mScale, 0, 1500));
            cam.lookAt(ofVec3f(mFalling->GetPosition().x * mScale, 0, 0));
            
        }
        
    }
    

}



//--------------------------------------------------------------

void ofApp::draw(){
    
    pickUpRotation += 0.1;
    
    //Blue
    
    pickUpPos[0].Set(163.0f * mScale, 0.0f * mScale);
    pickedUpPos[0].Set(-32.00 * mScale + cam.getGlobalPosition().x, 17.65 * mScale + cam.getGlobalPosition().y);
    
    //Green
    
    pickUpPos[1].Set(179.0f * mScale, 24.24 * mScale);
    pickedUpPos[1].Set(pickedUpPos[0].x + 2.00f * mScale, pickedUpPos[0].y);
    
    //Orange
    
    pickUpPos[2].Set(318.0f * mScale, 0.82f * mScale);
    pickedUpPos[2].Set(pickedUpPos[1].x + 2.00f * mScale, pickedUpPos[0].y);
    
    //Purple
    
    pickUpPos[3].Set(387.24f * mScale, 36.25f * mScale);
    pickedUpPos[3].Set(pickedUpPos[2].x + 2.00f * mScale, pickedUpPos[0].y);
    
    //Brown (BASEMENT)

    pickUpPos[4].Set(297.00 * mScale, -41.00 * mScale);
    pickedUpPos[4].Set(pickedUpPos[3].x + 2.00f * mScale, pickedUpPos[0].y);
    
    //Purple (BASEMENT)
    
    pickUpPos[5].Set(347.41 * mScale, -69.00 * mScale);
    pickedUpPos[5].Set(pickedUpPos[4].x + 2.00f * mScale, pickedUpPos[0].y);
    
    //Orange (BASEMENT)
    
    pickUpPos[6].Set(394.24 * mScale, -67.00 * mScale);
    pickedUpPos[6].Set(pickedUpPos[5].x + 2.00f * mScale, pickedUpPos[0].y);
    
    //Beige (BASEMENT)
    
    pickUpPos[7].Set(437.06 * mScale, -53.00 * mScale);
    pickedUpPos[7].Set(pickedUpPos[6].x + 2.00f * mScale, pickedUpPos[0].y);
    
    //Grey (1st)
    
    pickUpPos[9].Set(59.29 * mScale, -7.5 * mScale);
    
    //Buckets
    
    pickUpPos[8].Set(398.24 * mScale, 36.00 * mScale);
    bucketVecs[0].Set(199.35 * mScale, -1.18  * mScale);
    bucketVecs[1].Set(335.41  * mScale, -72.00  * mScale);
    bucketVecs[2].Set(404.24  * mScale, -68.00  * mScale);
    
    
    
    cam.begin();
    
    ofSetColor(255);
    
    ofPushMatrix();
    
    background.draw(ofGetWidth()*1.5, ofGetHeight()/2);
    background.draw(ofGetWidth()*5.5, ofGetWindowHeight()/2);
    buildings.draw(ofGetWidth()*1.5, ofGetHeight()/2);
    buildings.draw(ofGetWidth()*5.5, ofGetWindowHeight()/2);
    
    ofSetColor(255, 255, 255, 255);
    
    for (int a = 0; a < 4; a++){
    
        ofSetColor(255, 255, 255, pickUpVars[a][2]);
        colBuilds[a].draw(ofGetWidth()*1.5, ofGetHeight()/2);
        colBuilds[a].draw(ofGetWidth()*5.5, ofGetWindowHeight()/2);
    }
    
    ofSetColor(255, 255, 255, pickUpVars[8][2]);
    colBuilds[8].draw(ofGetWidth()*1.5, ofGetWindowHeight()/2);
    colBuilds[8].draw(ofGetWidth()*5.5, ofGetWindowHeight()/2);
    
    ofSetColor(255, 255, 255, 255);
    _platform1.draw(ofGetWidth()*1.5, ofGetWindowHeight()/2);
    _platform2.draw(ofGetWidth()*5.5, ofGetWindowHeight()/2);
    _platform3.draw(ofGetWidth()*1.5, -ofGetWindowHeight()*1.5);
    bsmntBackGr.draw(ofGetWidth()*5.5, -ofGetWindowHeight()*1.5);
    
    for (int a = 4; a < 8; a++){
        
        ofSetColor(255, 255, 255, pickUpVars[a][2]);
        colBuilds[a].draw(ofGetWidth()*5.5, -ofGetWindowHeight()*1.5);
        
    }

    
    ofSetColor(255, 255, 255, 255);
    _platform4.draw(ofGetWidth()*5.5, -ofGetWindowHeight()*1.5);
    groundSpikes.draw(ofGetWidth()*1.5, ofGetHeight()/2);
    
    for (int a = 0; a < 8; a++){

        ofSetColor(255, 255, 255, pickUpVars[a][0]);
        pickUps[a].resize(80, 80);
        pickUps[a].draw(pickUpPos[a].x + 0.8 * sin(pickUpRotation), pickUpPos[a].y);
        
        ofSetColor(255, 255, 255, pickUpVars[a][1]);
        pickedUps[a].resize(80, 80);
        pickedUps[a].draw(pickedUpPos[a].x + 0.8 * sin(pickUpRotation), pickedUpPos[a].y);
        
        ofSetColor(255, 255, 255, 255);

    }
    
    ofSetColor(255, 255, 255, pickUpVars[9][0]);
    pickUps[9].resize(80, 80);
    pickUps[9].draw(pickUpPos[9].x + 0.8 * sin(pickUpRotation), pickUpPos[9].y);
    
    ofSetColor(255, 255, 255, pickUpVars[8][0]);
    pickUps[8].resize(80, 80);
    pickUps[8].draw(pickUpPos[8].x + 0.8 * sin(pickUpRotation), pickUpPos[8].y);
    pickUps[8].draw(bucketVecs[0].x + 0.8 * sin(pickUpRotation), bucketVecs[0].y);
    pickUps[8].draw(bucketVecs[1].x + 0.8 * sin(pickUpRotation), bucketVecs[1].y);
    pickUps[8].draw(bucketVecs[2].x + 0.8 * sin(pickUpRotation), bucketVecs[2].y);
    
    ofPushMatrix();
    ofSetColor(255, 255, 255, 255);
    ofScale(mScale, mScale);
    ofTranslate(mFalling->GetPosition().x, mFalling->GetPosition().y);
    ofRotate(ofRadToDeg(mFalling->GetAngle()), 0, 0, 1);
    ofSetColor(255);
    ball.setAnchorPercent(0, 0);
    ball.draw(0, 0, 2, 2);
    
    ofPopMatrix();
    
    ofSetColor(255, 255, 255, pickUpVars[8][0]);
    colBuilds[9].draw(cam.getGlobalPosition().x, cam.getGlobalPosition().y);
    
    if (lavaTouched) {
    ofSetColor(255, 255, 255, 255);
    findBucket.draw(cam.getGlobalPosition().x, cam.getGlobalPosition().y);
    }
    
    ofSetColor(255, 255, 255, 255);
    crt.draw(cam.getGlobalPosition().x, cam.getGlobalPosition().y);
    
    ofPopMatrix();
    
    
    ofPushMatrix();
    ofScale(mScale, mScale);
    ofSetColor(255, 255, 255, 255);

    ofSetColor(255, 0, 0, 100);
    ofFill();
    
    int bands = 256;
    float * soundSpectrum;
    soundSpectrum = ofSoundGetSpectrum(bands);
    
    if (mFalling->GetPosition().y <  - 18.59){
        inBasement = true;
    }
    else {
        inBasement = false;
    }
    
    //FIRST PICKUP
    
        if (ofDist(mFalling->GetPosition().x, mFalling->GetPosition().y, pickUpPos[9].x/mScale, pickUpPos[9].y/mScale) < 2.0f){
            pickedUp[9] = true;
            pickUpVars[9][6] += 1;
        }
        
        if (pickUpVars[9][6] == 1){
            grab.setVolume(1.0f);
            grab.play();
            music[8].setVolume(1.0f);
        }
    
        if (pickedUp[9]){
        pickUpVars[9][3] += 1;
        if (pickUpVars[9][3] > 0 && pickupVol[9] < 1.0){
            music[8].setVolume(pickupVol[9] += 0.005);
            pickUpVars[9][4] = 1;
        }
        
        if (pickUpVars[9][4] == 1){
            pickUpVars[9][5] += 2;
            if (pickUpVars[9][5] > 150){
                pickUpVars[9][5] = 150;
            }
        }
        pickUpVars[9][0] -= 20;
        pickUpVars[9][1] +=20;
        //pickUpVars[9][2] = (soundSpectrum[12])*600 * pickUpVars[9][4] + pickUpVars[9][5];
    }
    
    else {
        
        if (!pickedUp[9]){
            music[8].setVolume(0.0f);
            pickUpVars[9][0] = 255;
            pickUpVars[9][1] = 0;
            pickUpVars[9][2] = 0;
        }
    }
    
    //BUCKET
    
    if (lavaTouched){
        
        if (pickUpVars[8][0] < 254){
        pickUpVars[8][0] += 1;
        }
        
        if (ofDist(mFalling->GetPosition().x, mFalling->GetPosition().y, pickUpPos[8].x/mScale, pickUpPos[8].y/mScale) < 2.0f){
            pickUpVars[8][0] -= 1;
            alphaAddSpike = 0;
            pickedUp[8] = true;
            lavaTouched = false;
            music[10].setVolume(1.0);
            music[10].play();
            lava.setVolume(0.0);

            
        }
        

    }
    else if (!lavaTouched && pickUpVars[8][0] > 21){
        pickUpVars[8][0] -= 20;
        pickUpsInit();
    }

        
        
    if (lavaTouched){
        
        
        for (int i = 0; i < 3; i++){
        
        if (pickUpVars[8][0] < 254){
            pickUpVars[8][0] += 1;
        }
        
        if (ofDist(mFalling->GetPosition().x, mFalling->GetPosition().y, bucketVecs[i].x/mScale, bucketVecs[i].y/mScale) < 2.0f){
            pickUpVars[8][0] -= 1;
            alphaAddSpike = 0;
            pickedUp[8] = true;
            lavaTouched = false;
            music[10].setVolume(1.0);
            music[10].play();
            lava.setVolume(0.0);
            
            
        }
        
        
    }
    }
    else if (!lavaTouched && pickUpVars[8][0] > 21){
        pickUpVars[8][0] -= 20;
        pickUpsInit();
    
    }
    
    
    // UPSTAIRS PICKUPS


if (!inBasement){
    
    //cout << "not in da B" << endl;
    for (int i = 4; i < 8; i ++){
        if (pickupVol[i] > 0.0){
        music[i].setVolume(pickupVol[i] -= 0.005);
        }
    }
    
if (!lavaTouched){
    
    for (int a = 0; a < 4; a ++) {
        if (ofDist(mFalling->GetPosition().x, mFalling->GetPosition().y, pickUpPos[a].x/mScale, pickUpPos[a].y/mScale) < 2.0f){
            pickedUp[a] = true;
            pickUpVars[a][6] += 1;
        }
        
        if (pickUpVars[a][6] == 1){
            grab.setVolume(1.0f);
            grab.play();
        }
        
        if (pickedUp[a]){
            pickUpVars[a][3] += 1;
            if (pickUpVars[a][3] > 0 && pickupVol[a] < 1.0){
                music[a].setVolume(pickupVol[a] += 0.005);
                pickUpVars[a][4] = 1;
            }
            
            if (pickUpVars[a][4] == 1){
                pickUpVars[a][5] += 2;
                if (pickUpVars[a][5] > 150){
                    pickUpVars[a][5] = 150;
                }
            }
            pickUpVars[a][0] -= 20;
            pickUpVars[a][1] +=20;
            pickUpVars[a][2] = (soundSpectrum[12])*600 * pickUpVars[a][4] + pickUpVars[a][5];
        }
        
        else {
            
            if (!pickedUp[a]){
                music[a].setVolume(0.0f);
                pickUpVars[a][0] = 255;
                pickUpVars[a][1] = 0;
                pickUpVars[a][2] = 0;
            }
        }
        
    }
}
}

    
///////////// PILL PICKUP ///////////////
    
    if (ofDist(mFalling->GetPosition().x, mFalling->GetPosition().y, pickUpPillX, pickUpPillY) < 2.0f){
        pickUpCountPill += 1;
    }
    
    if (pickUpCountPill == 1){
        grab.setVolume(1.0f);
        grab.play();
    }
    
    if (pickUpCountPill >= 1){
            pDisplayPill += 1;
            if (pDisplayPill > 0){
                hatsClaps.setVolume(1.0f);
                chords.setVolume(1.0f);
                kick.setVolume(1.0f);
                bass.setVolume(1.0f);
                lava.setVolume(0.0f);
                alphaMulPill = 1;
                alphaMulSpike = 0;
                buildingsSpikeAlpha = (soundSpectrum[12])*600 * alphaMulSpike;

            }
        if (alphaMulPill == 1){
            alphaAddPill += 2;
            if (alphaAddPill > 150){
                alphaAddPill = 150;
            }
        }
        pickUpPillAlpha -= 20;
        pickedUpPillAlpha +=20;
        buildingsPillAlpha = (soundSpectrum[12])*600 * alphaMulPill + alphaAddPill;
        buildingsSpikeAlpha -= 20;
        alphaMulSpike = 0;
        buildingsSpikeAlpha = (soundSpectrum[12])*600 * alphaMulSpike;

    }
    
    else {
        
        if (pDisplaySpike < 1){

            pickUpSpikeAlpha = 255;
            pickUpPillAlpha = 255;
            pickedUpSpikeAlpha = 0;
            buildingsSpikeAlpha = 0;
        }
    }


if (inBasement){
    
    //cout << "in da B" << endl;
    music[9].setVolume(1.0);
    for (int i = 0; i < 4; i ++){
        if (pickupVol[i] > 0.0){
            music[i].setVolume(pickupVol[i] -= 0.005);
        }
    }
    
    if (!lavaTouched){
    
    //BASEMENT PICKUPS
    
    for (int a = 4; a < 8; a ++) {
        if (ofDist(mFalling->GetPosition().x, mFalling->GetPosition().y, pickUpPos[a].x/mScale, pickUpPos[a].y/mScale) < 2.0f){
            pickedUp[a] = true;
            pickUpVars[a][6] += 1;
        }
        
        if (pickUpVars[a][6] == 1){
            grab.setVolume(1.0f);
            grab.play();
        }
        
        if (pickedUp[a]){
            pickUpVars[a][3] += 1;
            if (pickUpVars[a][3] > 0 && pickupVol[a] < 1.0){
                music[a].setVolume(pickupVol[a] += 0.005);
                pickUpVars[a][4] = 1;
            }
            
            if (pickUpVars[a][4] == 1){
                pickUpVars[a][5] += 2;
                if (pickUpVars[a][5] > 150){
                    pickUpVars[a][5] = 150;
                }
            }
            pickUpVars[a][0] -= 20;
            pickUpVars[a][1] +=20;
            pickUpVars[a][2] = (soundSpectrum[12])*600 * pickUpVars[a][4] + pickUpVars[a][5];
        }
        
        else {
            
            if (!pickedUp[a]){
                music[a].setVolume(0.0f);
                pickUpVars[a][0] = 255;
                pickUpVars[a][1] = 0;
                pickUpVars[a][2] = 0;
            }
        }
    }
    
    }
}

    //  LAVA TOUCHED
    
    for (int a = 0; a < 8; a++){
    
    if (lavaTouched){
            music[a].setVolume(0.0f);
            buildingsSpikeAlpha = (soundSpectrum[8])*600 * alphaMulSpike + alphaAddSpike;
            pickUpVars[8][2] = (soundSpectrum[8])*600 * alphaMulSpike + alphaAddSpike;
            pickUpVars[9][2] = (soundSpectrum[8])*600 * alphaMulSpike + alphaAddSpike;
            alphaAddSpike += 2;
            pickUpVars[a][0] = 0;
            pickUpVars[a][1] = 0;
            pickedUp[a] = false;
            music[9].setVolume(0.0);
        
            if(alphaAddSpike == 4){
            music[11].setVolume(1.0);
            music[11].play();
            }
    
        
            if (alphaAddSpike > 150){
                alphaAddSpike = 150;
            }
        
            if(lava.getVolume() < 1){
                lava.setVolume(lavaVol += 0.005f);
            }
            else if(lava.getVolume() > 1){
                lava.setVolume(1.00);
            }
    }

        
    }

    
    //DISPLAY DEBUG GROUND SHAPES
    
    /*for(int x = 0; x < 150; x++){
        
        if (mMouse->GetPosition().x > vertices[x][0].x && mMouse->GetPosition().x < vertices[x][3].x
            && mMouse->GetPosition().y > vertices[x][1].y  && mMouse->GetPosition().y < vertices[x][0].y){
            
            ofSetColor(255, 255, 0, 100);
            ofBeginShape();
            for(int i = 0; i < 4; i++){
                ofVertex(vertices[x][i].x, vertices[x][i].y);
            }
            ofEndShape(true);
        }
        
        else;
        
        
        ofSetColor(255, 0, 0, 100);
        ofBeginShape();
        for(int i = 0; i < 4; i++){
            ofVertex(vertices[x][i].x, vertices[x][i].y);
        }
        ofEndShape(true);
        
        }*/
    
    for (int a = 0; a < 3; a++){
        if (mFalling->GetPosition().x > lavaRecs[a][0].x && mFalling->GetPosition().x < lavaRecs[a][2].x && mFalling-> GetPosition().y < lavaRecs[a][0].y && mFalling->GetPosition().y > lavaRecs[a][1].y){
            lavaTouched = true;
            //cout << "Player Deceased" << endl;
        }
    }
    
    for (int c = 0; c < 12; c++){
        if (ofDist(mFalling->GetPosition().x, mFalling->GetPosition().y, lavaPoints[c].x, lavaPoints[c].y) < 3.51f) {
            lavaTouched = true;
            //cout << "Player Deceased" << endl;
        }
    }
    
    ofPopMatrix();
    
    cam.end();
    
    cout << pickedUp[8] << endl;

}


//--------------------------------------------------------------

void ofApp::keyPressed(int key){
    
    //cam.setGlobalPosition(x, y, z);
    //cam.lookAt(ofVec3f (x,y,0));
    
    
    b2Vec2 vel = mFalling->GetLinearVelocity();
    
    switch(key){
            
        case 'w': //jump
        {
            for (int a = 0; a < 134; a++){
                if(mFalling->GetPosition().x > vertices[a][0].x && mFalling->GetPosition().x < vertices[a][3].x){
                    for (int b = 0; b < 4; b++){
                        if (mFalling->GetPosition().y - vertices[a][b].y < 1.2f && mFalling->GetPosition().y - vertices[a][b].y > 0.2f){
                            vel.y = 20;//upwards - don't change x velocity
                            mFalling->SetLinearVelocity( vel );
                        }
                    }
                }
            }
        }
            
            break;
            
        case 'd': //move right
        {
            vel.x = vel.x + 4;
            mFalling->SetLinearVelocity( vel );
            
            if(mFalling->GetLinearVelocity().x >= 15.0) {
                vel.x = 15.0;
                mFalling->SetLinearVelocity( vel );
            }
        }
            
            break;
            
        case 'a': //move left
        {
            vel.x = vel.x - 4 ;
            mFalling->SetLinearVelocity( vel );
            
            if(mFalling->GetLinearVelocity().x <= -15) {
                vel.x = -15;
                mFalling->SetLinearVelocity( vel );
            }
            
            break;
        }

    
    }
    //cout << lavaTouched << endl;
   // cout << "ball X:" << mFalling->GetPosition().x << ", Mouse X:" << mouseX/5 << endl;
   // cout << "ball Y:" << mFalling->GetPosition().y << ", Mouse Y:" << mouseY/5 << endl;

}


//--------------------------------------------------------------

void ofApp::keyReleased(int key){
    
    
}

//--------------------------------------------------------------

void ofApp::mouseMoved(int x, int y){
    
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

void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------

void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}

//--------------------------------------------------------------

void ofApp::debugDraw(){
        
}

//-------------------------------------------------------------

void ofApp::exit(){
    
    delete mWorld;
    
}