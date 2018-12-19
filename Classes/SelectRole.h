#include "cocos2d.h"
USING_NS_CC;
class SelectRole : public CCLayer,public cocos2d::CCTextFieldDelegate
{
public:
	SelectRole(void);
	~SelectRole(void);

	CCRect rect(CCSprite* tack);
	bool isTouchInside_nan(CCPoint thisPos,CCSprite* tack);
	bool isTouchInside_nv(CCPoint thisPos,CCSprite* tack);


    virtual void registerWithTouchDispatcher(void);
    virtual bool ccTouchBegan(CCTouch *pTouch,CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch,CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch,CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch,CCEvent *pEvent);

    
   // //当用户启动虚拟键盘时的回调函数
   //virtual bool onTextFieldAttachWithIME(CCTextFieldTTF *pSender);
   // //当用户关闭虚拟键盘时的回调函数
   //virtual bool onTextFieldDetachWithIME(CCTextFieldTTF *pSender);
   // //当用户进行输入时的回调函数
   //virtual bool onTextFieldInsertText(CCTextFieldTTF *pSender,const char *text,int nLen);
   // //当用户删除文字时的回调函数
   //virtual bool onTextFieldDeleteBackward(CCTextFieldTTF *pSender,const char *delText,int nLen);
};

