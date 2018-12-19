#include "SelectRole.h"
#include "ImagePaths.h"
#include "Effects/EffectsCommen.h"
#include "Commen/FontChina.h"
#define FONT_NAME                       "Thonburi"
#define FONT_SIZE                       36

SelectRole::SelectRole(void)
{
	float x,y;
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	x = size.width;
	y = size.height+origin.y;

	CCSprite *background_navbd=CCSprite::create(p_select_bd);
	background_navbd->setPosition(ccp(x/2,y/2));

	CCActionInterval *move_l  =  CCMoveBy::create(1.5f,ccp(75,0));
	CCActionInterval *move_r  =  CCMoveBy::create(1.5f,ccp(-75,0));
	CCActionInterval *move_l0  =  CCMoveBy::create(1.5f,ccp(75,0));
	CCActionInterval *move_r0  =  CCMoveBy::create(1.5f,ccp(-75,0));
	CCActionInterval *fade_act1  =  CCFadeOut::create(1.0f);
	CCActionInterval *fade_act2  =  CCFadeOut::create(1.0f);
	CCSprite *rolebd_nan= CCSprite::create(p_select_nan);
	rolebd_nan->setPosition(ccp(x/2+60,y/2));
	rolebd_nan->runAction(move_l0);
	CCSprite *rolebd_nv= CCSprite::create(p_select_nv);
	rolebd_nv->setPosition(ccp(x/2-60,y/2));
	rolebd_nv->runAction(move_r0);


	CCSprite *rolebd_nan0= CCSprite::create(p_select_nan0);
	rolebd_nan0->setPosition(ccp(x/2+60,y/2));
	rolebd_nan0->runAction(CCSequence::create(move_l,fade_act1,NULL));

	CCSprite *rolebd_nv0= CCSprite::create(p_select_nv0);
	rolebd_nv0->setPosition(ccp(x/2-60,y/2));
	rolebd_nv0->runAction(CCSequence::create(move_r,fade_act2,NULL));



#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	static CCString* cjs5 = CCString::create("eff_sl1_");
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	static CCString* cjs5 = CCString::create("/effects/sl1/eff_sl1_");
#endif
	EffectsCommen* csj1 = new EffectsCommen(ccp(x/2,y/2-50),cjs5,4,39,0,5);
	CCActionInterval* scale_actby1 = CCScaleBy::create(1.5f,0.35f);
	CCActionInterval* scale_actby = CCScaleBy::create(1.5f,0.7f);
	csj1->effects_main->runAction(CCSequence::create(scale_actby1,scale_actby->reverse(),NULL));

	 //CCTextFieldTTF *textField = CCTextFieldTTF::textFieldWithPlaceHolder(FontChina::G2U("点出输入..."),"Helvetica", 24);
  //  textField->setPosition(ccp(size.width*0.5, size.height*0.7));
  //  addChild(textField);
  //  
  //  //绑定接口
  //  textField->setDelegate(this);
  //  //开启输入
  //  textField->attachWithIME();

	this->addChild(csj1->effects_main,3,1990);
	this->addChild(background_navbd,1,10);
	this->addChild(rolebd_nan,2,11);
	this->addChild(rolebd_nv,2,12);
	this->addChild(rolebd_nan0,2,111);
	this->addChild(rolebd_nv0,2,122);
	
	setTouchEnabled(true);
}


CCRect SelectRole::rect(CCSprite* tack)
{
	//获取精灵区域大小
	return CCRectMake(tack->getPositionX()- tack->getContentSize().width  * tack->getAnchorPoint().x,tack->getPositionY()-tack->getContentSize().height* tack->getAnchorPoint().y,tack->getContentSize().width, tack->getContentSize().height); 
}


bool SelectRole::isTouchInside_nan(CCPoint thisPos,CCSprite* tack)
{
	CCPoint localPos = thisPos;
	CCRect rc = rect(tack);
	bool isTouched = rc.containsPoint(localPos);
	if (isTouched == true) {
		CCActionInterval *fade_act  =  CCFadeIn::create(1.0f);
		this->getChildByTag(111)->runAction(fade_act);
		this->getChildByTag(111)->setVisible(true);
		this->getChildByTag(11)->setVisible(false);
		this->getChildByTag(122)->setVisible(false);
		this->getChildByTag(12)->setVisible(true);
	}else
	{
	}
	return isTouched;
}
bool SelectRole::isTouchInside_nv(CCPoint thisPos,CCSprite* tack)
{
	CCPoint localPos = thisPos;
	CCRect rc = rect(tack);
	bool isTouched = rc.containsPoint(localPos);
	if (isTouched == true) {
		CCActionInterval *fade_act  =  CCFadeIn::create(1.0f);
		this->getChildByTag(122)->runAction(fade_act);
		this->getChildByTag(122)->setVisible(true);
		this->getChildByTag(111)->setVisible(false);
		this->getChildByTag(12)->setVisible(false);
		this->getChildByTag(11)->setVisible(true);
	}else
	{
	}
	return isTouched;
}


SelectRole::~SelectRole(void)
{

}

void SelectRole::registerWithTouchDispatcher()  
{  
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,true);  
}  


bool SelectRole::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)  
{  
	isTouchInside_nan(pTouch->getLocation(),(CCSprite*)this->getChildByTag(11));
	isTouchInside_nv(pTouch->getLocation(),(CCSprite*)this->getChildByTag(12));
	return true;  
}  

void SelectRole::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)  
{  
}  

void SelectRole::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)  
{  
}  

void SelectRole::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)  
{  
}  
