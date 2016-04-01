//
//  GameOverScene.hpp
//  NoOneDies
//
//  Created by 刘盘风 on 16/3/30.
//
//

#ifndef GameOverScene_hpp
#define GameOverScene_hpp

#include <stdio.h>
#include <cocos2d.h>
USING_NS_CC;

class GameOver:public LayerColor {
    
private:
    int _currentHeroCount;
    double _score;
    Label *btnReplay,*btnGoHome;
    EventListenerTouchOneByOne * touchListener;
    
private:
    Label * createButton(std::string text,float fontSize);
    
public:
    virtual bool initWithCurrentHeroCountAndScore(int currentHeroCount,double score);
    
    static Scene* createScene(int currentHeroCount,double score);

    static GameOver* create(int currentHeroCount,double score);
};

#endif /* GameOverScene_hpp */
