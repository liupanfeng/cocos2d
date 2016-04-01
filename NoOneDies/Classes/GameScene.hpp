//
//  GameScene.hpp
//  NoOneDies
//
//  Created by 刘盘风 on 16/3/31.
//
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include <stdio.h>
#include "GameController.hpp"

USING_NS_CC;

class Game:public LayerColor {
    
private:
    Vector<GameController*> gcs;
    int _heroCount;
    EventListenerPhysicsContact * contactListener;
    EventListenerTouchOneByOne * touchListener;
    
private:
    void addContactListener();
    void addUserTouchListener();
    void addGcs(int heroCount);
    
public:
    virtual bool initWithHeroCount(int heroCount);
    virtual void update(float dt);
    static Game * create(int heroCount);
    static Scene* createScene(int heroCount);
};


#endif /* GameScene_hpp */
