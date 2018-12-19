#ifndef __SCENE_TEST__
#define __SCENE_TEST__
#include "cocos2d.h"
#include "ToScene.h"
USING_NS_CC;

class SceneTest : public ToScene
{
public:
	virtual void runThisTest();
};

class TestLayer1 : public CCLayer
{
public:
    TestLayer1(void);
    ~TestLayer1(void);
    void nextCallback(CCObject* pSender);
    virtual void registerWithTouchDispatcher(void);
    virtual bool ccTouchBegan(CCTouch *pTouch,CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch,CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch,CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch,CCEvent *pEvent);
	
};

class TestLayer2 : public CCLayer        
{
public:
    TestLayer2(void);
    ~TestLayer2(void);
    void backCallback(CCObject* pSender);
};

#endif //__SCENE_TEST__