#include "cocos2d.h"
#include "ToScene.h"
#include "../MapSpirits/Maps_Diyu.h"
#include "../PublicUI/BaseUI.h"

USING_NS_CC;
class Scene_Diyu : public CCLayer
{
public:
	Scene_Diyu(void);
	~Scene_Diyu(void);
	Maps_Diyu* mainmap;
	FDPixelSprite* mainmap_Touch;
	BaseUI* baseui;

	void nextCallback(CCObject* pSender);
    virtual void registerWithTouchDispatcher(void);
    virtual bool ccTouchBegan(CCTouch *pTouch,CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch,CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch,CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch,CCEvent *pEvent);


};

