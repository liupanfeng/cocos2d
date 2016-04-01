//
//  GameController.cpp
//  NoOneDies
//
//  Created by 刘盘风 on 16/3/30.
//
//

#include "GameController.hpp"


GameController* GameController::create(cocos2d::Layer *layer, float positionY){
    GameController * _ins = new GameController();
    _ins->initWithLayerAndPositionY(layer, positionY);
    _ins->autorelease();
    return _ins;
}


bool GameController::initWithLayerAndPositionY(cocos2d::Layer *layer, float positionY){
    _layer = layer;
    _positionY = positionY;
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    //add edge
    _edge = Edge::create();
    _edge->setPosition(visibleSize.width/2, visibleSize.height/2+positionY);
    _edge->setContentSize(visibleSize);
    layer->addChild(_edge);
    
//    _edge = Edge::create();
//    _edge->setPosition(0, positionY);
//    _edge->setContentSize(visibleSize);
//    layer->addChild(_edge);
    
    
    //add ground
//    auto ground = Sprite::create();
//    ground->setTextureRect(Rect(0, 0, visibleSize.width, 3));
//    ground->setColor(Color3B(0, 0, 0));
//    layer->addChild(ground);
//    ground->setPosition(visibleSize.width/2, visibleSize.height/2);
    auto ground = Sprite::create();
    ground->setColor(Color3B(0, 0, 0));
    ground->setTextureRect(Rect(0, 0, visibleSize.width, 3));
    ground->setPosition(visibleSize.width/2,1.5+positionY);
    layer->addChild(ground);
    
    
    //add hero
    _hero = Hero::create();
    layer->addChild(_hero);
    _hero->setPosition(50, positionY+_hero->getContentSize().height);
    
    resetTimer();
    return true;
}

void GameController::resetTimer(){
    frameIndex = 0;
    nextKeyFrameIndex = rand()%100+120;
}

void GameController::onUpdate(){
    
    frameIndex++;
    
    if (frameIndex>=nextKeyFrameIndex) {
        
        auto b = Block::create();
        _layer->addChild(b);
        b->setPositionY(_positionY+b->getContentSize().height/2);
        
        resetTimer();
    }
}


Node* GameController::getEdge(){
    return _edge;
}


void GameController::onTouch(){
//     _hero->getPhysicsBody()->setVelocity(Vec2(0, 400));
    if (_hero->getPositionY()<_positionY+_hero->getContentSize().height/2+5) {
        _hero->getPhysicsBody()->setVelocity(Vec2(0, 400));
    }
}