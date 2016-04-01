//
//  Hero.hpp
//  NoOneDies
//
//  Created by 刘盘风 on 16/3/29.
//
//

#ifndef Hero_hpp
#define Hero_hpp

#include <stdio.h>
#include <cocos2d.h>
USING_NS_CC;

class Hero :public Sprite{
public:
    CREATE_FUNC(Hero);
    virtual bool init();
    
};


#endif /* Hero_hpp */
