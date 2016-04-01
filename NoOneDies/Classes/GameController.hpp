//
//  GameController.hpp
//  NoOneDies
//
//  Created by 刘盘风 on 16/3/30.
//
//

#ifndef GameController_hpp
#define GameController_hpp

#include <stdio.h>
#include "Edge.hpp"
#include "Hero.hpp"
#include "Block.hpp"
#include <cocos2d.h>
USING_NS_CC;

class GameController :public Scheduler{
    
private:
    Layer * _layer;
    bool running;
    float _positionY;
    int nextKeyFrameIndex;
    int frameIndex;
    Node * _edge;
    Hero * _hero;
    
private:
    void resetTimer();
    
public:
    virtual bool initWithLayerAndPositionY(Layer * layer,float positionY);
    void onUpdate();
    Node * getEdge();
    void onTouch();
    static GameController* create(Layer * layer,float positionY);
};

#endif /* GameController_hpp */
