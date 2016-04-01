//
//  Block.cpp
//  NoOneDies
//
//  Created by 刘盘风 on 16/3/30.
//
//

#include "Block.hpp"

bool Block::init(){
    Sprite::init();
    Size s=Size((rand()%20)+5, (rand()%30)+10);
    Size  visibleSize=Director::getInstance()->getVisibleSize();
    setTextureRect(Rect(0, 0, s.width,s.height));
    setPhysicsBody(PhysicsBody::createBox(s));
    setContentSize(s);
    setColor(Color3B(0,0,0));
    setPositionX(visibleSize.width);
    scheduleUpdate();
    getPhysicsBody()->setDynamic(false);
    getPhysicsBody()->setContactTestBitmask(1);
//    Size size=Size((rand()%20)+5, (rand()%30)+10);
//    
//    auto r=Sprite::create();
//    r->setTextureRect(Rect(0, 0, size.width,size.height));
//    r->setPhysicsBody(PhysicsBody::createBox(size));
//    r->setContentSize(size);
//    addChild(r);

    

    
    return true;
}

void Block::update(float dt){
    this->setPositionX(getPositionX()-2);
    if (getPositionX()<0) {
//        log(">>>>>>>");
        unscheduleUpdate();
        removeFromParent();
    }
    
}