//
//  FlashTool.hpp
//  NoOneDies
//
//  Created by 刘盘风 on 16/3/30.
//
//

#ifndef FlashTool_hpp
#define FlashTool_hpp

#include <stdio.h>
#include <cocos2d.h>

USING_NS_CC;

class FlashTool {
    
public:
    static Animate * readJsonSpriteSheet(std::string jsonFile,float delayPerUnit);
};


#endif /* FlashTool_hpp */
