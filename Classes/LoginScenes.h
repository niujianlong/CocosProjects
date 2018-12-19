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
#if COCOS2DX_VERSION_2X
    virtual void registerWithTouchDispatcher(void);
#endif
    virtual bool onTouchBegan(CCTouch *pTouch,CCEvent *pEvent);
    virtual void onTouchMoved(CCTouch *pTouch,CCEvent *pEvent);
    virtual void onTouchEnded(CCTouch *pTouch,CCEvent *pEvent);
    virtual void onTouchCancelled(CCTouch *pTouch,CCEvent *pEvent);
	//开始
	void menuStartGame(CCObject* pSender);
	//新建
	void menuNewGame(CCObject* pSender);
};

