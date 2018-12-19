#pragma once
#include "cocos2d.h"

USING_NS_CC;
class LoginScenes : public CCLayer
{
public:
	LoginScenes(void);
	~LoginScenes(void);

	void makebd(float num,int w,int tag);

	void movebd(float times);

	void nextCallback(CCObject* pSender);
    virtual void registerWithTouchDispatcher(void);
    virtual bool ccTouchBegan(CCTouch *pTouch,CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch,CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch,CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch,CCEvent *pEvent);
	//开始
	void menuStartGame(CCObject* pSender);
	//新建
	void menuNewGame(CCObject* pSender);
};

