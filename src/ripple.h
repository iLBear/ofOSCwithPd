//
//  ripple.h
//  myOSCtest
//
//  Created by iLBe@r on 2013/04/05.
//
//

#ifndef __myOSCtest__ripple__
#define __myOSCtest__ripple__

#include <iostream>
#include "ofMain.h"

class Ripple{
public:
    float radian;
    ofColor color;
    ofPoint point;
    float speed;
    void update();
    int life;
    
    Ripple(){
        radian = 0.0f;
        speed  = 0.0f;
        color.set(0, 0, 0, 0);
        point.set(0, 0);
        life = 0;
    }
    
};


#endif /* defined(__myOSCtest__ripple__) */
