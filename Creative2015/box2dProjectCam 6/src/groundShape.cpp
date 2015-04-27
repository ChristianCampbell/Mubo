//
//  groundShape.cpp
//  emptyExample
//
//  Created by Max Chambati-Woodhead on 11/03/2015.
//
//

#include "groundShape.h"


groundShape::groundShape(int _index, ofVec2f _gp, vector<ofVec2f> _v){

    index = _index;
    mGlobPos.set( _gp);
    mRelVertices = _v;

    
}

b2Body * groundShape::createBody(b2World * b){
    
    mBd.type = b2_staticBody;
    mBd.position.Set(mGlobPos.x, mGlobPos.y);
    mBody = b->CreateBody(&mBd);
    
    int numverts = mRelVertices.size();
    
    b2Vec2 * verts = new b2Vec2[mRelVertices.size()];
    
    
    for(int i = 0; i < mRelVertices.size(); i++){
        verts[i].Set(mRelVertices[i].x + mGlobPos.x, mRelVertices[i].y + mGlobPos.y);
    }
    
    b2PolygonShape platform;
    platform.Set(verts, mRelVertices.size());
    mBody->CreateFixture(&platform, 22.0f);

    delete verts;
    

}


