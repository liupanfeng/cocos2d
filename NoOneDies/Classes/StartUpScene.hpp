//
//  StartUpScene.hpp
//  NoOneDies
//
//  Created by 刘盘风 on 16/3/31.
//
//

#ifndef StartUpScene_hpp
#define StartUpScene_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "GameController.hpp"

USING_NS_CC;

class GameController;

class StartUp : public cocos2d::LayerColor
{
    
private:
    Label *btnTwo,*btnThree,*btnFour,*btnFive;
    EventListenerTouchOneByOne * touchListener;
    
private:
    void addBtns();
    void addBtnListeners();
    
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(StartUp);
};


#endif /* StartUpScene_hpp */
