//
//  Edge.cpp
//  NoOneDies
//
//  Created by 刘盘风 on 16/3/29.
//
//

#include "Edge.hpp"
bool Edge::init(){
    Node::init();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    setContentSize(visibleSize); //这里注意要先设置contentSize 再设置引擎什么的
    setAnchorPoint(Vec2(0.5,0.5));//设置锚点，如果缺少这个，会发生边界跑到左上角或者其他错误！！！！！！！
    setPhysicsBody(PhysicsBody::createEdgeBox(visibleSize));
  
    return true;
}