//
//  ripple.cpp
//  myOSCtest
//
//  Created by iLBe@r on 2013/04/05.
//
//

#include "ripple.h"

void Ripple::update(){
    static int threshold = 50;
    
    radian += speed;
    life--;
    
    if(life > threshold){
        color.a = 100;
    }else{
        speed *= 1.03;
        color.a = ofMap(life, 0, threshold, 0, 100);
    }
}