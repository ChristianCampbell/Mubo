//
//  groundShape.h
//  emptyExample
//
//  Created by Max Chambati-Woodhead on 11/03/2015.
//
//

#ifndef __emptyExample__groundShape__
#define __emptyExample__groundShape__

#include <stdio.h>
#include "Box2D.h"
#include "ofMain.h"




class groundShape{
    
    public:
    
    groundShape(int _index, ofVec2f _gp , vector<ofVec2f> _v);
    b2Body * createBody(b2World * b);
    
    
    private:
    
    int index;
    ofVec2f mGlobPos;
    vector<ofVec2f> mRelVertices;
    
    b2BodyDef mBd;
    b2Body * mBody;
    

};

#endif /* defined(__emptyExample__groundShape__) */