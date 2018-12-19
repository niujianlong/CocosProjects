#include "SceneTest.h"
#include "../ImagePaths.h"
#include "../Commen/FontChina.h"
#include "../GameData/GetNPCData.h"
#include "../Spirits/SpiritsPlayer.h"
#define TRANSITION_DURATION (1.2f)


CCTransitionScene* createTransition(int nIndex, float t, CCScene* s)
{
    // fix bug #486, without setDepthTest(false), FlipX,Y will flickers
    CCDirector::sharedDirector()->setDepthTest(false);

    switch(nIndex)
    {
    case 0: return CCTransitionJumpZoom::create(t, s);

    case 1: return CCTransitionProgressRadialCCW::create(t, s);
    case 2: return CCTransitionProgressRadialCW::create(t, s);
    case 3: return CCTransitionProgressHorizontal::create(t, s);
    case 4: return CCTransitionProgressVertical::create(t, s);
    case 5: return CCTransitionProgressInOut::create(t, s);
    case 6: return CCTransitionProgressOutIn::create(t, s);

    case 7: return CCTransitionCrossFade::create(t,s);
    case 10: return CCTransitionFadeTR::create(t, s);
    case 11: return CCTransitionFadeBL::create(t, s);
    case 12: return CCTransitionFadeUp::create(t, s);
    case 13: return CCTransitionFadeDown::create(t, s);

    case 14: return CCTransitionTurnOffTiles::create(t, s);

    case 15: return CCTransitionSplitRows::create(t, s);
    case 16: return CCTransitionSplitCols::create(t, s);


    case 31: return CCTransitionShrinkGrow::create(t, s);
    case 32: return CCTransitionRotoZoom::create(t, s);

    case 33: return CCTransitionMoveInL::create(t, s);
    case 34: return CCTransitionMoveInR::create(t, s);
    case 35: return CCTransitionMoveInT::create(t, s);
    case 36: return CCTransitionMoveInB::create(t, s);

    case 37: return CCTransitionSlideInL::create(t, s);
    case 38: return CCTransitionSlideInR::create(t, s);
    case 39: return CCTransitionSlideInT::create(t, s);
    case 40: return CCTransitionSlideInB::create(t, s);

    default: break;
    }

    return NULL;
}            

void SceneTest::runThisTest()
{
    CCLayer * pLayer = new TestLayer1();
    addChild(pLayer);
    pLayer->release();
    CCDirector::sharedDirector()->replaceScene(this);
}



TestLayer1::TestLayer1(void)
{
    float x,y;
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    x = size.width;
    y = size.height;
	//地图
	float map_x , map_y,map_x1 , map_y1,map_x2 , map_y2;
	CCSprite* bg1 = CCSprite::create(map_fangcunshan);
	map_y = bg1->getAnchorPointInPoints().y;
	map_x = bg1->getAnchorPointInPoints().x;
	map_y1 = bg1->getTexture()->getPixelsHigh();
	map_x1 =  bg1->getTexture()->getPixelsWide();
	map_y2 = bg1->getContentSize().height;
	map_x2 =  bg1->getContentSize().width;
	bg1->setPosition(ccp(map_x,map_y+origin.y));
    addChild(bg1, -1);
	
	//主角
	GetNPCData npcdata11 = GetNPCData();
	npcdata11.GetNPCchapter1();
	npcdata11.role_player.nowpoint=CCPointMake(x/2,y/2);
	npcdata11.role_player.dir=rigth_down;
	SpiritsPlayer taiyizhengren = SpiritsPlayer(npcdata11.role_player,0,false);

	// menu
	CCMenuItemImage *item1 = CCMenuItemImage::create(p_toscene, p_toscene0, this, menu_selector(TestLayer1::nextCallback));
	item1->setPosition(ccp(origin.x + x - item1->getContentSize().width/2 ,
        y-origin.y - item1->getContentSize().height/2));
    CCMenu *menu = CCMenu::create(item1, NULL);
	menu->setPosition(CCPointZero);
	this->addChild(menu, 0);
	setTouchEnabled(true);
}

void TestLayer1::registerWithTouchDispatcher()  
{  
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,true);  
}  


bool TestLayer1::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)  
{  
	//主角
	GetNPCData npcdata11 = GetNPCData();
	npcdata11.GetNPCchapter1();
	npcdata11.role_player.nowpoint= pTouch->getLocation();
	npcdata11.role_player.dir=rigth_down;
	SpiritsPlayer taiyizhengren = SpiritsPlayer(npcdata11.role_player,0,false);
    return true;  
}  
  
void TestLayer1::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)  
{  
	//主角
	GetNPCData npcdata11 = GetNPCData();
	npcdata11.GetNPCchapter1();
	npcdata11.role_player.nowpoint= pTouch->getLocation();
	npcdata11.role_player.dir=rigth_down;
	SpiritsPlayer taiyizhengren = SpiritsPlayer(npcdata11.role_player,0,false);
    CCLOG("move");  
}  
  
void TestLayer1::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)  
{  
}  
  
void TestLayer1::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)  
{  
}  

TestLayer1::~TestLayer1(void)
{

}


TestLayer2::~TestLayer2(void)
{

}


TestLayer2::TestLayer2(void)
{
    float x,y;
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    x = size.width;
    y = size.height;

    float map_x , map_y,map_x1 , map_y1;
	CCSprite* bg1 = CCSprite::create(map_fengjing1);
	map_y = bg1->getAnchorPointInPoints().y;
	map_x = bg1->getAnchorPointInPoints().x;
	bg1->setPosition(ccp(map_x,map_y+origin.y));
    addChild(bg1, -1);

	// menu
	CCMenuItemImage *item1 = CCMenuItemImage::create(p_toscene, p_toscene0, this, menu_selector(TestLayer2::backCallback));
    item1->setPosition(ccp(origin.x + x - item1->getContentSize().width/2 ,
        y-origin.y - item1->getContentSize().height/2));
    CCMenu *menu = CCMenu::create(item1, NULL);
	menu->setPosition(CCPointZero);
	this->addChild(menu, 0);
}

void TestLayer1::nextCallback(CCObject* pSender)
{
	CCScene* s = new SceneTest();

    CCLayer* pLayer = new TestLayer2();
    s->addChild(pLayer);

    CCScene* pScene = createTransition(6, TRANSITION_DURATION, s);
    s->release();
    pLayer->release();
    if (pScene)
    {
        CCDirector::sharedDirector()->replaceScene(pScene);
    }
}

void TestLayer2::backCallback(CCObject* pSender)
{ 

    CCScene* s = new SceneTest();

    CCLayer* pLayer = new TestLayer1();
    s->addChild(pLayer);

    CCScene* pScene = createTransition(5, TRANSITION_DURATION, s);
    s->release();
    pLayer->release();
    if (pScene)
    {
        CCDirector::sharedDirector()->replaceScene(pScene);
    }
}
