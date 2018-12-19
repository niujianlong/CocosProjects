#include "Scene_Diyu.h"
#include "../ImagePaths.h"


Scene_Diyu::Scene_Diyu(void)
{
	float x,y;
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    x = size.width;
    y = size.height;
	//地图
	mainmap = new Maps_Diyu(this,"map_diyu_naihe.jpg","map_diyu_naihe1.png",0,ccp(x/2-308,y/2-486));
	mainmap_Touch =  mainmap_Touch->create("map_diyu_naihe0.png");
	mainmap_Touch->setimg("map_diyu_naihe0.png");
	mainmap_Touch->setPosition(ccp(x/2-308,y/2-486));
	mainmap_Touch->setVisible(false);//是否显示点击层

	baseui = new BaseUI(this);

	this->addChild(mainmap_Touch, 0);
#if 0
	setTouchEnabled(true);
#endif // 0
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(Scene_Diyu::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(Scene_Diyu::onTouchMoved, this);
	listener->onTouchCancelled = CC_CALLBACK_2(Scene_Diyu::onTouchCancelled, this);
	listener->onTouchEnded = CC_CALLBACK_2(Scene_Diyu::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

}


#if 0
void Scene_Diyu::registerWithTouchDispatcher()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}
#endif // 0



bool Scene_Diyu::onTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)  
{  
	if(mainmap_Touch->onTouchBegan(pTouch,pEvent)==true&&mainmap->touch_select(pTouch->getLocation())==false)
	{
		mainmap->moveMapto(pTouch->getLocation(),mainmap_Touch);
	}
	;
	baseui->isTouchInside(pTouch);
    return true;  
}  
  
void Scene_Diyu::onTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)  
{  
}  
  
void Scene_Diyu::onTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)  
{  
}  
  
void Scene_Diyu::onTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)  
{  
}  

Scene_Diyu::~Scene_Diyu(void)
{
}
