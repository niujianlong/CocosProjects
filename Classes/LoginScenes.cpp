#include "LoginScenes.h"
#include "ImagePaths.h"
#include "Effects/EffectsCommen.h"
#include "PublicScenes/ToScene.h"
#include "SelectRole.h"
LoginScenes::LoginScenes(void)
{
	float x,y;
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	x = size.width;
	y = size.height+origin.y;
	CCSprite *background_navbd=CCSprite::create(p_login_bd1);
	background_navbd->setPosition(ccp(x/2,y/2-70));
	CCSprite *ui_logo=CCSprite::create(p_logo);
	ui_logo->setPosition(ccp(x/2,y/2+50));
	//CCSprite *ui_login_start=CCSprite::create(p_login_start);
	//ui_login_start->setPosition(ccp(x/2-40,y/2-70));
	//CCSprite *ui_login_newrole=CCSprite::create(p_login_newrole);
	//ui_login_newrole->setPosition(ccp(x/2+40,y/2-100));

	EffectsCommen* cj1 = new EffectsCommen(ccp(x/2+50,y/2+100),eff_cj1,4.5f,28,0,5);
	EffectsCommen* cj2 = new EffectsCommen(ccp(x/2,y/2),eff_cj2,5.5f,29,0,5);
	EffectsCommen* cj3 = new EffectsCommen(ccp(x/2-60,y/2-70),eff_cj4,5.0f,29,0,5);
	CCActionInterval* scale_actby = CCScaleBy::create(2.0f,3.0f);
	CCActionInterval *animation = CCSequence::create(scale_actby,scale_actby->reverse(),NULL);
	cj1->effects_main->runAction(CCRepeatForever::create(animation));
	this->addChild(cj1->effects_main,105);
	this->addChild(cj2->effects_main,106);
	this->addChild(cj3->effects_main,107);
	CCMenuItemImage *p_ui_login_start = CCMenuItemImage::create(
		"login_start.png",
		"login_start0.png",
		this,
		menu_selector(LoginScenes::menuStartGame));
	CCMenu* pMenu = CCMenu::create(p_ui_login_start, NULL);
	pMenu->setPosition(ccp(x/2-40,y/2-70));
	this->addChild(pMenu, 102);
	CCMenuItemImage *p_ui_login_newrole = CCMenuItemImage::create(
		"login_newrole.png",
		"login_newrole0.png",
		this,
		menu_selector(LoginScenes::menuNewGame));
	CCMenu* pMenu2 = CCMenu::create(p_ui_login_newrole, NULL);
	pMenu2->setPosition(ccp(x/2+40,y/2-100));
	this->addChild(pMenu2, 103);

	this->addChild(background_navbd,100);
	this->addChild(ui_logo,101);
	this->makebd(0,0,99);
	this->makebd(1,0,98);
	this->schedule(schedule_selector(LoginScenes::movebd)); 
	setTouchEnabled(true);
}

//新建
void LoginScenes::menuNewGame(CCObject* pSender)
{
	CCScene* s = new ToScene(true);
	CCLayer * pLayer = new SelectRole();
	s->addChild(pLayer);
	pLayer->release();
	CCDirector::sharedDirector()->replaceScene(s);
}

//开始
void LoginScenes::menuStartGame(CCObject* pSender)
{
}

void LoginScenes::makebd(float num,int w,int tag)
{
	float x,y;
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	x = size.width;
	y = size.height+origin.y;

	CCSprite *background=CCSprite::create(p_loginallbd);
	background->setAnchorPoint(CCPoint(0,0.5));
	background->setPosition(CCPoint(background->getContentSize().width*num+w,y/2));
	this->addChild(background,tag,tag);
}

void LoginScenes::movebd(float times)
{
	float x,y;
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	x = size.width;
	y = size.height+origin.y;

	CCNode *bg1=CCNode::getChildByTag(99);
	CCSprite *sp1=(CCSprite*)bg1;

	CCNode *bg2=CCNode::getChildByTag(98);
	CCSprite *sp2=(CCSprite*)bg2;
	sp1->setPosition(CCPoint(sp1->getPositionX()-0.5,sp1->getPositionY()));
	sp2->setPosition(CCPoint(sp2->getPositionX()-0.5,sp2->getPositionY()));
	if(sp1->getPositionX()<=-sp1->getContentSize().width)
	{
		sp1->setPosition(CCPoint(sp1->getContentSize().width,y/2));
	}
	if(sp2->getPositionX()<=-sp2->getContentSize().width)
	{
		sp2->setPosition(CCPoint(sp2->getContentSize().width,y/2));
	}
}

LoginScenes::~LoginScenes(void)
{
}

void LoginScenes::registerWithTouchDispatcher()  
{  
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,true);  
}  


bool LoginScenes::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)  
{  

	return true;  
}  

void LoginScenes::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)  
{  
}  

void LoginScenes::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)  
{  
}  

void LoginScenes::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)  
{  
}  
