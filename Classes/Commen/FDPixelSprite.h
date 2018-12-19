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

class FDPixelSprite : public CCSprite {
public:
    FDPixelSprite();
    virtual ~FDPixelSprite();
    
    virtual void onEnter();  //继承于Node的虚函数
    virtual void onExit();  //继承于Node的虚函数
	void setimg(CCString Url);
    
    FDPixelSprite* create(CCString Url);
	CCImage* img ;
    
    CCRect atlasRect();
    bool isContainTouchLocation(CCTouch *pTouch);
    
    bool onTouchBegan(CCTouch *pTouch, CCEvent *pEvent);//这里不是继承于Layer的虚函数，所以不加virtual
    void onTouchMoved(CCTouch *pTouch, CCEvent *pEvent);//同上
    void onTouchEnded(CCTouch *pTouch, CCEvent *pEvent);//同上
private:
	EventListenerTouchOneByOne* listener;
    //CC_SYNTHESIZE(const char*, m_pName,Name);
};

#endif /* defined(__PixelDemo__FDPixelSprite__) */
