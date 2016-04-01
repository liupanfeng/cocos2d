//
//  Block.hpp
//  NoOneDies
//
//  Created by 刘盘风 on 16/3/30.
//
//

#ifndef Block_hpp
#define Block_hpp

#include <stdio.h>
#include <cocos2d.h>
USING_NS_CC;

class Block:public Sprite{
public:
    virtual bool init();
    virtual void update(float dt);
    CREATE_FUNC(Block);
};

#endif /* Block_hpp */
