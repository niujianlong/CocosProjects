//
//  FDPixelSprite.h
//  PixelDemo
//
//  Created by firedragonpzy on 13-2-19.
//
//

#ifndef __PixelDemo__FDPixelSprite__
#define __PixelDemo__FDPixelSprite__
#include "cocos2d.h"
USING_NS_CC;

class FDPixelSprite : public CCSprite, public CCTargetedTouchDelegate {
public:
    FDPixelSprite();
    virtual ~FDPixelSprite();
    
    void onEnter();
    void onExit();
	void setimg(CCString Url);
    
    FDPixelSprite* create(CCString Url);
	CCImage* img ;
    
    CCRect atlasRect();
    bool isContainTouchLocation(CCTouch *pTouch);
    
    bool ccTouchBegan(CCString thismapurl,CCTouch *pTouch, CCEvent *pEvent);
    void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);

    CC_SYNTHESIZE(const char*, m_pName,Name);
};

#endif /* defined(__PixelDemo__FDPixelSprite__) */
