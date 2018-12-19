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
#if 0
	virtual void registerWithTouchDispatcher(void);
#endif // 0

    virtual bool onTouchBegan(CCTouch *pTouch,CCEvent *pEvent);
    virtual void onTouchMoved(CCTouch *pTouch,CCEvent *pEvent);
    virtual void onTouchEnded(CCTouch *pTouch,CCEvent *pEvent);
    virtual void onTouchCancelled(CCTouch *pTouch,CCEvent *pEvent);
	
};

class TestLayer2 : public CCLayer        
{
public:
    TestLayer2(void);
    ~TestLayer2(void);
    void backCallback(CCObject* pSender);
};

#endif //__SCENE_TEST__