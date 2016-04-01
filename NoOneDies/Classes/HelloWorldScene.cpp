#include "HelloWorldScene.h"

#include "GameOverScene.hpp"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();//这样创建场景，就可以使用物理引擎了
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vec2(-1000,-800));//设置重力加速度
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !LayerColor::initWithColor(Color4B(255,255,255,255)))
    {
        return false;
    }
    
//    Size visibleSize = Director::getInstance()->getVisibleSize();
//    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
//    // add edge
//    auto edge=Edge::create();
//    edge->setPosition(visibleSize.width/2, visibleSize.height/2);
//    addChild(edge);
//    
//    // add hero
//    auto hero=Hero::create();
//    hero->setPosition(50, 50);
//    addChild(hero);
    
//    //add block
//    auto block=Block::create();
//    addChild(block);
//  
//    block->setPosition(visibleSize.width,block->getContentSize().height/2);
//    gcs.pushBack(GameController::create(this, 30));

    gcs.insert(0, GameController::create(this, 30));
    
    gcs.insert(0, GameController::create(this, 180));
    scheduleUpdate();
    
//    auto listener = EventListenerPhysicsContact::create();
//    listener->onContactBegin = [this](PhysicsContact & contact){
//        this->unscheduleUpdate();
//        
////        Director::getInstance()->replaceScene(GameOverScene::createScene());
//        
//        return true;
//    };
//    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
//    
//    
//    auto touchListener = EventListenerTouchOneByOne::create();
//    touchListener->onTouchBegan = [this](Touch * t,Event * e){
//        
//
//         
//        for (auto it = gcs.begin(); it!=gcs.end(); it++) {
//            if ((*it)->hitTestPoint(t->getLocation())) {
//                (*it)->onUserTouch();
//                break;
//            }
//        }
//        
//        return false;
//    };
//    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    return true;
}

void HelloWorld::update(float ft){
//    for(auto it=gcs.begin();it!=gcs.end();it++){
//        (*it)->onUpdate(ft);
//    }
}
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
