//
//  Hero.cpp
//  NoOneDies
//
//  Created by 刘盘风 on 16/3/29.
//
//

#include "Hero.hpp"
#include "FlashTool.h"

bool Hero::init(){
    Sprite::init();
    
    Size s = Size(44, 52);
    
    setContentSize(s);
    setPhysicsBody(PhysicsBody::createBox(s));
    runAction(RepeatForever::create(FlashTool::readJsonSpriteSheet("hero.json", 0.2f)));
    setScale( 0.8);
    getPhysicsBody()->setRotationEnable(false);
    getPhysicsBody()->setContactTestBitmask(1);
    
    
//    Size s = Size(44, 52);
//    
//    runAction(RepeatForever::create(FlashTool::readJsonSpriteSheet("Hero.json", 0.22f)));
//    
//    setPhysicsBody(PhysicsBody::createBox(s));
//    setContentSize(s);
//    setScale( 0.8);
//    getPhysicsBody()->setRotationEnable(false);
//    getPhysicsBody()->setContactTestBitmask(1);
    
    return true;
}