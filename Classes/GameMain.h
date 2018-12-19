﻿#ifndef __GAMEMAIN_H__
#define __GAMEMAIN_H__

#include "cocos2d.h"

#include "MapSpirits/MapsBase.h"
#include "Commen/FDPixelSprite.h"

class GameMain : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(GameMain);

	virtual void GoToCcene(CCObject* pSender);

	MapsBase* mainmap;
	FDPixelSprite* mainmap_Touch;
	float map_x , map_y;

	//点击事件部分
	void nextCallback(CCObject* pSender);
#if COCOS2DX_VERSION_2X
    virtual void registerWithTouchDispatcher(void);
#endif
    virtual bool onTouchBegan(CCTouch *pTouch,CCEvent *pEvent);
    virtual void onTouchMoved(CCTouch *pTouch,CCEvent *pEvent);
    virtual void onTouchEnded(CCTouch *pTouch,CCEvent *pEvent);
    virtual void onTouchCancelled(CCTouch *pTouch,CCEvent *pEvent);

	//故事对话框
	TipsForStory* storyTips_part1;
	TipsForStory* storyTips_part2;
	//故事里面的NPC列表
	CCArray* npclist;



	void storyplaydataflag(float times);
};

#endif // __GAMEMAIN_H__
