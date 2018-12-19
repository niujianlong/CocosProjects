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
#if COCOS2DX_VERSION_2X
	virtual void registerWithTouchDispatcher(void);
#endif // COCOS2DX_VERSION_2X

    virtual bool onTouchBegan(CCTouch *pTouch,CCEvent *pEvent);
    virtual void onTouchMoved(CCTouch *pTouch,CCEvent *pEvent);
    virtual void onTouchEnded(CCTouch *pTouch,CCEvent *pEvent);
    virtual void onTouchCancelled(CCTouch *pTouch,CCEvent *pEvent);


};

